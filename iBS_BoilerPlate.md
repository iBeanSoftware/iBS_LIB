type defenitions:

    PageInfo
       u8str doc_type;
       u8str lang;
       u8str content_type;
       
    WebPage
       PageInfo info;
       u8str page_title;
       u8text style_text;
       u8str stylesheet_filepath;
       u8text scipt_text;
       u8str javascript_filepath;
       u8text head, body, footer;
       
       u8text make_page(u8str filePath);

