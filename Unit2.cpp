//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

int varredura (int);
int visualconf (int);
void define ();

//---------------------------------------------------------------------------
int c=1, a=0, lin = 5, linha = 3;
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
	else if (Form2->Memo1->Lines->Strings[lin] != "1" && Form2->Memo1->Lines->Strings[lin] != "2" && Form2->Memo1->Lines->Strings[lin] != "3") {
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
	else if (Form2->Memo1->Lines->Strings[lin] != "1" && Form2->Memo1->Lines->Strings[lin] != "2" && Form2->Memo1->Lines->Strings[lin] != "3") {
		lin++;
	}
	if (Form2->Memo1->Lines->Strings[lin] == "true") {
		Form3->CheckBox4->Checked = true;
		lin++;
	}
	define();
	lin = 5;
return 0;
}
//---------------------------------------------------------------------------
void define (){
	if ( Form3->CheckBox1->Checked==true && Form2->ProgressBar1->Visible == false ) {
		Form2->ProgressBar1->Visible=true;
		Form2->Label1->Visible=true;
			Form2->Height+=30;
			Form2->Button1->Top+=30;
	}
	else if ( Form3->CheckBox1->Checked==false && Form2->ProgressBar1->Visible == true ){
		Form2->ProgressBar1->Visible=false;
		Form2->Label1->Visible=false;
			Form2->Height-=30;
			Form2->Button1->Top-=30;
	}
	if (Form3->CheckBox2->Checked==true && Form2->Edit2->Visible == false && Form2->Label3->Visible == false ) {
		Form2->Edit2->Visible=true;
		Form2->Label3->Visible=true;
		Form2->Height+=34;
		Form2->Button1->Top+=34;
		Form2->Label2->Top+=34;
		Form2->Label1->Top+=34;
		Form2->Edit1->Top+=34;
		Form2->ProgressBar1->Top+=34;
	}
	else if ( Form3->CheckBox2->Checked == false && Form2->Edit2->Visible == true ){
		Form2->Edit2->Visible=false;
		Form2->Label3->Visible=false;
		Form2->Label2->Top-=34;
		Form2->Label1->Top-=34;
		Form2->Height-=34;
		Form2->Button1->Top-=34;
		Form2->Edit1->Top-=34;
		Form2->ProgressBar1->Top-=34;
	}
	if (Form3->CheckBox3->Checked == false && Application->MainFormOnTaskBar == false ) {
		Application->MainFormOnTaskBar = true;
	}
	else if (Form3->CheckBox3->Checked == true && Application->MainFormOnTaskBar == true ){
		Application->MainFormOnTaskBar = false;
	}
	if ( Form3->RadioButton1->Checked == true ) {
		Form2->BorderStyle=bsToolWindow;
	}
	if ( Form3->RadioButton2->Checked == true ) {
		Form2->BorderStyle=bsNone;
	}
	if ( Form3->RadioButton3->Checked == true ) {
		Form2->BorderStyle=bsSingle;
	}
	if (Form3->RadioButton4->Checked == true) {
//--Apenas um condicional para confirmar _ Just a confirmation conditional --
	}
	if (Form3->RadioButton5->Checked == true) {
		Form3->Memo1->Lines->LoadFromFile("..\\idiomas\\en.idioma");
		varredura(linha);
	}
	if (Form3->RadioButton6->Checked == true) {
		Form3->Memo1->Lines->LoadFromFile("..\\idiomas\\edit.idioma");
		varredura(linha);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer3Timer(TObject *Sender)
{
	if (FileExists("..\\config\\interface.conf")) {
		visualconf(lin);
	}
		Timer3->Enabled = false;
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
		Form1->Refresh();
		Form2->Refresh();
		Form3->Refresh();
		Form4->Refresh();
		Form5->Refresh();
		Form6->Refresh();
		ShowMessage("Sucesso!");
return 0;
}
//---------------------------------------------------------------------------
