#include<iostream>
#include<math.h>

using namespace std;

int main(){
    double D, E, F, L, G; // Мы объявляем все переменные
    cout << "Enter the variable" << endl;
    cout << "D = "; cin >> D; // Получаем значение D
    cout << "E = "; cin >> E; // Получаем значение E
    cout << "F = "; cin >> F; // Получаем значение F

    cout << "\n=========================================\n" << endl;

    // Мы считаем значение аргумента логарифма, и смотрим на его знак
    // Если Х меньше нуля, то нельзя посчитать логарифм

    double X = pow(E,2) - F * D + sqrt(pow(F,2) + pow(D,2));
    if (X>0){
        // Мы считаем значение переменной L
        L = log(X);
        cout << "L = " << L << endl;

        // Мы считаем значение переменной G
        G = pow(sin(L),2) + cos(pow(L,2));
        cout << "G = " << G << endl;
    } 
    else{ 
        cout << "The input values are not valid!!\n" << endl;
    }

    return 0;
}