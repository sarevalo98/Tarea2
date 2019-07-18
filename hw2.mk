Parte1.png Parte2.png ENERGIA_SISTEMA.png MOMENTUM_ANGULAR.png VELOCIDADES.png ORBITAS.png: Fourier.py Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
	python Fourier.py
%.dat:a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    