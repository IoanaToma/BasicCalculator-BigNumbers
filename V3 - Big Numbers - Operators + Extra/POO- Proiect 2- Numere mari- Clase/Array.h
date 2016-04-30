//
//  Array.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 13/04/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

class Array
{
    BigNumber *v;
    int n;
    
public:
    Array();
    void set_array (int i);
    void delete_array ();
    friend istream& operator>> (istream& y, Array &v);
    friend ostream& operator<< (ostream &y, Array &arr);
    friend BigNumber operator* (Array first, Array second);
    friend BigNumber greatest_value (Array vex);
};

Array::Array() //constructorul imi va initializa dimensiunea vectorului cu 0 si pointerul pentru vector cu null
{
    v = nullptr;
    n = 0;
}

void Array::set_array(int i) //aceasta functie imi va modifica dimensiunea vectorului si ii va aloca memorie
{
    v = new BigNumber[i];
    n = i;
}

void Array::delete_array() //functie ce sterge vectorul, adica elibereaza memoria si reduce dimensiunea sa la 0
{
    delete [] v;
    n = 0;
}

istream& operator>> (istream &y, Array &arr) //operatorul de citire va citi, pe rand, cate un element din vector
{
    for (int i=0; i<arr.n; i++)
        y >> arr.v[i]; //ma folosesc de faptul ca operatorul de citire a fost deja supraincarcat pentru obiectele din clasa BigNumber
    return y;
}

ostream& operator<< (ostream &y, Array &arr) //operatorul de afisare va afisa, pe rand, cate un element din vector
{
    for (int i=0; i<arr.n; i++)
        y << arr.v[i] << endl; //operatorul de afisare a fost deja supraincarcat pentru obiectele din clasa BigNumber
    return y;
}

BigNumber operator* (Array first, Array second) //produsul scalar a doi vectori
{
    BigNumber product, P;
    if (first.n != second.n) //daca cei doi vectori au dimensiune diferita, nu se poate realiza produsul scalar
    {
        cout << "Nu se poate realiza produsul scalar! ";
        product.add_elem(10); //deoarece operatorul * trebuie sa returneze ceva, in acest caz va returna numarul 0
        product.add_elem(0);
        return product;
    }
    product = first.v[0] * second.v[0]; //in cazul in care cei doi vectori au aceeasi dimensiune, voi initializa product cu produsul dintre
    int i;                              //primele elemente ale vectorilor
    for (i=1; i<first.n; i++) //la product voi aduna mereu produsul a cate doua elemente, fiecare din cate un vector
    {
        P = first.v[i] * second.v[i]; //ma folosesc de supraincarcarea operatorului * pentru numere mari
        product = product + P;
    }
    return product;
}

BigNumber greatest_value (Array vex) //cea mai mare valoare in modul dintr-un vector
{
    BigNumber Great = vex.v[0]; //initial, aceasta valoare va fi primul element
    int i, n1, n2, ok;
    for (i=1; i<vex.n; i++) //apoi voi parcurge tot vectorul si voi compara mereu valorile obtinute
    {
        n1 = count(Great);
        n2 = count(vex.v[i]);
        BigNumber G;
        greater_number(Great, vex.v[i], ok, n1, n2, G); //ma folosesc de functiile deja existente pentru numere mari
        Great = G;
    }
    return Great;
}
