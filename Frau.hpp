#pragma once
#include "Person.hpp"

/** \brief Erstellt eine Frau aufbauend auf einer Person
 *
 * Erstellt eine Frau aufbauend auf der Klasse Person und implementiert zusätzlich die
 * puplic Funktion Promille(), welche mit Gewicht und AlkGewicht den Promillewert der Frau berechnet.
 *
 * @see Person.hpp, Mann.hpp, Kind.hpp
 *
 */
class Frau : public Person
{
public:
    Frau(double, double);
    double Promille() const override;

};
