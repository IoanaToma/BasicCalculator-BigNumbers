//
//  Header.h
//  POO- Proiect 1- Numere mari- Clase
//
//  Created by Ioana Toma on 15/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

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

void BigNumber::read (int &n) //citeste numarul mare de la tastatura, cifra cu cifra, incepand cu semnul, apoi cifra unitatilor si numara cate
{                             //cifre are numarul; citirea se opreste cand este introdus "-1"
    int x;
    n = 0;
    cin >> x;
    while (x != -1)
    {
        add_elem (x);
        n++;
        cin >> x;
    }
}

void BigNumber::print()
{
    elem *p;
    p = end;
    if (start->info == 10) cout << "+"; //afisez semnul numarului; 10 = '+', 11 = '-'
    else cout << "-";
    while (p->prev) //conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja,deci merge pana la al doilea nod
    {
        cout << p->info;
        p = p->prev;
    }
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
