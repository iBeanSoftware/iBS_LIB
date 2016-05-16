//
//  iBS_Header.h
//  iBS_LIB
//
//  Created by nash on 5/15/16.
//  Copyright 2016 iBean Software. 
//  All rights reserved.
//  http://www.NashBean.github.io/index.html 
//
#ifndef iBS_Header_h
#define iBS_Header_h

#include <vector>
#include <cwchar>


const int iBS_HEADER_MAJOR_VERSION = 0;
const int iBS_HEADER_MINOR_VERSION = 4;

namespace iBS 
{
    
    //-----------------------------------------------
    // uint = unsigned 32 bit int made to hold Unicode value
    //-----------------------------------------------
    struct uint 
    {
        uint():value(0){}; 
        uint(int v):value((uint32_t)v){}; 
        uint(long v):value((uint32_t)v){}; 
        uint(char v):value((uint32_t)v){}; 
        uint(uint const &v):value(v.value){}; 
        uint(uint32_t v):value(v){}; 
        
        uint& operator=(uint unicode) { set(unicode.value); return *this; };
        uint& operator=(uint32_t unicode){ set(unicode); return *this; };
        uint& operator=(char ch) { set((uint32_t)ch); return *this; };

        bool operator==(char c) { std::string str; return (value == (uint32_t)c); };
        bool operator==(int i) { return (value == (uint32_t)i); };
        bool operator==(uint32_t unicode) { return (value == unicode); };
        bool operator==(uint unicode) { return (value == unicode.get()); };
        
        uint32_t get() { return value; };
        void set(uint32_t v) { value = v; };
        
    private:    
        uint32_t value;
        
    };
 
    //-----------------------------------------------
    //inline function for uint 
    //-----------------------------------------------
    inline uint decode(std::vector<char>& c)
    {
        uint32_t result = uint32_t(0);
        
       //UnicodeInt result=0;
        if (c.size()==0) { return uint(result);}
        if (c.size()==1) { return uint(c[0]); }
        if (c.size()==2) { result=c[0] & 0x1f; }
        else if (c.size()==3) { result=c[0] & 0x0f; }
        else if (c.size()==4) { result=c[0] & 0x07; }
        else if (c.size()==5) { result=c[0] & 0x03; }
        else if (c.size()==6) { result=c[0] & 0x01; }
        for (size_t i=1; i<c.size(); ++i) 
        { result=result<<6; result+=c[i] & 0x3f; }
        
        
        return uint(result);
    };
    
    inline uint decode(wchar_t& wch)
    {
      //  uint result = uint();
        
        
        //*
         char temp[6];
         std::vector<char> ref;
         std::mbstate_t state ;
         int ret = std::wcrtomb((&temp[0]), wch, &state);
             
         ref.resize(ret);
         for (short i=0; i<ret; ++i) 
             ref[i]=temp[i];
         //*/
        return decode(ref);
    };

    //-----------------------------------------------
    //uchar = uint made to hold any char of the world
    //-----------------------------------------------
     struct uchar
    {
        uchar():value(0){}; 
        uchar(int v):value((uint32_t)v){}; 
        uchar(long v):value((uint32_t)v){}; 
        uchar(uint32_t v):value(v){}; 
        uchar(uint v):value(v.get()){}; 
        uchar(char v):value((uint32_t)v){}; 
        uchar(uchar const &v):value(v.value){}; 
        uchar(wchar_t wch):value(decode(wch)){}; 
        
        uchar& operator=(int unicode){ set((uint32_t)unicode); return *this; };
        uchar& operator=(uint32_t unicode){ set(unicode); return *this; };
        uchar& operator=(uint unicode) { set(unicode.get()); return *this; };
        uchar& operator=(char ch) { set((uint32_t)ch); return *this; };
        uchar& operator=(uchar uch) { set(uch.get()); return *this; };
        uchar& operator=(wchar_t wch) { set(decode(wch).get()); return *this; };// use of Uchar.h
        
        bool operator==(int i) { return (value == i); };
        bool operator==(uint32_t unicode) { return (value == unicode); };
        bool operator==(uint unicode) { return (value == unicode); };
        bool operator==(char c) { return (value == c); };
        bool operator==(uchar uch) { return (value == uch.value); };
        
        uint32_t get() { return value.get(); };
        void set(uint32_t v) { value = v; };

    private:    
        uint value;
    };
    
    //-----------------------------------------------
    //
    //-----------------------------------------------
    struct ustr
    {
        
    private:    
        std::vector<uchar> ref;
    };
    
    
    
}// end of iBS namespace
#endif // iBS_Header_h