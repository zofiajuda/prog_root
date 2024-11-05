#include <iostream>
#include <fstream>
using namespace std;

Bool_t DrawHistogram(void){
    TH1F *hGauss = new TH1F("gauss", "gauss", 50, -10, 10);
    hGauss->FillRandom("gaus", 5000);

    hGauss->SetLineColor(kGreen+3);
    hGauss->SetLineWidth(2);
    hGauss->SetFillColor(kGreen-6);

    hGauss->GetXaxis()->SetTitle("x values");
    hGauss->GetYaxis()->SetTitle("y values");
    hGauss->SetTitle("Gaussian distribution");

    TCanvas *can = new TCanvas("can", "can", 600, 600);
    can->cd();
    hGauss->Draw();

    Double_t binCont = hGauss->GetBinContent(25);
    Double_t binCent = hGauss->GetBinCenter(8);
    Int_t binNo = hGauss->FindBin(3.75);
    Double_t binWidth = hGauss->GetBinWidth(1);

    cout << "Content of bin number 25 = " << binCont << endl;
    cout << "Center of bin number 8 = " << binCent << endl;
    cout << "Value 3.75 belongs to the bin number " << binNo << endl;
    cout << "Width of the bin number 1 = " << binWidth << endl;

    return kTRUE;
}

void macro2()
{
    DrawHistogram();
}