void genCircle()
{
	TH2F* hist = new TH2F("hist", "h", 100, -1, 1, 100, -1, 1);

	gBenchmark->Start("genCircle");

	unsigned int n = 0;

	for(int i = 0; n < 1000000; ++i)
	{
		double x = gRandom->Uniform(-1, 1);
		double y = gRandom->Uniform(-1, 1);

		if(x*x + y*y <= 1.) 
		{
			hist->Fill(x, y);
			++n;
		}
	}

	gBenchmark->Show("genCircle");

	hist->Draw("colz");
}
