//
//  Greater absolute value.h
//  POO- Proiect 1- Numere mari- Clase
//
//  Created by Ioana Toma on 15/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

int BigNumber::compare(BigNumber SecondNr) //compara cele doua numere, comparand pe rand cifrele lor, plecand de la
{                                       //cifra dominanta (acest caz este folosit doar daca numerele au numar egal de cifre)
    int ok = 0;
    elem *first = end, *second = SecondNr.end;
    while (!ok && first->prev && second->prev)
    {
        if (first->info > second->info) ok = 1; //daca in primul numar a gasit o cifra mai mare decat cifra celui de-al doilea, este clar ca
        if (first->info < second->info) ok = 2; //primul este mai mare in modul; la fel si pentru cazul in care a doilea are o cifra mai mare;
        first = first->prev;                   //subprogramul da un rezultat corect, intrucat parcurge in paralel cifrele celor doua numere
        second = second->prev;
    }
    return ok; //valoarea lui ok va reprezenta care dintre cele doua numere este mai mare in modul; ok = 0 daca cele doua sunt egale in modul
}

void BigNumber::greater_number (int &ok, int n1, int n2, BigNumber SecondNr)
{
    if (n1 < n2) //daca primul numar are mai putine cifre, cel de-al doilea este clar mai mare in modul
    {
        ok = 2; //valorea lui ok va reprezenta care numar este mai mare
        cout << "Al doilea numar este mai mare decat primul in modul";
    }
    else if (n1 > n2) //daca cel de-al doilea numar are mai putine cifre, primul este clar mai mare in modul
    {
        ok = 1;
        cout << "Primul numar este mai mare decat al doilea in modul";
    }
    else if (compare (SecondNr) == 1) //daca au numar egal de cifre, voi apela functia compare
    {
        ok = 1;
        cout << "Primul numar e mai mare decat al doilea in modul";
    }
    else if (!compare (SecondNr))
    {
        ok = 0;
        cout << "Cele doua numere sunt egale in modul";
    }
    else
    {
        ok = 2;
        cout << "Al doilea numar este mai mare decat primul in modul";
    }
    cout << endl;
}
