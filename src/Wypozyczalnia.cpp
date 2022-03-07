#include "Wypozyczalnia.h"

Wypozyczalnia::Wypozyczalnia()
{
    this->pid=1;
    this->wid=1;
}

void Wypozyczalnia::DodajPlyteTmp(Plyta p)
{
    this->plyty.insert({this->pid, p});
    this->pid+=1;
}
void Wypozyczalnia::PokazPlyty()
{
    cout<<left<<setw(6)<<"ID"
        <<left<<setw(20)<<"Tytul"
        <<left<<setw(14)<<"Rok Premiery"
        <<left<<setw(10)<<"Ilosc"
        <<left<<setw(8)<<"Rodzaj"<<endl;

    for(auto& p : this->plyty){
        cout<<left<<setw(6)<<to_string(p.first)+".";
        p.second.PokazInfo();

    }
}
int Wypozyczalnia::GetWybor()
{
    int w;

    cin >> setw(1) >> w;
    while( !cin.good())
    {
        cout<<"BLAD!, podano zle wartosci. Wpisz ponownie."<<endl;

        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cin >> setw(1) >> w;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return w;
}
void Wypozyczalnia::DodajPlyte()
{
    string typPlyty, tytulFilmu;
    int rok, ilosc, w;

    cout<<"PODAJ TYTUL FILMU:"<<endl;
    getline(cin, tytulFilmu);

    cout<<"PODAJ ROK PREMIERY:"<<endl;
    rok = this->GetWybor();

    cout<<"PODAJ ILOSC PLYT:"<<endl;
    ilosc = this->GetWybor();

    cout<<"PODAJ TYP PLYTY: 1.CD / 2.BlueRay / 3.DVD (Wpisz 1, 2 lub 3)"<<endl;
    w = this->GetWybor();

    while(w != 1 && w != 2 && w != 3)
    {
        cout<<"PODAJ TYP PLYTY: 1.CD / 2.BlueRay / 3.DVD (Wpisz 1, 2 lub 3)"<<endl;
        w = this->GetWybor();
    }
    if(w==1){
        typPlyty = "CD";
    }else if(w==2){
        typPlyty = "BR";
    }else{
        typPlyty = "DVD";
    }
    Plyta p = Plyta(typPlyty, ilosc, tytulFilmu, rok);
    this->plyty.insert({this->pid, p});
    this->pid+=1;
    cout<<"DODANIE PLYTY - UDANE"<<endl;

}
void Wypozyczalnia::UsunPlyte()
{
    cout<<"Podaj ID plyty ktora chcesz usunac:"<<endl;
    int id;
    bool f = false;
    id = this->GetWybor();

    for(auto& p : this->plyty){
        if(p.first == id){
            this->plyty.erase(id);

            f=true;
            break;
        }
    }
    (!f) ? cout<<"Usuwanie nie udalo sie. Nie ma takiego ID."<<endl : cout<<"Usuwanie udalo sie."<<endl;
}
void Wypozyczalnia::EdytujPlyte()
{
    cout<<"Podaj ID plyty ktora chcesz edytowac:"<<endl;
    int id;
    bool f=false;
    id = this->GetWybor();
    //check if exists
    for(auto& p : this->plyty){
        if(p.first == id){
            f=true;
            p.second.PokazInfo();

            string typPlyty, tytulFilmu;
            int rok, ilosc, w;

            cout<<"Podaj nowy tytul filmu"<<endl;
            getline(cin, tytulFilmu);

            cout<<"Podaj nowy rok premiery"<<endl;
            rok = this->GetWybor();

            cout<<"Podaj nowa ilosc"<<endl;
            ilosc = this->GetWybor();

            cout<<"Podaj nowy typ plyty: 1.CD / 2.BlueRay / 3.DVD (Wpisz 1, 2 lub 3)"<<endl;
            w = this->GetWybor();

            while(w != 1 && w != 2 && w != 3)
            {
                cout<<"Podaj nowy typ plyty: 1.CD / 2.BlueRay / 3.DVD (Wpisz 1, 2 lub 3)"<<endl;
                w = this->GetWybor();
            }
            if(w==1){
                typPlyty = "CD";
            }else if(w==2){
                typPlyty = "BR";
            }else{
                typPlyty = "DVD";
            }
            Plyta tmp = Plyta(typPlyty, ilosc, tytulFilmu, rok);
            p.second = tmp;
            break;
        }
    }

}
void Wypozyczalnia::WypozyczPlyte()
{
    int id;
    bool f=false;
    cout<<"Podaj id plyty do wypozyczenia:"<<endl;
    id = this->GetWybor();

    for(auto& p : this->plyty){
        if(p.first == id){
            if(p.second.WypozyczPlyte())
            {
                string i, n;

                cout<<"Podaj imie"<<endl;
                getline(cin, i);
                cout<<"Podaj nazwisko"<<endl;
                getline(cin, n);


                Wypozyczenie w = Wypozyczenie(i, n, id);

                this->wypozyczenia.insert({this->wid, w});
                this->wid += 1;
                f=true;
                break;
            }else{
                cout<<"Wszystkie plyty wypozyczone."<<endl;
            }
        }
    }
    (!f) ? cout<<"UWypozyczenie nie udalo sie. Nie ma takiego ID."<<endl : cout<<"Wypozycznie udalo sie."<<endl;

}
void Wypozyczalnia::PokazWypozyczenia()
{
    cout<<left<<setw(16)<<"ID Wypozyczenia"
        <<left<<setw(10)<<"Imie"
        <<left<<setw(15)<<"Nazwisko"
        <<left<<setw(10)<<"ID Plyty"
        <<left<<setw(8)<<"Status"<<endl;

    for(auto& w : this->wypozyczenia){
        cout<<left<<setw(16)<<to_string(w.first)+".";
        w.second.PokazInfo();
    }
}
void Wypozyczalnia::ZwrocPlyte()
{
    cout<<"Podaj ID wypozyczenia: "<<endl;
    int id;
    id = this->GetWybor();
    bool f=false;

    for(auto& w : this->wypozyczenia){
        if(w.first==id)
        {
            if(w.second.GetStatus()=="ZWROT.")
            {
                cout<<"Juz dokonano zwrotu"<<endl;
                break;
            }
            f=true;
            w.second.Zwrot();

            int pid = w.second.GetIdPlyty();
            for(auto& p : this->plyty){
                if(p.first==pid)
                {
                    p.second.ZwrocPlyte();
                }
            }
            break;
        }

    }
    (!f) ? cout<<"Zwrot nie udal sie."<<endl : cout<<"Zwrot udal sie."<<endl;

}
void Wypozyczalnia::Menu()
{
    int wybor;
    cout<<"Menu:"<<endl;
    cout<<"1. Dodaj plyte."<<endl<<"2. Usun plyte."<<endl<<"3. Edytuj Plyte."<<endl<<"4. Pokaz wszystkie plyty."<<endl;
    cout<<"5. Wypozyczenie plyty."<<endl<<"6. Zwrot plyty."<<endl<<"7. Pokaz wszystkie wypozyczenia."<<endl;
    cout<<"8. Zamknij program."<<endl<<endl;
    cout<<"Podaj nr opcji: ";

    wybor = this->GetWybor();

    switch ( wybor )
    {
        case 1:
            this->Clear();
            cout<<"DODAWANIE PLYTY"<<endl<<endl;
            this->DodajPlyte();
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 2:
            cout<<"USUWANIE PLYTY:"<<endl;
            this->UsunPlyte();
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 3:
            cout<<"EDYTOWANIE PLYTY:"<<endl;
            this->EdytujPlyte();
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 4:
            this->Clear();
            cout<<endl<<"WSZYSTKIE PLYTY:"<<endl;
            this->PokazPlyty();
            cout<<endl;
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 5:
            cout<<"WYPOZYCZANIE PLYTY:"<<endl;
            this->WypozyczPlyte();
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 6:
            cout<<"ZWROT PLYTY:"<<endl;
            this->ZwrocPlyte();
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 7:
            this->Clear();
            cout<<"WSZYSTKIE PLYTY"<<wybor<<endl;
            this->PokazWypozyczenia();
            //system("pause");
            cin.get();
            this->Menu();
            break;
        case 8:
            this->Clear();
            cout<<"PROGRAM ZOSTANIE WYLACZONY.."<<endl;
            exit(0);
            break;

        default:
            cout<<"PODAJ PRAWIDLOWY NUMER"<<endl;
            this->Menu();
    }
}
void Wypozyczalnia::Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}


