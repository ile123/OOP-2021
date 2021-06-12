#include "koko.h"

void Vektor::new_Vektor(Vektor& pvektor, int n) {
    pvektor.niz = new double[n];
    pvektor.fizicka_velicina = n;
    pvektor.logicka_velicina = 0;
}

void Vektor::Vektor_pop_back(Vektor& pvektor) {
    for (int i = pvektor.logicka_velicina;i < pvektor.fizicka_velicina;i++) {
        pvektor.niz[i] = pvektor.niz[i + 1];
    }
    pvektor.logicka_velicina = pvektor.logicka_velicina - 1;
}

int Vektor::Vektor_size(Vektor& pvektor) {
    return pvektor.logicka_velicina;
}

double& Vektor::Vektor_front(Vektor& pvektor) {
    return pvektor.niz[0];
}

double& Vektor::Vektor_back(Vektor& pvektor) {
    return pvektor.niz[pvektor.logicka_velicina - 1];
}

void Vektor::Vektor_unos_brojeva(Vektor& pvketor, int n) {
    std::cout << "Unesi niz brojeva:" << std::endl;
    double koko;
    for (int i = 0;i < n;i++) {
        std::cin >> koko;
        pvketor.niz[i] = koko;
        pvketor.logicka_velicina++;
    }
}

void Vektor::Vektor_delete(Vektor pvektor) {
    delete pvektor.niz;
}

void Vektor::Vektor_push_back(Vektor& pvektor, int broj) {
    if (pvektor.fizicka_velicina == pvektor.logicka_velicina) {
        int n = pvektor.fizicka_velicina *= 2;
        double* temp = new double[n];
        for (int i = 0;i < pvektor.logicka_velicina;i++) {
            temp[i] = pvektor.niz[i];
        }
        delete pvektor.niz;
        pvektor.niz = 0;
        pvektor.niz = new double[n];
        for (int i = 0;i < pvektor.logicka_velicina;i++) {
            pvektor.niz[i] = temp[i];
        }
        delete temp;
        temp = 0;
    }
    int i = pvektor.logicka_velicina;
    pvektor.niz[i] = broj;
    pvektor.logicka_velicina++;
}

void Vektor::Vektor_print(Vektor& pvektor) {
    std::cout << "Ispis brojeva vektora:" << std::endl;
    for (int i = 0;i < pvektor.logicka_velicina;i++) {
        std::cout << pvektor.niz[i] << std::endl;
    }
}