//
//  UTF-8_String.h
//
//
//  Created by nash(https://github.com/NashBean) on 9/20/16.
//  Copyright 2016 iBean Software(https://iBeanSoftware.github.io),
//  All rights reserved.
//

#ifndef iBS_Uchar_h
#ifndef iBS_UTF_8_String_h
#define iBS_UTF_8_String_h

//
//  Uchar.h  // Uchar header
//  Get cureent version off Github:
//  https://github.com/NashBean/UTF-8_Vector/blob/master/Uchar.h
//
//  Created by nash on 9/18/15.
//  Copyright© 2015+ iBean Software. All rights reserved.
//  iBeanSoftware@GMail.com
//  https://www.facebook.com/iBeanSowtware
//
//  a struct to hold a multi length UTF-8 char
//  Constructs using 0-6: 8 bit bytes
//  to hold a UTF-8 char.
//  Should be std::vector safe
//  And should be fast.


#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cwchar>

const int UTF8Str_MAJOR_VERSION = 3;
const int UTF8Str_MINOR_VERSION = 4;

namespace iBS 
{
/*  rem switch to change from 32 bit int - 64 bit int
#define UnicodeInt uint32_t 
/*/    
#define UnicodeInt uint64_t
//*/
    
    //-------
    typedef struct  u8char  //Changed struct name to match C++ standerds
    {     //-------
        
        u8char():ref(0){ref.reserve(1);};//ref[0]='\x0000';};
        u8char(std::vector<unsigned char>& c):ref(c.size())
        {   // should I just allacate here?
            if(c.size()>6)    resize(6);//making 6 max size
            for (size_t i=0; i<ref.size(); ++i) 
            {   ref[i]=c[i];   }
        };
        ~u8char(){if(ref.size())ref.clear();};
        u8char(UnicodeInt unicode):ref(1)
        {   
            setUnicode(unicode); 
        };
        u8char(char ch):ref(1)
        {   
            setUnicode((UnicodeInt)ch); 
        };
        u8char(wchar_t ch):ref(1)
        {   
            char temp[6];
            std::mbstate_t state ;
            int ret = std::wcrtomb((&temp[0]), ch, &state);
            ref.resize(ret);
            for (short i=0; i<ret; ++i) 
                ref[i]=temp[i];
        };
        u8char& operator=( u8char const& x)
        {
            resize(x.ref.size());   
            for (size_t i=0; i<ref.size(); ++i) 
            {   ref[i]=x.ref[i];   }
            return *this;
        };
        u8char& operator=(UnicodeInt unicode)
        {
            setUnicode(unicode); 
            return *this;
        };
        u8char& operator=(char ch)
        {
            setUnicode((UnicodeInt)ch); 
            return *this;
        };
        u8char& operator=(wchar_t& wc)
        {
            char temp[6];
            std::mbstate_t state ;
            int ret = std::wcrtomb((&temp[0]), wc, &state);
            ref.resize(ret);
            for (short i=0; i<ret; ++i) 
                ref[i]=temp[i];
            return *this;
        };
        size_t size() const  { return ref.size(); };
        void   encode(unsigned int& unicode){setUnicode(unicode);}; 
        inline void setUnicode(UnicodeInt unicode)
        { //converts unicode into UTF-8 formatted u8char  
            if (unicode<=0x7f) 
            {
                resize(1);    
                ref[0]=  unicode;
            }  
            else if (unicode>=0x80 && unicode<=0x07ff) 
            {
                resize(2);    
                unsigned char temp;     
                temp=unicode;
                ref[1]=temp&0x3f;
                ref[1]=ref[1]|0x80;
                temp=unicode>>6;
                ref[0]=temp&0x1f;
                ref[0]=ref[0]|0xc0;
            }  
            else if (unicode>=0x0800 && unicode<=0xffff) 
            {
                resize(3);    
                unsigned char temp;     
                temp=unicode;
                ref[2]=temp&0x3f;
                ref[2]=ref[2]|0x80;
                temp=unicode>>6;
                ref[1]=temp&0x3f;
                ref[1]=ref[1]|0x80;
                temp=unicode>>12;
                ref[0]=temp&0x0f;
                ref[0]=ref[0]|0xe0;
            }  
            else if(unicode>=0x010000 && unicode<=0x1fffff) 
            {
                resize(4);
                unsigned char temp;     
                temp=unicode;
                ref[3]=temp&0x3f;
                ref[3]=ref[3]|0x80;
                temp=unicode>>6;
                ref[2]=temp&0x3f;
                ref[2]=ref[2]|0x80;
                temp=unicode>>12;
                ref[1]=temp&0x3f;
                ref[1]=ref[1]|0x80;
                temp=unicode>>18;
                ref[0]=temp&0x07;
                ref[0]=ref[0]|0xf0;
            }  
            else if(unicode>=0x200000 && unicode<=0x03ffffff) 
            {
                resize(5);
                unsigned char temp;     
                temp=unicode;
                ref[4]=temp & 0x3f;
                ref[4]=ref[4]|0x80;
                temp=unicode>>6;
                ref[3]=temp & 0x3f;
                ref[3]=ref[3]|0x80;
                temp=unicode>>12;
                ref[2]=temp & 0x3f;
                ref[2]=ref[2]|0x80;
                temp=unicode>>18;
                ref[1]=temp & 0x3f;
                ref[1]=ref[1]|0x80;
                temp=unicode>>24;
                ref[0]=temp&0x03;
                ref[0]=ref[0]|0xf8;
            }  
            else if(unicode>=0x04000000 && unicode<=0x7fffffff) 
            {
                resize(6);
                unsigned char temp;     
                temp=unicode;
                ref[5]=temp & 0x3f;
                ref[5]=ref[5]|0x80;
                temp=unicode>>6;
                ref[4]=temp & 0x3f;
                ref[4]=ref[4]|0x80;
                temp=unicode>>12;
                ref[3]=temp & 0x3f;
                ref[3]=ref[3]|0x80;
                temp=unicode>>18;
                ref[2]=temp & 0x3f;
                ref[2]=ref[2]|0x80;
                temp=unicode>>24;
                ref[1]=temp & 0x3f;
                ref[1]=ref[1]|0x80;
                temp=unicode>>30;
                ref[0]=temp&0x01;
                ref[0]=ref[0]|0xfc;
            }  
            else    ref[0]=0x00;
        };
        
        void setUnicode(UnicodeInt unicode)
            {setUnicode(UnicodeInt(unicode));};
        
        bool appendtostr(std::string& str)
        {
            try { for(size_t i=0; i<ref.size(); ++i) 
            { str+= ref[i]; } } 
            catch (...) { return false; }
            return true;
        };
        bool appendtostr(std::stringstream& str)
        {
            try { for(size_t i=0; i<ref.size(); ++i) 
            {  str<< char(ref[i]); } } 
            catch (...) { return false; }
            return true;
        };
        std::string str()
        {
            if (ref.size()==0) 
            { return ""; }
            std::stringstream result;
            try { for (size_t i=0; i<ref.size(); ++i) 
            { result<< char(ref[i]); } } 
            catch (...) { return "u8error"; }
            return result.str();
        };
        
   // protected:

        std::vector <unsigned char>  ref;//always keeps data in a UTF-8 format.
        
        void resize(size_t x)
        {
            if (ref.size()!=x) 
            {   
                if (ref.max_size()<x){  }//throw out of memory
                else {  ref.resize(x); }   
            }
        };       
    };
    //----------------------------------------------------------    
    //
    //----------------------------------------------------------    
    
    
    typedef struct u8str
    {
        std::vector<u8char> ref;

        u8str():ref(0){ref.reserve(64);};
        u8str(u8char uc):ref(1){ref.reserve(64); ref[0]=uc;};
        u8str(char ch):ref(1){ref.reserve(64); ref[0]=u8char(ch);};
        u8str(wchar_t ch):ref(1){ref.reserve(64); ref[0]=u8char(ch);};
        u8str(std::stringstream& str):ref(str.size()){if (str.size()) for(size_t i=0; i<ref.size(); ++i) ref[i]=str[i]);};
        u8str(std::vector<unsigned char>& c):ref(c.size()){for (size_t i=0; i<ref.size(); ++i) ref[i]=c[i];};
        u8str(std::string& str):ref(str.size()){if (ref.size()) for(size_t i=0; i<ref.size(); ++i) ref[i]=str[i];};
        ~u8str(){clear();};
        
