#include "Wypozyczenie.h"

Wypozyczenie::Wypozyczenie(string imie, string nazwisko, int idPlyty)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->idPlyty = idPlyty;
    this->status = "WYPOZ.";
}
void Wypozyczenie::PokazInfo()
{
    cout<<left<<setw(10)<<this->imie
        <<left<<setw(15)<<this->nazwisko
        <<left<<setw(10)<<this->idPlyty
        <<left<<setw(8)<<this->status<<endl;
}
void Wypozyczenie::Zwrot()
{
    this->status = "ZWROT.";
}
int Wypozyczenie::GetIdPlyty()
{
    return this->idPlyty;
}
string Wypozyczenie::GetStatus()
{
    return this->status;
}


