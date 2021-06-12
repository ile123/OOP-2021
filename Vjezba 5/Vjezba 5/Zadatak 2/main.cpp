# include "koko.hpp"

int main(){
    Game igra;
    Human igrac1,igrac2;
    Bot bot1,bot2;
    std::cout<<"Unesi vrijednost za prvog igraca"<<std::endl;
    igrac1.odabir_broja_i_te_stvari(igrac1,'p');
    /*
    std::cout << "Unesi vrijednost za drugog igraca" << std::endl;
    igrac2.odabir_broja_i_te_stvari(igrac2,'n');
    igra.zapocni_igru_human(igrac1,igrac2);
    */
    bot1.random_odabir_bot(bot1);
    //bot2.random_odabir_bot(bot2);
    //igra.zapocni_igru_bot(bot1, bot2);
    igra.zapocni_igru_mijesano(igrac1, bot1);
}