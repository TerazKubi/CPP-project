#ifndef WYPOZYCZALNIA_H
#define WYPOZYCZALNIA_H
#include <map>
#include <string>
#include <iomanip>
#include <iostream>
#include <climits>
#include "Plyta.h"
#include "Wypozyczenie.h"

using namespace std;

class Wypozyczalnia
{
    public:
        Wypozyczalnia();

        void PokazPlyty();
        void DodajPlyteTmp(Plyta p); // metoda tymczasowa; dodaje gotowy obiekt typu plyta do mapy; w celu testu programu
        void DodajPlyte();
        void UsunPlyte();
        void EdytujPlyte();

        void WypozyczPlyte();
        void ZwrocPlyte();
        void PokazWypozyczenia();

        void Menu();
        void Clear();
    protected:

    private:
        int pid; //licznik ID dla plyt
        int wid; //licznik ID dla wypozyczen
        map<int, Plyta> plyty;
        map<int, Wypozyczenie> wypozyczenia;

        int GetWybor();
};

#endif // WYPOZYCZALNIA_H
