#ifndef KOKO_H
#define KOKO_H

#include <iostream>

typedef struct Point {
    double x;
    double y;
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
}Point;

class Board {
    char** matrica;
    int broj_redova;
    int broj_stupova;
public:
    void draw_char(const Point& tocka, char znak);
    void display();
    void draw_up_line(const Point& point, char znak);
    void draw_line(const Point& point1, const Point& point2, char znak);
    Board() {
        std::cout << "Default Konstruktor Pozvan" << std::endl;
    }
    Board(int red, int stupac) {
        broj_redova = red;
        broj_stupova = stupac;
        matrica = new char* [red];
        for (int i = 0;i < red;i++) {
            matrica[i] = new char[stupac];
        }
        for (int i = 0;i < stupac;i++) {
            matrica[0][i] = '@';
        }
        for (int i = 0;i < red;i++) {
            matrica[i][0] = '@';
        }
        for (int i = 0;i < red;i++) {
            matrica[i][stupac - 1] = '@';
        }
        for (int i = 0;i < stupac;i++) {
            matrica[red - 1][i] = '@';
        }
    }
    Board(const Board& board) {
        *matrica = new char[**board.matrica];
        broj_redova = board.broj_redova;
        broj_stupova = board.broj_stupova;
    }
    ~Board() {
        for (int i = 0;i < broj_redova;i++) {
            delete[] matrica[i];
        }
        delete[] matrica;
    }



};



#endif