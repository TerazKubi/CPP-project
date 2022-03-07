#ifndef PLYTA_H
#define PLYTA_H
#include <string>
#include <iomanip>
#include "Film.h"

using namespace std;

class Plyta : public Film
{
    public:
        Plyta(string rodzajPlyty, int iloscPlyt, string tytul, int rokPremiery);

        virtual void PokazInfo();
        bool WypozyczPlyte();
        void ZwrocPlyte();



    private:
        string rodzajPlyty;
        int iloscPlytMax; // max ilosc plyt
        int iloscPlytTeraz; // ilosc plyt w danym momencie
};

#endif // PLYTA_H
