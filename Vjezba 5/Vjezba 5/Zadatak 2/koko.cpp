#include "koko.hpp"

void Human::odabir_broja_i_te_stvari(Human& igrac,const char znak){
    igrac.par_nepar=znak;
    std::cout<<"Unesi broj"<<std::endl;
    int broj;
    std::cin>>broj;
    igrac.broj_odabran=broj;
}

void Bot::random_odabir_bot(Bot& bot){
    srand(time(0));
    int random_bool = rand() % 2;
    if(random_bool==1){
        bot.par_nepar='p';
    }
    else{
        bot.par_nepar='n';
    }
    bot.broj_odabran=random_int();
}

int random_int(){
    int broj;
    broj = rand() % 100;
    return broj;
}

int Bot::provjera_razlicitosti(Bot& bot1,Bot& bot2){
    if((bot1.par_nepar=='p' && bot2.par_nepar=='p') || (bot1.par_nepar=='n' && bot2.par_nepar=='n')){
        if(bot1.par_nepar=='p'){
            bot2.par_nepar='n';
            return 1;
        }
        else{
            bot2.par_nepar='p';
            return 0;
        }
    }
    else {
        if (bot1.par_nepar == 'p') {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int Human::provjera_razlicitosti(Human& igrac1,Human& igrac2){
     if((igrac1.par_nepar=='p' && igrac2.par_nepar=='p') || (igrac1.par_nepar=='n' && igrac2.par_nepar=='n')){
        if(igrac1.par_nepar=='p'){
            igrac2.par_nepar='n';
            return 1;
        }
        else{
            igrac2.par_nepar='p';
            return 0;
        }
    }
     else {
         if (igrac1.par_nepar == 'p') {
             return 1;
         }
         else {
             return 0;
         }
     }
}

void Game::zapocni_igru_bot(Bot& bot1,Bot& bot2){
    int provjera=bot1.provjera_razlicitosti(bot1,bot2);
    int zbroj=bot1.zbroj_bot(bot1,bot2);
    if(zbroj%2==0 && provjera==1){
        std::cout<<"BOT 1 je POBJEDIA!"<<std::endl;
    }
    else{
        std::cout<<"BOT 2 je POBJEDIA!"<<std::endl;
    }
}

void Game::zapocni_igru_human(Human& igrac1,Human& igrac2){
    int provjera=igrac1.provjera_razlicitosti(igrac1,igrac2);
    int zbroj=igrac1.zbroj_human(igrac1,igrac2);
    if(zbroj%2==0 && provjera==1){
        std::cout<<"IGRAC 1 je POBJEDIA!"<<std::endl;
    }
    else{
        std::cout<<"IGRAC 2 je POBJEDIO"<<std::endl;
    }
}

int Bot::zbroj_bot(Bot& bot1,Bot& bot2){
    return bot1.broj_odabran+bot2.broj_odabran;
}

int Human::zbroj_human(Human& igrac1,Human& igrac2){
    return igrac1.broj_odabran+igrac2.broj_odabran;
}

void Game::zapocni_igru_mijesano(Human& igrac, Bot& bot) {
    if (igrac.par_nepar == bot.par_nepar) {
        if (igrac.par_nepar == 'p') {
            bot.par_nepar = 'n';
        }
        else {
            bot.par_nepar = 'p';
        }
    }
    int zbroj = igrac.broj_odabran + bot.broj_odabran;
    if (zbroj % 2 == 0 && igrac.par_nepar == 'p') {
        std::cout << "Igrac je pobjedia!" << std::endl;
    }
    else if (zbroj % 2 != 0 && igrac.par_nepar == 'n') {
        std::cout << "Igrac je pobjedia!" << std::endl;
    }
    else {
        std::cout << "Bot je pobjedia!" << std::endl;
    }
}