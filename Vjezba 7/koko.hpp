#ifndef KOKO_HPP
#define KOKO_HPP
#include <iostream>
#include <string>
#include <vector>

class Vehicle {
public:
	virtual std::string vrati_vrstu() = 0;
	virtual unsigned int broj_putnika() = 0;
	virtual ~Vehicle() {};
};

class Watercraft : virtual public Vehicle{
public:
	std::string vrati_vrstu() {
		return "Watercraft";
	}
};

class Aircraft : virtual public Vehicle{
public:
	std::string vrati_vrstu() {
		return "Aircraft";
	}
};

class Seaplane : public Watercraft, public Aircraft {
protected:
	unsigned int trenutni_broj_ljudi;
public:
	std::string vrati_vrstu();
	Seaplane(unsigned int putnici) {
		trenutni_broj_ljudi = putnici;
	}
	unsigned int broj_putnika() {
		return trenutni_broj_ljudi;
	}
};

class Catamaran : public Watercraft {
protected:
	unsigned int trenutni_broj_ljudi;
public:
	Catamaran(unsigned int putnici) {
		trenutni_broj_ljudi = putnici;
	}
	unsigned int broj_putnika() {
		return trenutni_broj_ljudi;
	}
};

class Ferry : public Watercraft {
protected:
	unsigned int trenutni_broj_ljudi;
public:
	Ferry(unsigned int putnici,unsigned int bicikle,unsigned int auta) {
		trenutni_broj_ljudi = putnici+bicikle+(auta*5);
	}
	unsigned int broj_putnika() {
		return trenutni_broj_ljudi;
	}
};

class Counter{
protected:
	unsigned int ukupan_broj_putnika;
public:
	void dodaj(Vehicle* vozilo);
	Counter() {
		ukupan_broj_putnika = 0;
	}
	void broj_putnika(){
		std::cout << "Ukupan broj putnika: " << ukupan_broj_putnika << std::endl;
	}
};

#endif // !KOKO_HPP