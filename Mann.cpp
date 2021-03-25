#include "Mann.hpp"


/** \brief Kunstruktor Mann
*
* Ruft Konstruktor der Klasse Person auf
*
* @param d Gewicht der Person
* @param g AlkGewicht der getrunkenen Getränke
*
*/
Mann::Mann(double d, double h):Person(d,h){}


/** \brief Berechnung des Promillewertes
*
* @return Promillewert des Mannes
*
*/
double Mann::Promille() const
{
    return getAlkGewicht()/(getGewicht()*0.68);
}
