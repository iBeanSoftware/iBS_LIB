# iBS_LIB
# Unicode C++ Lib
# iBS::u8char, iBS::u8str, iBS::u8text

//------------------------------------------------------------------------

UTF-8_String.h - Is a header you can drop in your project to have access to a collection vector safe structures that can do many things like convert from any type of char used to create a cross platform C++ programmer's UTF-8 tool kit. 

    Found in the UTF-8_String.h File using namespace iBS
        List of varable types:
        iBS::u8char,        iBS::u8str,        iBS::u8text

        They are: 
            compatable with char, wchar_t, std::string, and Unicodes.
            vector safe structures.
            Self Cleaning.

    Useful UTF-8 Functions 
        bool isTrailByte(unsigned char byte);
        short ByteCount(unsigned char byte);
        void readu8file(std::string filename,u8str& u8_v);    
        inline UnicodeInt decode(u8char& c);
//------------------------------------------------------------------------

//------------------------------------------------------------------------

//Unicode_String.h - Is like the above header, but the structures charT are saved in memory as a single Unicode Int.

    Found in the Unicode_String.h File using namespace iBS
        List of varable types:
        iBS::Uchar,        iBS::Ustr,        iBS::Utext
//------------------------------------------------------------------------

//------------------------------------------------------------------------

//iBS_Matrix.h - An int based matrix stuct of vectors. 

    Found in the iBS_Matrix.h File using namespace iBS
        varable type: iBS::Matrix
           The varables are mathmatically correct with operator +,-,*,^