        u8str& operator=(u8str const& str)
        {   ref.resize(str.ref.size());   
            for (size_t i=0; i<ref.size(); ++i) ref[i]=str.ref[i]; 
            return *this;
        };
        u8str& operator=(std::string const& str)
        {   ref.resize(str.length());   
            for (size_t i=0; i<ref.size(); ++i) ref[i]=str.ref[i]; 
            return *this;
        };

        
        size_t u8char_count(){return ref.size();};
        size_t size()// returns total count of unsigned char
        {   size_t s=0;
            for (size_t rs=0;rs<ref.size(); ++rs) 
            {   s+=ref[rs].ref.size();  }
            return s;
        };
        void clear(){if(ref.size())ref.clear();};
        
        void append(u8char uc){ref.push_back(uc);};
        void append(char ch){ref.push_back(u8char(ch));};
        void append(wchar_t ch){ref.push_back(u8char(ch));};
        void append(std::stringstream& str)
        {
            if (ref.size()) 
            {
                for (size_t i=0; i<ref.size(); ++i) 
                    ref[i].append(str);
            }
        };
        void append(std::string& str)
        {
            if (ref.size()) 
            {
                for (size_t i=0; i<ref.size(); ++i) 
                    ref[i].append(str);
            }
        };
        void append(std::vector<unsigned char>& c):ref(c.size())
        { 
            for (size_t i=0; i<c.size(); ++i) 
            {   ref.push_back(c[i]);   }
        };
        
