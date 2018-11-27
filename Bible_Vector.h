//
//  Bible_Vector.h
//
//
//  Created by Nash(https://github.com/NashBean) on 11/27/2018.
//  Copyright 2018 iBean Software(https://iBeanSoftware.github.io),
//  iBeanSoftware@GMail.com
//  https://www.facebook.com/iBeanSoftware
//  All rights reserved.
//
//
//  a struct to hold a Bible with books[].Chapers[].Verses[] stuctured vectors 

#ifndef Bible_Vector_h
#define Bible_Vector_h

#include<fstream>
#include<sstream>
#include<iostream>

const int BibleVector_MAJOR_VERSION = 0;
const int BibleVector_MINOR_VERSION = 2;

namespace iBS 
{
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
            {
              Book nb;
              sin >> bookNumber;
              getline(sin, nb.name);
              book.push_back(nb);
            }
            else
            {
              Verse nv;//new verse
              nv.cn = StrToInt(bookInput);//chapter number
              sin >> nv.vn;//verseNumber;
              getline(sin, nv.ref);
              do while(nV.cn<book[bookNumber].chapter.size())
              {
                  Chapter nc;//new chapter
                  book[bookNumber].chapter.push_back(nc);
              };
              book[bookNumber].chapter[nv.cn].verse.push_back(nv);
            }
          } while (!fin.eof());  
      };

    };
}// end    namespace iBS 
#endif // Bible_Vector_h





