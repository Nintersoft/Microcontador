//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Fechar1Click(TObject *Sender)
{
	Form6->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Salvar1Click(TObject *Sender)
{
	Memo1->Lines->SaveToFile("..\\idiomas\\edit.idioma");
}
//---------------------------------------------------------------------------
