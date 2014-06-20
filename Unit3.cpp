//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"

int varredura (int);
int conf (int);

int h=0, m=0, s=0, c=0, linha=3, linhas=5;
float idioma;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	h = StrToInt (MaskEdit1->EditText);
	m = StrToInt (MaskEdit2->EditText);
	s = StrToInt (MaskEdit3->EditText);
	c =(h*3600)+(m*60)+s;
	if ( CheckBox1->Checked==true && Form2->ProgressBar1->Visible == false ) {
		Form2->ProgressBar1->Visible=true;
		Form2->Label1->Visible=true;
			Form2->Height+=30;
			Form2->Button1->Top+=30;
	}
	else if ( CheckBox1->Checked==false && Form2->ProgressBar1->Visible == true ){
		Form2->ProgressBar1->Visible=false;
		Form2->Label1->Visible=false;
			Form2->Height-=30;
			Form2->Button1->Top-=30;
	}
	if (CheckBox2->Checked==true && Form2->Edit2->Visible == false && Form2->Label3->Visible == false ) {
		Form2->Edit2->Visible=true;
		Form2->Label3->Visible=true;
		Form2->Height+=34;
		Form2->Button1->Top+=34;
		Form2->Label2->Top+=34;
		Form2->Label1->Top+=34;
		Form2->Edit1->Top+=34;
		Form2->ProgressBar1->Top+=34;
	}
	else if ( CheckBox2->Checked == false && Form2->Edit2->Visible == true ){
		Form2->Edit2->Visible=false;
		Form2->Label3->Visible=false;
		Form2->Label2->Top-=34;
		Form2->Label1->Top-=34;
		Form2->Height-=34;
		Form2->Button1->Top-=34;
		Form2->Edit1->Top-=34;
		Form2->ProgressBar1->Top-=34;
	}
	if (CheckBox3->Checked==true && Application->MainFormOnTaskBar == false ) {
		Application->MainFormOnTaskBar=true;
	}
	else {
		Application->MainFormOnTaskBar=false;
	}
	if ( RadioButton1->Checked == true ) {
		Form2->BorderStyle=bsToolWindow;
	}
	if ( RadioButton2->Checked == true ) {
		Form2->BorderStyle=bsNone;
	}
	if ( RadioButton3->Checked == true ) {
		Form2->BorderStyle=bsSingle;
	}
	if (RadioButton4->Checked == true && idioma != 2.2) {
		idioma = 2.1;
		Memo1->Lines->LoadFromFile("..\\idiomas\\pt.idioma");
		varredura(linha);
		ShowMessage("Para completar a atualiza��o de idioma, por favor, reinicie o programa para prevenir erros de tradu��o!");
	}
	if (RadioButton5->Checked == true && idioma != 2.2) {
		idioma = 2.2;
		Memo1->Lines->LoadFromFile("..\\idiomas\\en.idioma");
		varredura(linha);
	}
	if (RadioButton6->Checked == true && idioma != 2.3) {
		idioma = 2.3;
		Memo1->Lines->LoadFromFile("..\\idiomas\\edit.idioma");
		varredura(linha);
	}
	if (CheckBox4->Checked == true) {
		conf(linhas);
	}
		Form2->Edit2->Text = IntToStr (c);
		Form2->Edit1->Text = IntToStr (c);
		Form2->ProgressBar1->Max = c;
		Form3->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
	if (Button2->Caption == "Sobre n�s") {
		idioma = 2.1;
	}
	if (Button2->Caption == "About us") {
		idioma = 2.2;
	}
	else {
        idioma = 2.3;
	}
	if (FileExists("..\\config\\interface.conf")) {
		Form3->Memo2->Lines->LoadFromFile("..\\config\\interface.conf");
	}
}
//---------------------------------------------------------------------------
int varredura (int linha){
		Form2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form2->Button1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form2->Button2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form2->Button3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form2->Label1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form2->Label2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form2->Label3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form1->Label1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form1->Label2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form1->Label6->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form1->Label7->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form1->Label8->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form4->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form4->Memo1->Lines->Strings[0] = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form5->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form5->Label1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form5->Label2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form5->Button1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form5->Button2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->GroupBox1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Button3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->GroupBox2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Label3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Label4->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->CheckBox1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->CheckBox2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->CheckBox3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->RadioButton1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->RadioButton2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->RadioButton3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->GroupBox3->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->RadioButton4->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->RadioButton5->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Button2->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Button1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->RadioButton6->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form3->Button4->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form6->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form6->Label1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form6->Arquivo1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form6->Salvar1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		Form6->Fechar1->Caption = Form3->Memo1->Lines->Strings[linha];
		linha++;
		linha = 3;
return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	Form6->Memo1->Lines->LoadFromFile("..\\idiomas\\edit.idioma");
	Form6->Show();
}
//---------------------------------------------------------------------------
int conf (int linhas){
	if (Form3->CheckBox1->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "true";
		linhas++;
	}
	if (Form3->CheckBox1->Checked == false) {
		Form3->Memo2->Lines->Strings[linhas] = "false";
		linhas++;
	}
	if (Form3->CheckBox2->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "true";
		linhas++;
	}
	if (Form3->CheckBox2->Checked == false) {
		Form3->Memo2->Lines->Strings[linhas] = "false";
		linhas++;
	}
	if (Form3->CheckBox3->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "true";
		linhas++;
	}
	if (Form3->CheckBox3->Checked == false) {
		Form3->Memo2->Lines->Strings[linhas] = "false";
		linhas++;
	}
	if (Form3->RadioButton1->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "1";
		linhas++;
	}
	if (Form3->RadioButton2->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "2";
		linhas++;
	}
	if (Form3->RadioButton3->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "3";
		linhas++;
	}
	if (Form3->RadioButton4->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "1";
		linhas++;
	}
	if (Form3->RadioButton5->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "2";
		linhas++;
	}
	if (Form3->RadioButton6->Checked == true) {
		Form3->Memo2->Lines->Strings[linhas] = "3";
		linhas++;
	}
	linhas = 5;
return 0;
}
//---------------------------------------------------------------------------
