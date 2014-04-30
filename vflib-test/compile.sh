#! /bin/sh
g++ -c -I/home/stan/Fortress/Dev/external/vflib-2.0.6/include test.cpp 
g++ -o test test.o -L/home/stan/Fortress/Dev/external/vflib-2.0.6/lib -lstdc++ -lm -lvf
