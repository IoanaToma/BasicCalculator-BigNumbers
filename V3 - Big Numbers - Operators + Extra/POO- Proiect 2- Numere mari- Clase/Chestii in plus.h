//
//  Chestii in plus.h
//  POO- Proiect 2- Numere mari- Clase
//
//  Created by Ioana Toma on 28/04/14.
//  Copyright (c) 2014 Ioana Toma. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

BigNumber BigNumber::operator*= (BigNumber SecondNr)
{
    *this = *this * SecondNr;
    return *this;
}

BigNumber BigNumber::operator--()
{
    BigNumber x;
    x.add_elem(10);
    x.add_elem(1);
    *this = *this - x;
    return *this;
}

BigNumber BigNumber::operator--(int y)
{
    BigNumber x;
    x.add_elem(10);
    x.add_elem(1);
    *this = *this - x;
    return *this;
}

