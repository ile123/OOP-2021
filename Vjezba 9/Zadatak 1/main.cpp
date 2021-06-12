#include "koko.hpp"

int main() {
	Niz<int> intniz(5);
	Niz<double> doubleniz(5);
	intniz.upis();
	intniz.sortiranje();
	intniz.ispis();
	doubleniz.upis();
	doubleniz.sortiranje();
	doubleniz.ispis();
}