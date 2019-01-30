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
          Constructor:
            HexTrail();
          Deconstructor:
            ~HexTrail();
          
HexTrail& operator =(HexTrail& other)
bool isSet(){if(ref.size()) return true; return false;};
Line bee_line;

        
        iBS::HexGrid
