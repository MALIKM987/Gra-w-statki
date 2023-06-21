#include "Gra.h"
#include <iostream>

Gra::Gra()
{
    char pouse{};
    std::cout << "                          " << "WOJNA MORSKA \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "          Nacisnij Enter, aby kontynuowac...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");



    int wybor{};

    while (wybor != 1 && wybor != 2 && wybor != 3)
    {
        std::cout << "           Wybierz poziom\n            1 - Latwy\n            2 - Sredni\n            3 - Trudny\n ";
        std::cin >> wybor;

        switch (wybor)
        {
        case 1:
            poziom = 10;
            break;
        case 2:
            poziom = 20;
            break;
        case 3:
            poziom = 30;
            break;
        default:
            std::cout << "           Nieprawidlowy wybor. Spróbuj ponownie.\n" << std::endl;
            break;
        }
    }

    system("cls");

    planszaStatkiGracz1.SetPoziom(poziom);
    planszaStatkiGracz2.SetPoziom(poziom);
    planszaStrzalyGracz1.SetPoziom(poziom);
    planszaStrzalyGracz2.SetPoziom(poziom);
    planszaStatkiGracz1.UstawPlansze();
    planszaStatkiGracz2.UstawPlansze();
    planszaStrzalyGracz1.UstawPlansze();
    planszaStrzalyGracz2.UstawPlansze();

    UstawianieStatkow();
    std::cout << "           Tura Gracza 1\n\n\n\n";
    std::cout << "           Nacisnij Enter, aby kontynuowac...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");
    Rozgrywka();
}

void Gra::UstawianieStatkow()
{
    int liczbaStatkow;
    bool poprawnaLiczbaStatkow = false;
    do
    {
        std::cout << " \n\n\n           Wybierz liczbe statkow\n            1)   5\n            2)   10\n            3)   15 \n";
        std::cin >> liczbaStatkow;

        switch (liczbaStatkow)
        {
        case 1:
            liczbaStatkow = 5;
            poprawnaLiczbaStatkow = true;
            break;
        case 2:
            liczbaStatkow = 10;
            poprawnaLiczbaStatkow = true;
            break;
        case 3:
            liczbaStatkow = 15;
            poprawnaLiczbaStatkow = true;
            break;
        default:
            std::cout << "           Nieprawidlowa liczba statkow. Sprobuj ponownie.\n" << std::endl;
            break;
        }
    } while (!poprawnaLiczbaStatkow);
    system("cls");

    // Ustawianie statków dla gracza 1
    std::cout << "           Gracz 1 - Ustawianie statkow:\n" << std::endl;
    
    for (int i = 0; i < liczbaStatkow; ++i)
    {
        planszaStatkiGracz1.WyswietlMacierz();

        int wiersz, kolumna;
        bool poprawneWspolrzedne = false;
        do
        {
            std::cout << "           Podaj wspolrzedne statku " << i + 1 << ": \n";
            SprawdzLiczby(wiersz, kolumna);

            if (wiersz >= 0 && wiersz < poziom && kolumna >= 0 && kolumna < poziom &&
                planszaStatkiGracz1.SprawdzStan(wiersz, kolumna) == Pole::Puste)
            {
                planszaStatkiGracz1.UstawStatek(wiersz, kolumna);
                poprawneWspolrzedne = true;
            }
            else
            {
                std::cout << "           Nieprawidlowe wspolrzedne lub pole jest zajete. Sprobuj ponownie.\n" << std::endl;
            }
        }

        while (!poprawneWspolrzedne);
        system("cls");
    }

    std::cout << "           Teraz wybiera gracz 2\n\n\n\n\n\n\n\n";
    std::cout << "           Nacisnij Enter, aby kontynuowaæ...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");


    // Ustawianie statków dla gracza 2
    std::cout << "           Gracz 2 - Ustawianie statkow:\n" << std::endl;
    for (int i = 0; i < liczbaStatkow; ++i)
    {
        planszaStatkiGracz2.WyswietlMacierz();

        int wiersz, kolumna;
        bool poprawneWspolrzedne = false;
        do
        {
            std::cout << "           Podaj wspolrzedne statku " << i + 1 << ": \n";
            SprawdzLiczby(wiersz, kolumna);

            if (wiersz >= 0 && wiersz < poziom && kolumna >= 0 && kolumna < poziom &&
                planszaStatkiGracz2.SprawdzStan(wiersz, kolumna) == Pole::Puste)
            {
                planszaStatkiGracz2.UstawStatek(wiersz, kolumna);
                poprawneWspolrzedne = true;
            }
            else
            {
                std::cout << "           Nieprawidlowe wspolrzedne lub pole jest zajete. Sprobuj ponownie.\n" << std::endl;
            }
        } while (!poprawneWspolrzedne);
        system("cls");
    }
}

