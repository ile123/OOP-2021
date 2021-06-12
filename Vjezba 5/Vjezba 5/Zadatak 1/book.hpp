#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef  BOOK_HPP
#define BOOK_HPP


class Book {
protected:
	std::string Ime_Knjige;
    std::string Autor;
	int godina_izdanja;
	friend class Library;
public:
	virtual void ispisi() {
		std::cout <<"Ime Autora: "<< " " << Autor << std::endl;
		std::cout << "Naslov Knjige: " << " " << Ime_Knjige << std::endl;
		std::cout << "Godina Izdanja: " << " " << godina_izdanja << std::endl;
	}
};

class HardCopyBook : public Book {
protected:
	int broj_stranica;
public:
	void zapisivanje_knjige(const std::string& str, HardCopyBook& hardcopybook);
	virtual void ispisi() {
		std::cout << "-----------------------------------------------------" << std::endl;
		std::cout << "Ime Autora: " << " " << Autor << std::endl;
		std::cout << "Naslov Knjige: " << " " << Ime_Knjige << std::endl;
		std::cout << "Godina Izdanja: " << " " << godina_izdanja << std::endl;
		std::cout << "Broj Stranica: " << " " << broj_stranica << std::endl;
		std::cout << "-----------------------------------------------------" << std::endl;
	}
};

class EBook : public Book {
protected:
	std::string Ime_Dadoteke;
	int Velicina_Dadoteke;
public:
	void zapisivanje_knjige(const std::string& str,EBook& ebook);
	virtual void ispisi() {
		std::cout<<"-----------------------------------------------------" << std::endl;
		std::cout << "Ime Autora: " << " " << Autor << std::endl;
		std::cout << "Naslov Knjige: " << " " << Ime_Knjige << std::endl;
		std::cout << "Godina Izdanja: " << " " << godina_izdanja << std::endl;
		std::cout << "Ime Dadoteke: " << " " << Ime_Dadoteke << std::endl;
		std::cout << "Velicina Dadoteke: " << " " << Velicina_Dadoteke <<" " << "MB"<<std::endl;
		std::cout << "-----------------------------------------------------" << std::endl;
	}
};

class Library {
protected:
	std::vector<HardCopyBook> hardcopy_niz;
	std::vector<EBook> ebook_niz;
	std::vector<Book*> sve_knjige;
public:
	Library() {
		sve_knjige.resize(0);
		ebook_niz.resize(0);
		hardcopy_niz.resize(0);
	}
	~Library() {
		ebook_niz.clear();
		hardcopy_niz.clear();
		sve_knjige.clear();
	}
	void naslovi_autora(const std::string& Ime_Autora) {
		for (int i = 0;i < sve_knjige.size();i++) {
			if (sve_knjige[i]->Autor == Ime_Autora) {
				sve_knjige[i]->ispisi();
			}
		}
	}

	void trazenje_ime(std::vector<std::string> niz_stringova) {
		int flag;
		std::string temp;
		size_t nadeno;
		for (int i = 0;i < sve_knjige.size();i++) {
			flag = 1;
			temp = sve_knjige[i]->Ime_Knjige;
			for (int i = 0;i < niz_stringova.size();i++) {
				nadeno = temp.find(niz_stringova[i]);
				if (nadeno != std::string::npos) {
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				sve_knjige[i]->ispisi();
			}
		}
	}

	void dodavanje_knjige(Library& knjiznica,const std::string& knjiga,EBook& ebook,HardCopyBook& hardcopybook);
	void dodaj_u_niz_ebook(const EBook& ebook);
	void dodaj_u_niz_hardcopy(const HardCopyBook& hardcopy);
	void spoji_sve_u_glavni_niz(const int broj_ebook, const int broj_hardcopy);
	void ispis_svih_knjiga();
};

void broj_knjiga(int& broj_ebok,int& broj_hardcopy);
#endif // ! BOOK_HPP

