//
//  Header.h
//  POO- Proiect 3- Numere mari- Template
//
//  Created by Ioana Toma on 12/05/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

template <class T1> void BigNumber<T1>::add_elem (int x) //adauga un element la lista dublu inlantuita
{
    if (!start) //daca lista nu contine niciun nod, creeaza primul nod
    {
        start = new elem<T1>; //aloca memorie
        start->info = x;
        start->next = NULL;
        start->prev = NULL;
        end = start;
    }
    else //altfel adauga un nod in continuare
    {
        elem<T1> *q;
        q = new elem<T1>;
        q->info = x;
        q->next = NULL;
        q->prev = end;
        end->next = q;
        end = q;
    }
}

template <class T1> int count(BigNumber<T1> A) //numara cate cifre are un numar, parcurgand lista element cu element
{
    int n = 0;
    elem<T1> *p = A.start->next;
    while (p)
    {
        n++;
        p = p->next;
    }
    return n;
}

template <class T1> void BigNumber<T1>::delete_number() //aceasta functie imi sterge intreaga lista, nod cu nod, incepand cu primul
{
    elem<T1> *p;
    while (start)
    {
        p = start;
        start = start->next;
        delete p;
    }
}
