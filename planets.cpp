#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;


void izris_premagane_poti(float s0, float s, int N, string planet) {
    int n = s / s0 * 100;
    int primerjava = 0;
    cout << "Premagana pot planets: "<<planet<<" je: " << n << "%"<<endl;
    while (primerjava < N) {
        for (int i = 0; i < 100; i++) {
            if (i <= n) {
                cout << "*";
            } else {
                cout << ".";
            }
        }
        cout << endl;
        primerjava++;
    }
}
/*
void izris_kvadrata(float planet, float s0, float s, int k, int N){
    int n = s/s0 * 100;
    cout<<planet<<" "<<k<<"("<<n<<"%)"<<endl;
    for(int i=0;i<N;i++){
        izris_poti(n);
    }
}

*/
int main() {
    float radij, cas_opazovanja, obhodni_cas;
    string planet;
    float Pi = 3.14;

    // t0
    cout << "Napisi cas opazovanja v dnevih za vse planete: ";
    cin >> cas_opazovanja;
    cout << endl;

    int N;
    cout << "Stevilo vrstic za planete: ";
    cin >> N;


    for (int j = 1; j < 10; j++) {
        //saturn = 928.54 a.e
        cout << "Napisi ime planeta "<<j<<": ";
        cin >> planet;

        cout << "Napisi radij poljubnega planeta (a.e): ";
        cin >> radij;
        cout << endl;


        // saturn = 29,46l t
        cout << "Napisi obhodni cas: ";
        cin >> obhodni_cas;
        cout << endl;


        float obhod;
        obhod = 2 * Pi * radij;

        float krozna_hitrost;
        krozna_hitrost = (2 * Pi * radij) / obhodni_cas;

        float manjkajoca_pot;
        cout << "Vase vrednosti so: " << radij << ", " << cas_opazovanja << ", " << obhodni_cas << endl;
        manjkajoca_pot = obhod - (cas_opazovanja * krozna_hitrost);

        cout << "Manjkajoca pot: " << manjkajoca_pot << " = " << obhod << " - " << manjkajoca_pot << " * "
             << krozna_hitrost << endl;


        float s = 2 * Pi * radij * obhodni_cas / cas_opazovanja;
        float s0 = 2 * Pi * radij;


        float st;
        cout << "Obhod je: " << obhod << endl;
        if (cas_opazovanja >= obhodni_cas) {
            st = cas_opazovanja / obhodni_cas;
            cout << "Planet je naredil toliko obhodov: " << st << endl;
        } else {
            cout << "Planet ni naredil še nobenega obhoda." << endl;
        }

        /*for (int i = 0; i < 5; i++) {
            cout << "Vnesi ime planeta: ";
            cin >> planet;

            float s = krozna_hitrost * obhodni_cas;
        }*/
        izris_premagane_poti(s0, s, N, planet);
    }
    return 0;
}