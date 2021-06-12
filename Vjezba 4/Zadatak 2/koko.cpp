#include "koko.h"

void Board::draw_line(const Point& tocka1, const Point& tocka2, char znak) {
    int x1 = (int)tocka1.x + 0.5;
    int y1 = (int)tocka1.y + 0.5;
    int x2 = (int)tocka2.x + 0.5;
    int y2= (int)tocka2.y + 0.5;
    while ((x1 != x2) || (y1 != y2)) {
        if ((x1 < x2) && (y1 < y2)) {
            matrica[x1][y1] = znak;
            x1++;
            y1++;
        }
        else if (x1 < x2) {
            matrica[x1][y1] = znak;
            x1++;
        }
        else if(y1<y2){
            matrica[x1][y1] = znak;
            y1++;
        }
    }
}

void Board::draw_up_line(const Point& tocka, char znak) {
    int x = (int)tocka.x + 0.5;
    int y = (int)tocka.y + 0.5;
    for (int i = 1;i <= y;i++) {
        matrica[i][y] = znak;
    }
}

void Board::draw_char(const Point& tocka, char znak) {
    int x = (int)tocka.x + 0.5;
    int y = (int)tocka.y + 0.5;
    matrica[x][y] = znak;
}

void Board::display() {
    for (int i = 0;i < broj_redova;i++) {
        for (int j = 0;j < broj_stupova;j++) {
            std::cout << matrica[i][j];
        }
        std::cout << std::endl;
    }
}
