#include "book.hpp"

void EBook::zapisivanje_knjige(const std::string& str,EBook& ebook) {
    int broj;
    std::string temp,temp1;
    temp1 = str;
    //Autor
    size_t token = temp1.find(";");
    temp = temp1.substr(0, token);
    ebook.Autor = temp;
    temp1.erase(0, token+2);
    //Ime Knjige
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    ebook.Ime_Knjige = temp;
    temp1.erase(0, token + 2);
    //Godina izdanja
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    broj = atoi(temp.c_str());
    ebook.godina_izdanja = broj;
    temp1.erase(0, token + 2);
    //Ime PDF-a
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    ebook.Ime_Dadoteke = temp;
    temp1.erase(0, token + 2);
    //Velicina Dadoteke
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    broj = atoi(temp.c_str());
    ebook.Velicina_Dadoteke = broj;
    temp1.erase(0, token + 2);
}

void HardCopyBook::zapisivanje_knjige(const std::string& str, HardCopyBook& hardcopybook) {
    int broj;
    std::string temp, temp1;
    temp1 = str;
    //Autor
    size_t token = temp1.find(";");
    temp = temp1.substr(0, token);
    hardcopybook.Autor = temp;
    temp1.erase(0, token + 2);
    //Ime Knjige
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    hardcopybook.Ime_Knjige = temp;
    temp1.erase(0, token + 2);
    //Godina izdanja
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    broj = atoi(temp.c_str());
    hardcopybook.godina_izdanja = broj;
    temp1.erase(0, token + 2);
    //Broj Stranica
    token = temp1.find(";");
    temp = temp1.substr(0, token);
    broj = atoi(temp.c_str());
    hardcopybook.broj_stranica = broj;
    temp1.erase(0, token + 2);
}


void broj_knjiga(int& broj_ebok,int& broj_hardcopy) {
	std::ifstream fp("knjige.txt");
	std::string temp;
    if (fp.is_open())
    {
        while (!fp.eof())
        {
            getline(fp, temp);
            if (temp.find(".pdf") != -1) {
                broj_ebok++;
            }
            else {
                broj_hardcopy++;
            }
        }
        fp.close();
    }
}

void Library::dodavanje_knjige(Library& knjiznica,const std::string& temp,EBook& ebook,HardCopyBook& hardcopybook) {
    int provjera1 = temp.find(".pdf");
    if (provjera1 != -1) {
        ebook.zapisivanje_knjige(temp,ebook);
    }
    else {
        hardcopybook.zapisivanje_knjige(temp, hardcopybook);
    }
}

void Library::dodaj_u_niz_ebook(const EBook& ebook) {
    ebook_niz.push_back(ebook);
}

void Library::dodaj_u_niz_hardcopy(const HardCopyBook& hardcopy) {
    hardcopy_niz.push_back(hardcopy);
}

void Library::spoji_sve_u_glavni_niz(const int broj_ebook, const int broj_hardcopy) {
    sve_knjige.resize(broj_ebook + broj_hardcopy);
    for (int i = 0;i < broj_ebook;i++) {
        sve_knjige[i] = &ebook_niz[i];
    }
    for (int i = broj_ebook,j = 0;j < broj_hardcopy;i++, j++) {
        sve_knjige[i] = &hardcopy_niz[j];
    }
}

void Library::ispis_svih_knjiga() {
    for (int i = 0;i < sve_knjige.size();i++) {
        sve_knjige[i]->ispisi();
    }
}


