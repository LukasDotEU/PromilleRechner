#pragma once
#include <string>

/** \brief Erstellt ein Getr�nk mit Namen und Alkoholprozentwert
 *
 * Erstellt ein Getr�nk mit den private Daten Name und AlkProz.
 * �ber die puplic Funktionen getName() und getAlkProz() kann auf diese Werte zugegriffen werden.
 *
 */
class Getraenk
{
private:
    std::string Name;
    double AlkProz;

public:
    Getraenk(std::string, double);
    ~Getraenk();
    std::string getName() const;
    double getAlkProz() const;
};
