
/* Naloga 1:
 * Izpis najnižje in najvišje temperature zraka v (°C) za 11 krajev
 * */
#include <iostream>
// iomanip knjižnjica za uporabo setw
#include <iomanip>

using namespace std;

int main() {

    /* cout - izpis oz. prikaz na zaslonu.
     * setw(int število) - nastavi pirino izhodnega polja.
     * (primer: imamo izpisano število 123, nastavljeno širino polja pa 5. Izpisalo nam bo naše število in 2 prazni polji saj je naš niz 3 (3 števila).
     * left - poravnava našega polja na levo za lepši prikaz naše tabele :).
     * */
    cout << setw(30) << left << "Kraj"                   <<  setw(30) <<"Najnizja temp. zraka "       <<  setw(30) <<"Najvisja temp. zraka " << endl;
    cout << setw(30) << left << "Celje "                 <<  setw(30) << left << 12.5                 <<  setw(30) << left << 26.3 << endl;
    cout << setw(30) << left << "Crnomelj "              <<  setw(30) << left << 10.5                 <<  setw(30) << left << 27.2 << endl;
    cout << setw(30) << left << "Kredarica "             <<  setw(30) << left << 3.3                  <<  setw(30) << left << 11.3 << endl;
    cout << setw(30) << left << "Lisca "                 <<  setw(30) << left << 12.6                 <<  setw(30) << left << 20.8 << endl;
    cout << setw(30) << left << "Ljubljana "             <<  setw(30) << left << 15.3                 <<  setw(30) << left << 24.5 << endl;
    cout << setw(30) << left << "Murska Sobota "         <<  setw(30) << left << 12.4                 <<  setw(30) << left << 26.3 << endl;
    cout << setw(30) << left << "Novo mesto "            <<  setw(30) << left << 12.9                 <<  setw(30) << left << 25.7 << endl;
    cout << setw(30) << left << "Postojna "              <<  setw(30) << left << 13.8                 <<  setw(30) << left << 21.1 << endl;
    cout << setw(30) << left << "Slovenj Gradec "        <<  setw(30) << left << 6.8                  <<  setw(30) << left << 24.2 << endl;
    cout << setw(30) << left << "Bilje pri Novi Gorici " <<  setw(30) << left << 18.2                 <<  setw(30) << left << 23.5 << endl;
    cout << endl;
    cout<< "Link do povezave temperatur zraka za posamezne kraje:  https://meteo.arso.gov.si/met/sl/weather/observ/surface/tntx/" << endl;

    return 0;
}