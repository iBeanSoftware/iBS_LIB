iBean Software's UTF-8 API for c or c++
iBS_UTF-8_String.h

Type Definitions:

        Defined UnicodeInt as a uint64_t
    
        iBS::u8char //u8char replaces char as a vector of chars, that represent a single Unicode value in UTF-8 format.
                Constructors:
                       u8char();
                       u8char(std::vector<unsigned char>& c);// char vector that represents a single Unicode char
                       u8char(UnicodeInt unicode);// 64 bit Unicode
                       u8char(char ch);// ANSII value
                       u8char(wchar_t ch);// for converting Windows Wide Char to UTF-8 format
                Deconstructor:
                       ~u8char();
              
                        
        iBS::u8str  // u8str replaces std::string as a vector of u8char, but matains compatabilaty with std::string. 
        
        iBS::u8text  // u8text is a vector of u8str. A vector of strings that can represent a file, a note, a record or anything else that your could think of.
        
        iBS::u8record // still needs improvements
        
        iBS::u8table // still needs improvements
         
Related Functions included:

         bool iBS::isTrailByte(unsigned char byte)
         
         short iBS::ByteCount(unsigned char byte) 
         
         void iBS::readu8file(std::string filename,u8str& u8_v)
         
         UnicodeInt iBS::asUnicode(u8char& c)
