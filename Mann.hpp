#pragma once
#include "Person.hpp"

/** \brief Erstellt einen Mann aufbauend auf einer Person
 *
 * Erstellt einen Mann aufbauend auf der Klasse Person und implementiert zusätzlich die
 * puplic Funktion Promille(), welche mit Gewicht und AlkGewicht den Promillewert des Manns berechnet.
 *
 * @see Person.hpp, Frau.hpp, Kind.hpp
 *
 */
class Mann : public Person
{
public:
    Mann(double, double);
    double Promille() const override;
};
