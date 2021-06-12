#include "koko.hpp"

int main() {
	Money juha(11, 30), becki(15, 50), salata(10), pivo(15), babic(16, 40);
	Money racun = juha + becki + salata + pivo;
	racun -= pivo;
	racun += babic;
	std::cout << racun << std::endl;
	double koko =(double) racun.operator double();
	std::cout << "Double vrijednost: " << koko << std::endl;
}