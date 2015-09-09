//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdlib.h"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//��� ������ ����� ������ ����������� ���������:
//1. ����� - ���������� ����, �� ����� ���� ����, ���������� �������� (��� ������ � ������).
//2. ����� - ������ �������������. ����� �������� ����������� �� ���, �� ��� �� ������ ����� ������� (��������� ������������).
//3. ����� ������ - ���������� ����, � ����� - �������������. ����� �������� � 9 ������� �� 10 �������� ����������� ��� ������, � � 1 ������ - ������ ����� ������� (��� � ��������� MC_Demo).
//(c) ��� ���������   =)

double dis, dis2;       //1.����. ���������� ������� ��� ����������� ������� ����� ����
                        //2. ������ ������� ��� ������������
double x,z,x1;          //���������
double lt;              //����� ���������� �������
double E,Ei;            //��������� � ���������� ������� ���������� � �����
double a,c;             //������������ � ��������� ���� ���������� ��� ����������
double b,d;             //��������� ���� ����������
double th;              //���������� ��������� ��� ��������� stopping power
double SP;              //�������� SP
double BSy;             //�������� BS yield
long M;                 //����� ���������� � �����
long i,j,k,l,m,n,o,o2;         //�������
double rnd;             // ��������� ��������
double ver;               //����������� ��������� � ������ 2
double tol;               //�������� ������� �������
const long N=500;       //������ �������
long A[N];              //������, ���������� �������, ���������� ����� �����������

const double eV=0.00000000000000000016;
const double rad=0.01745;
const double nm =0.000000001;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        m =1;
        Edit3->Enabled =true;
        Edit4->Enabled =false;
        Edit10->Enabled =false;
        TrackBar1->Enabled =false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
        Edit11->Enabled =false;
        Edit9->Enabled =false;
        n=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
        Edit11->Enabled =true;
        Edit9->Enabled =true;
        n=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
        m =2;
        Edit4->Enabled =true;
        Edit3->Enabled =false;
        Edit10->Enabled =true;
        TrackBar1->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        E    = eV*atoi(Edit1->Text.c_str());
        lt   = nm*atoi(Edit2->Text.c_str());
        dis  = eV*atoi(Edit3->Text.c_str());
        dis2 = eV*atoi(Edit4->Text.c_str());
        M    = atoi(Edit5->Text.c_str());
        a    = rad*atoi(Edit6->Text.c_str());
        c    = rad*atoi(Edit7->Text.c_str());
        th   = nm*atoi(Edit8->Text.c_str());
        ver  = atoi(Edit10->Text.c_str());
        tol  = nm*atoi(Edit11->Text.c_str());
        SP   = 0;
        k    = 0;
        l    = 0;

        if (RadioButton1->Checked==true) m =1;
        if (RadioButton2->Checked==true) m =2;
        if (RadioButton3->Checked==true) n =1;
        if (RadioButton4->Checked==true) n =2;

        PaintBox1->Canvas->FillRect(Rect(0,0,PaintBox1->Width,PaintBox1->Height));
        for (j=1; j<M; j++)
        {
                x =0; z =0; b =c; Ei =E;
                i =0;
                PaintBox1->Canvas->MoveTo(0, 20);
                PaintBox1->Canvas->LineTo(PaintBox1->Width, 20);
                PaintBox1->Canvas->MoveTo(PaintBox1->Width/2-(long)(20*sin(c)/cos(c)), 0);
                PaintBox1->Canvas->LineTo(PaintBox1->Width/2, 20);
                do
                {
                        i++;
                        if (m==1)
                        {
                                d = random(2*a+1)-a;  //�������� ��������� ���� ���������
                                b = b +d;
                                x = x +lt*sin(b);    //������� ���������� ���������
                                z = z +lt*cos(b);
                                Ei =Ei -(long)(lt/nm)*dis;    //������� ������� ���������
                                PaintBox1->Canvas->LineTo((long)(x/nm)+(long)(PaintBox1->Width/2),(long)(z/nm)+10);  //������ ������� ���������� ���������
                        }
                        if (m==2)
                        {
                                d = random(2*a+1)-a;
                                rnd = random(100);
                                b = b +d;
                                x = x +lt*sin(b);
                                z = z +lt*cos(b);
                                if (rnd < ver) Ei =Ei -dis2;
                                PaintBox1->Canvas->LineTo((long)(x/nm)+(long)(PaintBox1->Width/2),(long)(z/nm)+10);
                        }
                } while (((Ei > 0) && (z > 0)) && ((z < tol) || (n ==2)));
                if  (z<0)     //������ �������, ���������� �� �����������,  ������
                {
                        x1 = (long)(x/nm)+(long)(PaintBox1->Width/2);
                        if  (((long)floor(x1 / ((double)PaintBox1->Width/(double)N))<N) && (long)floor(x1 / ((double)PaintBox1->Width/(double)N))>0) A[(long)floor(x1 / ((double)PaintBox1->Width/(double)N))]++;  //������ � ������ �������, ���������� �� �����������
                        l++;
                        //PaintBox1->Canvas->LineTo(x+PaintBox1->Width/2,100);
                }
                if (((z >tol) && (n ==1)) && ((((long)(PaintBox1->Width/2))+(long)(th/nm) >(long)(x/nm))&& ((long)(x/nm) >((long)(PaintBox1->Width/2))-(long)(th/nm))))
                {
                        SP =SP +(E-Ei)/eV;
                        k++;
                }
                //SP =(0.5)*(SP +(E-Ei)/th);
                //{
                //        if (j=1) SP = (E-Ei)/th;
                //        else SP =(0.5)*(SP +(E-Ei)/th);
                //}
        }
        if(k>0)
        {
                SP =SP/((long)(tol/nm)*k);
                Edit9->Text = SP;
        }
        BSy = (double)l/M;
        Edit12->Text = BSy;
        //Form1->Caption =k;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
        Edit10->Text = TrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1Change(TObject *Sender)
{
for (j=1; j<M; j++)  Memo1->Lines= A[j];

}
//---------------------------------------------------------------------------

