
Unicode 64bit int API

Unicode_String.h - Is like the above header, but the structures charT are saved in memory as a single Unicode 64 bit Int.

Found in the Unicode_String.h File using namespace iBS List of varable types: 

iBS::Uchar
    Constructors:
       uchar(); 
        uchar(int v); 
        uchar(long v); 
        uchar(UnicodeInt v); 
        uchar(char v); 
        uchar(uchar const &v); 
        uchar(wchar_t wch); 
        
   Operators:     
        uchar& operator=(int unicode);
        uchar& operator=(UnicodeInt unicode);
        //uchar& operator=(uint unicode);
        uchar& operator=(char ch);
        uchar& operator=(uchar const& uch);
        uchar& operator=(wchar_t wch);
        uchar& operator=(int64_t i64);
        bool operator==(int i);
        bool operator==(UnicodeInt unicode);
        bool operator==(char c) ;
        bool operator==(uchar uch) ;
        bool operator<(UnicodeInt unicode);
        bool operator>(UnicodeInt unicode);
        bool operator<=(UnicodeInt unicode);
        bool operator>=(UnicodeInt unicode);
        
   Functions:
        UnicodeInt get();
        void set(UnicodeInt v);
        void set(uchar uch);
        void set(wchar_t wch);
        void set(int64_t i64);
        UnicodeInt lower_case();
        UnicodeInt upper_case();




, iBS::Ustr, iBS::Utext

    They are: 
        compatable with iBS::u8char, iBS::u8str, iBS::u8text
        vector safe structures.
        Self Cleaning.
