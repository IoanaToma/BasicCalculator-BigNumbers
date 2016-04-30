//
//  Class.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 24/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

class BigNumber;
class Array;

class elem
{
    int info;
    elem *next, *prev;
    
public:
    friend class BigNumber; //clasa BigNumber este declarata ca friend, pentru a accesa datele private din clasa elem
    friend ostream& operator<< (ostream& y, BigNumber &number); //era necesarca acesti operatori sa fie friend si pentru clasa elem
    friend BigNumber operator+ (BigNumber SecondNr); //altfel, nu puteam accesa datele unui nod
    friend BigNumber operator- (BigNumber FirstNr, BigNumber SecondNr);
    friend BigNumber operator* (BigNumber FirstNr, BigNumber SecondNr);
    
    friend int count(BigNumber A); //initial era functie membra a clasei BigNumber
};

class BigNumber
{
    elem *start, *end;
    
public:
    BigNumber();
    //static BigNumber fc();
    //BigNumber (const BigNumber &x);
    //~BigNumber(); //acest minunat destructor se apeleaza aiurea si imi creeaza probleme
    void add_elem (int x);
    friend istream& operator>> (istream &y, BigNumber &number);
    friend ostream& operator<< (ostream& y, BigNumber &number);
    friend int count(BigNumber A);
    void delete_number();
    int compare (BigNumber SecondNr);
    void sum (BigNumber FirstNr, BigNumber SecondNr);
    void sub (BigNumber FirstNr, BigNumber SecondNr);
    BigNumber operator+ (BigNumber SecondNr); //initial era functie friend a clasei
    friend BigNumber operator- (BigNumber FirstNr, BigNumber SecondNr);
    friend BigNumber operator* (BigNumber FirstNr0, BigNumber SecondNr0);
    BigNumber operator= (BigNumber x);
    friend class Array;
    
    BigNumber operator *= (BigNumber SecondNr);
    BigNumber operator--(); //prefix
    BigNumber operator--(int y); //postfix
};

BigNumber::BigNumber() //constructorul imi va initializa pointerii de inceput si de sfarsit ai listei cu null
{
    start = nullptr;
    end = nullptr;
}

/*BigNumber::BigNumber (const BigNumber &x)
{
    elem *x1;
    x1 = x.start;
    while (x1)
    {
        add_elem(x1->info);
        x1 = x1->next;
    }
}*/

/*BigNumber::~BigNumber()
{
    elem *p;
    while (start)
    {
        p = start;
        start = start->next;
        delete p;
    }
    cout << "Numarul a fost sters!";
}*/

/*numar_par():BigNumber();

numar_par::numar_par():BigNumber()
{
    cdsjhcnslcl;
}*/