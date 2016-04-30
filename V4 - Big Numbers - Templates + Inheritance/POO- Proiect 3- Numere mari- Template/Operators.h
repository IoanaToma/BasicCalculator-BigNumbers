//
//  Operators.h
//  POO- Proiect 3- Numere mari- Template
//
//  Created by Ioana Toma on 16/05/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

template <class T2> istream& operator>> (istream& y, BigNumber<T2> &number) //citeste numarul mare de la tastatura, cifra cu cifra, incepand cu semnul, apoi cifra
{                                                   // unitatilor; citirea se opreste cand este introdus "-1"
    int x;
    y >> x;
    try {
        if (x == 10 || x == 11);
        else throw 1;
    } catch (int sucks) {
        while (x != 10 && x != 11)
        {
            cout << "Nu ati introdus semnul bine! Incercati din nou: ";
            y >> x;
        }
    }
    while (x != -1)
    {
        number.add_elem (x);
        y >> x;
    }
    
    return y;
}

template <class T2> istream& operator>> (istream& y, Even_BigNumber<T2> &number) //citeste numarul mare de la tastatura, cifra cu cifra, incepand cu semnul, apoi cifra
{                                                   // unitatilor; citirea se opreste cand este introdus "-1"
    int x;
    y >> x;
    try {
        if (x == 10 || x == 11);
        else throw 1;
    } catch (int sucks) {
        while (x != 10 && x != 11)
        {
            cout << "Nu ati introdus semnul bine! Incercati din nou: ";
            y >> x;
        }
    }
    number.add_elem(x);
    y >> x;
    try {
        if (!x % 2);
        else throw 1;
    } catch (int sucks) {
        while(x % 2)
        {
            cout << "Nu ati introdus un numar par! Incercati sa introduceti ultima cifra din nou: ";
            y >> x;
        }
    }
    while (x != -1)
    {
        number.add_elem (x);
        y >> x;
    }
    
    return y;
}

template <class T2> ostream& operator<< (ostream& y, BigNumber<T2> &number)
{
    elem<int> *p;
    p = number.end;
    if (number.start->info == 10) y << "+"; //afisez semnul numarului; 10 = '+', 11 = '-'
    else if (number.start->info == 11) y << "-";
    while (p->prev) //conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja,deci merge pana la al doilea nod
    {
        y << p->info;
        p = p->prev;
    }
    return y;
}

template <class T2> ostream& operator<<(ostream& y, Even_BigNumber<T2> &number)
{
    elem<int> *p;
    p = number.end;
    if (number.start->info == 10) y << "+"; //afisez semnul numarului; 10 = '+', 11 = '-'
    else if (number.start->info == 11) y << "-";
    while (p->prev) //conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja,deci merge pana la al doilea nod
    {
        y << p->info;
        p = p->prev;
    }
    return y;
}

template <class T2> BigNumber<T2> BigNumber<T2>::operator= (BigNumber<T2> x) //supraincarcarea operatorului =; creeaza un nou numar mare in care va pune, element cu element,
{                                            //informatia din fiecare nod din numarul pe care il copiaza
    delete_number();
    elem<T2> *x1;
    x1 = x.start;
    while (x1)
    {
        add_elem(x1->info);
        x1 = x1->next;
    }
    return *this;
}

