//
//  Unicode_String.h
//
//
//  Created by nash on 9/20/16.
//  By NashBean (https://github.com/NashBean)
//  Copyright 2015-2018 iBean Software (https://ibeansoftware.github.io/)
//  All rights reserved.
//

#ifndef iBS_Uchar_h
#ifndef iBS_Unicode_String_h
#define iBS_Unicode_String_h

//
//  Uchar.h  // Uchar header
//  Get cureent version off Github:
//  https://github.com/NashBean/UTF-8_Vector/blob/master/Uchar.h
//
//  Created by nash on 9/18/15.
//  Copyright© 2015+ iBean Software. All rights reserved.
//  iBeanSoftware@GMail.com
//  https://www.facebook.com/iBeanSoftware
//
//  a struct to hold a multi length UTF-8 char
//  Constructs using 0-6: 8 bit bytes
//  to hold a Unicode Int.
//  std::vector safe.
//  And should be fast in most cases.


#include "UTF-8_String.h"

const int iBS_UStr_MAJOR_VERSION = 3;
const int iBS_UStr_MINOR_VERSION = 0;

namespace iBS 
{
    //---------------------------------------------------------------
    // next group keeps a Unicode as a single 32 bit Unsigned Integer
    //---------------------------------------------------------------
    /*    
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
     
     uint& operator+(uint32_t unicode){ set(value+unicode); return *this; };
     uint& operator-(uint32_t unicode){ set(value-unicode); return *this; };
     
     bool operator==(char c) { std::string str; return (value == (uint32_t)c); };
     bool operator==(int i) { return (value == (uint32_t)i); };
     bool operator==(uint32_t unicode) { return (value == unicode); };
     bool operator==(uint unicode) { return (value == unicode.get()); };
     bool operator<(uint32_t unicode) { return (value < unicode); };
     bool operator>(uint32_t unicode) { return (value > unicode); };
     bool operator<=(uint32_t unicode) { return (value <= unicode); };
     bool operator>=(uint32_t unicode) { return (value >= unicode); };
     
     uint32_t get() { return value; };
     void set(uint32_t v) { value = v; };
     void set(uint v) { value = v.value; };
     
     
     private:    
     uint32_t value;
     
     };
     //*/   
    //-----------------------------------------------
    //inline function for uint 
    //-----------------------------------------------
    inline UnicodeInt decode(std::vector<char>& c)
    {
        uint64_t result = uint64_t(0);
        
        //UnicodeInt result=0;
        if (c.size()==0) { return UnicodeInt(result);}
        if (c.size()==1) { return UnicodeInt(c[0]); }
        if (c.size()==2) { result=c[0] & 0x1f; }
        else if (c.size()==3) { result=c[0] & 0x0f; }
        else if (c.size()==4) { result=c[0] & 0x07; }
        else if (c.size()==5) { result=c[0] & 0x03; }
        else if (c.size()==6) { result=c[0] & 0x01; }
        for (size_t i=1; i<c.size(); ++i) 
        { result=result<<6; result+=c[i] & 0x3f; }
        
        
        return UnicodeInt(result);
    };
    
