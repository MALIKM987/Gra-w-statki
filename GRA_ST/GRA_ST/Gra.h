#pragma once
#include "Plansza.h"

class Gra
{
public:
    Gra();
    void Tura();
    void UstawianieStatkow();
    void Rozgrywka();
    void SprawdzLiczby(int& liczba1, int& liczba2);
    int poziom;
private:
    Plansza planszaStatkiGracz1;
    Plansza planszaStatkiGracz2;
    Plansza planszaStrzalyGracz1;
    Plansza planszaStrzalyGracz2;
};
