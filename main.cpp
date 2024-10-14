#include <iostream>
#include <cmath>
/*
Write a program that will enable the calculation of how many cars can be produced. The program allows you to enter three numbers, namely:

the number of wheels
the number of frameworks
the number of side mirrors
        Four wheels, one frame and two side mirrors are needed to make one car.

Based on the entered values, the program should print out how many cars can be produced.
Print the minimum amount of individual parts that we still need to use up all the material.
Example:
Number of wheels: 55
Number of frames: 24
Number of side mirrors: 32
Number of possible cars: 13
We are left with:

Number of wheels: 3
Number of frames: 11
Number of side mirrors: 6
You still need to purchase:

Number of wheels: 41
Number of frameworks: 0
Number of side mirrors: 16
Program Requirements:
Write a program that asks the user for three integers as long as the given numbers are not positive (use a do while loop).

Calculate and print the number of cars that can be made, the number of parts we have left, and the minimum amount of missing individual parts we need to make so many cars that we have no parts left.

Example program:
Input number of wheels: 55

Input number of bodies: 24

Input number of mirrors: 32

Number of possible cars: 13

We still have:
Number of wheels: 3
Number of bodies: 11
Number of mirrors: 6

We need additional parts:
Number of wheels: 41
Number of bodies: 0
Number of mirrors: 16
*/

// FUNCTION PROTOTYPES
void minimumPossible(int wheelCounter, int bodyCounter, int mirrorCounter, int wheels, int bodies, int mirrors);
void leftoverMaterial(int leftoverWheels, int leftoverBodies, int leftoverMirrors, int wheels, int bodies, int mirrors);
void maximumLeftovers(int wheelsLeft, int bodiesLeft, int mirrorsLeft);
void totalCost(float Wheels, float Bodies, float Mirrors);

using namespace std;

// WHOLE NUMBER
void inputNumbers(int& wheels, int& bodies, int& mirrors){
    do{
        cout<<"Write a whole positive number for number of WHEELS: ";
        cin>>wheels;
    }while(wheels < 0 );

    cout<<endl;
    do{
        cout<<"Write a whole positive number for number of BODIES: ";
        cin>>bodies;
    }while(bodies < 0);

    cout<<endl;
    do{
        cout<<"Write a whole positive number of MIRRORS: ";
        cin>>mirrors;
    }while(mirrors < 0);

    cout<<endl;
    cout<<"We have this many WHEELS: "<<wheels<<endl;
    cout<<"We have this many BODIES: "<<bodies<<endl;
    cout<<"We have this many MIRRORS: "<<mirrors<<endl;
    cout<<endl;
}

// COUNT HOW MANY POSSIBLE CARS OF EACH
void counter(int wheels, int bodies, int mirrors){
    int wheelCounter = 0;
    while(wheels >= 4){
        wheelCounter++;
        wheels = wheels - 4;
    }

    int bodyCounter = 0;
    while(bodies >= 1){
        bodyCounter++;
        bodies = bodies - 1;
    }

    int mirrorCounter = 0;
    while(mirrors >= 2){
        mirrorCounter++;
        mirrors = mirrors - 2;
    }

    cout<<"Wheel car possibility: "<<wheelCounter<<endl;
    cout<<"body car possibility: "<<bodyCounter<<endl;
    cout<<"mirror car possibility: "<<mirrorCounter<<endl;
    cout<<endl;

    minimumPossible(wheelCounter, bodyCounter, mirrorCounter, wheels, bodies, mirrors);
}

void profit(int counter){
    float cars;
    cars = (counter) * 7;
    float oneCarWheel = 4 * 0.30;
    float oneCarBody = 1 * 1.80;
    float oneCarMirror =  2 * 0.15;

    float allMaterial = (oneCarWheel + oneCarBody + oneCarMirror) * counter;
    float total;
    total = cars - allMaterial;
    cout<<"Profit for our made cars is: "<<total<<"eur"<<endl;
}

