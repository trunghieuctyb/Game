#pragma once
#include <iostream>
using namespace std;
enum viTri {STOP = 0, trai = 1, tLen = 2, tXuong = 3, phai = 4, pLen = 5, pXuong = 6};
class Ball{
private:
    int x, y; // toa do cua qua bong
    int x0, y0; // toa do ban dau
    viTri huong; // huong di chuyen
public:
    Ball(int x, int y) : x0(x), y0(y){
        this -> x = x0;
        this -> y = y0;
        huong = STOP;
    }
    void reset(){
        x = x0;
        y = y0;
        huong = STOP;
    }
    void doiViTri(viTri d){  // xac dinh huong di cua Ball
        huong = d;
    }
    void randomHuong(){   
        huong = (viTri)((rand() % 6) + 1); //  so du khi chia 6 ->{0 - 5} => +1 đe ra enum viTri
    }
    inline  int getX(){return x;}
    inline  int getY(){return y;}
    inline  viTri getHuong(){return huong;}
    void diChuyen(){
        switch(huong){
            case STOP:
                break;
            case trai:
                x--;
                break;
            case tLen:
                x--; y--;
                break;
            case tXuong:
                x--; y++;
                break;
            case phai:
                x++;
                break;
            case pLen:
                x++; y--;
                break;
            case pXuong:
                x++; y++;
                break;
            default:
                break;
        }
    }
};