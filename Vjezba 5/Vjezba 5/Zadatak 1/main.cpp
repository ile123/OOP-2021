#include "book.hpp"

int main() {
	std::vector<std::string> niz_stringova;
	niz_stringova.push_back("The");
	niz_stringova.push_back("to");
	int broj_ebok=0, broj_hardcopy=0,i=0,j=0;
	broj_knjiga(broj_ebok,broj_hardcopy);
	Library knjiznica;
	EBook ebook;
	HardCopyBook hardcopybook;
	std::string temp;
	std::ifstream fp("knjige.txt");
	if (fp.is_open()) {
		while (getline(fp, temp)) {
			knjiznica.dodavanje_knjige(knjiznica, temp,ebook,hardcopybook);
			if (temp.find(".pdf") != -1) {
				knjiznica.dodaj_u_niz_ebook(ebook);
			}
			else {
				knjiznica.dodaj_u_niz_hardcopy(hardcopybook);
			}
		}
	}
	knjiznica.spoji_sve_u_glavni_niz(broj_ebok, broj_hardcopy);
	knjiznica.naslovi_autora("Neal Stephenson");
	knjiznica.trazenje_ime(niz_stringova);

}