#include "Person.hpp"

/** \brief Kunstruktor Person
*
* @param d Gewicht der Person
* @param g AlkGewicht der getrunkenen Getränke
*
*/
Person::Person(double d, double g)
{
    Gewicht = d;
    AlkGewicht = g;
}

/** \brief Destruktor Person
*
*/
Person::~Person(){}

/** \brief Ausgabe des Gewichtes
*
* @return Gewicht der Person
*
*/
double Person::getGewicht() const
{
    return Gewicht;
}

/** \brief Ausgabe des Alkoholgewichtes
*
* @return Alkoholgewicht in Gramm
*
*/
double Person::getAlkGewicht() const
{
    return AlkGewicht;
}
