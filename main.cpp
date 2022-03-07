#include <iostream>
#include "Plyta.h"
#include "Wypozyczalnia.h"
using namespace std;



int main()
{
    Wypozyczalnia w = Wypozyczalnia();

    //stworzenie i dodanie kilku plyt w celu wypelnienia bazy danymi
    Plyta p1 = Plyta("BR", 10, "star wars", 1990);
    Plyta p2 = Plyta("CD", 12, "star wars2", 1992);
    Plyta p3 = Plyta("CD", 14, "star wars3", 1995);
    Plyta p4 = Plyta("CD", 60, "star wars6", 1997);

    w.DodajPlyteTmp(p1);
    w.DodajPlyteTmp(p2);
    w.DodajPlyteTmp(p3);
    w.DodajPlyteTmp(p4);


    w.Menu();



    return 0;
}
