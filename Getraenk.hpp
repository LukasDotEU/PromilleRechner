#pragma once
#include <string>

/** \brief Erstellt ein Getränk mit Namen und Alkoholprozentwert
 *
 * Erstellt ein Getränk mit den private Daten Name und AlkProz.
 * Über die puplic Funktionen getName() und getAlkProz() kann auf diese Werte zugegriffen werden.
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
