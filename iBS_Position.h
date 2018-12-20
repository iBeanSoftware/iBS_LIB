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
//------------------------------------------------------------
  
//------------------------------------------------------------
const int GRID_WIDTH=23;
const int GRID_HIGHT=21;
//------------------------------------------------------------
 struct	HexGrid
{
    int ref[GRID_WIDTH][GRID_HIGHT];
    
	HexGrid(){clear();};
	~HexGrid(){};
	
    void setValue(Position& p, int val)
    {
        ref[p.x][p.y] = val;
    };
	
	void scan_state()
	{
    	for(int	a=0; a<GRID_WIDTH; ++a) 
        	for(int	b=0; b<GRID_HIGHT; ++b) 
            	std::cin >> ref[a][b];
	};
	
	bool in_bounds(Position&	p)
	{
		if(p.x < 0 || p.y < 0)	return false;
		else if(p.x >= GRID_WIDTH || p.y >= GRID_HIGHT)	return false;
		return	true;
	};
	
	bool is_corner(Position&	p)
	{
		if(p.x == 0 && p.y == 0)	return true;
		else if(p.x == 0 && p.y == GRID_HIGHT-1)	return true;
		else if(p.x == GRID_WIDTH-1 && p.y == 0)	return true;
		else if(p.x == GRID_WIDTH-1 && p.y == GRID_HIGHT-1)	return true;
		return	false;
	};
	
	bool is_edge(Position&	p)
	{
		if(p.x == 0 || p.y == 0)	return true;
		else if(p.x == GRID_WIDTH-1 || p.y == GRID_HIGHT-1)	return true;
		return	false;
	};
    
    void movePos(Position& pos, int arg1)// arg1 = direction 0@ 3 OClock 1@ 1:30 OCLOCK ... 5@ 4:30 OCLOCK
    {
        if(pos.is_even())
        {
            if(!arg1) { pos.x = 1 + pos.x; }
            else if(arg1==1) { pos.y = -1 + pos.y; }
            else if(arg1==2) { pos.x = -1+pos.x; pos.y = -1+pos.y; }
            else if(arg1==3) { pos.x = -1+pos.x; }
            else if(arg1==4) { pos.x = -1+pos.x; pos.y = 1+pos.y; }
            else if(arg1==5) { pos.y = 1+pos.y; }
        }   
        else
        {
            if(!arg1) { pos.x = 1 + pos.x; }
            else if(arg1==1) { pos.x = 1+pos.x; pos.y = -1+pos.y; }
            else if(arg1==2) { pos.y = -1+pos.y; }
            else if(arg1==3) { pos.x = -1+pos.x; }
            else if(arg1==4) { pos.y = 1+pos.y; }
            else if(arg1==5) { pos.x = 1+pos.x; pos.y = 1+pos.y; }
        }  
        
        if(pos.x>=GRID_WIDTH) pos.x= GRID_WIDTH-1;
        if(pos.y>=GRID_HIGHT) pos.y= GRID_HIGHT-1;
        if(pos.x<0) pos.x= 0;
        if(pos.y<0) pos.y= 0;
    };
    
	int safe(Position&	p)
	{
		int result=8;	
		if(is_corner(p))
		{result=result-5;}
		else if(is_edge(p))
		{result=result-3;}
		
		Position	temp;
        temp.set(p.x-1, p.y-1);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x, p.y-1);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x+1, p.y-1);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x-1, p.y);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x+1, p.y);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x-1, p.y+1);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x, p.y+1);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
        temp.set(p.x+1, p.y+1);
		if(in_bounds(temp))if(ref[temp.x][temp.y]!=0)--result;
		
		return	result;
	};

    void zero()
    {
        for(int	a=0; a<GRID_WIDTH; ++a) 
        	for(int	b=0; b<GRID_HIGHT; ++b) 
            	ref[a][b]=0;
    };   

    void clear()
    {
        for(int	a=0; a<GRID_WIDTH; ++a) 
        	for(int	b=0; b<GRID_HIGHT; ++b) 
            	ref[a][b]=-1;
    };   
    
};
//-------------------------------------------------------------------------------------

  
  
}//end of namespace iBS 

#endif // iBS_Position_h
//-------------------------------------------------------------------