// MINIMUM CARS POSSIBLE
void minimumPossible(int wheelCounter, int bodyCounter, int mirrorCounter, int wheels, int bodies, int mirrors) {
    int leftoverBodies = 0;
    int leftoverWheels = 0;
    int leftoverMirrors = 0;

    if (wheelCounter <= bodyCounter && wheelCounter <= mirrorCounter) {
        // quaranteed cars
        cout << "Number of possible cars: " << wheelCounter << endl;
        profit(wheelCounter);

        // cars to materials
        leftoverBodies = (bodyCounter - wheelCounter) * 1;
        leftoverWheels = (wheelCounter - wheelCounter) * 4;
        leftoverMirrors = (mirrorCounter - wheelCounter) * 2;

    } else if (bodyCounter <= wheelCounter && bodyCounter <= mirrorCounter) {
        cout << "Number of possible cars: " << bodyCounter << endl;
        profit(bodyCounter);

        leftoverBodies = (bodyCounter - bodyCounter) * 1;
        leftoverWheels = (wheelCounter - bodyCounter) * 4;
        leftoverMirrors = (mirrorCounter - bodyCounter) * 2;

    } else if (mirrorCounter <= wheelCounter && mirrorCounter <= bodyCounter) {
        cout << "Number of possible cars: " << mirrorCounter << endl;
        profit(mirrorCounter);

        leftoverBodies = (bodyCounter - mirrorCounter) * 1;
        leftoverWheels = (wheelCounter - mirrorCounter) * 4;
        leftoverMirrors = (mirrorCounter - mirrorCounter) * 2;

    }else {
        cout << "Something is wrong " << endl;
    }

    leftoverMaterial(leftoverWheels, leftoverBodies, leftoverMirrors, wheels, bodies, mirrors);
}



// LEFTOVERS CALCULATE
void leftoverMaterial(int leftoverWheels, int leftoverBodies, int leftoverMirrors, int wheels, int bodies, int mirrors) {
    // from these leftovers. wheels from counter/minimum
    int wheelsLeft = leftoverWheels + wheels;
    int bodiesLeft = leftoverBodies + bodies;
    int mirrorsLeft = leftoverMirrors + mirrors;

    cout<<"Leftovers for wheels: "<< wheelsLeft <<endl;
    cout<<"Leftovers for bodies: "<< bodiesLeft <<endl;
    cout<<"Leftovers for mirrors: "<< mirrorsLeft <<endl;
    cout<<endl;

    maximumLeftovers(wheelsLeft, bodiesLeft, mirrorsLeft);
}

