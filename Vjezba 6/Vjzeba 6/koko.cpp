#include "koko.hpp"

void Brojac::dodavanje_zivotinje(Zivotinja& zivotinja) {
	brojac_noga += zivotinja.vrati_broj_nogu();
	sve_vrste.append(zivotinja.vrati_ime_vrste());
	sve_vrste.append(", ");
	std::cout << "Dodana Vrsta: " << zivotinja.vrati_ime_vrste() << std::endl;
}