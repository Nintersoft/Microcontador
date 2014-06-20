//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *Arquivo1;
	TMenuItem *Salvar1;
	TMenuItem *N2;
	TMenuItem *Fechar1;
	void __fastcall Fechar1Click(TObject *Sender);
	void __fastcall Salvar1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
