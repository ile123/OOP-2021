#include <iostream>
#define velicina_niza(x) (sizeof(x)/sizeof(x[0]))
template<typename T>

#ifndef KOKO_HPP
#define KOKO_HPP

class Niz {
protected:
	T* niz;
	size_t n;
public:
	Niz(int n);
	~Niz();
	void sortiranje();
	void ispis();
	void upis();
};

template<typename T> Niz<T>::~Niz() { delete[]niz; }
template<typename T> Niz<T>::Niz(int broj) : niz(new T[broj]), n(broj) { }

template<typename T> void Niz<T>::sortiranje() {
	T temp;
	for (unsigned int i = 0;i < n - 1;i++) {
		for (unsigned int j = i + 1;j < n;j++) {
			if (niz[i] > niz[j]) {
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}
}

template<typename T> void Niz<T>::ispis() {
	std::cout << "--------------------------------------------" << std::endl;
	for (unsigned int i = 0;i < n;i++) {
		std::cout << niz[i] << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
}

template<typename T> void Niz<T>::upis() {
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Unesi elemetne niza" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (unsigned int i = 0;i < n;i++) {
		std::cin >> niz[i];
	}
}

template<typename T> void sortiranje(char niz[], const int n) {
	char temp;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			temp = niz[i];
			niz[i] = niz[j];
			niz[j] = temp;
		}
	}
}


#endif
