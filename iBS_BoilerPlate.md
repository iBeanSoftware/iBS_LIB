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
       
       // if above info is set, following function 
       //   will create html file, using above data.
       u8text make_page(u8str filePath);


Example:

    WebPage my_page;
    my_page.page_title = "My Page Title";
    my_page.stylesheet_filepath = "https://github.com/iBeanSoftware/iBeanSoftware.github.io/blob/master/iBS_MonochromeStyle.css";
    ...
    u8text newpage = my_page.make_page("MyPage.html");
