#ifndef KOKO
#define KOKO

#include <iostream>
class Vektor {
    double* niz;
    int fizicka_velicina;
    int logicka_velicina;
public:
    void new_Vektor(Vektor& pvektor, int n);
    void Vektor_delete(Vektor pvektor);
    void Vektor_unos_brojeva(Vektor& pvektor, int n);
    void Vektor_push_back(Vektor& pvektor,int broj);
    void Vektor_print(Vektor& pvektor);
    int Vektor_size(Vektor& pvektor);
    double& Vektor_front(Vektor& pvektor);
    double& Vektor_back(Vektor& pvektor);
    void Vektor_pop_back(Vektor& pvektor);
    Vektor(){
        std::cout << "Default Konstruktor Pozvan" << std::endl;
    } 

    Vektor(int n){
       std::cout<<"Konstruktor bez parametra k pozvan"<<std::endl;
       niz=new double[n];
       for(int i=0;i<n;i++){
           niz[i]=0;
       }
    }

    Vektor(int n, int k) {
        std::cout<<"Konstruktor sa parametrima n i k pozvan"<<std::endl;
        niz = new double[n];
        for(int i=0;i<n;i++){
            niz[i]=k;
        }
    } 
    Vektor(const Vektor& pvektor){
          std::cout<<"Copy Konstruktor Pozvan"<<std::endl;
          niz=new double[*pvektor.niz];
          logicka_velicina=pvektor.logicka_velicina;
          fizicka_velicina=pvektor.fizicka_velicina;
    }
    ~Vektor(){
        std::cout << "Destroktur pozvan" << std::endl;
       delete niz;
    }
};

#endif
//koko