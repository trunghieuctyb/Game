#pragma once
#include <conio.h>
#include <time.h>
#include "Ball.cpp"
#include "Paddle.cpp"
class Game{
    private:
        int width, height; // kich thuoc game 
        int diem1, diem2; // diem nguoi choi trai va phai 
        char nLen1, nXuong1, nLen2, nXuong2; // 2 thanh 
        bool thoat;
        Ball * ball;
        Paddle *nguoiChoi1;
        Paddle *nguoiChoi2;        
    public:
        Game(int w, int h){
            srand(time(NULL));
            thoat = false;
            nLen1 = 'w'; nLen2 = 'i';
            nXuong1 = 's'; nXuong2 = 'k';   
            diem1 = diem2 = 0;
            width = w; height = h;
            ball = new Ball(w / 2, h / 2);
            nguoiChoi1 = new Paddle(1, h / 2 - 3);
            nguoiChoi2 = new Paddle(w - 2, h / 2 - 3);
        }
        ~Game()
    {
        delete ball, nguoiChoi1, nguoiChoi2;
    }
    void tangDiem(Paddle *nguoiChoi){
        if (nguoiChoi == nguoiChoi1)
            diem1++;
        if(nguoiChoi == nguoiChoi2)
            diem2++;
        ball -> reset();
        nguoiChoi1 -> reset();
        nguoiChoi2 -> reset();
    }
    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;
 
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int ballx = ball->getX();
                int bally = ball->getY();
                int nguoiChoi1x = nguoiChoi1->getX();
                int nguoiChoi2x = nguoiChoi2->getX();
                int nguoiChoi1y = nguoiChoi1->getY();
                int nguoiChoi2y = nguoiChoi2->getY();
 
                if (j == 0)
                    cout << "\xB2";
 
                if (ballx == j && bally == i)
                    cout << "O"; //ball
                else if (nguoiChoi1x == j && nguoiChoi1y == i)
                    cout << "\xDB"; //nguoiChoi1
                else if (nguoiChoi2x == j && nguoiChoi2y == i)
                    cout << "\xDB"; //nguoiChoi2
 
                else if (nguoiChoi1x == j && nguoiChoi1y + 1 == i)
                    cout << "\xDB"; //nguoiChoi1
                else if (nguoiChoi1x == j && nguoiChoi1y + 2 == i)
                    cout << "\xDB"; //nguoiChoi1
                else if (nguoiChoi1x == j && nguoiChoi1y + 3 == i)
                    cout << "\xDB"; //nguoiChoi1
 
                else if (nguoiChoi2x == j && nguoiChoi2y + 1 == i)
                    cout << "\xDB"; //nguoiChoi1
                else if (nguoiChoi2x == j && nguoiChoi2y + 2 == i)
                    cout << "\xDB"; //nguoiChoi1
                else if (nguoiChoi2x == j && nguoiChoi2y + 3 == i)
                    cout << "\xDB"; //nguoiChoi1
                else
                    cout << " ";
 
                if (j == width - 1)
                    cout << "\xB2";
            }
            cout << endl;
        }
 
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;
 
        cout << "Diem nguoi choi 1: " << diem1 << endl;
        cout << "Diem nguoi choi 2: " << diem2 << endl;
    }
    void Input(){
        ball -> diChuyen();
        
        int ballx = ball ->getX();
        int bally = ball ->getY();
        int nguoiChoi1x = nguoiChoi1->getX();
        int nguoiChoi2x = nguoiChoi2->getX();
        int nguoiChoi1y = nguoiChoi1->getY();
        int nguoiChoi2y = nguoiChoi2->getY();
        
        if (_kbhit())
        {
            char current = _getch();
            if (current == nLen1)
                if (nguoiChoi1y > 0)
                    nguoiChoi1->diLen();
            if (current == nLen2)
                if (nguoiChoi2y > 0)
                    nguoiChoi2->diLen();
            if (current == nXuong1)
                if (nguoiChoi1y + 4 < height)
                    nguoiChoi1->diXuong();
            if (current == nXuong2)
                if (nguoiChoi2y + 4 < height)
                    nguoiChoi2->diXuong();
 
            if (ball->getHuong() == STOP)
                ball->randomHuong();
 
            if (current == 'q')
                thoat = true;
        }

    }
    void Logic()
    {
        int ballx = ball->getX();
        int bally = ball->getY();
        int nguoiChoi1x = nguoiChoi1->getX();
        int nguoiChoi2x = nguoiChoi2->getX();
        int nguoiChoi1y = nguoiChoi1->getY();
        int nguoiChoi2y = nguoiChoi2->getY();
 
        // paddle trai - nguoiChoi1
        for (int i = 0; i < 4; i++)
            if (ballx == nguoiChoi1x + 1)
                if (bally == nguoiChoi1y + i)
                    ball->doiViTri((viTri)((rand() % 3) + 4));
 
        // paddle phai - nguoiChoi2
        for (int i = 0; i < 4; i++)
            if (ballx == nguoiChoi2x - 1)
                if (bally == nguoiChoi2y + i)
                    ball->doiViTri((viTri)((rand() % 3) + 1));
 
        // tuong bao duoi
        if (bally == height - 1)
            ball->doiViTri(ball->getHuong() == pXuong ? pLen : tLen);
        // tuong bao tren
        if (bally == 0)
            ball->doiViTri(ball->getHuong() == pLen ? pXuong : tXuong);
        // tuong bao ben phai
        if (ballx == width - 1)
            tangDiem(nguoiChoi1);
        // tuong bao ben trai
        if (ballx == 0)
            tangDiem(nguoiChoi2);
    }
    void Run(){
        while (!thoat)
        {
            Draw();
            Input();
            Logic();
        }
    }
};  