    inline UnicodeInt decode(wchar_t& wch)
    {
        //  uint result = uint();
        
        
        //*  test more
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
    
    struct raw_u8str 
    {
        std::vector <unsigned char> ref;
    };
    
    //-----------------------------------------------
    //uchar = uint made to hold any char of the world
    //-----------------------------------------------
    
    struct uchar
    {
    private:    
        UnicodeInt value;
        
    public:
        uchar():value(0){}; 
        uchar(int v):value(v){}; 
        uchar(long v):value(v){}; 
        uchar(UnicodeInt v):value(v){}; 
        //uchar(uint v):value(v.get()){}; 
        uchar(char v):value((uint32_t)v){}; 
        uchar(uchar const &v):value(v.value){}; 
        uchar(wchar_t wch):value(decode(wch)){}; 
        
        UnicodeInt get() { return value; };
        void set(UnicodeInt v) { value = v; };
        //uint get() { return value; };
        //void set(uint v) { value = v; };
        void set(uchar uch) { value = uch.value; };
        void set(wchar_t wch) { value = decode(wch); };
        void set(int64_t i64) { set((UnicodeInt)i64); };
        
        uchar& operator=(int unicode){ set((UnicodeInt)unicode); return *this; };
        uchar& operator=(UnicodeInt unicode){ set(unicode); return *this; };
        //uchar& operator=(uint unicode) { set(unicode); return *this; };
        uchar& operator=(char ch) { set((UnicodeInt)ch); return *this; };
        uchar& operator=(uchar const& uch) { set(uch); return *this; };
        uchar& operator=(wchar_t wch) { set(wch); return *this; };
        uchar& operator=(int64_t i64) { set((UnicodeInt)i64); return *this; };
        
        bool operator==(int i) { return (value == i); };
        bool operator==(UnicodeInt unicode) { return (value == unicode); };
        //bool operator==(uint unicode) { return (value == unicode); };
        bool operator==(char c) { return (value == c); };
        bool operator==(uchar uch) { return (value == uch.value); };
        
        bool operator<(UnicodeInt unicode) { return (value < unicode); };
        bool operator>(UnicodeInt unicode) { return (value > unicode); };
        bool operator<=(UnicodeInt unicode) { return (value <= unicode); };
        bool operator>=(UnicodeInt unicode) { return (value >= unicode); };
        
        UnicodeInt lower_case() { if(value>=65 && value<=90) return (value+32); else return value;};
        UnicodeInt upper_case() { if(value>=97 && value<=122) return (value-32); else return value;};
        
    };
    
    //------------------------------------------------------------------
    // ustr = the last string container you will ever need!!!
    //------------------------------------------------------------------
    
    struct ustr
    {
        ustr():ref(0){ref.reserve(1);};//ref[0]='\x0000';};
        // ustr(std::vector<unsigned char>& c):ref(c.size())
        // {   // should I just allacate here?
        //     for (size_t i=0; i<ref.size(); ++i) 
        //     {   ref[i]=c[i];   }
        // };
        ~ustr(){if(ref.size())ref.clear();};
        ustr(UnicodeInt unicode):ref(1) { ref[0] = unicode; };
        ustr(char ch):ref(1) { ref[0] = ch; };
        ustr(wchar_t wch):ref(1) { ref[0] = wch; };
        ustr(std::vector<unsigned char>& raw_utf8):ref(0) 
        { 
            //todo
        };
        ustr(unsigned char* raw_utf8):ref(0) 
        { 
            //todo
        };
        ustr(std::string str):ref(str.size()) 
        { 
            //todo
        };
        
        ustr& operator=(ustr const& x)// required by C++ for vector
        {
            ref.resize(x.ref.size());   
            for (size_t i=0; i<ref.size(); ++i) 
            {   ref[i]=x.ref[i];   }
            return *this;
        };
        ustr& operator=(char ch)
        {
            ref.resize(1);
            ref[0] = ch;
            return *this;
        };
        ustr& operator=(wchar_t& wc)
        {
            ref.resize(1);
            ref[0] = wc;
            return *this;
        };
        size_t size() const  { return ref.size(); };    
        
        std::string str()
        {
            if (ref.size()==0) 
            { return ""; }
            std::stringstream result;
            uchar temp = uchar();
            for (size_t i=0; i<ref.size(); ++i) 
            {
                temp = ref[i];
                //todo!          temp.appendtostr(result);// todo uchar.appendtostr(std::stringstream& result)
            }
            return result.str();
        };
        
        
    private:    
        std::vector<uchar> ref;
    };
    
    //-----------------------------------------------------------------------------
    // utext = string list container saved as a uint32_t multi leangth col sized grid
    //-----------------------------------------------------------------------------
    struct utext
    {
        utext():ref(0){ref.reserve(1);};
        // ustr(std::vector<unsigned char>& c):ref(c.size())
        // {   // should I just allacate here?
        //     for (size_t i=0; i<ref.size(); ++i) 
        //     {   ref[i]=c[i];   }
        // };
        ~utext(){if(ref.size())ref.clear();};
        utext(UnicodeInt unicode):ref(1) { ref[0] = unicode; };
        utext(char ch):ref(1) { ref[0] = ch; };
        utext(wchar_t wch):ref(1) { ref[0] = wch; };
        utext(std::vector<unsigned char>& raw_utf8):ref(0) 
        { 
            //todo
        };
        utext(unsigned char* raw_utf8):ref(0) 
        { 
            //todo
        };
        utext(std::string str):ref(1) 
        { 
            ref[0] = str;
        };
        
        utext& operator=(utext const& x)// required by C++ for vector
        {
            ref.resize(x.ref.size());   
            for (size_t i=0; i<ref.size(); ++i) 
            {   ref[i]=x.ref[i];   }
            return *this;
        };
        utext& operator=(char ch)
        {
            ref.resize(1);
            ref[0] = ch;
            return *this;
        };
        utext& operator=(wchar_t& wc)
        {
            ref.resize(1);
            ref[0] = wc;
            return *this;
        };
        size_t size() const  { return ref.size(); };    
        
        std::string str(size_t index)
        {
            return ref[index].str();
        };
        
    private:    
        std::vector<ustr> ref;
    };
    
    
    
}//end of namespace iBS 

#endif // iBS_u8char_h


#endif // iBS_Unicode_String_h
