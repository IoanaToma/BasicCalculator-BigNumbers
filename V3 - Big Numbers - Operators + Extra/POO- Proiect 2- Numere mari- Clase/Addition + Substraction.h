//
//  Addition + Substraction.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 24/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

//suma se face plecand de la cifra unitatilor
void BigNumber::sum (BigNumber FirstNr, BigNumber SecondNr) //suma a doua numere de acelasi semn (suma uzuala)
{
    int k = 0, s;
    elem *first = FirstNr.start->next, *second = SecondNr.start->next;
    while (first && second)               //creez lista suma; atata timp cat exista cifre pentru ambele numere
    {
        if (first->info + second->info + k >= 10) //decid daca am transport la urmatoarea cifra; la suma celor doua cifre adaug si
        {                                         //transportul,daca exista
            s = (first->info + second->info + k)%10;
            k = 1; //k = transportul
        }
        else
        {
            s = first->info + second->info + k;
            k = 0;
        }
        add_elem(s); //creez un nou nod in lista suma
        first = first->next;
        second = second->next;
        
        if (!first && !second && k)   //decid daca dupa adunarea ultimelor doua cifre este necesar sa creez un nou nod pentru transportul ramas
            add_elem(k);
    }
    
    while (first)                 //acest while este doar pentru cazul in care numarul mai mare in modul are mai multe cifre
    {                             //si in acest caz se verifica daca exista transport
        if (first->info + k >= 10)
        {
            s = (first->info +k)%10;
            k = 1;
        }
        else
        {
            s = first->info + k;
            k = 0;
        }
        add_elem(s);
        first = first->next;
        
        if (!first && k) //daca s-a terminat lista repr. numarul mai mare in modul, dar mai aveam inca un transport de facut,creez inca un nod
            add_elem(k);
    }
}

//diferenta se face plecand de la cifra unitatilor
void BigNumber::sub (BigNumber FirstNr, BigNumber SecondNr) //diferenta a doua numere de acelasi semn (diferenta uzuala)
{
    int k = 0, d;
    elem *first = FirstNr.start->next, *second = SecondNr.start->next;
    while (first && second)                      //creez lista scadere; atata timp cat am cifre in ambele numere
    {
        if (first->info - k < second->info) //decid daca trebuie sa 'imprumut' de la urmatoarea cifra
        {
            d = first->info - second->info - k + 10;
            k = 1; //k= 'imprumutul'
        }
        else
        {
            d = first->info - second->info - k;
            k = 0;
        }
        add_elem(d); //creez/adaug un nou nod la lista diferenta
        first = first->next;
        second = second->next;
    }
    while (first)                 //pentru cazul in care numarul mai mare in modul are mai multe cifre
    {
        if (first->info - k < 0)
        {
            d = first->info - k + 10;
            k = 1;
        }
        else
        {
            d = first->info - k;
            k = 0;
        }
        add_elem(d); //adaug noi elemente la lista scadere
        first = first->next;
    }
    elem *p = end, *q;
    while (p->prev && !p->info)         //avand in vedere ca rezultatul scaderii poate avea mai putine
    {                                   //cifre decat numerele initiale, sterg toate zerourile de la
        q = end;                      //capat inspre inceput, pentru a nu afisa numere precum
        end = p->prev;                // "0001" sau "0000" (pentru a lasa doar cifrele diferite de 0
        end->next = NULL;             //incepand cu cifra unitatilor
        delete q;
        p = end;
    }
}

