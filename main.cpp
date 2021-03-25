/** \mainpage Promillerechner Abschlussaufgabe 26 für GdP 20MIB
 *
 * Eine Liste von Getränken (Name und Alkoholprozentwert) wird ausgegeben.
 * Der Benutzer kann immer wieder eines von ihnen per Index auswählen und anschließend die
 * getrunkene Menge in Liter angeben.
 * Das Gewicht des gesamten getrunkenen Alkohols wird berechnet.
 * Wenn alle Getränke angegeben wurden, wird mit der Eingabe 0 der weitere Programmablauf gestartet.
 * Wurde 0g Alkohol getrunken, wird das Programm nach einer Ausgabe von 0 Promille geschlossen.
 * Ansonsten wird nach dem Gewicht gefragt und ob man ein Mann, eine Frau, oder ein Kind ist.
 * Es wird ein Objekt Mensch der entsprechenden Klasse mit dem Gewicht und Alkoholgewicht erstellt
 * und die klassenspezifische Funktion Promille() ausgeführt. Diese gibt den Promillewert zurück.
 * Zu jedem Zeitpunkt wird unerwartetes Reagieren des Programms durch falsche Eingaben unterbunden.
 *
 * @author Lukas Heinrich
 * @version 17.02.2021
 */
#include <iostream>
#include "Kind.hpp"
#include "Mann.hpp"
#include "Frau.hpp"
#include "Getraenk.hpp"
#include <string>
#include <vector>
#include <limits>

std::vector<Getraenk> Vektor();
void GetraenkeAusgabe(const std::vector<Getraenk>&);
double BestimmeAlkGewicht(const std::vector<Getraenk>&);
double FrageLiter(unsigned int, const std::vector<Getraenk>&);
double FrageGewicht();
void FrageTyp(double, double);


/** \brief Abfrage der getrunkenen Alkoholmenge, des Gewichtes und des Typs und Ausgabe des Promillewertes
 *
 * Erstellt über Vektor() eine Liste mit Getränken, übergibt diese der Ausgabe- und
 * Alkoholgewichtsberechnungsfunktion, von welcher das Alkoholgewicht zurückkommt. Wenn dieses
 * größer als 0 ist, wird das Gewicht der Person erfragt und dieses mit dem Alkoholgewicht der Funktion
 * FrageTyp übergeben, welche nach dem Typ des Menschen fragt und den berechneten Promillewert ausgibt.
 *
 */

int main()
{
    std::vector<Getraenk> Liste = Vektor();
    GetraenkeAusgabe(Liste);
    double Alkoholgewicht= BestimmeAlkGewicht(Liste);
    //Abfang wenn kein Alkohol getrunken wurde
    if (Alkoholgewicht<=0)
    {
        std::cout<<"Wer nichts trinkt hat eine Blutalkoholkonzentration von 0 Promille. Sehr gut!"<<std::endl;
    }
    else
    {
        std::cout<<"Du nahmst "<<Alkoholgewicht<<"g reinen Alkohol zu dir."<<std::endl;
        double Gewicht = FrageGewicht();
        FrageTyp(Alkoholgewicht, Gewicht);
    }
}


/** \brief Erstellt Liste (Vektor) mit Objekten der Klasse Getraenk
 *
 * Erstellt Liste (Vektor) mit Objekten der Klasse Getraenk (Die Liste wird damit im Programm gespeichert)
 *
 * @return Liste (Vektor) mit Objekten der Klasse Getraenk
 *
 */
std::vector<Getraenk> Vektor()
{
    std::vector<Getraenk> Liste;
    Liste.push_back(Getraenk("Bier",0.05));
    Liste.push_back(Getraenk("Sekt",0.11));
    Liste.push_back(Getraenk("Lemon-Wodka",0.18));
    Liste.push_back(Getraenk("Rum",0.375));
    Liste.push_back(Getraenk("Wodka",0.4));

    return Liste;
}


/** \brief Ausgabe eines gegebenen Vektors mit Objekten der Klasse Getraenk
 *
 * Ausgabe eines gegebenen Vektors mit Objekten der Klasse Getraenk in folgender Form:
 * index+1: Getränkname (Getränkalkoholprozentanteil%)
 *
 * @param Liste ein Vektor welche Objekte der Klasse Getraenk enthält
 *
 */
void GetraenkeAusgabe (const std::vector<Getraenk>& Liste)
{
    std::cout<<"Gib die Nummer deines Getraenkes an bzw. 0 falls das alle Getraenke waren."<<std::endl;
    for (size_t i=0; i<Liste.size();i++)
    {
        //Ausgabe mit angezeigtem Index+1
        std::cout<<i+1<<".: "<<Liste.at(i).getName()<<" ("<<Liste.at(i).getAlkProz()*100<<"%)"<<std::endl;
    }
}


