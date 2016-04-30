//
//  Greater absolute value.h
//  POO- Proiect 3- Numere mari- Template
//
//  Created by Ioana Toma on 16/05/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

template <class T2> int BigNumber<T2>::compare(BigNumber<T2> SecondNr) //compara cele doua numere, comparand pe rand cifrele lor, plecand de la
{                                       //cifra dominanta (acest caz este folosit doar daca numerele au numar egal de cifre)
    int ok = 0;
    elem<int> *first = end, *second = SecondNr.end;
    while (!ok && first->prev && second->prev)
    {
        if (first->info > second->info) ok = 1; //daca in primul numar a gasit o cifra mai mare decat cifra celui de-al doilea, este clar ca
        if (first->info < second->info) ok = 2; //primul este mai mare in modul; la fel si pentru cazul in care a doilea are o cifra mai mare;
        first = first->prev;                   //subprogramul da un rezultat corect, intrucat parcurge in paralel cifrele celor doua numere
        second = second->prev;
    }
    return ok; //valoarea lui ok va reprezenta care dintre cele doua numere este mai mare in modul; ok = 0 daca cele doua sunt egale in modul
}

template <class T2> void greater_number (BigNumber<T2> FirstNr, BigNumber<T2> SecondNr, int &ok, int n1, int n2, BigNumber<T2> &Great)
{
    Great.delete_number();
    if (n1 < n2) //daca primul numar are mai putine cifre, cel de-al doilea este clar mai mare in modul
    {
        Great = SecondNr;
        ok = 2; //valorea lui ok va reprezenta care numar este mai mare
    }
    else if (n1 > n2) //daca cel de-al doilea numar are mai putine cifre, primul este clar mai mare in modul
    {
        Great = FirstNr;
        ok = 1;
    }
    else if (FirstNr.compare (SecondNr) == 1) //daca au numar egal de cifre, voi apela functia compare
    {
        Great = FirstNr;
        ok = 1;
    }
    else if (!FirstNr.compare (SecondNr))
    {
        Great = FirstNr;
        ok = 0;
    }
    else
    {
        Great = SecondNr;
        ok = 2;
    }
}

template <class T2> void write_greater (BigNumber<T2> FirstNr, BigNumber<T2> SecondNr, int n1, int n2)
{
    if (n1 < n2) //daca primul numar are mai putine cifre, cel de-al doilea este clar mai mare in modul
        cout << "Al doilea numar este mai mare decat primul in modul";
    else if (n1 > n2) //daca cel de-al doilea numar are mai putine cifre, primul este clar mai mare in modul
        cout << "Primul numar este mai mare decat al doilea in modul";
    else if (FirstNr.compare (SecondNr) == 1) //daca au numar egal de cifre, voi apela functia compare
        cout << "Primul numar e mai mare decat al doilea in modul";
    else if (!FirstNr.compare (SecondNr))
        cout << "Cele doua numere sunt egale in modul";
    else
        cout << "Al doilea numar este mai mare decat primul in modul";
    cout << endl;
}
