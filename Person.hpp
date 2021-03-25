#pragma once

/** \brief Erstellt eine Person mit einem Gewicht und Alk(ohol)Gewicht
 *
 * Erstellt eine Person mit den privaten double Daten Gewicht und AlkGewicht.
 * Über die puplic Funktionen getGewicht() und getAlkGewicht() kann auf diese Werte zugegriffen werden.
 * Die puplic Funktion Promille() wird nicht implementiert.
 *
 * @see Mann.hpp, Frau.hpp, Kind.hpp
 *
 */
class Person
{
private:
    double Gewicht;
    double AlkGewicht;

public:
    Person(double, double);
    virtual ~Person();
    virtual double getGewicht() const;
    virtual double getAlkGewicht() const;
    virtual double Promille() const =0;
};
