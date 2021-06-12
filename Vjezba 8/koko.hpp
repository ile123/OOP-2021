#ifndef KOKO_HPP
#define KOKO_HPP
#include <iostream>

class Money {
protected:
	int kune;
	int lipe;
public:
	Money() {
		kune = 0;
		lipe = 0;
	}
	Money(int k) {
		kune = k;
		lipe = 0;
	}
	Money(int k, int l) {
		kune = k;
		lipe = l;
	}
	Money operator+(const Money& money1);
	Money operator-(const Money& money1);
	Money operator-=(const Money& money1);
	Money operator+=(const Money& money1);
	friend std::ostream& operator<< (std::ostream& os, const Money& money1);
	operator double() { return  kune + lipe * 0.01; }
};

#endif // !KOKO_HPP
