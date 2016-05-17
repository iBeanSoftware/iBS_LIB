//
//  main.cpp
//  iBS_LIB
//
//  Created by nash on 5/15/16.
//  Copyright 2016 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "iBS_Header.h"

int main (int argc, const char * argv[])
{
    
    iBS::uint u_int = iBS::uint();
    
    std::cout << u_int.get() << std::endl;

    u_int = 'A';
    std::cout << "A = " << u_int.get() << "  Z = "<<iBS::uint('Z').get() <<std::endl;

    u_int = 'a';
    std::cout << "a = " << u_int.get() << "  z = "<<iBS::uint('z').get() <<std::endl;
    
    char ch = char(u_int.get());
    
    std::cout << "a = " << ch << "  z = "<<char(iBS::uint('z').get()) <<std::endl;

    iBS::uchar uch = iBS::uchar(u_int); // created uchar from a uint
    
    wchar_t w = wchar_t(uch.get()); // created wchar_t with uchar
    //w = 'A';
    std::cout << "a = " << w << "  z = "<<char(iBS::uchar('z').upper_case()) <<std::endl;
  
    u_int = '\r';
    std::cout << "return = " << u_int.get() << "  tab = "<<iBS::uint('\t').get() <<std::endl;

    return 0;
}

