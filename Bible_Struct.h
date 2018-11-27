struct Verse
{
  int cn, vn; // Chapter Number, Verse Number
  static char* ref;
  //int wordSearch(char* word_ref){};
};

struct Page
{
    std::string page_index;// /alpha/alphaBook/omaga/alphaChater/omaga/alphaVerse/omaga/omaga
    vector<std::sring> line;
    bool word_wrap=false;
    Page():line(0) {max_lines_per_page = 99;};
    ~Page(){if(line.size()) line.clear();};
  
    void setMaxLinesPerPage(int v){max_lines_per_page=v;};

  private:
    int max_lines_per_page;
};

struct Chapter
{
  std::vector<Verse> verse;
  Chapter():verse(0) {};
  ~Chapter(){if(verse.size()) verse.clear();};
};

struct Book
{
    std::vector<Chapter> chapter;
  Book():chapter(0) {};
  ~Book(){if(chapter.size()) chapter.clear();};
  
};

struct Bible
{
  std::vector<Book> book; 
  Bible():book(0) {};
  ~Bible(){if(book.size()) book.clear();};
  
};
