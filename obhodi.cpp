#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float radij, cas_opazovanja, obhodni_cas;
    float Pi = 3.14;

    //saturn = 928.54 a.e
    cout<<"Napisi radij poljubnega planeta (a.e): ";
    cin>>radij;
    cout<<endl;

    cout<<"Napisi cas opazovanja zanj: ";
    cin>>cas_opazovanja;
    cout<<endl;

    // saturn = 29,46l
    cout<<"Napisi obhodni cas: ";
    cin>>obhodni_cas;
    cout<<endl;

    float obhod;
    obhod = 2 * Pi * radij;

    float krozna_hitrost;
    krozna_hitrost = (2 * Pi * radij) / obhodni_cas;

    float manjkajoca_pot;
    cout<<"Vase vrednosti so: "<<radij<<", "<<cas_opazovanja<<", "<<obhodni_cas<<endl;
    manjkajoca_pot = obhod - (cas_opazovanja * krozna_hitrost);

    cout<<manjkajoca_pot<<" = "<<obhod<<" - "<<manjkajoca_pot<<" * "<<krozna_hitrost<<endl;
    float st;
    cout<<"Obhod je: "<<obhod<<endl;
    if(cas_opazovanja >= obhodni_cas){
        st = cas_opazovanja / obhodni_cas;
        cout<<"Planet je naredil toliko obhodov: "<<st<<endl;}
    else{
        cout<<"Planet ni naredil še nobenega obhoda."<<endl;
    }


    return 0;
}