        std::string str()
        {
            if (ref.size()==0) 
            { return ""; }
            std::stringstream result;
            for (size_t i=0; i<ref.size(); ++i) 
                ref[i].append(result);
            
            return result.str();
        };
        
    };
    
    typedef struct u8text
    {
        std::vector<u8str> ref;
        
        u8text():ref(0){ref.reserve(4);};
        u8text(u8char uc):ref(1){ref.reserve(4); ref[0]=u8str(uc);};
        u8text(char ch):ref(1){ref.reserve(4); ref[0]=u8str(ch);};
        u8text(wchar_t ch):ref(1){ref.reserve(4); ref[0]=u8str(ch);};
        u8text(std::stringstream& str):ref(1){ref.reserve(4); ref[0]=u8str(str);};
        u8text(std::vector<unsigned char>& c):ref(1){ref.reserve(4); ref[0]=u8str(c);};
        u8text(std::string& str):ref(1){ref.reserve(4); ref[0]=u8str(str);};
        ~u8text(){clear();};

        void append(u8str str){ref.push_back(str);};
        void append(std::string str){ref.push_back(u8str(str));};
        void append(std::stringstream& str){ref.push_back(u8str(str));};
        
        void clear(){if(ref.size())ref.clear();};
        size_t line_count()// returns total lines in text
        {  return ref.size(); };
        size_t letter_count()// returns total count of unsigned char
        {   size_t s=0;
            for (size_t rs=0;rs<ref.size(); ++rs) 
            {   s+=ref[rs].ref.size();  }
            return s;
        };
    };
    
    struct u8record
    {
        std::vector<u8str> ref;
        void append(u8str str){ref.push_back(str);};
        void clear(){ref.clear();};
        size_t width() {  return ref.size(); };

    };
    
    struct u8table
    {// ref[0] = field names, ref[1] = record 1
        std::vector<u8record> ref;
        void append(u8record rec){ref.push_back(rec);};
        void clear(){ref.clear();};
        size_t length() {  return ref.size(); };
    };
    
    
    //-------------------------------
    //      Useful UTF-8 Functions
    //-------------------------------
    //bool isLeadByte(unsigned char byte); //use ByteCount 
    
    bool isTrailByte(unsigned char byte)
    { return (byte & 0x80)&&((byte & 0x40)==0); };
    //-------------------------------
    
    short ByteCount(unsigned char byte) 
    {//  returns 0 if not lead byte or -1 if not UTF-8 formated 
        if ((byte & 0x80)==0) { return 1; }
        short result=0;
        if (byte & 0x80) result++;
        if (byte & 0x40) result++;
        if (result != 2) 
        {   if(isTrailByte(byte)) return 0;//this was not lead byte
        else return -1;//this was not UTF-8 format 
        }
        if (byte & 0x10) result++;
        else return result;
        if (byte & 0x08) result++;
        else return result;
        if (byte & 0x04) result++;  
        else return result;
        if (byte & 0x02) return -1;//this was not UTF-8 format  
        return result;
    };
    //-------------------------------
    
    void readu8file(std::string filename,u8str& u8_v)
    {
        std::ifstream    fin  ;  
        fin.open(filename.c_str());
        if (fin.fail()) {return;} 
        
        unsigned char  temp=0;   
        u8char   u8temp=u8char();
        unsigned short sz=0;  
        std::vector<unsigned char> ref; 
        ref.reserve(1);
        
        
        if (u8_v.ref.size())u8_v.ref.clear();
        while(fin >> temp)
        {
            if (isTrailByte(temp)) {
                ref.push_back(temp);  
                --sz;
                //if(sz<0) // too many TrailBytes
            }
            else
            {
                sz = ByteCount(temp);  
                if (ref.size()) 
                {
                    u8_v.append(u8char(ref));
                    ref.clear();
                }
                ref.push_back(temp);
                --sz;
            }
        }
        if (ref.size()) 
        {
            u8_v.append(u8char(ref));
            ref.clear();
        }
        
        fin.close();
    };    
    //-------------------------------
    
    UnicodeInt decode(u8char& c)//returns a Unicode
    {
        UnicodeInt result=0;
        if (c.size()==0) { return result;}
        if (c.size()==1) { return (result = c.ref[0]); }
        if (c.size()==2) { result=c.ref[0] & 0x1f; }
        else if (c.size()==3) { result=c.ref[0] & 0x0f; }
        else if (c.size()==4) { result=c.ref[0] & 0x07; }
        else if (c.size()==5) { result=c.ref[0] & 0x03; }
        else if (c.size()==6) { result=c.ref[0] & 0x01; }
        for (size_t i=1; i<c.size(); ++i) 
        { result=result<<6; result+=c.ref[i] & 0x3f; }
        return result;
    };   
    //-------------------------------
    
    
    
    
 
    
}//end of namespace iBS 

#endif // iBS_u8char_h


#endif // iBS_UTF_8_String_h


