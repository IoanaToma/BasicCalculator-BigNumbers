//
//  Add + Read + Print + Delete.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 24/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void BigNumber::add_elem (int x) //adauga un element la lista dublu inlantuita
{
    if (!start) //daca lista nu contine niciun nod, creeaza primul nod
    {
        start = new elem; //aloca memorie
        start->info = x;
        start->next = NULL;
        start->prev = NULL;
        end = start;
    }
    else //altfel adauga un nod in continuare
    {
        elem *q;
        q = new elem;
        q->info = x;
        q->next = NULL;
        q->prev = end;
        end->next = q;
        end = q;
    }
}

int count(BigNumber A) //numara cate cifre are un numar, parcurgand lista element cu element
{
    int n = 0;
    elem *p = A.start->next;
    while (p)
    {
        n++;
        p = p->next;
    }
    return n;
}

void BigNumber::delete_number() //aceasta functie imi sterge intreaga lista, nod cu nod, incepand cu primul
{
    elem *p;
    while (start)
    {
        p = start;
        start = start->next;
        delete p;
    }
}
