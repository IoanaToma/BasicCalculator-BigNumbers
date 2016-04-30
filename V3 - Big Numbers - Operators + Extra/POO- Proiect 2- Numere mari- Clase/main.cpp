
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
#include "Add + Count + Delete.h"
#include "Greater absolute value.h"
#include "Addition + Substraction.h"
#include "Multiplication.h"
#include "Array.h"
#include "Operators >>, <<, =.h"
#include "Chestii in plus.h"

using namespace std;

/*BigNumber BigNumber::fc()
{
    BigNumber x;
    cin >> x;
    return x;
}*/

int main()
{
    ifstream f ("Numbers.txt");
    ofstream g ("afisare_numere.txt");
    ifstream h ("vectori.txt");
    ofstream i ("vectori_iesire.txt");
    
    BigNumber FirstNr, SecondNr, SumNr, SubNr, MultiNr;
    int n1, n2;
    
    /*FirstNr = BigNumber::fc();
    SecondNr = BigNumber::fc();*/
    
    f >> FirstNr >> SecondNr; //citesc din fisier cele doua numere
    g << "Primul numar este: " << FirstNr << endl << "Al doilea numar este: " << SecondNr; //le afisez in fisier
    g.close();
    
    /*BigNumber Number(FirstNr);
    cout << "Numarul nou este: " << Number << endl;*/
    
    BigNumber Number;
    Number = FirstNr;
    Number *= SecondNr;
    cout << "Primul numar devine el inmultit cu al doilea: " << Number << endl << endl;
    
    Number--;
    cout << Number << endl;
    
    --Number;
    cout << Number << endl << endl;
    
    n1 = count(FirstNr); //n1 = numarul de elemente al primului numar
    n2 = count(SecondNr); //n2 = numarul de elemente al celui de-al doilea numar
    
    cout << "Mostra (pentru numerele citite din fisier si vectorii cititi din fisier): " << endl;
//afisez primul numar pe ecran
    cout << "Primul numar este: ";
    cout << FirstNr;
    cout << endl;
    
//afisez cel de-al doilea numar pe ecran
    cout << "Al doilea numar este: ";
    cout << SecondNr;
    cout << endl;
    
//aflu care dintre cele doua numere este mai mare in modul
    write_greater(FirstNr, SecondNr, n1, n2);
    
//calculez suma celor doua numere si o afisez
    SumNr = FirstNr + SecondNr;
    cout << "Suma celor doua numere este: ";
    cout << SumNr;
    cout << endl;
    
//calculez diferenta celor doua numere si o afisez
    SubNr = FirstNr - SecondNr;
    cout << "Diferenta celor doua numere este: ";
    cout << SubNr;
    cout << endl;
    
//calculez produsul celor doua numere si il afisez
    MultiNr = FirstNr * SecondNr;
    cout << "Produsul celor doua numere este: ";
    cout << MultiNr;
    cout << endl << endl;
    
    Array Arr1, Arr2;
    int nr1, nr2;
    
    h >> nr1 >> nr2; //citesc din fisier dimensiunile celor doi vectori
    Arr1.set_array(nr1); //aloc memorie vectorilor si le modific dimensiunea
    Arr2.set_array(nr2);
    h >> Arr1 >> Arr2; //citesc cei doi vectori din fisier
    cout << "Primul vector: " << endl << Arr1 << "Al doilea vector: " << endl << Arr2; //afisez vectorii pe ecran
    i << "Primul vector: " << endl << Arr1 << "Al doilea vector: " << endl << Arr2; //afisez vectorii in fisier
    i.close();
    
//calculez produsul scalar al celor doi vectori si il afisez pe ecran
    BigNumber product;
    product = Arr1 * Arr2;
    cout << "Produsul scalar al celor doi vectori este: " << product << endl;
   
//gasesc cea mai mare valoare in modul din primul vector si o afisez pe ecran
    BigNumber greatest;
    greatest = greatest_value(Arr1);
    cout << "Cea mai mare valore in modul din primul vector este: " << greatest << endl << endl << endl;
    
    cout << "Atentie! Daca doriti sa modificati numerele, trebuie stiut faptul ca prima data trebuie introdus semnul, conventia fiind: 10 = '+', 11 = '-'. Apoi, trebuie introduse numai cifre, altfel programul nu va functiona!! De asemenea, cifrele trebuie introduse in ordine inversa, de la cifra unitatilor la cifra dominanta. Introducerea de cifre poate fi oprita tastand '-1'." << endl << "Pentru vectori, trebuie data mai intai dimensiunea, apoi elementele (numere mari, introduse de la tastatura asa cum este specificat mai sus." << endl << "Acestea fiind zise, distractie placuta!" << endl << endl;
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
        cout << "7. Modificarea primului vector" << endl;
        cout << "8. Modificarea celui de-al doilea vector" << endl;
        cout << "9. Produsul scalar al celor doi vectori" << endl;
        cout << "10. Cea mai mare valoare in modul din primul vector" << endl;
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
                cin >> FirstNr; //citesc numarul nou
                n1 = count(FirstNr);
                cout << endl;
                cout << "Primul numar este acum: ";
                cout << FirstNr; //il afisez
                cout << endl;
                break;
            }
            case 2:
            {
                SecondNr.delete_number();
                cin >> SecondNr;
                n2 = count(SecondNr);
                cout << endl;
                cout << "Al doilea numar este acum: ";
                cout << SecondNr;
                cout << endl;
                break;
            }
            case 3:
            {
                cout << endl;
                write_greater(FirstNr, SecondNr, n1, n2); //apelez functiile necesare
                break;
            }
            case 4:
            {
                SumNr.delete_number(); //de fiecare data voi sterge lista suma, respectiv diferenta sau produs, pentru ca programul sa nu adauge
                cout << endl;          //urmatoarea data la ceva ce exista deja
                SumNr = FirstNr + SecondNr;
                cout << "Suma celor doua numere este: " << endl;;
                cout << FirstNr << " + (" << SecondNr << ") = " << SumNr << endl;
                break;
            }
            case 5:
            {
                cout << endl;
                SubNr.delete_number();
                SubNr = FirstNr - SecondNr;
                cout << "Diferenta celor doua numere este: " << endl;
                cout << FirstNr << " - (" << SecondNr << ") = " << SubNr << endl;
                break;
            }
            case 6:
            {
                cout << endl;
                MultiNr.delete_number();
                MultiNr = FirstNr * SecondNr;
                cout << "Produsul celor doua numere este: " << endl;
                cout << FirstNr << " * (" << SecondNr << ") = " << MultiNr << endl;
                break;
            }
            case 7:
            {
                Arr1.delete_array(); //sterg vectorul deja existent, pentru a-l putea inlocui cu unul nou (mai exact, eliberez memoria)
                cout << "Dati numarul de elemente: ";
                cin >> nr1; //citesc numarul de elemente
                Arr1.set_array(nr1);
                cin >> Arr1;
                cout << "Primul vector este acum:" << endl << Arr1; //afisez vectorul nou
                break;
            }
            case 8:
            {
                Arr2.delete_array();
                cout << "Dati numarul de elemente: ";
                cin >> nr2;
                Arr2.set_array(nr2);
                cin >> Arr2;
                cout << "Al doilea vector este acum:" << endl << Arr2;
                break;
            }
            case 9:
            {
                product.delete_number(); //sterg produsul scalar care exista deja, il recalculez si il afisez
                product = Arr1 * Arr2;
                cout << product << endl;
                break;
            }
            case 10:
            {
                greatest.delete_number(); //sterg valoarea maxima calculata anterior, o calculez pentru noul vector si o afisez
                greatest = greatest_value(Arr1);
                cout << greatest << endl;
                break;
            }
        }
        cout << endl;
    } while (y);
    
    f.close();
    h.close();
    
    return 0;
}