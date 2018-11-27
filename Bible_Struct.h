struct Verse
{
  int cn, vn; // Chapter Number, Verse Number
  static char* ref;
  //int wordSearch(char* word_ref){};
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
