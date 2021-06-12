#include <iostream>
#include <vector>

class Player{
protected:
    int broj_odabran;
    char par_nepar;
    bool jeli_pobjednik;
public:
};

class Human : public Player{
    public:
    friend class Game;
    Human(){
        jeli_pobjednik=0;
    }
    ~Human(){
        broj_odabran=NULL;
        par_nepar=NULL;
        jeli_pobjednik=0;
    }
    void odabir_broja_i_te_stvari(Human& igrac,const char znak);
    int provjera_razlicitosti(Human& igrac1,Human& igrac2);
    int zbroj_human(Human& igrac1,Human& igrac2);
};

class Bot : public Player{
public:
   friend class Game;
   Bot(){
       jeli_pobjednik=0;
   }
   ~Bot(){
        broj_odabran=NULL;
        par_nepar=NULL;
        jeli_pobjednik=0;
   }
   void random_odabir_bot(Bot& bot);
   int provjera_razlicitosti(Bot& bot1,Bot& bot2);
   int zbroj_bot(Bot& bot1,Bot& bot2);
};

class Game{
public:
    void zapocni_igru_human(Human& igrac1,Human& igrac2);
    void zapocni_igru_bot(Bot& bot1,Bot& bot2);
    void zapocni_igru_mijesano(Human& igrac,Bot& bot);
};

int random_int();