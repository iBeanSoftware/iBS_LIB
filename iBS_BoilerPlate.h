#include "UTF-8_String.h"

using namespace iBS;

struct PageInfo
{
       u8str doc_type;
       u8str lang;
       u8str content_type;
       
};


struct WebPage
{
       PageInfo info;
       u8str page_title;
       u8text style_text;
       u8str stylesheet_filepath;
       u8text scipt_text;
       u8str javascript_filepath;
        
       u8text head, body, footer;
       
       u8text make_page(u8str filePath)
       {
              u8str temp;
              u8text result;
              
              result.append("<!doctype html>");
              result.append("<html lang=\"en\">");
              result.append("<head>");
              result.append(head);
              result.append("</head>");
              result.append("<body>");
              result.append(body);
              result.append("</body>");
              result.append("<footer>");
              result.append(footer);
              result.append("</footer>");
              
              //todo
              // add function u8text::save2file(u8str filePath);
              // result.save2file(filePath);
              return result;
       };
      u8text make_page(u8str filePath, u8text h, u8text b, u8text f)
       {
           head = h; body = b; footer = f;
           return make_page(filePath);
       };
       
};
