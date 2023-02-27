all: median_eigen mode_eigen

median_eigen: median_eigen.ccp utils.o
    g++ -I/usr/include/eigen3 -o median_eigen median_eigen.ccp utils.o
    
mode_eigen: mode_eigen.ccp utils.o
    g++ -I/usr/include/eigen3 -o mode_eigen mode_eigen.ccp utils.o

util.o: utils.cc utils.hpp 
    g++ -c utils.cc    
