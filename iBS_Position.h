//
//  iBS_Position.h
//  https://github.com/iBeanSoftware/iBS_LIB/blob/master/iBS_Position.h
//
//  Created by nash(https://github.com/NashBean) on 12/18/2018.
//  Copyright 2018 iBean Software(https://iBeanSoftware.github.io),
//  All rights reserved.


#ifndef iBS_Position_h
#define iBS_Position_h

#include <vector>
#include <algorithm>


//-------------------------------------------------------------------
const int iBS_POSITION_MAJOR_VERSION = 1;
const int iBS_POSITION_MINOR_VERSION = 0;
namespace iBS 
{
  struct Position 
  {
      int x, y;
      Position(){x=y=0;};
      Position(int ax, int ay){x=ax;y=ay;};
      //    Position(const  Position& a){x=a.x;y=a.y;};
      ~Position(){};
 
      Position& operator =(Position& other)
      {
        x=other.x;
        y=other.y;
        return *this;
      };
    
      bool operator ==(Position& other)
      {
          if(x == other.x && y == other.y)
              return true;
          return false;
      };

      bool operator !=(Position& other)
      {
         if(x == other.x && y == other.y)
             return false;
          return true;
      };

    void set(int px, int py){x=px;y=py;}; 
    void set(Position& a){x=a.x;y=a.y;}; 

      int find_distance(int px, int py)
      {
          int   result=0;
          if (x>px) result+=x-px;
          else if(x<px) result+=px-x;
          if (y>py) result+=y-py;
          else if(y<py) result+=py-y;
          return result;
      };

      int distance(Position& a)
      {
          return find_distance(a.x,a.y);
      };

    bool is_neighbour(int px, int py) 
    {
        if (px == x  &&  py == y)
            return false;
        else if (abs(px-x) <= 1 && abs(py-y) <= 1)
            return true;
        return false;
    };
    
     bool is_even()
     {
        if(!y) return false;
        else if((y%2) == 0) return false;//even on one base
        else return true;//odd on one base
     };
  };
}//end of namespace iBS 

#endif // iBS_Position_h
//-------------------------------------------------------------------