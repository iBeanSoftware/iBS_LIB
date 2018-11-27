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
  
    setMaxLinesPerPage(int v){max_lines_per_page=v;};

  private:
    int max_lines_per_page = 99;
};

struct Chapter
{
  std::vector<Verse> verse;
};

struct Book
{
    std::vector<Chapter> chapter;
  
};

struct Bible
{
  std::vector<Book> book; 
  
};
