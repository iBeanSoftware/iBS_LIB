Object Type iBS::fstr

iBS::fstr is a fast, flat byte string class optimized for performance, using small-string optimization (SSO) for short strings and dynamic allocation for larger ones. It serves as a drop-in alternative to std::string for byte data, with lower overhead in common operations. Can be used as a base for specialized strings like u8str in UTF-8_String.h.

Constructors:
    fstr();
    fstr(char ch);
    fstr(std::stringstream& str);
    fstr(std::vector<unsigned char>& c);
    fstr(const std::string& str);

Destructor:
    ~fstr();

Operators:
    fstr& operator=(const fstr& other);
    fstr& operator=(const std::string& str);

Functions:
    size_t size(); // returns total byte count
    void clear();
    void append(char ch);
    void append(std::stringstream& str);
    void append(const std::string& str);
    void append(const std::vector<unsigned char>& c);
    std::string str(); // converts to std::string for compatibility

Example:
    iBS::fstr myfstr("Hello, world!");
    myfstr.append(" more bytes");
    std::cout << myfstr.size() << std::endl; // Outputs byte count
    std::string stdstr = myfstr.str(); // Compatible with std::string
