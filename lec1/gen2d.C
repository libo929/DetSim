void gen2d()
{
	TH2F* hist = new TH2F("hist", "h", 100, -1, 1, 100, -1, 1);

	for(int i = 0; i < 1000000; ++i)
	{
		double x = gRandom->Uniform(0, 1) * 2 - 1;
		double y = gRandom->Uniform(0, 1) * 2 - 1;

		hist->Fill(x, y);
	}

	hist->Draw("colz");
}
