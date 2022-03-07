#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Wypozyczenie
{
    public:
        Wypozyczenie(string imie, string nazwisko, int idPlyty);
        void PokazInfo();
        void Zwrot();
        int GetIdPlyty();
        string GetStatus();


    protected:

    private:
        string imie;
        string nazwisko;
        int idPlyty; // id wypozyczonej plyty
        string status; // wypozyczone/oddane
};

#endif // WYPOZYCZENIE_H
