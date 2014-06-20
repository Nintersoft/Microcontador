//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

int visualconf (int);

//---------------------------------------------------------------------------
int c=1, a=0, lin = 5;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	ProgressBar1->Max = StrToInt(Edit2->Text);
	ProgressBar1->Min = 0;
	c = StrToInt (Edit1->Text);
	if ( c != 0 && a != 1) {
		c--;
		Edit1->Text = IntToStr (c);
		ProgressBar1->Position = c;
	}
	else if (a != 1 && c == 0) {
		a++;
		if (Form4->Memo1->Lines->Strings[0] != "Digite sua mensagem aqui! - Opcional") {
			Application->BringToFront();
			throw Exception (Form4->Memo1->Lines->Strings[0]+" "+Form4->Memo1->Lines->Strings[1]);
		}
		else {
			Application->BringToFront();
			throw Exception ("Tempo limite atingido, sua contagem acabou!");
		}
	}
	else if (a == 1) {
		a=0;
		Timer1->Enabled=false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	if (Edit1->Text == "Configure o módulo antes!") {
		throw Exception ("Você deve colocar um valor válido para ser contado em configurações!");
	}
	else{
		Timer1->Enabled=true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
	if (FileExists("..\\config\\interface.conf")) {
		visualconf(lin);
	}
}
//---------------------------------------------------------------------------
int visualconf (int lin) {
	if (Form2->Memo1->Lines->Strings[lin] == "true") {
	Form3->CheckBox1->Checked = true;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "false") {
	Form3->CheckBox1->Checked = false;
	lin++;
	}
	else if (Form2->Memo1->Lines->Strings[lin] != "false" && Form2->Memo1->Lines->Strings[lin] == "true") {
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "true") {
	Form3->CheckBox2->Checked = true;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "false") {
	Form3->CheckBox2->Checked = false;
	lin++;
	}
	else if (Form2->Memo1->Lines->Strings[lin] != "false" && Form2->Memo1->Lines->Strings[lin] == "true") {
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "true") {
	Form3->CheckBox3->Checked = true;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "false") {
	Form3->CheckBox3->Checked = false;
	lin++;
	}
	else if (Form2->Memo1->Lines->Strings[lin] != "false" && Form2->Memo1->Lines->Strings[lin] == "true") {
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "1") {
	Form3->RadioButton1->Checked = true;
	Form3->RadioButton2->Checked = false;
	Form3->RadioButton3->Checked = false;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "2") {
	Form3->RadioButton2->Checked = true;
	Form3->RadioButton1->Checked = false;
	Form3->RadioButton3->Checked = false;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "3") {
	Form3->RadioButton3->Checked = true;
	Form3->RadioButton1->Checked = false;
	Form3->RadioButton2->Checked = false;
	lin++;
	}
	else if (Form2->Memo1->Lines->Strings[lin] == "1" && Form2->Memo1->Lines->Strings[lin] == "2" && Form2->Memo1->Lines->Strings[lin] == "3") {
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "1") {
	Form3->RadioButton4->Checked = true;
	Form3->RadioButton5->Checked = false;
	Form3->RadioButton6->Checked = false;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "2") {
	Form3->RadioButton5->Checked = true;
	Form3->RadioButton4->Checked = false;
	Form3->RadioButton6->Checked = false;
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "3") {
	Form3->RadioButton6->Checked = true;
	Form3->RadioButton4->Checked = false;
	Form3->RadioButton5->Checked = false;
	lin++;
	}
	else if (Form2->Memo1->Lines->Strings[lin] == "1" && Form2->Memo1->Lines->Strings[lin] == "2" && Form2->Memo1->Lines->Strings[lin] == "3") {
	lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "true") {
	Form3->CheckBox4->Checked = true;
	lin++;
	}
	lin = 5;
return 0;
}
//---------------------------------------------------------------------------

