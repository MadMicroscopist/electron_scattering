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
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TButton *Button1;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TEdit *Edit14;
        TProgressBar *ProgressBar1;
        TProgressBar *ProgressBar2;
        TEdit *Edit6;
        TOpenDialog *OpenDialog1;
        TLabel *Label20;
        TLabel *Label21;
    TScrollBox *ScrollBox1;
    TPageControl *PageControl2;
    TTabSheet *TabSheet3;
    TTabSheet *TabSheet4;
    TButton *Button6;
    TEdit *Edit2;
    TLabel *Label6;
    TLabel *Label3;
    TLabel *Label11;
    TGroupBox *GroupBox1;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TEdit *Edit5;
    TLabel *Label8;
    TLabel *Label1;
    TEdit *Edit1;
    TLabel *Label2;
    TLabel *Label10;
    TEdit *Edit7;
    TLabel *Label12;
    TLabel *Label13;
    TEdit *Edit8;
    TTabSheet *TabSheet5;
    TEdit *Edit9;
    TLabel *Label17;
    TLabel *Label19;
    TEdit *Edit12;
    TLabel *Label4;
    TEdit *Edit3;
    TCheckBox *CheckBox1;
    TEdit *Edit4;
    TLabel *Label5;
    TOpenDialog *OpenDialog2;
    TButton *Button7;
    TLabel *Label7;
    TEdit *Edit10;
    TLabel *Label9;
    TEdit *Edit13;
    TLabel *Label14;
    TTabSheet *TabSheet6;
    TEdit *Edit15;
    TLabel *Label15;
    TLabel *Label16;
    TEdit *Edit16;
    TTabSheet *TabSheet7;
    TButton *Button9;
    TMemo *Memo1;
    TImage *Image1;
    TImage *Image2;
    TImage *Image3;
    TImage *Image4;
    TButton *Button10;
    TImage *Image5;
    TImage *Image6;
    TMemo *Memo2;
    TImage *Image7;
    TButton *Button2;
    TChart *Chart1;
    TLineSeries *Series1;
    TButton *Button8;
    TEdit *Edit17;
    TLabel *Label22;
    TButton *Button11;
        TCheckBox *CheckBox2;
    TScrollBox *ScrollBox2;
    TTabSheet *TabSheet8;
    TEdit *Edit18;
    TEdit *Edit19;
    TEdit *Edit20;
    TEdit *Edit21;
    TEdit *Edit22;
    TEdit *Edit23;
    TLabel *Label23;
    TLabel *Label24;
    TLabel *Label26;
    TLabel *Label27;
    TLabel *Label28;
    TEdit *Edit25;
    TEdit *Edit26;
    TLabel *Label30;
    TLabel *Label25;
    TEdit *Edit24;
    TLabel *Label29;
    TButton *Button12;
    TMemo *Memo3;
    TMemo *Memo4;
    TButton *Button13;
    TButton *Button14;
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button9Click(TObject *Sender);
    void __fastcall Button10Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall Button11Click(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
    void __fastcall Button12Click(TObject *Sender);
    void __fastcall Button13Click(TObject *Sender);
    void __fastcall Button14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
            long F2L(double value);
            double Rotate(long flag, double ort, double c_fi, double s_fi, double c_c, double s_s, double c_s, double s_c, double psy, double lenght);
            void TForm1::DrawArrayF (double **array,  TImage *img);
            void TForm1::Spacimen_substrate( void);
            void TForm1::Spacimen_layer( void);
            //void Print_File_Matrix(double end[][100],int x1,int y1,char *str);
           // void TForm1::DrawArrayL (long *array[][501],  TImage *img);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
