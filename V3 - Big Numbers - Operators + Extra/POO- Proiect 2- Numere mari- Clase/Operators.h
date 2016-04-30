//
//  BigNumber operators.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 18/04/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

istream& operator>> (istream& y, BigNumber &number) //citeste numarul mare de la tastatura, cifra cu cifra, incepand cu semnul, apoi cifra
{                                                   // unitatilor; citirea se opreste cand este introdus "-1"
    int x;
    y >> x;
    try {
        if (x == 10 || x == 11);
            else throw 1;
    } catch (int sucks) {
        cout << "N-ati scris semnul bine!";
    }
    while (x != -1)
    {
        number.add_elem (x);
        y >> x;
    }
    return y;
}

ostream& operator<< (ostream& y, BigNumber &number)
{
    elem *p;
    p = number.end;
    try {
        if (number.start->info == 10) y << "+"; //afisez semnul numarului; 10 = '+', 11 = '-'
        else if (number.start->info == 11) y << "-";
        else throw 1;
    } catch (int sucks) {
        cout << "N-ati dat semnul bine! ";
    }
    while (p->prev) //conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja,deci merge pana la al doilea nod
    {
        y << p->info;
        p = p->prev;
    }
    return y;
}

BigNumber BigNumber::operator= (BigNumber x) //supraincarcarea operatorului =; creeaza un nou numar mare in care va pune, element cu element,
{                                            //informatia din fiecare nod din numarul pe care il copiaza
    delete_number();
    elem *x1;
    x1 = x.start;
    while (x1)
    {
        add_elem(x1->info);
        x1 = x1->next;
    }
    return *this;
}
