//
//  Division.h
//  POO- Proiect 1- Numere mari- Clase
//
//  Created by Ioana Toma on 17/03/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

void BigNumber::division (int x)
{
    if (end->info == 0)
        if (x != 0) cout << 0;
        else cout << "Nu se poate face impartirea!";
    else
    {
        if (start->info == 10)
            cout << "+";
        else cout << "-";
        if (end->prev->info == 10 || end->prev->info == 11)
            cout << end->info/x;
        else
        {
            elem *p = end;
            int d, c, r;
            if (p->info < x)
            {
                d = p->info * 10 + p->prev->info;
                c = d/x;
                cout << c;
                r = d - c * x;
                p = p->prev->prev;
            }
            else
            {
                d = p->info;
                c = d/x;
                cout << c;
                r = d - c * x;
                p = p->prev;
            }
            while (p->prev)
            {
                d = r * 10 + p->info;
                c = d/x;
                cout << c;
                r = d - c * x;
                p = p->prev;
                if (p->info == 10 || p->info == 11) break;
            }
        }
    }
}
