#! /bin/sh

echo "Standard compilation (64-bit?)"
g++ -std=c++98 tmp.cpp -o tmp
./tmp 
 
echo ""
echo ""
echo "32-bit"
g++ -m32 -std=c++98 tmp.cpp -o tmp
./tmp 
