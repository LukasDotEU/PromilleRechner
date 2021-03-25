#include "Getraenk.hpp"
#include <string>
#include <iostream>

/** \brief Kunstruktor Getreank
*
* @param N Name des Getr�nkes
* @param A Alkoholprozentanteil des Getr�nkes
*
*/
Getraenk::Getraenk(std::string N, double A)
{
    Name=N;
    AlkProz=A;
}

/** \brief Destruktor Getraenk
*
*/
Getraenk::~Getraenk(){}

/** \brief Ausgabe des Namens
*
* @return den Namen des Getr�nkes
*
*/
std::string Getraenk::getName() const
{
    return Name;
}

/** \brief Ausgabe des Alkoholprozentanteils
*
* @return Alkoholprozentanteil des Getr�nkes
*
*/
double Getraenk::getAlkProz() const
{
    return AlkProz;
}
