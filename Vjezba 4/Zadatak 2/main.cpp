#include "koko.h"

int main() {
	Point tocka1(12.4,5.2),tocka2(3.1,2.1),tocka3(4.5,5.1),tocka4(7.5,15.5),tocka5(16.1,12.5),tocka6(16.2,18.1);
	Board tabela(20, 20);
	tabela.draw_char(tocka1, '$');
	tabela.draw_up_line(tocka2, '&');
	tabela.draw_line(tocka3, tocka4, '!');
	tabela.draw_line(tocka5, tocka6,'?');
	tabela.display();
}