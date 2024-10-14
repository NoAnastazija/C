#include <iostream>
#include <cmath>

using namespace std;
/*
int main() {
    int stevilo;
    cout<<"Vnesi stevilo: "<<endl;
    cin>>stevilo;
    for(int i=stevilo-1; i>1; i--){
        if(stevilo % i == 0 || stevilo <= 1){
            cout<<"Ni prastevilo";
            return 0;
        }
    }
    cout<<"Je prastevilo";
    return 0;
}
*/

  /*Napišite funkcijo, ki za podano celo število vrne logično vrednost, ali je število praštevilo (testirajte delitelje).
 * Pazite na to, da negativna števila, 0 in število 1 niso praštevila.*/
bool prastevilo(int stevilo) {

    if (stevilo <= 1) {
        cout << "Ni prastevilo" << endl;
        return false;
    } else {
        for (int i = 2; i <= stevilo / 2; i++) {
            if (stevilo % i == 0) {
                cout << "Ni prastevilo" << endl;
                return false;
            }
        }
        cout << "Je prastevilo" << endl;
        return true;
    }
}

// Napišite še funkcijo, ki izračuna in vrne vsoto vseh praštevil na intervalu med -256 in 512.
int vsota(){
    int vsota=0;
    const int a= -256;
    const int b= 512;

    for (int c = a; c <= b; ) {
        if (c <= 1) {
            c++;
        } else {
            bool je_prastevilo = true;
            for (int i = 2; i <= c / 2; i++) {
                if (c % i == 0) {
                    je_prastevilo = false;
                    break;
                }
            }

            if (je_prastevilo) {
                cout<<c<<endl;
                vsota += c;
            }
            c++;
        }
    }
    cout << "Vsota prastevil na tem intervalu je: " << vsota<<endl;
    return vsota;
}
/*Napišite še funkcijo, ki ima dva parametra, prvi je polje velikosti 20, drugi je celo število.
  Funkcija v to podano polje shrani prvih 20 praštevil, ki so večja od podanega števila v drugem parametru.
 Nato v tej funkciji izračunajte še povprečno vrednost teh praštevil in jo vrnite kot rezultat s stavkom return.*/
float povprecje(int prastevilo_array[20], int n) {
    int i = 0;
    int vsota = 0;
    int trenutno_stevilo = n + 1;

    while (i < 20) {
        if (prastevilo(trenutno_stevilo)) {
            prastevilo_array[i] = trenutno_stevilo;
            vsota += trenutno_stevilo;
            i++;
        }
        trenutno_stevilo++;
    }

    cout<<"Vsota: "<<vsota;
    if (i == 0) {
        cout << "Povprecna vrednost prvih 20 prastevil vecjih od " << n << ": " << 0 << endl;
    } else {
        cout << "Povprecna vrednost prvih 20 prastevil vecjih od " << n << ": " << vsota / 20 << endl;
    }

    return vsota / 20;
}

/* * V glavnem programu uporabnik najprej vnese števili potrebni za klic prve in tretje funkcije.
 * Nato uporabnik vnese neko novo število in po klicu tretje funkcije izpišite najmanjše praštevilo iz podanega polja, ki je najbližje kubičnemu korenu tega števila.
 * Pred definicijo teh treh funkcij deklarirajte njihov predpis (prototip funkcije), prikažite uporabo vseh definiranih funkcij.
 * Ne uporabljajte globalnih spremenljivk. Te tri zahtevane funkcije naj ne berejo in pišejo na zaslon, ampak to opravite v glavnem programu.*/
int main() {
    int stevilo;
    int prastevilo_array[20];
    int n;

    cout << "Vpisi poljubno stevilo: ";
    cin >> stevilo;
    cout<<endl;
    cout << "Vpisi drugo stevilo: ";
    cin>>n;

    vsota();
    povprecje(prastevilo_array, n);
    prastevilo(stevilo);

    int novo;
    cout<<endl;
    cout<<"Vpisi novo stevilo: ";

    cin>>novo;
    cout<<endl;


    double kubicni_koren = cbrt((novo));

   //Bubble sort
    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - i - 1; j++) {
            if (prastevilo_array[j] > prastevilo_array[j + 1]) {
                int temp = prastevilo_array[j];
                prastevilo_array[j] = prastevilo_array[j + 1];
                prastevilo_array[j + 1] = temp;
            }
        }
    }

    int najblizje_prastevilo = prastevilo_array[0];
    int min = abs(prastevilo_array[0] - kubicni_koren);

    for (int i = 1; i < 20; i++) {
        int diff = abs(prastevilo_array[i] - kubicni_koren);
        if (diff < min) {
            min = diff;
           najblizje_prastevilo= prastevilo_array[i];
        }
    }

    cout << "Najmanjse prastevilo iz polja, ki je najblizje kubicnemu korenu novega stevila: " << najblizje_prastevilo << endl;



    return 0;
}
