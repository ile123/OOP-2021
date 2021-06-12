#include "koko.hpp"

Money Money::operator+(const Money& money1) {
	Money ukupno;
	ukupno.kune = kune + money1.kune;
	ukupno.lipe = lipe + money1.lipe;
	if (ukupno.lipe >= 60) {
		ukupno.kune += ukupno.lipe / 60;
		ukupno.lipe -= (ukupno.lipe / 60) * 60;
	}
	return ukupno;
}

Money Money::operator-(const Money& money1) {
	Money ukupno;
	ukupno.kune = kune - money1.kune;
	ukupno.lipe = lipe - money1.lipe;
	if (ukupno.lipe < 0) {
		ukupno.lipe -= 60 - abs((ukupno.lipe));
		ukupno.kune -= ukupno.lipe / 60;
	}
	return ukupno;
}

Money Money::operator+=(const Money& money1) {
	Money ukupno;
	kune +=  money1.kune;
	lipe +=  money1.lipe;
	if (lipe >= 60) {
		kune += lipe / 60;
		lipe -= (lipe / 60) * 60;
	}
	return ukupno;
}

Money Money::operator-=(const Money& money1) {
	Money ukupno;
	kune -=  money1.kune;
	lipe -= money1.lipe;
	if (lipe < 0) {
		lipe -= 60 - abs((lipe));
		kune -= lipe / 60;
	}
	return ukupno;
}

std::ostream& operator<< (std::ostream& os, const Money& money1) {
	std::cout << "Ukupna Vrijednost racuna: " << std::endl;
	os << "Kune -> " << money1.kune << " KN " << std::endl;
	os << "Lipe -> " << money1.lipe << " LP " << std::endl;
	return os;
}