//"adunarea" a doua numere poate fi si 'adunare uzuala', si 'scadere uzuala', in functie de ce semn au
BigNumber BigNumber::operator+ (BigNumber SecondNr) //supraincarcarea operatorului +
{
    BigNumber Sum;
    if (!start) //daca vreunul dintre numere nu exista, atunci functia va returna numarul care exista
        Sum = SecondNr;
    else if (!SecondNr.start)
        Sum = *this;
    else
    {
        int n1, n2, ok;
        n1 = count(*this); //n1 = numarul de cifre al primului numar; voi avea nevoie de el pentru a afla care numar este mai mare
        n2 = count(SecondNr);
        
        greater_number(*this, SecondNr, ok, n1, n2, Sum);
        Sum.delete_number(); //sterg Sum, in care este retinut cel mai mare dintre cele doua numere, deoarece am nevoie numai de valoarea lui ok
        
        elem *t;
        t = new elem;
        if (!ok || ok == 1) //daca cele doua numere sunt egale sau primul numar este mai mare in modul
        {
            if (start->info == SecondNr.start->info) //daca au acelasi semn, apelez suma uzuala, considerand primul numar mai mare in modul
            {
                Sum.sum (*this, SecondNr);
                t->info = start->info; //rezultatul va avea semnul comun al numerelor
            }
            else
            {
                Sum.sub (*this, SecondNr); //daca au semne diferite, apelez diferenta uzuala
                if (!ok) t->info = 10; //daca cele doua numere sunt egale, semnul va fi + (sa afiseze "+0")
                else t->info = start->info; //altfel rezultatul va avea semnul numarului mai mare in modul
            }
        }
        else //daca cel de-al doilea numar este mai mare in modul
        {
            if (start->info == SecondNr.start->info) //daca cele doua numere au acelasi semn
            {
                Sum.sum (SecondNr, *this); //apelez suma uzuala, considerand cel de-al doilea numar mai mare in modul
                t->info = SecondNr.start->info; //semnul rezultatului va fi semnul comun al celor doua numere
            }
            else //daca au semne diferite
            {
                Sum.sub (SecondNr, *this); //apelez diferenta uzuala, considerand cel de-al doilea numar mai mare in modul
                t->info = SecondNr.start->info; //semnul rezultatului va fi semnul numarului mai mare in modul
            }
        }
        t->next = Sum.start; //creez nodul pentru semn, pe care il adaug inaintea primul nod al listei suma
        t->prev = NULL;
        Sum.start->prev = t;
        Sum.start = t;
    }
    return Sum;
}

//"scaderea" a doua numere poate fi si 'adunare uzuala', si 'scadere uzuala', in functie de ce semn au
BigNumber operator- (BigNumber FirstNr, BigNumber SecondNr) //supraincarcarea operatorului -
{
    int n1, n2, ok;
    n1 = count(FirstNr); //n1 = numarul de cifre al primul numar, de care voi avea nevoia pentru a afla care dintre cele doua este mai mare
    n2 = count(SecondNr); //n2 = numarul de cifre al celui de-al doilea numar
    
    BigNumber Sub;
    greater_number(FirstNr, SecondNr, ok, n1, n2, Sub);
    Sub.delete_number();
    
    elem *t;
    t = new elem;
    if (!ok || ok == 1) //daca numerele sunt egale sau primul este mai mare in modul
    {
        if (FirstNr.start->info == SecondNr.start->info) //daca au acelasi semn
        {
            Sub.sub (FirstNr, SecondNr);//apelez diferenta uzuala, considerand primul numar mai mare in modul
            if (!ok) t->info = 10; //daca numerele sunt egale, vreau sa imi afiseze "+0"
            else t->info = FirstNr.start->info; //altfel semnul rezultatului va fi semnul comun al celor doua numere
        }
        else //daca au semne diferite
        {
            Sub.sum (FirstNr, SecondNr);//apelez suma, considerand primul numar mai mare in modul
            t->info = FirstNr.start->info; //semnul rezultatului va fi semnul numarului mai mare in modul
        }
    }
    else //daca al doilea numar este mai mare in modul
    {
        if (FirstNr.start->info == SecondNr.start->info) //daca au acelasi semn
        {
            Sub.sub (SecondNr, FirstNr);//apelez diferenta uzuala, considerand al doilea numar mai mare in modul
            if (SecondNr.start->info == 10) t->info = 11; //semnul rezultatului va fi "inversul" semnului numarului care este mai mare in modul
            else t->info = 10;
        }
        else //daca au semne diferite
        {
            Sub.sum (SecondNr, FirstNr); //apelez suma, considerand al doilea numar mai mare in modul
            if (SecondNr.start->info == 10) t->info = 11; //semnul rezultatului va fi "inversul" semnului numarului mai mare in modul
            else t->info = 10;
        }
    }
    t->next = Sub.start; //creez nodul pentru semn, pe care il adaug inainte de primul nod al listei diferenta
    t->prev = NULL;
    Sub.start->prev = t;
    Sub.start = t;
    
    return Sub;
}
