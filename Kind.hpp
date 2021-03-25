#pragma once
#include "Person.hpp"

/** \brief Erstellt ein Kind aufbauend auf einer Person
 *
 * Erstellt ein Kind aufbauend auf der Klasse Person und implementiert zusätzlich die
 * puplic Funktion Promille(), welche mit Gewicht und AlkGewicht den Promillewert des Kindes berechnet.
 *
 * @see Person.hpp, Frau.hpp, Mann.hpp
 *
 */
class Kind : public Person
{
public:
    Kind(double, double);
    double Promille() const override;
};
