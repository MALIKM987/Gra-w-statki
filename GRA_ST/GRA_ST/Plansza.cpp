#include "Plansza.h"
#include <iostream>

Pole Plansza::SprawdzStan(int wiersz, int kolumna) const
{
    // Sprawdzenie stanu obiektu Pole w danej komórce wektora planszy
    if (wiersz >= 0 && wiersz < poziom && kolumna >= 0 && kolumna < poziom)
    {
        return plansza[wiersz][kolumna];
    }
    else
    {
        return Pole::Puste;
    }
}

void Plansza::ZmienStan(int wiersz, int kolumna, bool trafiony)
{
    // Sprawdzenie stanu obiektu Pole w danej komórce wektora planszy i dokonanie zmiany
    if (wiersz >= 0 && wiersz < poziom && kolumna >= 0 && kolumna < poziom)
    {
        if (trafiony)
        {
            plansza[wiersz][kolumna] = Pole::Trafiony;
        }
        else
        {
            plansza[wiersz][kolumna] = Pole::Pudlo;
        }
    }
}

bool Plansza::CzySaStatki() const
{
    // Sprawdzanie czy w macierzy s¹ jakiekolwiek statki
    for (const auto& wiersz : plansza)
    {
        for (const auto& pole : wiersz)
        {
            if (pole == Pole::Statek)
            {
                return true;
            }
        }
    }
    return false;
}

void Plansza::UstawStatek(int wiersz, int kolumna)
{
    if (wiersz >= 0 && wiersz < poziom && kolumna >= 0 && kolumna < poziom)
    {
        plansza[wiersz][kolumna] = Pole::Statek;
    }
}

void Plansza::WyswietlMacierz() const
{
    // Wyœwietlanie macierzy z stanami obiektów klasy Pole
    std::cout << "    ";
    for (int i = 0; i < poziom; ++i)
    {
        if (i < 10)
            std::cout << " ";
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < poziom; ++i)
    {
        if (i < 10)
            std::cout << " ";
        std::cout << i << " ";

        for (int j = 0; j < poziom; ++j)
        {
            Pole pole = plansza[i][j];
            char znak;

            if (pole == Pole::Puste)
                znak = '.';
            else if (pole == Pole::Statek)
                znak = 'S';
            else if (pole == Pole::Trafiony)
                znak = 'X';
            else if (pole == Pole::Pudlo)
                znak = 'O';

            std::cout << " " << znak << " ";
        }
        std::cout << std::endl;
    }
}

void Plansza::UstawPlansze() {
    for (int i = 0; i < poziom; ++i)
    {
        std::vector<Pole> wiersz;
        for (int j = 0; j < poziom; ++j)
        {
            wiersz.push_back(Pole::Puste);
        }
        plansza.push_back(wiersz);
    }
}

int Plansza::GetPoziom() const
{
    return poziom;
}

void Plansza::SetPoziom(int poziom)
{
    this->poziom = poziom;
}