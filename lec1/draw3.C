void draw3()
{
	TH1F* histg  = new TH1F("histg" , "", 100, 0, 20);
	TH1F* histbw = new TH1F("histbw", "", 100, 0, 20);
	TH1F* histl  = new TH1F("histl" , "", 100, 0, 20);

	for(int i = 0; i < 100000; ++i)
	{
		double rg  = gRandom->Gaus(10, 1);
		double rbw = gRandom->BreitWigner(10, 1);
		double rl  = gRandom->Landau(10, 1);

		histg->Fill(rg);
		histbw->Fill(rbw);
		histl->Fill(rl);
	}

	histbw->SetStats(kFALSE);
	histbw->Draw("");

	histg->SetLineColor(kRed);
	histg->Draw("same");

	histl->SetLineColor(kGreen);
	histl->Draw("same");

	TLegend* legend = new TLegend(0.15,0.6,0.4,0.8);
	legend->AddEntry(histg,  "Gaus","l");
	legend->AddEntry(histbw, "BreitWigner","l");
	legend->AddEntry(histl,  "Landau","l");
	legend->Draw();
}
