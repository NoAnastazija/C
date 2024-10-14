#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>

/*
 * 2024: Assignment 1.1 (required)
Working with a field:

1. Study and use the example.
2. Modify the program so that 20 random numbers to two decimal places of exact numbers between 0.50 and 150.00 are entered into the field.
 The values represent the cost price in € for an individual purchase.
3. Complete the program by printing the rounded values of the cost prices to the nearest whole number (e.g. instead of 55.78, 56 is printed).
 It is not allowed to use existing functions that round values, such as e.g. round().
4. Complete the program by printing the average cost price.
5. Complete the program by printing the minimum cost price.
6. Write how many times the purchase amount was higher than €100.

The finished task must have 6 choices in the menu + a choice to exit the program.
 Each choice must be implemented in its own function (similar to the example shown for generation and output).
 In the main program, you only call these functions when you select them in the menu.
 Functions should return values (eg average price), output should be in the menu (unless functions are expected to output, such as printArray).
Help with generating random numbers:
std::rand
std::random_device
 */

using namespace std;

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1 ... GENERATE EXPENSES" << endl;
    cout << "2 ... PRINT EXPENSES" << endl;
    cout << "3 ... PRINT ROUNDED EXPENSES" << endl;
    cout << "4 ... PRINT AVERAGE COST PRICE" << endl;
    cout << "5 ... PRINT MINIMUM COST PRICE" << endl;
    cout << "6 ... PRINT COUNT WHEN PURCHASE AMOUNT WAS HIGHER THAN 100eur" << endl;
    cout << "7 ... SORT ELEMENTS FROM HIGHEST TO LOWEST NUMBER" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

//two decimal places = multiply it by 100, truncate to integer then divide by 100
void fillArray(double* array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        // array[i] = floor(100 * array[i]) / 100;//rand()/(150.00f - 0.50f) + 150.00f; // 0.5f + i;
        //   double r = (rand() / ( double )RAND_MAX) * (upper - lower) + lower
        array[i] = 0.50 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) / (150.00 - 0.50));
        array[i] = floor(array[i] * 100 + 0.5) / 100.0;

        //array[i] = ((rand() % 14951 + 50) / 100.0;
        // max - min + 1
        // 15000 - 50 + 1
    }
}

void printArray(const double* array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout <<array[i]<<"eur"<< endl;
    }

}

// increase by 0.5, f to specify float
void getRoundedArray(const double* array, const unsigned int size){
    for (unsigned int i = 0; i < size; i++) {
        int roundedNumber = (int)(array[i] + (double)0.5);
        cout<<"Rounded numbers: "<<roundedNumber<<endl;

    }
}

double getAverage(const double* array, const unsigned int size) {
    double sum = 0;
    double average;
    for(unsigned int i=0; i < size; i++){
        sum = sum + array[i];
    }
    average = sum / size;
   // cout<<"Average cost of all values with total sum: "<<sum<< " is "<<setprecision(4)<<average<<endl;
   return average;
}

double getMinimum(const double* array, const unsigned int size) {
    double minimum = array[0];
    for(unsigned int i=1; i < size; i++) {
        if(minimum > array[i]){
            minimum = array[i];
        }
    }
    //cout<<"Minimum cost of all values is: "<<minimum<<endl;
    return minimum;
}

double getCount(const double* array, const unsigned int size) {
    int counter = 0;
    for(unsigned int i=0; i < size; i++) {
        if(array[i] > 100){
            counter++;
        }
    }
   // cout<<"Cost was higher than 100eur: "<<counter<<" times"<<endl;
   return counter;
}

void sortElements(double* array, const unsigned int size){
    double temp;
    for(int i=0; i < size; i++){
        for(int j = size - 1; j > i; j--){
            if(array[j-1] < array[j]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

int main() {
    const unsigned int numOfExpenses =  20;
    auto* expenses = new double[numOfExpenses];

    srand(time(nullptr));

    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArray(expenses, numOfExpenses);
                break;
            case 2:
                printArray(expenses, numOfExpenses);
                break;
            case 3:
                getRoundedArray(expenses, numOfExpenses);
                break;
            case 4:
                cout << getAverage(expenses, numOfExpenses);
                break;
            case 5:
                cout << getMinimum(expenses, numOfExpenses);
                break;
            case 6:
                cout << getCount(expenses, numOfExpenses);
                break;
            case 7:
                sortElements(expenses, numOfExpenses);
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] expenses;

    return 0;
}