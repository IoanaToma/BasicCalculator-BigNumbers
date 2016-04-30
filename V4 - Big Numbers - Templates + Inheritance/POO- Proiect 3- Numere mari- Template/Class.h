//
//  Class.h
//  POO- Proiect 3- Numere mari- Template
//
//  Created by Ioana Toma on 15/05/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

template <class T1> class BigNumber;
template <class T1> class Even_BigNumber;
template <class T1> class Fibonacci_BigNumber;
template <class T1> class Even_Fibonacci_BigNumber;
template <class T1> class Array;

template <class T>
class elem
{
    T info;
    elem *next, *prev;
    
public:
    template <class T1> friend class BigNumber; //clasa BigNumber este declarata ca friend, pentru a accesa datele private din clasa elem
    template <class T1> friend class Even_BigNumber;
    template <class T1>friend class Fibonacci_BigNumber;
    template <class T1>friend class Even_Fibonacci_BigNumber;
    template <class T1> friend ostream& operator<< (ostream& y, BigNumber<T1> &number); //era necesar ca acesti operatori sa fie friend si pentru clasa elem
    template <class T1>friend ostream& operator<<(ostream& y, Even_BigNumber<T1> &number);
    template <class T1>friend istream& operator>> (istream& y, Even_BigNumber<T1> &number);
    template <class T1> friend BigNumber<T1> operator+ (BigNumber<T1> SecondNr); //altfel, nu puteam accesa datele unui nod
    template <class T1> friend BigNumber<T1> operator- (BigNumber<T1> FirstNr, BigNumber<T1> SecondNr);
    template <class T1> friend BigNumber<T1> operator* (BigNumber<T1> FirstNr, BigNumber<T1> SecondNr);
    template <class T1> friend int count(BigNumber<T1> A); //initial era functie membra a clasei BigNumber
};

template <class T1>
class BigNumber
{
protected:
    elem<T1> *start, *end;
    
public:
    BigNumber();
    //static BigNumber fc();
    //BigNumber (const BigNumber &x);
    //~BigNumber(); //acest minunat destructor se apeleaza aiurea si imi creeaza probleme
    void add_elem (int x);
    template <class T2> friend istream& operator>> (istream &y, BigNumber<T2> &number);
    template <class T2> friend ostream& operator<< (ostream& y, BigNumber<T2> &number);
    template <class T2> friend int count(BigNumber<T2> A);
    void delete_number();
    int compare (BigNumber<T1> SecondNr);
    void sum (BigNumber<T1> FirstNr, BigNumber<T1> SecondNr);
    void sub (BigNumber<T1> FirstNr, BigNumber<T1> SecondNr);
    BigNumber<T1> operator+ (BigNumber<T1> SecondNr); //initial era functie friend a clasei
    template <class T2> friend BigNumber<T2> operator- (BigNumber<T2> FirstNr, BigNumber<T2> SecondNr);
    template <class T2> friend BigNumber<T2> operator* (BigNumber<T2> FirstNr0, BigNumber<T2> SecondNr0);
    BigNumber<T1> operator= (BigNumber<T1> x);
    template <class T2> friend class Array;
    virtual void print();
    
    BigNumber<T1> operator *= (BigNumber<T1> SecondNr);
    BigNumber<T1> operator--(); //prefix
    BigNumber<T1> operator--(int y); //postfix
};

template <class T1>
class Even_BigNumber:public BigNumber<T1>
{
public:
    Even_BigNumber():BigNumber<T1>(){};
    template <class T2> friend istream& operator>>(istream &y, Even_BigNumber<T2> &number);
    template <class T2>friend ostream& operator<<(ostream& y, Even_BigNumber<T2> &number);
    
};

template <class T1>
class Fibonacci_BigNumber:public BigNumber<T1>
{
public:
    Fibonacci_BigNumber():BigNumber<T1>(){};
};

template <class T1>
class Even_Fibonacci_BigNumber:public Even_BigNumber<T1> , public Fibonacci_BigNumber<T1>
{
public:
    Even_Fibonacci_BigNumber():Even_BigNumber<T1>(){};
    void print();
};

template <class T1> BigNumber<T1>::BigNumber() //constructorul imi va initializa pointerii de inceput si de sfarsit ai listei cu null
{
    start = nullptr;
    end = nullptr;
}

template <class T2> void BigNumber<T2>::print()
{
    elem<int> *p;
    p = end;
    if (start->info == 10) cout << "+"; //afisez semnul numarului; 10 = '+', 11 = '-'
    else if (start->info == 11) cout << "-";
    while (p->prev) //conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja,deci merge pana la al doilea nod
    {
        cout << p->info;
        p = p->prev;
    }
}

template <class T2> void Even_Fibonacci_BigNumber<T2>::print()
{
    elem<int> *p;
    p = Even_BigNumber<T2>::end;
    if (Even_BigNumber<T2>::start->info == 10) cout << "+"; //afisez semnul numarului; 10 = '+', 11 = '-'
    else if (Even_BigNumber<T2>::start->info == 11) cout << "-";
    while (p->prev) //conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja,deci merge pana la al doilea nod
    {
        cout << p->info;
        p = p->prev;
    }
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
