#pragma once
#include <vector>
#include "Pole.h"

class Plansza
{
public:
    Pole SprawdzStan(int wiersz, int kolumna) const;
    void ZmienStan(int wiersz, int kolumna, bool trafiony);
    bool CzySaStatki() const;
    void UstawStatek(int wiersz, int kolumna);
    void WyswietlMacierz() const;
    void UstawPlansze();
    int GetPoziom() const;
    void SetPoziom(int poziom);
    int poziom;
private:
    std::vector<std::vector<Pole>> plansza;
};
