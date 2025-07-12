#include "komplexeZahl.h"
#include <iostream>
#include <stdio.h>

void calculator(string input);
bool checkIfFloat(string *p_input);
int main(void)
{
    string input;
    string yes = "y";
    string no = "n";
    bool status = false;
    cout << "Moechtest du eine Berechnung von zwei komplexen Zahlen durchfuehren? "
         << yes << " / " << no << endl;
    cin >> input;
    cin.clear();

    if (input == yes)
    {
        status = true;

        while (status == true)
        { // mehrfache Ausführung von Berechnungen möglich
            // Programmstart implementieren
            calculator(input);

            cout << "Moechtest du erneut eine Berechnung vornehmen? " << yes << " / "
                 << no << endl;
            cin >> input;
            if (input == no)
            {
                status = false;
                cout << "Alles klar, Tschuess!" << endl;
                getchar();
                return (0);
            }
        }
    }
    else if (input == no)
    {
        cout << "Alles klar, Tschuess!" << endl;
        getchar();
        return (0);
    }
    else
    {
        cout << "Keine gueltige Eingabe, starte das Programm erneut." << endl;
        getchar();
        return (0);
    }
}

void calculator(string input)
{
    // initialisiere Objekt
    komplexeZahl z1, z2, z3;
    float resultKom, resultReal;
    char calcMethode;
    string *p_input = &input;
    cout << "Gebe den realen Teil der ersten Zahl fuer die Berechnung ein" << endl;
    while (!checkIfFloat(p_input))
    {
    }
    z1.setRealterTeil(stof(*p_input));
    cout << "Gebe den komplexen bzw. imaginaeren Teil der ersten Zahl fuer die Berechnung ein" << endl;
    while (!checkIfFloat(p_input))
    {
    }
    z1.setKomplexerTeil(stof(*p_input));
    cout << "Gebe den realen Teil der zweiten Zahl fuer die Berechnung ein" << endl;
    while (!checkIfFloat(p_input))
    {
    }
    z2.setRealterTeil(stof(*p_input));
    cout << "Gebe den komplexen bzw. imaginaeren Teil der zweiten Zahl fuer die Berechnung ein" << endl;
    while (!checkIfFloat(p_input))
    {
    }
    z2.setKomplexerTeil(stof(*p_input));
    cout << "Mit welchem Operator moechtest du rechnen? + - / * " << endl;
    cin >> calcMethode;
    // calculation
    switch (calcMethode)
    {
    case '+':
        z3 = z1 + z2; // Funktionsaufruf durch + von z1
        break;

    case '-':
        z3 = z1 - z2; // Funktionsaufruf durch - von z2
        break;
    default:
        cout << "Falscher Eingabewert, Berechnung nicht möglich" << endl;
    }
    resultKom = z3.getKomplexerTeil();
    resultReal = z3.getRealterTeil();

    cout << "Dein Ergebnis lautet: Realter Teil:" << resultReal << " Komplexer Teil:" << resultKom << "" << endl;
    return;
};

bool checkIfFloat(string *p_input)
{
    try
    {
        cin >> *p_input;
        float tmpFloat = stof(*p_input);
        return true;
    }
    catch (const invalid_argument)
    {
        cout << "Bitte gebe eine gueltige Zahl ein" << endl;
        return false;
    }
};