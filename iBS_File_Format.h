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
  {
  file_format(){alf = "א";  ref=NULL; omaga=NULL;};
  ~file_format();
  
  size(){if(ref&&omaga) return(omaga-ref);};
  
  protected:
    unsigned char alf[2];
    unsigned char* ref;
    unsigned char* omaga;
  };
};
