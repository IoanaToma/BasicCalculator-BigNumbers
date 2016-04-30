//
//  Multiplication.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 24/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

//inmultirea se face plecand intotdeauna de la cifra unitatilor
BigNumber operator* (BigNumber FirstNr, BigNumber SecondNr)
{
    BigNumber Multi;
    if (FirstNr.end->info == 0 || SecondNr.end->info == 0) //daca unul dintre numere este 0, produsul va fi 0, cu semnul "+"
    {
        Multi.add_elem(10);
        Multi.add_elem(0);
    }
    else //daca ambele numere sunt diferite de 0, produsul va fi diferit de 0
    {
        if (FirstNr.start->info == SecondNr.start->info) //daca numerele au acelasi semn, semnul produsului va fi "+"
            Multi.add_elem(10);
        else Multi.add_elem(11); //daca numerele au semne diferite, semnul produsului va fi "-"; am creat nodul pentru semn
        
        if (count(FirstNr) == 1 && count(SecondNr) != 1) //daca primul numar are o singura cifra, iar al doilea mai multe, nu voi avea
        {                                                   //nevoie sa mai fac adunari ulterioare la lista produs deja existenta
            elem *first, *second;
            first = FirstNr.start->next;
            second = SecondNr.start->next;
            int k = 0, m;
            while (second)
            {
                if (first->info * second->info + k >= 10) //decid daca voi avea transport sau nu
                {
                    m = (first->info * second->info + k)%10; //m = cifra unitatilor a calculului
                    k = (first->info * second->info + k)/10; //k = cat trebuie sa transport
                }
                else
                {
                    m = first->info * second->info + k;
                    k = 0;
                }
                Multi.add_elem(m); //adaug un nou nod la lista produs
                second = second->next;
                
                if (!second && k) //daca am ajuns la sfarsitul listei 2, insa mai aveam inca un transport de facut, mai adaug un nod
                    Multi.add_elem(k);
            }
        }
        else 
        {
            elem *first, *second;
            int k = 0, m;
            first = FirstNr.start->next; // p = prima cifra a primului numar
            second = SecondNr.start->next; //q = prima cifra a celui de-al doilea numar
            while (first)               //creez o lista care reprezinta produsul primului numar cu prima cifra
            {                       //a celui de-al doilea numar
                if (first->info * second->info + k >= 10) //decid daca voi avea transport sau nu
                {
                    m = (first->info * second->info + k)%10; //m = cifra unitatilor a calculului
                    k = (first->info * second->info + k)/10; //k = cat trebuie sa transport
                }
                else
                {
                    m = first->info * second->info + k;
                    k = 0;
                }
                Multi.add_elem(m); //adaug un nou nod la lista produs
                first = first->next;
                
                if (!first && k) //daca am ajuns la sfarsitul primei liste, insa mai aveam inca un transport de facut, mai adaug un nod
                    Multi.add_elem(k);
            }
            first = FirstNr.start->next; //p pleaca de fiecare data de la prima cifra a primului numar
            second = second->next; //trec la a doua cifra din al doilea numar
            elem *sum;
            sum = Multi.start->next;
            sum = sum->next;
            elem *sum1;
            while (second) //cat timp exista cifre in al doilea numar
            {
                sum1 = sum; //sum va fi nodul din produs de la care trebuie sa incep sa adun noile rezultate, adica produse intre cifrele numerelor
                k = 0; //initial, transportul este 0
                while (first && sum1) //cat timp exista cifre in primul numar si in lista produs initiala
                {
                    if (first->info * second->info + sum1->info + k >= 10) //decid daca am transport
                    {
                        m = (first->info * second->info + sum1->info + k)%10;
                        k = (first->info * second->info + sum1->info + k)/10; //k = transportul
                    }
                    else
                    {
                        m = first->info * second->info + sum1->info + k;
                        k = 0;
                    }
                    sum1->info = m; //nodul din produs ia alta valoare, adica valoarea initiala + noul produs intre cifre + transport
                    first = first->next;
                    sum1 = sum1->next;
                    
                    if (!first && k) //daca nu mai am cifre in primul numar, dar mai am transport, adaug un nod in plus
                        Multi.add_elem(k);
                    
                }
                while (first) //daca s-a terminat lista produs initiala, dar nu s-a terminat prima lista, adaug noi noduri la lista produs
                {
                    if (first->info * second->info + k >= 10)
                    {
                        m = (first->info * second->info + k)%10;
                        k = (first->info * second->info + k)/10;
                    }
                    else
                    {
                        m = first->info * second->info + k;
                        k = 0;
                    }
                    Multi.add_elem(m);
                    first = first->next;
                    
                    if (!first && k)
                        Multi.add_elem(k);
                }
                second = second->next;
                sum = sum->next;
                first = FirstNr.start->next;
            }
        }
    }
    return Multi;
}

