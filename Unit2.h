//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <MPlayer.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
    TOpenDialog *OpenDialog2;
        TScrollBox *ScrollBox1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TLabel *Label7;
        TImage *Image1;
        TButton *Button1;
        TProgressBar *ProgressBar2;
        TScrollBox *ScrollBox2;
        TImage *Image4;
        TPageControl *PageControl2;
        TTabSheet *TabSheet3;
        TLabel *Label6;
        TLabel *Label3;
        TLabel *Label11;
        TLabel *Label8;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label10;
        TLabel *Label12;
        TLabel *Label18;
        TEdit *Edit2;
        TEdit *Edit5;
        TEdit *Edit1;
        TEdit *Edit7;
        TCheckBox *CheckBox1;
        TRadioGroup *RadioGroup1;
        TEdit *Edit11;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TCheckBox *CheckBox2;
        TTabSheet *TabSheet4;
        TLabel *Label13;
        TLabel *Label5;
        TLabel *Label9;
        TLabel *Label14;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TEdit *Edit8;
        TEdit *Edit4;
        TButton *Button7;
        TEdit *Edit10;
        TEdit *Edit13;
        TTabSheet *TabSheet5;
        TLabel *Label17;
        TLabel *Label19;
        TLabel *Label4;
        TEdit *Edit9;
        TEdit *Edit12;
        TEdit *Edit3;
        TTabSheet *TabSheet6;
        TLabel *Label15;
        TLabel *Label16;
        TEdit *Edit15;
        TEdit *Edit16;
        TTabSheet *TabSheet2;
        TLabel *Label20;
        TLabel *Label21;
        TImage *Image2;
        TImage *Image3;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TEdit *Edit14;
        TProgressBar *ProgressBar1;
        TEdit *Edit6;
        TButton *Button6;
        TButton *Button10;
        TTabSheet *TabSheet7;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TLabel *Label22;
        TButton *Button9;
        TMemo *Memo1;
        TMemo *Memo2;
        TButton *Button2;
        TChart *Chart1;
        TLineSeries *Series1;
        TButton *Button8;
        TEdit *Edit17;
        TButton *Button11;
        TMemo *Memo3;
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button9Click(TObject *Sender);
    void __fastcall Button10Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall Button11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
            long F2L(double value);
            double Rotate(long flag, double ort, double c_fi, double s_fi, double c_c, double s_s, double c_s, double s_c, double psy, double lenght);
            void TForm1::DrawArrayF (double **array,  TImage *img);
            //void Print_File_Matrix(double end[][100],int x1,int y1,char *str);
           // void TForm1::DrawArrayL (long *array[][501],  TImage *img);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
