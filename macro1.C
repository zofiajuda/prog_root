void macro1()
{
  TH1F *h = new TH1F("hGauss", "hGauss", 100, -500, 500);

  for (Int_t i = 0; i < 10000; i++)
  {
    Double_t random = gRandom->Gaus(0, 100);
    h->Fill(random);
  }
  gStyle->SetOptStat(1111111);
  //  h->SetStats(kFALSE);
  h->Draw();
}