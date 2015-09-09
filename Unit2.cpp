//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "stdlib.h"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

/*
const double Z=79;        //заряд Au
const double Az=197;       //в а е м атомная масса Au
const double ro=19.3;   //плотность Au в г/см3
const double J=789;

const double Z=78;        //заряд Pt
const double Az=195;       //в а е м атомная масса Pt
const double ro=21.45;   //плотность Pt в г/см3
const double J=792;
*/
const double Z=14;                          //заряд кремния
const double Az=28;                         //в а е м атомная масса кремния
const double ro=2.33;                       //плотность кремния в г/см3
const double J=178;                         //средний потенциал ионизации
const double eV = 1.6*1e-19;                //электрон вольт
const double rad = 0.01745;                 //радиан
const double nm = 1e-9;                     //нанометр
const double Na = 6.02*1e23;                //число Авогадро
const double cm = 0.01;
const double pixl = nm;
const long N=501;                           //размер картинок
const long N2=2*N;                           //размер массива BSE
long m,n,r;               //флаге

long B[N][N];
long Pole[N][N];
long A[N][N];
long C[N][N];
double BSE[N2] ;
double BSE_norm[N2];
double BSE_calc[N][N];
double Ort[9];
double Energy[2000];


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

long TForm1::F2L (double value)
{
    //Функция округления
    double module = fabs(value);

    if( module - floor(module ) < 0.5)
    {
        if(value >= 0) return(floor(module));
        else return(-floor(module));
    }
    else
    {
        if(value >= 0) return(ceil(module));
        else return(-ceil(module));
    }
}

//---------------------------------------------------------------------------


void TForm1::DrawArrayF ( double ** array, TImage *img)
{
    //Функция отрисовки 2D массива вещественных данных
    double max = 0;
    for(long i = 0; i < N; i++)
    {
        for(long j = 0; j < N; j++)
        {
            if( max < array[i][j] ) max = array[i][j];
        }
    }
    if( max == 0) max = 1;

    for(long i = 0; i < N; i++)
    {
        for(long j = 0; j < N; j++)
        {
            img->Canvas->Pixels[i][j] = F2L( (array[i][j]/max)*255 )*0x010101;
        }
    }
}


//---------------------------------------------------------------------------

/*void TForm1::DrawArrayL (long *array, long size, TImage *img)
{
    //Функция отрисовки 2D массива целых данных
    long max = 1;
    for(long i = 0; i < size; i++)
    {
        for(long j = 0; j < size; j++)
        {
            if( max < array[i][j] ) max = array[i][j];
        }
    }

    for(long i = 0; i < size; i++)
    {
        for(long j = 0; j < size; j++)
        {
            img->Canvas->Pixels[i][j] = F2L( (array[i][j]/max)*255 )*0x010101;
        }
    }
}
   */
/*void Print_File_Matrix(double end[][100],int x1,int y1,char *str)
{
 FILE *out=fopen(str,&quot;w&quot;);
 int i,j;
 i=j=0;
 for(i=0;i&lt;x1;i++,fprintf(out,&quot;\n&quot;))
   for(j=0;j&lt;y1;j++)
     fprintf(out,&quot;%2.3lf &quot;,end[i][j]);
 fprintf(out,&quot;\n&quot;);
 close(out);
}
//Это запись двумерного массива типа double, функция принимает массив,размерность массива и строку(имя файла)
*/
//---------------------------------------------------------------------------

double TForm1::Rotate(long flag, double ort, double c_fi, double s_fi, double c_c, double s_s, double c_s, double s_c, double psy, double lenght)
{
    //Функция вращения радиус-вектора электрона

        double e1 = c_c*Ort[flag] + c_s*Ort[flag+3] - s_fi*Ort[flag+6];
        double e2 = -sin(psy)*Ort[flag] + cos(psy)*Ort[flag+3];
        double e3 =  s_c*Ort[flag] + s_s*Ort[flag+3] + c_fi*Ort[flag+6];
        Ort[flag] = e1;
        Ort[flag+3] = e2;
        Ort[flag+6] = e3;

        ort = ort + lenght*e3;

        return(ort);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)

