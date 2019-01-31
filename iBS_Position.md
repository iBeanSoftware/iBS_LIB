  iBS_Position.h has following types defined.
  
  Type Definitions including Position and other related types:
  
        iBS::Position
          Varables:
            int x, y;
          Constructors:
              Position();
              Position(int ax, int ay);
          Deconstructor:
              ~Position();
          Operators:
              Position& operator =(Position& other);
              bool operator ==(Position& other);
              bool operator !=(Position& other);
          Functions:
              void set(int px, int py); 
              void set(Position& a); 
              int find_distance(int px, int py);
              int distance(Position& a);
              bool is_neighbour(int px, int py);
              bool is_even();

        
        iBS::Slope
          Varables:
              int x, y;
          Constructors:
              Slope();
              Slope(Position& pos1, Position& pos2);
          Deconstructor:
              ~Slope();
          Operators:
              Slope& operator =(Slope& other);
              bool operator ==(Slope& other);
              bool operator !=(Position& other);
              
        iBS::Line
          Varables:
              Slope m;
              Position A, B;
          Constructors:
              Line();
              Line(Position& spos, Position& epos);
          Deconstructor:
              ~Line();
          Operators:
              Line& operator =(Line& other);
              
        iBS::HexTrail
          Varibles:
            Line bee_line;
            vector<Position> ref;
          Constructor:
            HexTrail();
          Deconstructor:
            ~HexTrail();
          Operator:
            HexTrail& operator =(HexTrail& other);
          Functions:
            bool isSet();


        
        iBS::HexGrid
          Global Varibles:
            const int GRID_WIDTH=23;
            const int GRID_HIGHT=21;
          Varibles:
            int ref[GRID_WIDTH][GRID_HIGHT];
          Functions:
            void setValue(Position& p, int val);
            void scan_state();
            bool in_bounds(Position& p);
            bool is_corner(Position& p);
            bool is_edge(Position& p);
            void movePos(Position& pos, int arg1);
            int safe(Position& p);
            void zero();// sets all to 0
            void clear();// sets all to -1 
