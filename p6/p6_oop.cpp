#include "komplexeZahl.h"
#include <iostream>
#include <string>
#include <limits>

float getFloatInput();
void calculator();

int main(void)
{
    string input;
    string yes = "y";
    string no = "n";

    while (true)
    {
        cout << "Moechtest du eine Berechnung von zwei komplexen Zahlen durchfuehren? ("
             << yes << "/" << no << ")" << endl;
        cin >> input;

        // Eindeutige Abfrage auf 'y'
        if (input == yes)
        {
            calculator();
        }
        // Eindeutige Abfrage auf 'n'
        else if (input == no)
        {
            cout << "Alles klar, Tschuess!" << endl;
            break;
        }
        // Alles andere ist eine ungültige Eingabe
        else
        {
            cout << "Keine gueltige Eingabe, bitte nur '" << yes << "' oder '" << no << "' verwenden." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

void calculator()
{
    komplexeZahl z1, z2, z3;
    char calcMethode;
    cout << "Gebe den realen Teil der ersten Zahl ein:" << endl;
    z1.setRealterTeil(getFloatInput());

    cout << "Gebe den imaginaeren Teil der ersten Zahl ein:" << endl;
    z1.setKomplexerTeil(getFloatInput());

    // Schleife für die Eingabe der zweiten Zahl, um Division durch Null zu verhindern
    while (true)
    {
        cout << "Gebe den realen Teil der zweiten Zahl ein:" << endl;
        z2.setRealterTeil(getFloatInput());

        cout << "Gebe den komplexen bzw. imaginaeren Teil der zweiten Zahl ein:" << endl;
        z2.setKomplexerTeil(getFloatInput());

        cout << "Mit welchem Operator moechtest du rechnen? [+, -, /, *]" << endl;
        cin >> calcMethode;

        if (calcMethode == '/' && z2.getRealterTeil() == 0 && z2.getKomplexerTeil() == 0)
        {
            cout << "Fehler: Division durch Null ist nicht erlaubt. Bitte gib die zweite Zahl erneut ein." << endl;
            // Die Schleife wird fortgesetzt, um eine neue Eingabe zu erhalten
        }
        else
        {
            break;
        }
    }

    switch (calcMethode)
    {
    case '+':
        z3 = z1 + z2;
        break;
    case '-':
        z3 = z1 - z2;
        break;
    case '/':
        z3 = z1 / z2;
        break;
    case '*':
        z3 = z1 * z2;
        break;
    default:
        cout << "Keine Operator Eingabe, Berechnung nicht möglich." << endl;
        return;
    }
    cout << "Dein Ergebnis lautet: " << z3.getRealterTeil() << " + (" << z3.getKomplexerTeil() << ")i" << endl
         << endl;
}

// input eingabe auf float checken
float getFloatInput()
{
    float number;
    while (!(cin >> number))
    {
        cout << "Ungueltige Eingabe. Bitte eine gueltige Zahl eingeben:" << endl;
        cin.clear();
        // Den restlichen Inhalt der Zeile aus dem Eingabepuffer verwerfen
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /* Ohne cin.ignore(...) würde die while-Schleife endlos weiterlaufen, da sie bei jedem Durchlauf erneut versuchen
        würde, dieselbe ungültige Eingabe zu lesen. Diese Zeile sorgt dafür, dass der fehlerhafte Rest der Zeile aus dem
        Puffer "ignoriert" oder "verworfen" wird, sodass der Benutzer eine neue Eingabe tätigen kann. Die
        <limits>-Bibliothek wird verwendet, um sicherzustellen, dass der gesamte Puffer geleert wird, unabhängig davon,
        wie viele Zeichen eingegeben wurden.*/
    }
    return number;
}
