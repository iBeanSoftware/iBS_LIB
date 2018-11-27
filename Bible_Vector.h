
int StrToInt(std::string& sn)
{
    int number;
    if(!(istringstream(sn)>>number)) number=0;
    return number;
};

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
  std::string name;
    std::vector<Chapter> chapter;
  Book():chapter(0) {name="";};
  ~Book(){if(chapter.size()) chapter.clear();};
  
};

struct Bible
{
  std::vector<Book> book; 
  Bible():book(0) {};
  ~Bible(){if(book.size()) book.clear();};
  
  bool connectFile(std::string fpath)
  {
      ifstream fin(fpath);
      string line;
      string bookNumber, bookInput;
      //string book;
      //int chapter, verseNumber;
      //string verseText;

      do
      {
        getline(fin, line);
        istringstream sin(line);
        sin >> bookInput;
        if (bookInput == "Book")
        {//todo new book to start and push back old book if one
         // book = bookInput;
          sin >> bookNumber;
          getline(sin, book.name);
        //  book.erase(0, 1);
        }
        else
        {
          Verse nv;//new verse
          //chapter = stoi(bookInput);
          nv.cn = StrToInt(bookInput);//chapter number
          sin >> nv.vn;//verseNumber;
          getline(sin, nv.ref);
          book[bookNumber].chapter[nv.cn].verse.push_back(nv);
          //VerseKey newVerseKey;
          //newVerseKey.setBook(book);
          //newVerseKey.setChapter(chapter);
          //newVerseKey.setVerseNumber(verseNumber);

          //Verse newVerse;
         // newVerse.setVerseKey(newVerseKey);
          //newVerse.setVerseText(verseText);

         // (*this)[newVerseKey] = newVerse;
        }
      } while (!fin.eof());  
  };
  
};



