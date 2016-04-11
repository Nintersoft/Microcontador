//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"

int salvar (int);
void conferesom (String, bool);

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
	bool conf;

	if (Edit1->Text != "") {
		conferesom(Edit1->Text , conf);
		Form2->Label5->Caption = Edit1->Text;
		Form2->Label5->Hint = Edit1->Text;
	}

	if ( CheckBox1->Checked==true && Form2->ProgressBar1->Visible == false ) {
		Form2->ProgressBar1->Visible=true;
		Form2->Label1->Visible=true;
			Form2->Height+=30;
			Form2->Button1->Top+=30;
			Form2->Button2->Top+=30;
			Form2->Button3->Top+=30;
	}
	else if ( CheckBox1->Checked==false && Form2->ProgressBar1->Visible == true ){
		Form2->ProgressBar1->Visible=false;
		Form2->Label1->Visible=false;
		Form2->Height-=30;
		Form2->Button1->Top-=30;
		Form2->Button2->Top-=30;
		Form2->Button3->Top-=30;
	}
	if (CheckBox2->Checked==true && Form2->Edit2->Visible == false && Form2->Label3->Visible == false ) {
		Form2->Edit2->Visible=true;
		Form2->Label3->Visible=true;
		Form2->Height+=34;
		Form2->Button1->Top+=34;
		Form2->Button2->Top+=34;
		Form2->Button3->Top+=34;
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
		Form2->Button2->Top-=34;
		Form2->Button3->Top-=34;
		Form2->Edit1->Top-=34;
		Form2->ProgressBar1->Top-=34;
	}
/*	if (CheckBox3->Checked==true && Application->MainFormOnTaskBar == false ) {
		Application->MainFormOnTaskBar=true;
	}
	else if (Application->MainFormOnTaskBar == true){
		Application->MainFormOnTaskBar=false;
	}
*/
	if ( RadioButton1->Checked == true && Form2->BorderStyle != bsToolWindow) {
		Form2->BorderStyle=bsToolWindow;
	}
	else if ( RadioButton2->Checked == true && Form2->BorderStyle != bsNone) {
		Form2->BorderStyle=bsNone;
	}
	else if ( RadioButton3->Checked == true && Form2->BorderStyle != bsSingle) {
		Form2->BorderStyle=bsSingle;
	}
	if (RadioButton4->Checked == true && idioma != 2) {
		idioma = 2;
		Memo1->Lines->LoadFromFile("..\\idiomas\\pt.idioma");
		Form2->varredura(linha);
		ShowMessage("Para completar a atualização de idioma, por favor, reinicie o programa para prevenir erros de tradução!");
	}
	else if (RadioButton5->Checked == true && idioma != 3) {
		idioma = 3;
		Memo1->Lines->LoadFromFile("..\\idiomas\\en.idioma");
		Form2->varredura(linha);
	}
	else if (RadioButton6->Checked == true && idioma != 4) {
		idioma = 4;
		Memo1->Lines->LoadFromFile("..\\idiomas\\edit.idioma");
		Form2->varredura(linha);
	}
	if (CheckBox4->Checked == true) {
		salvar (linhas);
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
	if (Button2->Caption == "Sobre nós") {
		idioma = 2;
	}
	else if (Button2->Caption == "About us") {
		idioma = 3;
	}
	else {
		idioma = 4;
	}
	if (FileExists("..\\config\\interface.conf")) {
		Form3->Memo2->Lines->LoadFromFile("..\\config\\interface.conf");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	Form6->Memo1->Lines->LoadFromFile("..\\idiomas\\edit.idioma");
	Form6->Show();
}
//---------------------------------------------------------------------------
int salvar (int lin){

	if (Form3->CheckBox1->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "true";
		lin++;
	}
	if (Form3->CheckBox1->Checked == false) {
		Form3->Memo2->Lines->Strings[lin] = "false";
		lin++;
	}
	if (Form3->CheckBox2->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "true";
		lin++;
	}
	if (Form3->CheckBox2->Checked == false) {
		Form3->Memo2->Lines->Strings[lin] = "false";
		lin++;
	}
	if (Form3->CheckBox3->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "true";
		lin++;
	}
	if (Form3->CheckBox3->Checked == false) {
		Form3->Memo2->Lines->Strings[lin] = "false";
		lin++;
	}
	if (Form3->RadioButton1->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "1";
		lin++;
	}
	if (Form3->RadioButton2->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "2";
		lin++;
	}
	if (Form3->RadioButton3->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "3";
		lin++;
	}
	if (Form3->RadioButton4->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "1";
		lin++;
	}
	if (Form3->RadioButton5->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "2";
		lin++;
	}
	if (Form3->RadioButton6->Checked == true) {
		Form3->Memo2->Lines->Strings[lin] = "3";
		lin++;
	}
	if (Form3->Edit1->Text != "") {
		Form3->Memo2->Lines->Strings[lin] = Form3->Edit1->Text;
		lin++;
	}
	Form3->Memo2->Lines->SaveToFile("..\\config\\interface.conf");
	lin = 5;
	return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {
		Edit1->Text = OpenDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
void conferesom(String arquivo , bool k){

String extensao;
int i;
int a = arquivo.Length() - 3;

	for (i = a; i <= arquivo.Length(); i++) {
		extensao  = extensao + arquivo[i];
	}

	if (extensao != ".mp3" && extensao != ".wma") {
		throw Exception ("A música não está de acordo com os formatos suporados!");
	}
}
//---------------------------------------------------------------------------
