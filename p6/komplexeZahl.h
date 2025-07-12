#include <string>
using namespace std;

class komplexeZahl
{
private:
    /* data */
    float realerTeil;
    float komplexerTeil;

public:
    komplexeZahl();
    ~komplexeZahl();
    void setKomplexerTeil(float);
    void setRealterTeil(float);
    float getKomplexerTeil();
    float getRealterTeil();
    komplexeZahl operator+(const komplexeZahl &);
    komplexeZahl operator-(const komplexeZahl &);
};