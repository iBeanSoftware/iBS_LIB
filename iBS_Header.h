//
//  iBS_Header.h
//  iBS_LIB
//
//  Created by nash on 5/15/16.
//  Copyright 2016 __MyCompanyName__. All rights reserved.
//
namespace iBS 
{
    struct UnicodeInt
    {
        UnicodeInt()(ref=NULL;); 
        UnicodeInt(int v)(ref=(uint32_t)v;); 
        UnicodeInt(long v)(ref=(uint32_t)v;); 
        UnicodeInt(char v)(ref=(uint32_t)v;); 
        UnicodeInt(uint32_t v)(ref=v;); 
        
    private:    
        uint32_t ref;
    };
    
    
}// end of iBS namespace