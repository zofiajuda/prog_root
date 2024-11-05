void macro3b(){
    
    const Int_t nbins = 100;
    TH1F* hGaussDist = new TH1F("hGaussDist", "hGaussDist", nbins, -10, 10);

    Int_t maxEvents = 500;
    Double_t random = 0;

    for(Int_t i=0; i<maxEvents; i++){
        random = gRandom->Gaus(0, 2);
        hGaussDist->Fill(random);
    }
    hGaussDist->Draw();
}