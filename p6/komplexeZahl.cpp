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
