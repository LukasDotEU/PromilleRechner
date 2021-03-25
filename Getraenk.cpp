#include "Getraenk.hpp"
#include <string>
#include <iostream>

/** \brief Kunstruktor Getreank
*
* @param N Name des Getränkes
* @param A Alkoholprozentanteil des Getränkes
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
* @return den Namen des Getränkes
*
*/
std::string Getraenk::getName() const
{
    return Name;
}

/** \brief Ausgabe des Alkoholprozentanteils
*
* @return Alkoholprozentanteil des Getränkes
*
*/
double Getraenk::getAlkProz() const
{
    return AlkProz;
}
