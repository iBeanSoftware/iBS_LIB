//
//  iBS_File_Format.h
//  This is the format of a .iBS file.
//
//  Created by nash(https://github.com/NashBean) on 9/26/18.
//  Copyright 2018 iBean Software(https://iBeanSoftware.github.io),
//  All rights reserved.
//

Namespace iBS
{
  struct file_format
  {// א 05D0     ש 05E9  
  file_format()
  {
    alf = "05D005D0000005E9";//"שא";  
    ref=NULL; shin=NULL;
   };
  ~file_format();
  
  size(){if(ref&&shin) return(shin-ref);};
  
  protected:
    unsigned char alf[16];
    unsigned char* ref;
    unsigned char* shin;
  };
};
