#include "koko.hpp"

void Counter::dodaj(Vehicle* vozilo) {
	std::cout << "Vozilo: " << vozilo->vrati_vrstu() << std::endl;
	ukupan_broj_putnika += vozilo->broj_putnika();
}

std::string Seaplane::vrati_vrstu() {
	std::string temp = (Aircraft::vrati_vrstu() + "-").append(Watercraft::vrati_vrstu());
	return temp;
}