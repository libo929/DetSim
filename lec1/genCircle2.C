void genCircle2()
{
	//TH2F* hist = new TH2F("hist", "h", 100, -1, 1, 100, -1, 1);
	TH2F* hist = new TH2F("hist", "h", 100, 0, 1, 100, 0, 1);
	//TH2F* hist = new TH2F("hist", "h", 100, 0, 1, 100, 0, 2*TMath::Pi());

	gBenchmark->Start("genCircle2");

	for(int i = 0; i < 1000000; ++i)
	{
		double theta = gRandom->Uniform(0, 2*TMath::Pi());
		double rho = sqrt( gRandom->Uniform(0, 1) );
		//double rho = gRandom->Uniform(0, 1);

		double x = rho * cos(theta);
		double y = rho * sin(theta);

		hist->Fill(x, y);
		//hist->Fill(theta, rho);
	}

	gBenchmark->Show("genCircle2");

	//hist->Draw("colz");
	hist->Draw("colz pol");
}
