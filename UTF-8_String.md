iBean Software's UTF-8 API for c or c++
Creating a cross platform char, string, and text.
With following drop in header file that should be found in dirictory with this file:

iBS_UTF-8_String.h

Type Definitions:

        Defined UnicodeInt as a uint64_t
    
        iBS::u8char // u8char replaces char as a vector of chars, 
                    // that represent a single Unicode value in UTF-8 format.
                Constructors:
                       u8char();
                       u8char(std::vector<unsigned char>& c);// char vector that represents a single Unicode char
                       u8char(UnicodeInt unicode);// 64 bit Unicode
                       u8char(char ch);// ANSII value
                       u8char(wchar_t ch);// for converting Windows Wide Char to UTF-8 format
                Deconstructor:
                       ~u8char();
              
                        
        iBS::u8str  // u8str replaces std::string as a vector of u8char, 
                    //but matains compatabilaty with std::string. 
                Constructors:
                        u8str();
                        u8str(u8char uc);
                        u8str(char ch);
                        u8str(wchar_t ch);
                        u8str(std::stringstream& str);
                        u8str(std::vector<unsigned char>& c);
                        u8str(std::string& str);
                Deconstructor:
                        ~u8str();
                Operators:        
                        u8str& operator=(u8str const& str);
                        u8str& operator=(std::string const& str);
                Functions:
                        size_t u8char_count(); // returns total Unicode Charter count.
                        size_t size();// returns total count of unsigned char
                        void clear();
                        void append(u8char uc);
                        void append(char ch);
                        void append(wchar_t ch);
                        void append(std::stringstream& str);
                        void append(std::string& str);
                        void append(std::vector<unsigned char>& c);
                        std::string str();
        
        iBS::u8text  // u8text is a vector of u8str.
                     //A vector of strings that can represent a file, a note, a record 
                     //or anything else that your could think of.
                Constructors:
                        u8text();
                        u8text(u8char uc);
                        u8text(char ch);
                        u8text(wchar_t ch);
                        u8text(std::stringstream& str);
                        u8text(std::vector<unsigned char>& c);
                        u8text(std::string& str);
                Deconstructor:
                        ~u8text();
                Functions:
                        void append(u8str str);
                        void append(std::string str);
                        void append(std::stringstream& str);
                        void clear();
                        size_t line_count();// returns total lines in text
                        size_t letter_count();// returns total count of unsigned char

        
        iBS::u8record // still needs improvements
                Functions:
                        void append(u8str str);
                        void clear();
                        size_t width();
        
        iBS::u8table // still needs improvements
                Functions:
                        void append(u8record rec);
                        void clear();
                        size_t length();

         
Related Functions included:

         bool iBS::isTrailByte(unsigned char byte);
         
         short iBS::ByteCount(unsigned char byte); 
         
         void iBS::readu8file(std::string filename,u8str& u8_v);
         
         UnicodeInt iBS::asUnicode(u8char& c);
