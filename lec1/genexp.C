void genexp()
{
    const double lambda = 1.; 

    TH1F* hist = new TH1F("hist", "h", 100, 0, 5); 

    gBenchmark->Start("genexp");

    for(int i = 0; i < 1000000; ++i)
    {   
        double randx = gRandom->Uniform(0, 1); 
        double randy = -lambda * log(randx);

        hist->Fill(randy);
    }   

    gBenchmark->Show("genexp");
    hist->Draw();
}

