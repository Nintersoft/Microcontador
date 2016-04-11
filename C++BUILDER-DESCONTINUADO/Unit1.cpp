//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Docwiki1Click(TObject *Sender)
{
	ShellExecuteA( NULL, "open", "http://docwiki.nintersoft.com/Microcontador", NULL, NULL, SW_SHOW );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SiteNintersoft1Click(TObject *Sender)
{
	ShellExecuteA( NULL, "open", "http://www.nintersoft.com/", NULL, NULL, SW_SHOW );
}
//---------------------------------------------------------------------------