/** \brief Bestimmt das Alkoholgewicht der getrunkenen Getränke
 *
 * Fragt in einer Schleife den i+1ten Index der getrunkenen Getränke aus dem Vektor Liste ab
 * und übergibt den Index der Funktion FrageLiter. Der Rückgegebene Wert ist das Alkoholgewicht
 * des getrunkenen Getränkes. Dieser Wert wird auf die vorherigen aufaddierten Werte des gesamten
 * Alkoholgewichtes addiert. Die Schleife endet bei Eingabe der Zahl 0.
 *
 * @param Liste ein Vektor welche Objekte der Klasse Getraenk enthält
 * @see FrageLiter(unsigned int, const std::vector<Getraenk>&)
 * @return Alkoholgewicht aller getrunkenen Getränke in Gramm
 *
 */
double BestimmeAlkGewicht(const std::vector<Getraenk>& Liste)
{
    double AlkMenge=0.0;
    size_t index;
    do
    {
        std::cout<<"Getraenk-Nr.: ";
        if(!(std::cin>>index) || index>Liste.size())    //ungültige Eingabe
        {
            std::cout<<"FEHLER! Dies ist kein gueltiges Getraenk. Wiederhole deine Angabe."<<std::endl;
            index=1;
            std::cin.clear();                                                   //Löschen der vorherigen Fehlerflags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Löschen aller Zeichen der Eingabe bzw. bis \n
        }
        else if (index!=0)  //gültiges Getränk
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            AlkMenge+=Liste.at(index-1).getAlkProz()*FrageLiter(index, Liste);
        }
        else        //Ende der Eingabe der Getränke
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (index!=0);

    return AlkMenge*800.0;
}


/** \brief Fragt die Menge eines getrunkenen Getränkes in Liter ab
 *
 * Fragt die getrunkene Menge des index-1ten Getränkes im Vektor Liste ab.
 *
 * @param index des Getränkes an der i+1ten Stelle von Liste
 * @param Liste ein Vektor welche Objekte der Klasse Getraenk enthält
 * @return Menge des getrunkenen Getränkes in Liter
 * @pre index Eingabe eines existierenden Getränkes
 *
 */
double FrageLiter(unsigned int index, const std::vector<Getraenk>& Liste)
{
    double Liter;
    do
    {
        std::cout<<"Liter von "<<Liste.at(index-1).getName()<<": ";
        if(!(std::cin>>Liter) || Liter<0.0 || Liter>5.0)    //ungültige Eingabe
        {
            std::cout<<"FEHLER! Die Eingabe muss zwischen 0 und 5 liegen. Versuche es erneut."<<std::endl;
            Liter=-1.0;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (Liter==-1.0);
    return Liter;
}


/** \brief Fragt das Gewicht der Person ab.
 *
 * Fragt nach dem Gewicht der Person, welches zwischen 1kg und 400kg liegen muss.
 *
 * @return Das Gewicht der Person in Kg.
 * @pre Alkoholgewicht>0
 *
 */
double FrageGewicht()
{
    double Gewicht=0.0;
    do
    {
        std::cout<<"Wie viel Kg wiegst du (Dezimalstellen erlaubt)?: ";
        if(!(std::cin>>Gewicht) || Gewicht<1.0 || Gewicht>400.0)    //ungültige Eingabe
        {
            std::cout<<"FEHLER! Das Gewicht muss zwischen 1 und 400 liegen."<<std::endl;
            Gewicht=0.0;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while(Gewicht==0.0);
    return Gewicht;
}


/** \brief Fragt den Typ der Person ab und gibt den Promillewert aus.
 *
 * Fragt den Typ der Person (0 für Kind, 1 für Mann, 2 für Frau) ab und
 * erstellt das Objekt "Mensch" der Klasse Kind, Mann oder Frau.
 * Anschließend wird auf diesem der Wert der Funktion .Promille() ausgegeben.
 *
 * @param Alkoholgewicht des insgesamt getrunkenen Alkohols in Gramm.
 * @param Gewicht der Person in Kg.
 *
 */
void FrageTyp(double Alkoholgewicht, double Gewicht)
{
    unsigned int Typ;
    do
    {
        std::cout<<"Bist du ein Kind (0), Mann (1) oder Frau (2)?: ";
        if(!(std::cin>>Typ))    //Eingabe nicht unsigned int
        {
            Typ=3;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(Typ)
        {
        case 0:
            {
                Kind Mensch(Gewicht, Alkoholgewicht);
                std::cout<<"Ein Kind sollte NIEMALS Alkohol trinken!!!"<<std::endl;
                std::cout<<"Der THEORETISCHE Promillewert liegt bei: "<<Mensch.Promille()<<std::endl;
                break;
            }
        case 1:
            {
                Mann Mensch(Gewicht, Alkoholgewicht);
                std::cout<<"Promillewert bei einem Mann: "<<Mensch.Promille()<<std::endl;
                break;
            }
        case 2:
            {
                Frau Mensch(Gewicht, Alkoholgewicht);
                std::cout<<"Promillewert bei einer Frau: "<<Mensch.Promille()<<std::endl;
                break;
            }
        default:
            std::cout<<"FEHLER! Die Eingabe muss 0,1 oder 2 sein. Wiederhole deine Eingabe."<<std::endl;
        }
    }
    while (Typ>2);
}
