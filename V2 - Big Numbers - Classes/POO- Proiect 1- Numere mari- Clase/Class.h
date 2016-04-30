//
//  Header.h
//  POO- Proiect 1- Numere mari- Clase
//
//  Created by Ioana Toma on 14/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

class BigNumber
{
private:
    struct elem
    {
        int info;
        elem *next, *prev;
    };
    elem *start, *end;
    
public:
    BigNumber();
    //~BigNumber(); //acest minunat destructor se apeleaza aiurea si imi creeaza probleme
    void add_elem (int x);
    void read (int &n);
    void print();
    void delete_number();
    int compare (BigNumber SecondNr);
    void greater_number (int &ok, int n1, int n2, BigNumber SecondNr);
    void sum (BigNumber FirstNr, BigNumber SecondNr);
    void sub (BigNumber FirstNr, BigNumber SecondNr);
    void addition (BigNumber FirstNr, BigNumber SecondNr, int ok);
    void subtraction (BigNumber FirstNr, BigNumber SecondNr, int ok);
    void multiplication (BigNumber FirstNr, BigNumber SecondNr);
    void division (int x);
};

BigNumber::BigNumber() //constructorul imi va initializa pointerii de inceput si de sfarsit ai listei cu null
{
    start = nullptr;
    end = nullptr;
}

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
