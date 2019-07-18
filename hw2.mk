ORBITAS.png: Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
VELOCIDADES.png: Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
MOMENTUM_ANGULAR.png: Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
ENERGIA_SISTEMA.png: Plots_hw2.py Euler.dat LeapFrog.dat RungeKutta.dat Euler1.dat LeapFrog1.dat RungeKutta1.dat Euler2.dat LeapFrog2.dat RungeKutta2.dat
	python Plots_hw2.py
%.dat:a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    