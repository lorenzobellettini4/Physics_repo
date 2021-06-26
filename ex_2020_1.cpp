#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit;


// inspired by https://root.cern/doc/master/rf101__basics_8C.html

int ex_2020_1()
{
  // S e t u p  a CRISTAL BALL   m o d e l
  // --------------------------------------
  // https://en.wikipedia.org/wiki/Crystal_Ball_function
 
  // Declare variables x,mean,sigma, alpha, n
  // with associated name, title, initial value and allowed range

RooRealVar x("x","x",-10.,10.);
RooRealVar mean("mean","mean",0.);
RooRealVar sigma("sigma","sigma",1.);
RooRealVar alpha("alpha","alpha",1.5);
RooRealVar n("n","n",1.5);




  // Build Crystal_Ball pdf in terms of x,mean, sigma, alpha, n

RooCBShape CB("CB","pdf Crystal Ball",x,mean,sigma,alpha,n);
  
  // Construct plot frame in 'x'

RooPlot* xframe= x.frame(Title("Crystal Ball pdf"));

  //my model is CB, so i write CB.plotOn

CB.plotOn(xframe);
xframe->Draw();
  
  // P l o t   m o d e l   a n d   c h a n g e   p a r a m e t e r   v a l u e s

  // ---------------------------------------------------------------------------
 
  // Plot Crystal_Ball in frame (i.e. in x)

//my model is CB, so i write CB.plotOn

CB.plotOn(xframe);
xframe->Draw();
  
  
  // Change the value of sigma to 3

sigma.setVal(0.3);

  
  // Plot Crystal_Ball in frame (i.e. in x) and draw frame on canvas

CB.plotOn(xframe); //recreate the frame with sigma=3
xframe->Draw(); //new draw
  
  // G e n e r a t e   e v e n t s
  // -----------------------------
 
  // Generate a dataset of 1000 events in x from Crystal_Ball

RooDataSet* data = CB.generate(x,1000); 
  
  // Make a second plot frame in x and draw both the
  // data and the pdf in the frame

RooPlot* x2frame= x.frame(Title("Crystal Ball pdf"));

data->plotOn(x2frame);
CB.plotOn(x2frame);
x2frame->Draw(); 

  // F i t   m o d e l   t o   d a t a
  // -----------------------------
 
  // Fit pdf to data

CB.fitTo(*data);
 
  // Print values of mean and sigma (that now reflect fitted values and errors)

mean.Print();
sigma.Print();

  // Draw all frames on a canvas

TCanvas* c1 = new TCanvas("c1", ("All Frames"), 600, 600, 1000, 1000);
xframe->Draw();

TCanvas* c2 = new TCanvas("c2", ("All Frames"), 600, 600, 1000, 1000);
x2frame->Draw();


  return 0;
}