// LOOK FOR MAXIMUM AND HOW MANY MATERIAL WE NEED LEFT
void maximumLeftovers(int wheelsLeft, int bodiesLeft, int mirrorsLeft) {
    // Possible cars
    float maxWheelCars = (float) wheelsLeft / 4;
    float maxMirrorCars = (float) mirrorsLeft / 2;
    float maxBodyCars = (float) bodiesLeft / 1;

    int Wheels = 0;
    int Bodies = 0;
    int Mirrors = 0;

/*
    cout<<"+ 0.5"<<endl;
    cout<<ourMirrors<<endl;
    cout<<ourMirrors<<endl;
    cout<<ourBodies<<endl;


    ourWheels = round(ourWheels);
    ourBodies = round(ourBodies);
    ourMirrors = round(ourMirrors);

    cout<<"After rounding"<<endl;
    cout<<ourMirrors<<endl;
    cout<<ourMirrors<<endl;
    cout<<ourBodies<<endl;*/
   /*round(ourWheels = (int) (ourWheels + (float) 0.5));
    round(ourBodies = (int) (ourBodies + (float) 0.5));
    round(ourMirrors = (int) (ourMirrors + (float) 0.5));
*/



   /* ourWheels = round(ourWheels);
    ourBodies = round(ourBodies);
    ourMirrors = round(ourMirrors);*/

    if (maxWheelCars >= maxBodyCars && maxWheelCars >= maxMirrorCars && maxWheelCars > 0) {


        cout << "Number of maximum cars from leftover material: " << maxWheelCars << endl;
       // maxWheelCars = (float)(maxWheelCars + (float) 0.5);
        maxWheelCars = round(maxWheelCars);

       // maxBodyCars = (float)(maxBodyCars + (float) 0.5);
        maxBodyCars = round(maxBodyCars);

        //maxMirrorCars = (float)(maxMirrorCars + (float) 0.5);
        maxMirrorCars = round(maxMirrorCars);

if(maxWheelCars == 0){
    maxWheelCars++;
}

        /*if (ourWheels <= 0) {
            ourWheels = 0;
            ourMirrors = 0;
            ourBodies = 0;*/

           /* Wheels = (maxWheelCars * 4) - wheelsLeft;
            Mirrors = (maxWheelCars *)
            */

           // Wheels = (wheelsLeft * 4) - maxWheelCars;
           Wheels = (maxWheelCars * 4) - wheelsLeft;
           Bodies = (maxWheelCars * 1) - bodiesLeft;
           Mirrors = (maxWheelCars * 2) - mirrorsLeft;
          /*  Bodies = (maxWheelCars - maxBodyCars) * 1;
            Mirrors = (maxWheelCars - maxMirrorCars) * 2;*/


           /* Wheels = (maxWheelCars * 4) - maxWheelCars;
            Mirrors = (maxWheelCars - maxMirrorCars) * 2;
            Bodies = (maxWheelCars - maxBodyCars) * 1;*/


    } else if (maxBodyCars >= maxMirrorCars && maxBodyCars >= maxWheelCars && maxBodyCars > 0) {
        //int targetCars = (int)((float)ourBodies + (float)0.5);
        cout << "Number of maximum cars from leftover material: " << maxBodyCars << endl;
       // maxWheelCars = (float)(maxWheelCars + (float) 0.5);
        maxWheelCars = round(maxWheelCars);

       // maxBodyCars = (float)(maxBodyCars + (float) 0.5);
        maxBodyCars = round(maxBodyCars);

       // maxMirrorCars = (float)(maxMirrorCars + (float) 0.5);
        maxMirrorCars = round(maxMirrorCars);
        if(maxBodyCars == 0){
            maxBodyCars++;
        }
        /*if( ourBodies <= 0){
            ourWheels = 0;
            ourMirrors = 0;
            ourBodies = 0;
        }*/



        Wheels = (maxBodyCars * 4) - wheelsLeft;
        Bodies = (maxBodyCars * 1) - bodiesLeft;
        Mirrors = (maxBodyCars * 2) - mirrorsLeft;

/*
        Wheels = (maxBodyCars - maxWheelCars) * 4;
       // Bodies = (maxBodyCars - maxBodyCars) * 1;
        Bodies =  (maxBodyCars * 1) - wheelsLeft;
        Mirrors = (maxBodyCars - maxMirrorCars) * 2;*/


    } else if (maxMirrorCars >= maxBodyCars && maxMirrorCars >= maxWheelCars && maxMirrorCars > 0) {
        //int targetCars = (int)(ourMirrors + (float)0.5);
        cout << "Number of maximum cars from leftover material: " << maxMirrorCars<< endl;
       // maxWheelCars = (float)(maxWheelCars + (float) 0.5);
        maxWheelCars = round(maxWheelCars);

      //  maxBodyCars = (float)(maxBodyCars + (float) 0.5);
        maxBodyCars = round(maxBodyCars);

       // maxMirrorCars = (float)(maxMirrorCars + (float) 0.5);
        maxMirrorCars = round(maxMirrorCars);

        if(maxMirrorCars == 0){
            maxMirrorCars++;
        }
        /* if(ourMirrors <= 0){
             ourWheels = 0;
             ourMirrors = 0;
             ourBodies = 0;
         }*/
        // if(ourMirrors >= 0){

        Wheels = (maxMirrorCars * 4) - wheelsLeft;
        Bodies = (maxMirrorCars * 1) - bodiesLeft;
        Mirrors = (maxMirrorCars * 2) - mirrorsLeft;
/*
        Wheels = (maxMirrorCars - maxWheelCars) * 4;
        Bodies = (maxMirrorCars - maxBodyCars) * 1;
        //Mirrors = (maxMirrorCars - maxMirrorCars) * 2;
        Mirrors = (maxMirrorCars * 2) - mirrorsLeft;

*/
    }

 else {
        cout << "Something is wrong " << endl;
    }
    cout<<"We need this more wheels: "<< Wheels <<endl;
    cout<<"We need this more bodies: "<< Bodies <<endl;
    cout<<"We need this more mirrors: "<< Mirrors <<endl;
    cout<<endl;

    totalCost(Wheels, Bodies, Mirrors);
}

void totalCost(float Wheels, float Bodies, float Mirrors) {
    float costWheels = Wheels * 0.30;
    float costBodies = Bodies * 1.80;
    float costMirrors = Mirrors * 0.15;

    float total = costWheels + costBodies + costMirrors;
    cout<<"Cost of necessary material is: "<<total<<endl;
}

int main() {
    int wheels;
    int bodies;
    int mirrors;

    inputNumbers(wheels, bodies, mirrors);
    counter(wheels, bodies, mirrors);
    return 0;
}
