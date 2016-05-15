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
    
    iBS::uint testint = iBS::uint();
    
    std::cout << testint.get() << std::endl;

    testint = 'A';
    std::cout << "A = " << testint.get() << "  Z = "<<iBS::uint('Z').get() <<std::endl;

    testint = 'a';
    std::cout << "a = " << testint.get() << "  z = "<<iBS::uint('z').get() <<std::endl;
    
    char ch = char(testint.get());
    
    std::cout << "a = " << ch << "  z = "<<char(iBS::uint('z').get()) <<std::endl;

    
    ch = char(testint.get());
    
    std::cout << "a = " << ch << "  z = "<<char(iBS::uint('z').get()) <<std::endl;
  
    testint = '\r';
    std::cout << "return = " << testint.get() << "  tab = "<<iBS::uint('\t').get() <<std::endl;

    return 0;
}

