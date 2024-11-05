void macro3a(){

    const Int_t nbins = 1000;
    TH1F* hSpectrum = new TH1F("hSpectrum", "hSpectrum", nbins, 0, nbins);

    Double_t counts[nbins];
    Double_t errors[nbins];


    for(Int_t i = 0; i < nbins; i++){
            counts[i] = sin(i * 0.01) * 100 + 200;  
            errors[i] = sqrt(counts[i]);         
    }
       
    for(Int_t i=1; i<=1000; i++){
        hSpectrum->SetBinContent(i, counts[i]);
        hSpectrum->SetBinError(i, errors[i]);
    }
    hSpectrum->Draw();
}