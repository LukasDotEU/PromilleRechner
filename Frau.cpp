#include "Frau.hpp"


/** \brief Kunstruktor Frau
*
* Ruft Konstruktor der Klasse Person auf
*
* @param d Gewicht der Person
* @param g AlkGewicht der getrunkenen Getränke
*
*/
Frau::Frau(double d, double h):Person(d,h){}


/** \brief Berechnung des Promillewertes
*
* @return Promillewert der Frau
*
*/
double Frau::Promille() const
{
    return getAlkGewicht()/(getGewicht()*0.55);
}
