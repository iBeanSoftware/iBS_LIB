# iBS_LIB
# Unicode C++ Lib
# iBS::u8char, iBS::u8str, iBS::u8text
//------------------------------------------------------------------------

//UTF-8_String.h - Is a header you can drop in your project to have access to a collection vector safe structures that can do many things with iBean Software's UTF-8 formatted structures that can convert from any type of char used to create a cross platform C++ programmer's UTF-8 tool kit. 
Older Uchar.h Version located: https://github.com/NashBean/UTF-8_Vector/blob/master/Uchar.h

//------------------------------------------------------------------------
    struct  u8char  //Changed struct name to match C++ standerds
        {     

            u8char();
            u8char(std::vector<unsigned char>& c);
            ~u8char();
            u8char(UnicodeInt unicode);
            u8char(char ch);
            u8char(wchar_t ch);
            u8char& operator=( u8char const& x);
            u8char& operator=(UnicodeInt unicode);
            u8char& operator=(char ch);
            u8char& operator=(wchar_t& wc);
            size_t size() const ;
            void   encode(unsigned int& unicode); 
            inline void setUnicode(UnicodeLong unicode);
            inline void setUnicode(UnicodeInt unicode);
            bool appendtostr(std::string& str);
            bool appendtostr(std::stringstream& str);
            std::string str();
            std::vector <unsigned char>  ref;//always keeps data in a UTF-8 format.
            void resize(size_t x);
        };
    typedef struct 
        {
            std::vector<u8char> ref;
            void append(u8char uc);
            void append(char ch);
            void append(std::stringstream& str)
            size_t u8char_count();
            size_t size()// returns total count of unsigned char
            void appendtostr(std::string& str)
            std::string str()
        }u8str;
    struct u8text
        {
            std::vector<u8str> ref;
            void append(u8str str);
            void clear();
            size_t line_count()// returns total lines in text
            size_t letter_count()// returns total count of unsigned char
        };
    struct u8record
        {
            std::vector<u8str> ref;
            void append(u8str str);
            void clear();
            size_t width();
        };
    struct u8table
        {// ref[0] = field names, ref[1] = record 1
            std::vector<u8record> ref;
            void append(u8record rec);
            void clear();
            size_t length();
        };
    //-------------------------------
    //      Useful UTF-8 Functions
    //-------------------------------
    bool isTrailByte(unsigned char byte);
    short ByteCount(unsigned char byte);
    void readu8file(std::string filename,u8str& u8_v);    
    inline UnicodeInt decode(u8char& c)//returns a Unicode
//------------------------------------------------------------------------

//------------------------------------------------------------------------

//Unicode_String.h - Is like the above header, but the structures charT are saved in memory as a single Unicode Int.

//------------------------------------------------------------------------
    inline UnicodeInt decode(std::vector<char>& c);
    inline UnicodeInt decode(wchar_t& wch);
    struct raw_u8str {std::vector <unsigned char> ref;};
    struct uchar
        {
        private:    
            UnicodeInt value;
        public:
            uchar():value(0); 
            uchar(int v):value(v); 
            uchar(long v):value(v); 
            uchar(UnicodeInt v):value(v); 
            uchar(char v):value((uint32_t)v);
            uchar(uchar const &v):value(v.value); 
            uchar(wchar_t wch):value(decode(wch)); 
            UnicodeInt get() { return value; };
            void set(UnicodeInt v);
            void set(uchar uch);
            void set(wchar_t wch);
            void set(int64_t i64);
            uchar& operator=(int unicode);
            uchar& operator=(UnicodeInt unicode);
            uchar& operator=(char ch);
            uchar& operator=(uchar const& uch);
            uchar& operator=(wchar_t wch);
            uchar& operator=(int64_t i64);
            bool operator==(int i);
            bool operator==(UnicodeInt unicode);
            bool operator==(char c);
            bool operator==(uchar uch);
            bool operator<(UnicodeInt unicode);
            bool operator>(UnicodeInt unicode);
            bool operator<=(UnicodeInt unicode);
            bool operator>=(UnicodeInt unicode);
            UnicodeInt lower_case();
            UnicodeInt upper_case();
        };
    struct ustr
        {
            ustr();
            ~ustr();
            ustr(UnicodeInt unicode);
            ustr(char ch):ref(1);
            ustr(wchar_t wch);
            ustr& operator=(ustr const& x);// required by C++ for vector
            ustr& operator=(char ch);
            ustr& operator=(wchar_t& wc);
            size_t size();    
            std::string str()
        private:    
            std::vector<uchar> ref;
        };
    struct utext
        {
            utext();
            ~utext();
            utext(UnicodeInt unicode);
            utext(char ch);
            utext(wchar_t wch);
            utext(std::string str); 
            utext& operator=(utext const& x);// required by C++ for vector
            utext& operator=(char ch);
            utext& operator=(wchar_t& wc);
            size_t size() const;    
            std::string str(size_t index);
        private:    
            std::vector<ustr> ref;
        };

//------------------------------------------------------------------------


//------------------------------------------------------------------------

//iBS_Matrix.h - An int based matrix stuct of vectors that are mathmatically correct with operator +,-,*,^

//------------------------------------------------------------------------

        struct Matrix{
            std::vector<std::vector<int> > a; 

            Matrix& operator =(Matrix& o);
            Matrix& operator +(Matrix& o);
            Matrix& operator -(Matrix& o);
            Matrix& operator *(Matrix& o);
            Matrix& operator ^(int power);
            
            void print();
            };
//------------------------------------------------------------------------