{
        RadioButton2->Checked =false;

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
        RadioButton1->Checked =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Randomize();
        Label7->Caption = "Фкалываю";
        Label7->Update();
        Image1->Canvas->FillRect(Rect(0,0,N,N));
        Image4->Canvas->FillRect(Rect(0,0,N,N));
        if (RadioButton1->Checked==true) m =1;
        if (RadioButton2->Checked==true) m =2;
        if (RadioButton3->Checked==true) n =1;
        if (RadioButton4->Checked==true) n =2;
        if (CheckBox1->Checked==true) r=1;
        if (CheckBox1->Checked==false) r=0;

        long rancon  = (atoi(Edit10->Text.c_str()));
        double E    = atof(Edit1->Text.c_str());        //начальная энергия электронов в пучке
        double Emin = atof(Edit4->Text.c_str());
        double a0 = rad*atoi(Edit7->Text.c_str());      //угол падения электронного пучка
        long scale    = atoi(Edit2->Text.c_str());      //мастштаб отрисовки
        long current  = atoi(Edit5->Text.c_str());      //число обсчитываемых электронов
        double tol = nm/cm*atoi(Edit11->Text.c_str());  //конечная толщина образца
        double th  = nm*atoi(Edit8->Text.c_str());      //полуширина детектора для измерения stopping power
        long dl = atoi(Edit13->Text.c_str());           //число промежутков дельта лямбда
        double SP = 0;                                  //значение SP
        long k = 0;     long o = 0;      long l = 0;

        for (long j = 1; j <= current; j++)
        {
            ProgressBar2->Position = (j*100)/current;
            Image1->Canvas->MoveTo(0, 20);
            Image1->Canvas->LineTo(Image1->Width, 20);
            Image4->Canvas->MoveTo(250, 250);
            if (n==1)     //finite specimen
            {
                Image1->Canvas->MoveTo(0, F2L((tol/scale*cm)/pixl) + 20 );
                Image1->Canvas->LineTo(Image1->Width, F2L((tol/scale*cm)/pixl) + 20);
            }
            Image1->Canvas->MoveTo(Image1->Width/2+F2L(20*sin(a0)/cos(a0)), 0);
            Image1->Canvas->LineTo(Image1->Width/2, 20);

            Ort[0] =cos(a0); Ort[1] =0; Ort[2] =sin(a0); Ort[3] =0; Ort[4] =1; Ort[5] =0; Ort[6] =-sin(a0); Ort[7] =0; Ort[8] =cos(a0);
            double path = 0;
            double x = 0;
            double z = 0;
            double y = 0;
            double Ei =E;

            do
            {
                o++;
                double psi =  rad*(random(2*180+1)-180);
                double alpha =(3.4*1e-3*pow(Z,0.67))/(Ei);
                double sigma =(5.21*1e-21*(Z*Z)/(Ei*Ei)) * ( (4*M_PI)/(alpha*(1+alpha)) ) * pow( (Ei+511)/(Ei+1024) , 2);
                double lambda = (Az/(Na*ro*sigma));

                double randy = (double)(( random( rancon + 1 ) )) / (double)rancon;
                double cosfi = 1.0 - 2.0*alpha*( randy )/(1.0 + alpha - randy);
                double sinfi = 2* sqrt( alpha* ( 1 + alpha )* ( 1 - randy )* randy )/ ( 1 + alpha - randy);
                double ss = sinfi * sin(psi);
                double sc = sinfi * cos(psi);
                double cc = cosfi * cos(psi);
                double cs = cosfi * sin(psi);

                double rnd = ((double)random( dl ) + 1) / (double)dl;
                double lt = -lambda*log( rnd );
                path = path + lt;

                x = Rotate(0, x, cosfi, sinfi, cc, ss, cs, sc, psi, lt);
                y = Rotate(1, y, cosfi, sinfi, cc, ss, cs, sc, psi, lt);
                z = Rotate(2, z, cosfi, sinfi, cc, ss, cs, sc, psi, lt);

                Ei = Ei - 7.85*1e4*((Z*ro)/(Az*Ei))*log((1666*Ei)/J)*lt;

                if (r==1)
                {
                    Image4->Canvas->LineTo( F2L((x/scale*cm)/pixl) + 250, F2L((y/scale*cm)/pixl)+250);  //рисуем отрезок траектории электрона
                    if (m==1) Image1->Canvas->LineTo( F2L((x/scale*cm)/pixl) + 250, F2L((z/scale*cm)/pixl)+20);
                    if (m==2) Image1->Canvas->LineTo( F2L((y/scale*cm)/pixl) + F2L(Image1->Width/2), F2L((z/scale*cm)/pixl)+20);
                }
            } while ( ( (( (double)Ei > Emin ) ) && (z > 0) ) && ((z < tol) || (n ==2)));

            if  ( z < 0 )     //вносим частицы, вылетевшие на поврехность,  массив
            {
                long r1 = F2L( sqrt(pow( ( (x*cm)/pixl)/scale,2 )+ pow( ( (y*cm)/pixl)/scale ,2 ) ) );
                Energy[r1]++;
                long x1 = F2L( ((x*cm)/pixl)/scale ) + (N-1)/2;
                long y1 = F2L( ((y*cm)/pixl)/scale ) + (N-1)/2;
                if(r1 <= N2 ) BSE[r1]++;
                if ( ((y1<N) && (y1>0)) && ( (x1<N) && (x1>0)) ) B[x1][y1]++;
                l++;
            }

            if (((z >tol) && (n ==1)) && (((((Image1->Width-1)/2)) + F2L(th/nm) >F2L(x/nm))&& (F2L(x/nm) >( (Image1->Width -1)/2 - F2L(th/nm) ) ) )  );
            {
                SP = SP +(E-Ei)/eV;
                k++;
            }
        }

        if( k > 0 )
        {
            SP =SP/(F2L(tol*cm/pixl)*k);
            Edit9->Text = SP;
        }

        for(long i = 0; i < N2; i++)
        {
            BSE[i] = BSE[i]/current;
        }
        for (long i = 0; i < 2000; i++) Memo3->Lines->Add(Energy[i]);
        double BSy = (double)l/current;
        Edit12->Text = BSy;
        Edit3->Text = (double)o/current;
        Label7->Caption = "Фтыкаю";
        Label7->Update();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
         long max1 = 1;
         Image2->Canvas->MoveTo(0,0);
         for (long i = 0; i < N; i++)
         {
               for (long j = 0; j < N; j++)
               {
                    if (max1 < B[i][j]) max1 = B[i][j];
               }
         }

         for (long i = 0; i < N; i++)
         {
               for (long j = 0; j < N; j++)
               {
                    Image2->Canvas->Pixels[i][j] = (F2L(B[i][j]*255/max1))*0x010101;
               }
         }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{
        //Осаждение частиц на поверхность.
        long particles = atoi(Edit14->Text.c_str());
        long chance = 255*atoi(Edit6->Text.c_str());
        long a ;
        double x ;
        double y ;
        bool f ;

        for(long j = 0; j < particles; j++)
        {
                long a = random(360);
                double x = 249*cos(a*M_PI/180)+249;
                double y = 249*sin(a*M_PI/180)+249;
                bool f = true;

                do{
                        x = x + random(5)-2;
                        y = y + random(5)-2;
                        if(x < 0) x = Image3->Width;
                        if(y < 0) y = Image3->Height;
                        if(x > Image3->Width) x = 0;
                        if(y > Image3->Height) y = 0;
                        if(random(chance) < B[F2L(x)][F2L(y)])
                        {
                                f = false;
                                C[F2L(x)][F2L(y)] = C[F2L(x)][F2L(y)] + 1;
                        }
                }while(f);
                ProgressBar1->Position = (j*100)/particles;
        }

        long max2 = 1;
        for (long i = 0; i < N; i++)
         {
               for (long j = 0; j < N; j++)
               {
                        if (max2 < C[i][j]) max2 = C[i][j];
               }
         }
         Image3->Canvas->MoveTo(0,0);
         for (long i = 0; i < N; i++)
         {
               for (long j = 0; j < N; j++)
               {
                        Image3->Canvas->Pixels[i][j] = (F2L(C[i][j]*255/max2))*0x010101;
               }
         }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
OpenDialog1->Execute();
  if(OpenDialog1->FileName != "")
  {
    Graphics::TBitmap *Bitmap1 = new Graphics::TBitmap();
    Bitmap1->LoadFromFile(OpenDialog1->FileName);
    Image2->Canvas->Draw(0,0,Bitmap1);
    for(long i = 0; i < N; i++)
    {
      for(long j = 0; j < N; j++)
      {
        B[i][j] = Bitmap1->Canvas->Pixels[i][j]/0x010101;
      }
    }
    delete Bitmap1;
    Button3->Enabled = true;
    Image3->Canvas->Brush->Color = clBlack;
    Image3->Canvas->FillRect(Rect(0,0,N,N));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
    double maxim = B[1][1];

    for(long i=0; i < N; i++)
    {
        if (B[i][250] > maxim) maxim = B[i][250];
    }

    Image3->Canvas->MoveTo(0,Image3->Height)   ;
    for (long i=0; i < N; i++)
    {
        Image3->Canvas->LineTo(i, (Image3->Height - B[i][250]*Image3->Height/maxim) );
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button9Click(TObject *Sender)
{
    long maxv = 1;

    for(long i = 0; i < N2; i++)
    {
       if(maxv < BSE[i]) maxv = BSE[i];
    }
    for(long j = 0; j < N2; j++)
    {
       BSE_norm[j] = BSE[j]/(3.14* ( pow(j+1,2)- pow(j,2) ) ) ;
    }
    Image5->Canvas->MoveTo(0,Image5->Height);
    for(long i = 0; i < Image5->Width; i++)
    {
        Image5->Canvas->LineTo(i,Image5->Height*(1 - BSE[i]/maxv) );
    }

    double maxv2 = 1e-9;
    for(long i = 0; i < N2; i++)
    {
       if(maxv2 < BSE_norm[i]) maxv2 = BSE_norm[i];
    }
    Image6->Canvas->MoveTo(0,Image5->Height);
    for(long i = 0; i < Image5->Width; i++)
    {
        Image6->Canvas->LineTo(i,Image5->Height*(1 - BSE_norm[i]/maxv2) );
    }

    for(long l = 0; l < N2; l++) Memo1->Lines->Add(BSE[l]);
    for(long l = 0; l < N2; l++) Memo2->Lines->Add(BSE_norm[l]);


    for(long k = 0; k < N2; k++)
    {
        Chart1->Series[0]->AddXY(k,BSE_norm[k],' ',clGreen);
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
    Graphics::TBitmap *Bitmap1 = new Graphics::TBitmap();
    Bitmap1->Width = N;
    Bitmap1->Height = N;
    for(long x = 0; x < N; x++)
    {
        for(long y = 0; y < N; y++)
        {
            Bitmap1->Canvas->Pixels[x][y] = Image2->Canvas->Pixels[x][y];
        }
    }
    if(Bitmap1->Empty) Form1->Caption = "Empty";
    Bitmap1->SaveToFile((AnsiString)"ARGH"+(AnsiString)".bmp");
    delete Bitmap1;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
    for(long i = 0; i < N; i++)
    {
        for(long j = 0; j < N; j++)
        {
            BSE_calc[i][j] = BSE_norm[ F2L(sqrt( pow((i - (N+1)/2 ) , 2) + pow((j - (N+1)/2 ) , 2) ) ) ];
        }
    }

    double max;
    for(long i = 0; i < N; i++)
    {
       for(long j = 0; j < N; j++)
       {
            if(max < BSE_calc[i][j]) max = BSE_calc[i][j];
       }
    }
    Form1->Caption = max;
    if(max == 0) max = 1;


    for (long i = 0; i < N; i++)
    {
        for (long j = 0; j < N; j++)
        {
            Image7->Canvas->Pixels[i][j] = F2L( (BSE_calc[i][j]/max)*255 )*0x010101;
        }
    }

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button8Click(TObject *Sender)
{
   // DrawArrayF(BSE, Image7);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
    const long bsize = 101;
    double scale = atof(Edit17->Text.c_str() )/atof(Edit2->Text.c_str() );
    double BSE_rather[bsize][bsize];

    for(long i = 0; i < bsize; i++)
    {
        for(long j = 0; j < bsize; j++)
        {
            BSE_rather[i][j] = BSE_norm[ F2L(sqrt(  pow( scale*(i - (bsize+1)/2 ) , 2) + pow( scale*(j - (bsize+1)/2 ) , 2) ) ) ] * pow(scale, 2);
        }
    }
    double max;
    double sum = 0;
    for(long i = 0; i < bsize; i++)
    {
       for(long j = 0; j < bsize; j++)
       {
            if(max < BSE_rather[i][j]) max = BSE_rather[i][j];
            sum = sum + BSE_rather[i][j];
       }
    }
    Form1->Caption = sum;
    if(max == 0) max = 1;

    //Image7->Canvas->FillRect()
    for (long i = 0; i < bsize; i++)
    {
        for (long j = 0; j < bsize; j++)
        {
            Image7->Canvas->Pixels[i][j] = F2L( (BSE_rather[i][j]/max)*255 )*0x010101;
        }
    }
}

//---------------------------------------------------------------------------

