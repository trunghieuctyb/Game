#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
#pragma once
class Paddle{
    private:
        int x, y;
        int x0, y0;
    public:
        Paddle(int x, int y) : x0(x), y0(y), x(x), y(y) {
          ///
        }
        inline void reset() { x = x0; y = y0; }
        inline int getX() { return x; }
        inline int getY() { return y; }
        inline void diLen() { y--; }
        inline void diXuong() { y++; }
};