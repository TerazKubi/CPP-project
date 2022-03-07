#include "Plyta.h"

Plyta::Plyta(string rodzajPlyty, int iloscPlyt, string tytul, int rokPremiery): Film(tytul, rokPremiery)
{
    this->rodzajPlyty = rodzajPlyty;
    this->iloscPlytMax = iloscPlyt;
    this->iloscPlytTeraz = iloscPlyt;
}
void Plyta::PokazInfo()
{
    if(this->tytul.length() > 17){
        string tmp = this->tytul.substr(0,17) + "..";
        cout<<left<<setw(20)<<tmp;
    }else{
        cout<<left<<setw(20)<<this->tytul;
    }
    cout<<left<<setw(14)<<this->rokPremiery
        <<left<<setw(10)<<to_string(this->iloscPlytTeraz)+"/"+to_string(this->iloscPlytMax)
        <<left<<setw(8)<<this->rodzajPlyty<<endl;
}
bool Plyta::WypozyczPlyte()
{
    if(this->iloscPlytTeraz > 0)
    {
        this->iloscPlytTeraz -= 1;
        return true;
    }else{
        return false;
    }
}
void Plyta::ZwrocPlyte()
{
    if(this->iloscPlytTeraz < this->iloscPlytMax )
    {
        this->iloscPlytTeraz++;
    }else{
        cout<<"WARNING. Plyta juz oddana."<<endl;
    }
}


