FFtIm.pdf ImProceso.pdf ImHybrid.pdf Ener_met_dt.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf: Fourier.py Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
	python Fourier.py
%.dat:a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    