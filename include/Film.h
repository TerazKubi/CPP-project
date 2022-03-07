#ifndef FILM_H
#define FILM_H
#include <string>
#include <iostream>

using namespace std;

class Film
{
    public:
        Film(string tytul, int rokPremiery);

        virtual void PokazInfo();
;

    protected:
        string tytul;
        int rokPremiery;
};

#endif // FILM_H
