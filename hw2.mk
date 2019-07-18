ENERGIA_SISTEMA.png MOMENTUM_ANGULAR.png VELOCIDADES.png ORBITAS.png: Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
%.dat:a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
Parte1.png:Fourier.py
    python Fourier.py
    