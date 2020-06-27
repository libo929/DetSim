bool shootOneParticle()
{
	const double e0 = 10.;               // particle energy
	const double eMin = 0.1;             // stopping energy
	const double meanLossRatio = 0.10;    
	const double lossRatioWidth = 0.01;   
	const double maxStepLength = 10.;    
	const double maxRadius = 50.;        

	const unsigned int maxStep = 100000;

	////////////////////////////

	double particleEnergy = e0;
	TVector3 momentumDirection(0., 0., 1.);
	TVector3 position(0., 0., 0.);

	bool isOutside = false;
	bool isStopped = false;

	for(unsigned int i = 0; i < maxStep; ++i)
	{
		//position.Print();

		// new energy
		double energyLossRatio = gRandom->Gaus(meanLossRatio, lossRatioWidth);
		if(energyLossRatio < 0.) 
		{
			std::cout << " energyLossRatio < 0, next loop ... " << std::endl;
			continue;
		}

		double energyLoss = energyLossRatio * particleEnergy;
		particleEnergy -= energyLoss;

		// new position
		double stepLength = gRandom->Uniform(0., maxStepLength);
		TVector3 dp = momentumDirection * stepLength;        // delta pos 
		position += dp;

		// new momentum direction
		double pX = gRandom->Uniform(-1, 1);
		double pY = gRandom->Uniform(-1, 1);
		double pZ = gRandom->Uniform(-1, 1);

		TVector3 newDir = TVector3(pX, pY, pZ);
		momentumDirection = newDir.Unit();

		// check energy
		if(particleEnergy < eMin) isStopped = true;

		// check position
		if(position.Mag() > maxRadius) isOutside = true;

		if(isStopped || isOutside) break;
	}

	//if(isOutside == true) std::cout << "This particle is finally outside the sphere." << std::endl;

	return isOutside;
}

void simpleTracking()
{
	unsigned int nOutside = 0;
	unsigned int nParticles = 2000000;

	gBenchmark->Start("simpleTracking");

	for(unsigned int i = 0; i < nParticles; ++i)
	{
		if(true == shootOneParticle()) ++nOutside;
	}

	std::cout << "The number of paricles: " << nParticles << std::endl;
	std::cout << "The number of paricles outside the sphere: " << nOutside << std::endl;
	std::cout << "The particle leakage: " << 1. * nOutside / nParticles  << std::endl;

	gBenchmark->Show("simpleTracking");
}
