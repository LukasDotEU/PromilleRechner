#include "Kind.hpp"


/** \brief Kunstruktor Kind
*
* Ruft Konstruktor der Klasse Person auf
*
* @param d Gewicht der Person
* @param g AlkGewicht der getrunkenen Getränke
*
*/
Kind::Kind(double d, double h):Person(d,h){}


/** \brief Berechnung des Promillewertes
*
* @return Promillewert des Kindes
*/
double Kind::Promille() const
{
    return getAlkGewicht()/(getGewicht()*0.75);
}
