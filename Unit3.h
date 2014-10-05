//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TMaskEdit *MaskEdit1;
	TMaskEdit *MaskEdit2;
	TMaskEdit *MaskEdit3;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TLabel *Label3;
	TLabel *Label4;
	TCheckBox *CheckBox3;
	TButton *Button1;
	TLabel *Label5;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TButton *Button2;
	TButton *Button3;
	TGroupBox *GroupBox3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TMemo *Memo1;
	TRadioButton *RadioButton6;
	TButton *Button4;
	TCheckBox *CheckBox4;
	TMemo *Memo2;
	TMediaPlayer *MediaPlayer1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
