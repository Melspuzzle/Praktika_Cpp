#include "komplexeZahl.h"
using namespace std;

komplexeZahl::komplexeZahl()
{
    realerTeil = 0;
    komplexerTeil = 0;
}

komplexeZahl::~komplexeZahl() {}

komplexeZahl komplexeZahl::operator+(const komplexeZahl &z)
{
    komplexeZahl zTemp;
    zTemp.komplexerTeil = komplexerTeil + z.komplexerTeil;
    zTemp.realerTeil = realerTeil + z.realerTeil;
    return zTemp;
}

komplexeZahl komplexeZahl::operator-(const komplexeZahl &z)
{
    komplexeZahl zTemp;
    zTemp.komplexerTeil = komplexerTeil - z.komplexerTeil;
    zTemp.realerTeil = realerTeil - z.realerTeil;
    return zTemp;
}
komplexeZahl komplexeZahl::operator*(const komplexeZahl &z)
{
    komplexeZahl zTemp;
    // Formel für komplexe Multiplikation: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
    zTemp.realerTeil = (realerTeil * z.realerTeil) - (komplexerTeil * z.komplexerTeil);
    zTemp.komplexerTeil = (realerTeil * z.komplexerTeil) + (komplexerTeil * z.realerTeil);
    return zTemp;
}
komplexeZahl komplexeZahl::operator/(const komplexeZahl &z)
{
    komplexeZahl zTemp;
    // Formel für komplexe Division: (a+bi) / (c+di)
    float nenner = (z.realerTeil * z.realerTeil) + (z.komplexerTeil * z.komplexerTeil);

    // Das Abfangen der Division durch 0 wird jetzt hauptsächlich in der main.cpp gemacht,
    // diese Prüfung hier dient als zusätzliche Sicherheit, falls die Funktion woanders direkt aufgerufen wird.
    if (nenner == 0) {
        zTemp.realerTeil = 0;
        zTemp.komplexerTeil = 0;
        return zTemp;
    }

    zTemp.realerTeil = ((realerTeil * z.realerTeil) + (komplexerTeil * z.komplexerTeil)) / nenner;
    zTemp.komplexerTeil = ((komplexerTeil * z.realerTeil) - (realerTeil * z.komplexerTeil)) / nenner;
    return zTemp;
}
void komplexeZahl::setKomplexerTeil(float num)
{
    komplexerTeil = num;
}
void komplexeZahl::setRealterTeil(float num)
{
    realerTeil = num;
}

float komplexeZahl::getKomplexerTeil()
{
    return komplexerTeil;
}
float komplexeZahl::getRealterTeil()
{
    return realerTeil;
}
