//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TProgressBar *ProgressBar1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label3;
	TEdit *Edit2;
	TButton *Button2;
	TButton *Button3;
	TMemo *Memo1;
	TTimer *Timer2;
	TTimer *Timer3;
	TLabel *Label4;
	TLabel *Label5;
	TMediaPlayer *MediaPlayer1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	int varredura (int);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif