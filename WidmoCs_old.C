
#include <iostream>

int dim(string name)
{
    // ###############################################3
    // get dimension of file
    ifstream file; //= ifstream("1.lst", ios_base::in);

    int col = 0;
    int j = 0;
    file.open(name, ios_base::in);
    // otwieranie i czytanie z pliku
    if (file.is_open())
    {
        string line;

        while (!file.eof())
        {
            getline(file, line);
            j++;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    return j;
}

void read_file(string name = "Cs-127.dat", double *dane)
{
    // ###############################################3
    // Czytanie plików i wpisywanie ich w tablice
    ifstream file; //= ifstream("1.lst", ios_base::in);

    int col = 0;
    int j = 0;
    file.open(name, ios_base::in);
    // otwieranie i czytanie z pliku
    if (file.is_open())
    {
        string line;

        while (!file.eof())
        {
            int row = 0;

            getline(file, line);
            stringstream ss(line);
            ss >> dane[j];
            j++;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

bool Is_Peak(double pik, double *dane, int i)
{
    bool is_peak = false;
    for (int j = 1; j < 30; j++)
    {
        if (pik > dane[i + j] || pik > dane[i - j])
        {
            is_peak = true;
        }
        else
        {
            is_peak = false;
        }
    }
    return is_peak;
}

void WidmoCs()
{
    // READ FILE
    int n = dim("Cs-137.dat");
    n = n - 1;
    double dane[n];
    ifstream file; //= ifstream("1.lst", ios_base::in);

    int col = 0;
    int j = 0;
    file.open("Cs-137.dat", ios_base::in);
    // otwieranie i czytanie z pliku
    if (file.is_open())
    {
        string line;

        while (!file.eof())
        {
            getline(file, line);
            stringstream ss(line);
            ss >> dane[j];
            j++;
        }
        file.close();
    }

    else
    {
        cout << "Unable to open file" << endl;
    }
    // Histogram
    int nbins = 1024;
    TH1F *hCes = new TH1F("hces", "Cs energy spectrum;kanal", n, 0, 1024);
    TFile *rootfile = new TFile("file.root", "RECREATE");

    // ####################
    // HISTOGRAM FILLING
    for (int i = 0; i < n; i++)
    {
        hCes->SetBinContent(i, dane[i]);     // Fill histogram
        hCes->SetBinError(i, sqrt(dane[i])); // set bin error
    }
    double nmax[4];
    double xmax[4];
    for (int j = 0; j < 3; j++)
    {
        for (int i = 40; i < n; i++)
        {
            if (nmax[0] < dane[i])
            {
                double pik = dane[i];
                if (Is_Peak(pik, &dane[i], i))
                {
                    nmax[0] = dane[i];
                    xmax[0] = hCes->GetBinCenter(i);
                }
            }

            if (nmax[j] > dane[i] && dane[i] > nmax[j + 1])
            {
                double pik = dane[i];
                if (Is_Peak(pik, &dane[i], i))
                {
                    nmax[j + 1] = dane[i];
                    xmax[j + 1] = hCes->GetBinCenter(i);
                    cout << nmax[1] << endl;
                }
            }
        }
    }
    cout << "oto największa liczba zliczeń: " << nmax[0] << " oto jego środek: " << xmax[0] << endl;

    cout << "oto największa liczba zliczeń: " << nmax[1] << " oto jego środek: " << xmax[1] << endl;

    cout << "oto największa liczba zliczeń: " << nmax[2] << " oto jego środek: " << xmax[2] << endl;
    cout << "oto największa liczba zliczeń: " << nmax[3] << " oto jego środek: " << xmax[3] << endl;

    // ###################
    // HISTOGRAM DRAWING
    TCanvas *c1 = new TCanvas("k1", "k1", 0, 0, 1028, 1028);
    c1->cd();
    // gPad->SetLogy();
    hCes->SetLineWidth(3);
    hCes->SetLineColor(kBlack);
    hCes->GetXaxis()->SetRangeUser(0, 400);
    // hCes->SetLineStyle(2);
    hCes->Draw();
    hCes->Write();
    c1->Write();
    tr
        gStyle->SetOptStat(111111);
}