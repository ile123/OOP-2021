#include "koko.hpp"

int main() {
	Counter c;
	Vehicle* v[] = { new Catamaran(30), new Ferry(10, 5, 3), new Seaplane(15) };
	size_t sz = sizeof v / sizeof v[0];
	for (unsigned i = 0; i < sz; ++i)
		c.dodaj(v[i]);
	c.broj_putnika();
       for(unsigned i=0;i<sz;i++){
          delete v[i];
       }
}