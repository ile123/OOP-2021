#ifndef KOKO_HPP
#define KOKO_HPP
#include <iostream>
#include <string>
#include <vector>

class Zivotinja {
public:
	virtual int vrati_broj_nogu() = 0;
	virtual std::string vrati_ime_vrste() = 0;
};

class Kukac : public Zivotinja {
protected:
	std::string Vrsta;
	int broj_noga;
};

class Pauk : public Zivotinja {
protected:
	std::string Vrsta;
	int broj_noga;
};

class Ptica : public Zivotinja {
protected:
	std::string Vrsta;
	int broj_noga;
};

class Bubamara : public Kukac {
public:
	Bubamara(){
		Vrsta = "Bubamara";
		broj_noga = 6;
	}
	std::string vrati_ime_vrste() {
		return Vrsta;
	}
	int vrati_broj_nogu() {
		return broj_noga;
	}
};

class Mali_Aleksandar : public Ptica {
public:
	Mali_Aleksandar() {
		Vrsta = "Mali Aleksandar";
		broj_noga = 2;
	}
	std::string vrati_ime_vrste() {
		return Vrsta;
	}
	int vrati_broj_nogu() {
		return broj_noga;
	}
};

class Crna_Udovica : public Pauk {
public:
	Crna_Udovica() {
		Vrsta = "Crna Udovica";
		broj_noga = 8;
	}
	std::string vrati_ime_vrste() {
		return Vrsta;
	}
	int vrati_broj_nogu() {
		return broj_noga;
	}
};

class Brojac {
protected:
	int brojac_noga;
	std::string sve_vrste;
public:
	Brojac() {
		brojac_noga = 0;
	}
	~Brojac() {
		sve_vrste.clear();
	}
	void dodavanje_zivotinje(Zivotinja& zivotinja);
	void ispis_vrsta_i_broj_nogu() {
		std::cout << "Sve Vrste:" << std::endl;
		std::cout << sve_vrste << std::endl;
		std::cout << "Ukupan broj nogu: " << brojac_noga << std::endl;
	}
};

#endif // !KOKO_HPP
