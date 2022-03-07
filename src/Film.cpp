#include "Film.h"

Film::Film(string tytul, int rokPremiery)
{
    this->tytul = tytul;
    this->rokPremiery = rokPremiery;
}
void Film::PokazInfo()
{
    cout<<this->tytul <<", "<<this->rokPremiery<<"."<<endl;
}




