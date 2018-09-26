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
  #define Alf \x05D0
  #define Shin \x05E9
  
  struct file_format
  {// א 05D0     ש 05E9  
  file_format()
  {
    alf = Alf+Alf+'\x0000'+Shin;//"\x05D0\x05D0\x0000\x05E9";//Alf=" א "Shin=" ש ";  
    ref=Null; shin=Null;
   };
  ~file_format();
  
  int size(){if(ref&&shin) return(shin-ref); else return 0;};
  char[2] type(){char result[2]='\x0000'; if(alf[4]!=Null||alf[5]!=Null){result[0]=&alf[4]; result[1]=&alf[5]}};    
  protected:
    unsigned char alf[8];// beginning
    unsigned char* ref;
    unsigned char* shin;// end
  };
};