void Gra::Tura()
{
    // Tura gracza 1
    std::cout << "           Gracz 1 - Twoja tura:\n" << std::endl;
    int wiersz, kolumna;
    planszaStatkiGracz1.WyswietlMacierz();
    planszaStrzalyGracz1.WyswietlMacierz();
    std::cout << "           Podaj wspolrzedne strzalu: \n";
    SprawdzLiczby(wiersz, kolumna);
    system("cls");
    if (planszaStatkiGracz2.SprawdzStan(wiersz, kolumna) == Pole::Statek)
    {
        std::cout << "Trafiony statek! Masz dodatkowy strzal." << std::endl;
        planszaStrzalyGracz1.ZmienStan(wiersz, kolumna, true);
        planszaStatkiGracz2.ZmienStan(wiersz, kolumna, false);
        planszaStatkiGracz1.WyswietlMacierz();
        planszaStrzalyGracz1.WyswietlMacierz();
        std::cout << "Podaj wspolrzedne strzalu: ";
        SprawdzLiczby(wiersz, kolumna);
        system("cls");
    }

    planszaStatkiGracz2.ZmienStan(wiersz, kolumna, false);
    planszaStrzalyGracz1.ZmienStan(wiersz, kolumna, false);

    if (!planszaStatkiGracz2.CzySaStatki())
    {
        return;
    }


    std::cout << "           Tura Gracza 2\n\n\n\n";
    std::cout << "           Nacisnij Enter, aby kontynuowac...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");


    // Tura gracza 2
    std::cout << "           Gracz 2 - Twoja tura:\n" << std::endl;
    planszaStatkiGracz2.WyswietlMacierz();
    planszaStrzalyGracz2.WyswietlMacierz();
    std::cout << "           Podaj wspolrzedne strzalu: \n";
    SprawdzLiczby(wiersz, kolumna);
    system("cls");
    if (planszaStatkiGracz1.SprawdzStan(wiersz, kolumna) == Pole::Statek)
    {
        std::cout << "           Trafiony statek! Masz dodatkowy strzal.\n" << std::endl;
        planszaStrzalyGracz2.ZmienStan(wiersz, kolumna, true);
        planszaStatkiGracz1.ZmienStan(wiersz, kolumna, false);
        planszaStatkiGracz2.WyswietlMacierz();
        planszaStrzalyGracz2.WyswietlMacierz();
        std::cout << "           Podaj wspolrzedne strzalu: \n";
        SprawdzLiczby(wiersz, kolumna);
        system("cls");
    }

    planszaStatkiGracz1.ZmienStan(wiersz, kolumna, false);
    planszaStrzalyGracz2.ZmienStan(wiersz, kolumna, false);
    if (!planszaStatkiGracz2.CzySaStatki())
    {
        return;
    }
    std::cout << "           Tura Gracza 1\n\n\n\n";
    std::cout << "           Nacisnij Enter, aby kontynuowac...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");

}

void Gra::Rozgrywka()
{
    while (true)
    {
        Tura();
        if (!planszaStatkiGracz1.CzySaStatki())
        {
            std::cout << "                          Koniec gry! Wygral gracz 2.\n" << std::endl;
            break;
        }
        if (!planszaStatkiGracz2.CzySaStatki())
        {
            std::cout << "                          Koniec gry! Wygral gracz 1.\n" << std::endl;
            break;
        }
    }
}

void Gra::SprawdzLiczby(int& liczba1, int& liczba2)
{
    while (true)
    {
        while (!(std::cin >> liczba1 >> liczba2))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "           Nieprawidlowa liczba. Sprobuj ponownie: \n";
        }

        if (liczba1 >= 0 && liczba1 < poziom && liczba2 >= 0 && liczba2 < poziom)
        {
            break;
        }
        else
        {
            std::cout << "           Nieprawidlowe wspolrzedne. Sprobuj ponownie: \n";
        }
    }
}
