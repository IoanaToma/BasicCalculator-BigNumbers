//
//  main.cpp
//  POO- Proiect 1- Numere mari- Clase
//
//  Created by Ioana Toma on 12/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Class.h"
#include "Add + Read + Print + Delete.h"
#include "Greater absolute value.h"
#include "Addition + Substraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

int main()
{
    ifstream f ("/Users/Ioana/Desktop/XCode Projects/POO - Proiect 1- Numere mari/POO - Proiect 1- Numere mari/First_number.txt");
    ifstream g ("/Users/Ioana/Desktop/XCode Projects/POO - Proiect 1- Numere mari/POO - Proiect 1- Numere mari/Second_number.txt");
    
    BigNumber FirstNr, SecondNr, SumNr, SubNr, MultiNr;
    int x, n1 = 0, n2 = 0;
    
//construiesc prima lista reprezentand primul numar si numar cate cifre are
    while (f>>x) //citesc cifrele primului numar din primul fisier
    {
        FirstNr.add_elem (x);
        n1++; //numar cate cifre are primul numar
    }
    
//construiesc a doua lista reprezentand al doilea numar si numar cate cifre are
    while (g>>x) //citesc cifrele celui de-al doilea numar din al doilea fisier
    {
        SecondNr.add_elem (x);
        n2++; //numar cifrele celui de-al doilea numar
    }
   
    cout << "Mostra (pentru numerele citite din fisier): " << endl;
//afisez primul numar
    cout << "Primul numar este: ";
    FirstNr.print();
    cout << endl;
    
//afisez cel de-al doilea numar
    cout << "Al doilea numar este: ";
    SecondNr.print();
    cout << endl;
    
//aflu care dintre cele doua numere este mai mare in modul
    int ok;
    FirstNr.greater_number(ok, n1, n2, SecondNr);
    
//calculez suma celor doua numere si o afisez
    SumNr.addition(FirstNr, SecondNr, ok);
    cout << "Suma celor doua numere este: ";
    SumNr.print();
    cout << endl;
    
//calculez diferenta celor doua numere si o afisez
    SubNr.subtraction (FirstNr, SecondNr, ok);
    cout << "Diferenta celor doua numere este: ";
    SubNr.print();
    cout << endl;
    
//calculez produsul celor doua numere si il afisez
    MultiNr.multiplication(FirstNr, SecondNr);
    cout << "Produsul celor doua numere este: ";
    MultiNr.print();
    cout << endl << endl << endl;
    
    SumNr.delete_number();
    SubNr.delete_number();
    MultiNr.delete_number();
    
//fac impartirea la o cifra
    int z;
    cout << "Dati cifra la care vreti sa impartiti primul numar:";
    cin >> z;
    FirstNr.division(z);
    cout << endl << endl;
    
    cout << "Atentie! Daca doriti sa modificati numerele, trebuie stiut faptul ca prima data trebuie introdus semnul, conventia fiind: 10 = '+', 11 = '-'. Apoi, trebuie introduse numai cifre, altfel programul nu va functiona!! De asemenea, cifrele trebuie introduse in ordine inversa, de la cifra unitatilor la cifra dominanta. Introducerea de cifre poate fi oprita tastand '-1'. Acestea fiind zise, distractie placuta!" << endl;
//creez un meniu
    int y;
    do{
        
        cout << "Meniul dumneavoastra este: " << endl;
        cout << "0. Iesire din program" << endl;
        cout << "1. Modificarea primul numar" << endl;
        cout << "2. Modificarea celui de-al doilea numar" << endl;;
        cout << "3. Care numar este mai mare in modul?" << endl;
        cout << "4. Suma celor doua numere" << endl;
        cout << "5. Diferenta celor doua numere" << endl;
        cout << "6. Produsul celor doua numere" << endl;
        cout << "Optiunea este: ";
        cin >> y;
        switch (y)
        {
            case 0:
            {
                cout << endl;
                cout << "Multumesc pentru atentie!";
                break;
            }
            case 1:
            {
                FirstNr.delete_number(); //sterg numarul deja existent, pentru ca cel nou sa ii poata lua locul
                FirstNr.read(n1); //citesc numarul nou
                cout << endl;
                cout << "Primul numar este acum: ";
                FirstNr.print(); //il afisez
                cout << endl;
                break;
            }
            case 2:
            {
                SecondNr.delete_number();
                SecondNr.read(n2);
                cout << endl;
                cout << "Al doilea numar este acum: ";
                SecondNr.print();
                cout << endl;
                break;
            }
            case 3:
            {
                cout << endl;
                FirstNr.greater_number (ok, n1, n2, SecondNr); //apelez functiile necesare
                break;
            }
            case 4:
            {
                cout << endl;
                SumNr.addition(FirstNr, SecondNr, ok);
                cout << "Suma celor doua numere este: " << endl;;
                FirstNr.print(); cout << " + ("; SecondNr.print(); cout << ") = ";
                SumNr.print();
                cout << endl;
                SumNr.delete_number(); //de fiecare data voi sterge lista suma, respectiv diferenta sau produs, pentru ca programul sa nu adauge
                break;                 //urmatoarea data la ceva ce exista deja
            }
            case 5:
            {
                cout << endl;
                SubNr.subtraction (FirstNr, SecondNr, ok);
                cout << "Diferenta celor doua numere este: " << endl;
                FirstNr.print(); cout << " - ("; SecondNr.print(); cout << ") = ";
                SubNr.print();
                cout << endl;
                SubNr.delete_number();
                break;
            }
            case 6:
            {
                cout << endl;
                MultiNr.multiplication(FirstNr, SecondNr);
                cout << "Produsul celor doua numere este: " << endl;
                FirstNr.print(); cout << " * ("; SecondNr.print(); cout << ") = ";
                MultiNr.print();
                cout << endl;
                MultiNr.delete_number();
                break;
            }
        }
        cout << endl;
    } while (y);

    
    f.close();
    g.close();
    
    return 0;
}

