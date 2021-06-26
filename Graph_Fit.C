#include"TCanvas.h"
#include"TGraphErrors.h"
#include"TF1.h"
#include"TMath.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Grafico (const char* nome_file , int numero_dati) //numero_datièilnumerodicolonneperriga-1ovveroiltitolo//
{
TF1 *f1= new TF1("f1","pol1",0,15);

Double_t * x=new Double_t [numero_dati];
Double_t * y=new Double_t [numero_dati];
Double_t * ex=new Double_t [numero_dati];
Double_t * ey=new Double_t [numero_dati];

char titolo_asse_x[20];
char titolo_asse_y[20];
char errore_asse_x[20];
char errore_asse_y[20];

ifstream file(nome_file); 
if (!file){cout<<"file non aperto"<< endl;}
//PRENDE LE STRINGHE//
getline (file,titolo_asse_x,'\t');
getline (file,titolo_asse_y,'\t');
getline (file,errore_asse_x,'\t');
getline (file,errore_asse_y,'\n');

// prendo i dati//
for(int i=0; numero_dati;++i)
{
 file >> x[i] >>y[i] >> ex[i] >> ey[i];
 }
//CREO IL GRAFICO
TGraphErrors* Grafico= new TGraphErrors(numero_dati,x,y,ex,ey);
//FIT
Grafico->Fit("f1","Q");
//CREA CANVAS//
TCanvas* cz =new TCanvas("cz","cz",200,10,700,500);
Grafico->Draw("AP"); //STAMPA GRAFICO//
 







}
