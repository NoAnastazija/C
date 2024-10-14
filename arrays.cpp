#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cmath>

/*
a) Napišite program, ki v dvodimenzionalnem polju (uporaba std::vector ni dovoljena)
 vodi poimensko redovalnico za 3 sklope (KV, RV, VI) in končno oceno (OC) za 166 študentov.

b) V funkciji opravite generiranje podatkov, kjer so odstotki naključno generirana cela števila med 0 in 100.
 Polje nato izpišite.

 Za generiranje podatkov o imenih študentov izbirajte ime vsakokrat
 iz preddefiniranega polja 30 imen in 20 priimkov (posamezno ime je prav tako predstavljeno kot polje,
 vendar kot polje znakov - niz).  V tabeli za dodeljeno ime hranite le številko indeksa iz preddefiniranega polja.
 Če sta polno ime ali priimek sestavljena iz več besed, shranjujte te kot nize, ločene s presledkom
 (npr. Jose Daniel Hernandez Sosa => imena: "Jose Daniel" in priimki: "Hernandez Sosa").

c) Nato v dodatni funkciji vnesen seznam uredite padajoče glede na oceno.

d) Urejen seznam izpišite. Če je sklop RV<50 (vaje niso opravljene), namesto ocene izpišite niz "RV".
 Če je sklop VI<50 (vmesni izpiti niso opravljeni), namesto ocene izpišite niz "VI".
 Če sta sklopa RV<50 in VI<50 (vaje in vmesni izpiti niso opravljeni), namesto ocene izpišite niz "RV,VI".

e) Izračunajte še povprečje ocen (OC) vseh študentov, ki so izpit opravili in
 izpišite zaporedne številke študentov z oceno najbližje temu povprečju. Zaporedne številke so v razponu od 1 do 166.
 Določite uteži med sklopi KV, RV in VI (npr. vsak sklop je vreden tretjino ocene). Glede zaokroževanja: odstotke porežite po decimalkah (npr. 86,657% => 86%).

Primer:

Zaporedna številka	Ime in priimek	KV	RV	VI	OC
5	Mojca Golob	100	100	100	10
1	Janez Novak	60	60	60	7
6	Mitja Novak	60	60	60	7
4	Marcel Kos	50	50	50	6
2	Marija Krajnc	40	40	60	RV
3	Anže Novak	35	60	30	VI
Povprečna ocena študentov, ki so opravili izpit je 7,5 (najbližje pod zaporedno št.: 1, 6).

KRITERIJ OCENJEVANJA (za dosego nekega števila točk je potrebno rešiti vse, kar je zahtevano tudi za manj točk):
1 točka (a) - definicija polja primerne velikosti
2 točki - prenosi vrednosti parametrov polja v funkcije po referenci
3 točke (a-b) - naključno generiranje podatkov
4 točke (a-d) - urejanje po oceni:

če je RV<50, namesto ocene izpiše niz "RV"
če je VI<50, namesto ocene izpiše niz "VI"
če je RV<50 in VI<50, namesto ocene izpiše niz "RV,VI"
5 točk (a-e) - izračun povprečja ocen in izpis zaporednih številk študentov z oceno najbližje temu povprečju
 */
using namespace std;

string ime[30] = {"Anastasia", "Harry","Louis","Anna","Andrew","Steve","Brandon","Kate","Rose","Katheryn",
                  "Gabimaru","Aoi","Glenn","Fredrinn","Yuji","Shugen","Yuta","Yu Zhong","Mahito","Aza",
                  "Suguru", "Sakuna", "Nanami","Luo Yi","Toji","Yuji", "Satoru","Megumi","Nobara","Choso"};

string priimek[20] = {"Smith", "Yamada Asaemon","Okkotsu","Todo","Zenin","Geto","Chobei","Shinji","Norio","Kenichi",
                      "Yoshikazu","Masanori","Kamo","Mine","Shiko", "Fushiguro","Eiji","Kugisaki","Gojo","Itadori" };


void odstotki(int array[166][7]){

    srand(time(NULL));
    for(int i=0; i<166; i++){
        //i is student, column is the data
        array[i][0] = (i + 1); // student id (1-166)
        array[i][1] = rand()%30; // 0-29, index  ime
        array[i][2] = rand()%20; // priimek
        array[i][3] = (rand()%100);
        array[i][4] = (rand()%100);
        array[i][5] = (rand()%100); // KV, RV, IV
        array[i][6] = (array[i][3] + array[i][4] + array[i][5]) / 3; //30+1 final grade
    }
   /* srand(time(NULL));

    for(int i=0;i<166;i++){
        array[i][1] = rand()%100;
    }


    for(int i=0; i<166; i++){
        cout<<array[i][1];
        cout<<", ";
    }


    /*
    for(int i=0; i<166; i++) {
       cout<< rand() % (101 - 0) + 0;
       cout<<", ";
    }
*/
}

void padajoce(int array[166][7]){
    // Sort students based on their final grades
    int temp;
    for(int i=0; i<166; i++){
        for(int j=i+1; j<166; j++){

            if(array[j][6]> array[i][6]){
                for(int x=0; x<7; x++){
                    temp = array[j][x];
                    array[j][x] = array[i][x];
                    array[i][x] = temp;
                }
            }
        }
    }
}

// Information about each student, average grade
void izpis(int array[166][7]){
    int vsota = 0;
    int st = 0;
    for(int i=0;i<166;i++){
        for(int j=0;j<7;j++){
            if(j==1){
                cout<<ime[array[i][j]]<<" ";
            }
            else if(j==2){
                cout<<priimek[array[i][j]]<<"   ";
            }
            else if(j==6){
                if(array[i][4] < 50 && array[i][5] < 50){
                    cout<<"RV, VI";
                }
                else if(array[i][4]<50){
                    cout<<"RV";
                }
                else if(array[i][5]<50){
                    cout<<"VI";
                }
                else{
                    cout<<array[i][j];
                    vsota = array[i][j]+vsota;
                    st++;
                }
            }
            else{
                cout<<array[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    float avg = float(vsota) / st;
    float avgr = float(avg * 100)/100;
    float polje[166];
    for(int i=0;i<166;i++){
        polje[i] = abs(array[i][6]- avgr);
    }
    for(int i=0; i<166; i++){
        for(int j=i+1; j<166; j++){
            if(polje[i]>polje[j]){
                float temp = polje[i];
                polje[i] = polje[j];
                polje[j] = temp;
            }
        }
    }
    cout<<endl;
    cout<<"Povprecje ocene ucencev, ki so naredili izpit je: "<<avgr;

    for(int k=0; k<166; k++){
        if((array[k][4] > 50) && (array[k][5] > 50)){
            if(abs((array[k][6] - avgr)) <= polje[0]){
                cout<<array[k][0] << ", ";
            }
        }
    }
    cout<<endl;

}


int main() {




/*
    for(int i=0; i<30; i++){
        cout<<ime[i];
        cout<<", ";
    }
    cout<<endl;
    for(int i=0; i<20; i++){
        cout<<priimek[i];
        cout<<", ";
    }




int array[166][1];
    odstotki(array[166][1]);
*/
    int tabela[166][7];
    odstotki(tabela);
    padajoce(tabela);
    izpis(tabela);
    return 0;
}
