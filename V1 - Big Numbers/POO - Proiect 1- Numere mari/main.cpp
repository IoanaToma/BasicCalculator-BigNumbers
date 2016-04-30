//
//  main.cpp
//  POO - Proiect 1- Numere mari
//
//  Created by Ioana Toma on 02/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

struct elem
{
    int info;
    elem *next;
    elem *prev;
};

void add_elem (elem *&start, elem *&end, int x) //adauga un element la lista dublu inlantuita
{
    if (!start) //daca lista nu contine niciun nod, creeaza primul nod
    {
        start = new elem;
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

int compare(elem *p, elem *q) //compara cele doua numere, comparand pe rand cifrele lor, plecand de la
{                             //cifra dominanta (acest caz este folosit doar daca numerele au numar egal de cifre)
    int ok = 0;
    while (!ok && p->prev && q->prev)
    {
        if (p->info > q->info) ok = 1; //daca in primul numar a gasit o cifra mai mare decat cifra celui de-al doilea, este clar ca primul este
        if (p->info < q->info) ok = 2; //mai mare in modul; la fel si pentru cazul in care a doilea are o cifra mai mare; subprogramul
        p = p->prev;                   //da un rezultat corect, intrucat parcurge in paralel cifrele celor doua numere
        q = q->prev;
    }
    return ok;
}

void greater_number (int &ok, int n1, int n2, elem *end1, elem *end2)
{
    if (n1 < n2) //daca primul numar are mai putine cifre, cel de-al doilea este clar mai mare in modul
    {
        ok = 2; //valorea lui ok va reprezenta care numar este mai mare
        cout << "Al doilea numar este mai mare decat primul in modul";
    }
    else if (n1 > n2) //daca cel de-al doilea numar are mai multe cifre, primul este clar mai mare in modul
    {
        ok = 1;
        cout << "Primul numar este mai mare decat al doilea in modul";
    }
    else if (compare (end1, end2) == 1)
    {
        ok = 1;
        cout << "Primul numar e mai mare decat al doilea in modul";
    }
    else if (!compare (end1, end2))
    {
        ok = 0;
        cout << "Cele doua numere sunt egale in modul";
    }
    else
    {
        ok = 2;
        cout << "Al doilea numar este mai mare decat primul in modul";
    }
    cout << endl;
}

void print (elem *start, elem *end)
{
    elem *p;
    p = end;
    if (start->info == 10) cout << "+";         //afisez semnul numarului; 10 = '+', 11 = '-'
    else cout << "-";
    while (p->prev) // conditia este pusa astfel deoarece primul nod reprezinta semnul, pe care l-am afisat deja
    {
        cout << p->info;
        p = p->prev;
    }
    cout << endl;
}

//suma se face plecand de la cifra unitatilor
void sum (elem *start1, elem *start2, elem *&starts, elem *&ends) //suma a doua numere de acelasi semn (suma uzuala)
{
    int k = 0, s;
    elem *p = start1, *q = start2;
    while (p && q)                         //creez lista suma; atata timp cat exista cifre pentru ambele numere
    {
        if (p->info + q->info + k >= 10) //decid daca am transport la urmatoarea cifra; la suma celor doua cifre adaug si transportul,daca exista
        {
            s = (p->info + q->info + k)%10;
            k = 1; //k = transportul
        }
        else
        {
            s = p->info + q->info + k;
            k = 0;
        }
        add_elem(starts, ends, s); //creez un nou nod in lista suma
        p = p->next;
        q = q->next;
        
        if (!p && !q && k)                //decid daca dupa adunarea ultimelor doua cifre este necesar
            add_elem(starts, ends, k);    //sa creez un nou nod pentru transportul ramas
    }
    
    while (p)                           //acest while este doar pentru cazul in care numarul mai mare in modul
    {                                   //are mai multe cifre
        if (p->info + k >= 10)
        {
            s = (p->info +k)%10;
            k = 1;
        }
        else
        {
            s = p->info + k;
            k = 0;
        }
        add_elem(starts, ends, s);
        p = p->next;
        
        if (!p && k) //daca s-a terminat lista reprezentand numarul mai mare in modul, dar mai aveam inca un transport de facut,creez inca un nod
            add_elem(starts, ends, k);
    }
}

//diferenta se face plecand de la cifra unitatilor
void sub (elem *start1, elem *start2, elem *&startsb, elem *&endsb) //diferenta a doua numere de acelasi semn (diferenta uzuala)
{
    int k = 0, d;
    elem *p = start1, *q = start2;
    while (p && q)                      //creez lista scadere; atata timp cat am cifre in ambele numere
    {
        if (p->info - k < q->info) //decid daca trebuie sa 'imprumut' de la urmatoarea cifra
        {
            d = p->info - q->info - k + 10;
            k = 1; //k= 'imprumutul'
        }
        else
        {
            d = p->info - q->info - k;
            k = 0;
        }
        add_elem(startsb, endsb, d); //creez/adaug un nou nod la lista diferenta
        p = p->next;
        q = q->next;
    }
    while (p)                           //pentru cazul in care numarul mai mare are mai multe cifre
    {
        if (p->info - k < 0)
        {
            d = p->info - k + 10;
            k = 1;
        }
        else
        {
            d = p->info - k;
            k = 0;
        }
        add_elem(startsb, endsb, d); //adaug noi elemente la lista scadere
        p = p->next;
    }
    p = endsb;
    while (p->prev && !p->info)         //avand in vedere ca rezultatul scaderii poate avea mai putine
    {                                   //cifre decat numerele initiale, sterg toate zerourile de la
        q = endsb;                      //capat inspre inceput, pentru a nu afisa numere precum
        endsb = p->prev;                // "0001" sau "0000" (pentru a lasa doar cifrele diferite de 0
        endsb->next = NULL;             //incepand cu cifra unitatilor
        delete q;
        p = endsb;
    }
}

//"adunarea" a doua numere poate fi si 'adunare uzuala', si 'scadere uzuala', in functie de ce semn au
void addition (elem *start1, elem *start2, elem *&starts, elem *&ends, int ok)
{
    elem *t;
    t = new elem;
    if (!ok || ok == 1) //daca cele doua numere sunt egale sau primul numar este mai mare in modul
    {
        if (start1->info == start2->info) //daca au acelasi semn, apelez suma uzuala, considerand primul numar mai mare in modul
        {
            sum (start1->next, start2->next, starts, ends);
            t->info = start1->info; //rezultatul va avea semnul comun al numerelor
        }
        else
        {
            sub (start1->next, start2->next, starts, ends); //daca au semne diferite, apelez diferenta uzuala
            if (!ok) t->info = 10; //daca cele doua numere sunt egale, semnul va fi + (sa afiseze "+0")
            else t->info = start1->info; //altfel rezultatul va avea semnul numarului mai mare in modul
        }
    }
    else //daca cel de-al doilea numar este mai mare in modul
    {
        if (start1->info == start2->info) //daca cele doua numere au acelasi semn
        {
            sum (start2->next, start1->next, starts, ends); //apelez suma uzuala, considerand cel de-al doilea numar mai mare in modul
            t->info = start2->info; //semnul rezultatului va fi semnul comun al celor doua numere
        }
        else //daca au semne diferite
        {
            sub (start2->next, start1->next, starts, ends); //apelez diferenta uzuala, considerand cel de-al doilea numar mai mare in modul
            t->info = start2->info; //semnul rezultatului va fi semnul numarului mai mare in modul
        }
    }
    t->next = starts; //creez nodul pentru semn, pe care il adaug inaintea primul nod al listei suma
    t->prev = NULL;
    starts->prev = t;
    starts = t;
}

//"scaderea" a doua numere poate fi si 'adunare uzuala', si 'scadere uzuala', in functie de ce semn au
void subtraction (elem *start1, elem *start2, elem *&startsb, elem *&endsb, int ok)
{
    elem *t;
    t = new elem;
    if (!ok || ok == 1) //daca numerele sunt egale sau primul este mai mare in modul
    {
        if (start1->info == start2->info) //daca au acelasi semn
        {
            sub (start1->next, start2->next, startsb, endsb);//apelez diferenta uzuala, considerand primul numar mai mare in modul
            if (!ok) t->info = 10; //daca numerele sunt egale, vreau sa imi afiseze "+0"
            else t->info = start1->info; //altfel semnul rezultatului va fi semnul comun al celor doua numere
        }
        else //daca au semne diferite
        {
            sum (start1->next, start2->next, startsb, endsb);//apelez suma, considerand primul numar mai mare in modul
            t->info = start1->info; //semnul rezultatului va fi semnul numarului mai mare in modul
        }
    }
    else //daca al doilea numar este mai mare in modul
    {
        if (start1->info == start2->info) //daca au acelasi semn
        {
            sub (start2->next, start1->next, startsb, endsb);//apelez diferenta uzuala, considerand al doilea numar mai mare in modul
            if (start2->info == 10) t->info = 11; //semnul rezultatului va fi "inversul" semnului numarului care este mai mare in modul
            else t->info = 10;
        }
        else //daca au semne diferite
        {
            sum (start2->next, start1->next, startsb, endsb); //apelez suma, considerand al doilea numar mai mare in modul
            if (start2->info == 10) t->info = 11; //semnul rezultatului va fi "inversul" semnului numarului mai mare in modul
            else t->info = 10;
        }
    }
    t->next = startsb; //creez nodul pentru semn, pe care il adaug inainte de primul nod al listei diferenta
    t->prev = NULL;
    startsb->prev = t;
    startsb = t;
}

void multiplication (elem *start1, elem *end1, elem *start2, elem *end2, elem *&startp, elem *&endp)
{
    if (end1->info == 0 || end2->info == 0) //daca unul dintre numere este 0, produsul va fi 0, cu semnul "+"
    {
        add_elem(startp, endp, 10);
        add_elem(startp, endp, 0);
    }
    else //daca ambele numere sunt diferite de 0, produsul va fi diferit de 0
    {
        if (start1->info == start2->info) //daca numerele au acelasi semn, semnul produsului va fi "+"
            add_elem(startp, endp, 10);
        else add_elem(startp, endp, 11); //daca numerele au semne diferite, semnul produsului va fi "-"; am creat nodul pentru semn
        
        elem *p, *q;
        int k = 0, m;
        p = start1->next; // p = prima cifra a primului numar
        q = start2->next; //q = prima cifra a celui de-al doilea numar
        while (p)               //creez o lista care reprezinta produsul primului numar cu prima cifra
        {                       //a celui de-al doilea numar
            if (p->info * q->info + k >= 10) //decid daca voi avea transport sau nu
            {
                m = (p->info * q->info + k)%10; //m = cifra unitatilor a calculului
                k = (p->info * q->info + k)/10; //k = cat trebuie sa transport
            }
            else
            {
                m = p->info * q->info + k;
                k = 0;
            }
            add_elem(startp, endp, m); //adaug un nou nod la lista produs
            p = p->next;
            
            if (!p && k) //daca am ajuns la sfarsitul primei liste, insa mai aveam inca un transport de facut, mai adaug un nod
                add_elem(startp, endp, k);
        }
        p = start1->next; //p pleaca de fiecare data de la prima cifra a primului numar
        q = q->next; //trec la a doua cifra din al doilea numar
        elem *z;
        z = startp->next;
        z = z->next; //z = a doua cifra a produsului, plecand de la unitati
        while (q) //cat timp exista cifre in al doilea numar
        {
            k = 0; //initial, transportul este 0
            elem *x;
            x = z; //x va fi nodul din produs de la care trebuie sa incep sa adun noile rezultate, adica produse intre cifrele numerelor
            while (p && x) //cat timp exista cifre in primul numar si in lista produs initiala
            {
                if (p->info * q->info + x->info + k >= 10) //decid daca am transport
                {
                    m = (p->info * q->info + x->info + k)%10;
                    k = (p->info * q->info + x->info + k)/10; //k = transportul
                }
                else
                {
                    m = p->info * q->info + x->info + k;
                    k = 0;
                }
                x->info = m; //nodul din produs ia alta valoare, adica valoarea initiala + noul produs intre cifre + transport
                p = p->next;
                x = x->next;
                
                if (!p && k) //daca nu mai am cifre in primul numar, dar mai am transport, adaug un nod in plus
                    add_elem(startp, endp, k);
                
            }
            while (p) //daca s-a terminat lista produs initiala, dar nu s-a terminat prima lista, adaug noi noduri la lista produs
            {
                if (p->info * q->info + k >= 10)
                {
                    m = (p->info * q->info + k)%10;
                    k = (p->info * q->info + k)/10;
                }
                else
                {
                    m = p->info * q->info + k;
                    k = 0;
                }
                add_elem(startp, endp, m);
                p = p->next;
                
                if (!p && k)
                {
                    add_elem(startp, endp, k);
                }
            }
            q = q->next;
            z = z->next;
            p = start1->next;
        }
    }
}

void read (elem *&start, elem *&end, int &n)
{
    int x;
    n = 0;
    cin >> x;
    while (x != -1)
    {
        add_elem (start, end, x);
        n++;
        cin >> x;
    }
}


int main ()
{
    ifstream f ("/Users/Ioana/Desktop/XCode Projects/POO - Proiect 1- Numere mari/POO - Proiect 1- Numere mari/First_number.txt");
    ifstream g ("/Users/Ioana/Desktop/XCode Projects/POO - Proiect 1- Numere mari/POO - Proiect 1- Numere mari/Second_number.txt");
    
    elem *start1, *start2, *end1, *end2;
    int x, n1 = 0, n2 = 0;
    
//construiesc prima lista reprezentand primul numar si numar cate cifre are
    while (f>>x) //citesc cifrele primului numar din primul fisier
    {
        add_elem (start1, end1, x);
        n1++; //numar cate cifre are primul numar
    }
    
//construiesc a doua lista reprezentand al doilea numar si numar cate cifre are
    while (g>>x) //citesc cifrele celui de-al doilea numar din al doilea fisier
    {
        add_elem (start2, end2, x);
        n2++; //numar cifrele celui de-al doilea numar
    }
    
//afisez primul numar
    cout << "Primul numar este: ";
    print (start1, end1);
    
//afisez cel de-al doilea numar
    cout << "Al doilea numar este: ";
    print (start2, end2);
    
//aflu care dintre cele doua numere este mai mare in modul
    int ok;
    greater_number(ok, n1, n2, end1, end2);

//calculez suma celor doua numere si o afisez
    elem *starts, *ends;
    addition(start1, start2, starts, ends, ok);
    cout << "Suma celor doua numere este: ";
    print (starts, ends);
    
//calculez diferenta celor doua numere si o afisez
    elem *startsb, *endsb;
    subtraction (start1, start2, startsb, endsb, ok);
    cout << "Diferenta celor doua numere este: ";
    print (startsb, endsb);
    
//calculez produsul celor doua numere si il afisez
    elem *startp, *endp;
    multiplication(start1, end1, start2, end2, startp, endp);
    cout << "Produsul celor doua numere este: ";
    print (startp, endp);
    cout << endl << endl;
    
//creez un meniu
    int y;
    do{
        cout << "Meniul dumneavoastra este: " << endl;
        cout << "0. Iesire din program" << endl;
        cout << "1. Modificarea primul numar- Pentru a finaliza introducerea de cifre, tastati -1" << endl;
        cout << "2. Modificarea celui de-al doilea numar- Pentru a finaliza introducerea de cifre, tastati -1" << endl;
        cout << "    Atentie! Pentru modificarea celor doua numere, primul numar introdus de la tastatura trebuie sa fie semnul: 10='+', 11='-'";
        cout << endl;
        cout << "3. Care numar este mai mare in modul?" << endl;
        cout << "4. Suma celor doua numere" << endl;
        cout << "5. Diferenta celor doua numere" << endl;
        cout << "6. Produsul celor doua numere" << endl;
        cout << "Optiunea este: ";
        cin >> y;
        switch (y)
        {
            case 0:
            {
                cout << "Multumesc pentru atentie!";
                break;
            }
            case 1:
            {
                elem *p;
                while (start1)
                {
                    p = start1;
                    start1 = start1->next;
                    delete p;
                }
                read (start1, end1, n1);
                cout << "Primul numar este acum: ";
                print (start1, end1);
                break;
            }
            case 2:
            {
                elem *p;
                while (start2)
                {
                    p = start2;
                    start2 = start2->next;
                    delete p;
                }
                read (start2, end2, n2);
                cout << "Al doilea numar este acum: ";
                print (start2, end2);
                break;
            }
            case 3:
            {
                greater_number (ok, n1, n2, end1, end2);
                break;
            }
            case 4:
            {
                elem *starts, *ends;
                addition(start1, start2, starts, ends, ok);
                cout << "Suma celor doua numere este: ";
                print (starts, ends);
                break;
            }
            case 5:
            {
                elem *startsb, *endsb;
                subtraction (start1, start2, startsb, endsb, ok);
                cout << "Diferenta celor doua numere este: ";
                print (startsb, endsb);
                break;
            }
            case 6:
            {
                elem *startp, *endp;
                multiplication(start1, end1, start2, end2, startp, endp);
                cout << "Produsul celor doua numere este: ";
                print (startp, endp);
                break;
            }
        }
        cout << endl << endl;
    } while (y);
            
    f.close();
    g.close();
    
    return 0;
}
