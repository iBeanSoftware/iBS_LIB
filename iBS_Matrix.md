
Object Type iBS::Matrix 

    Constructors:
        Matrix();
        Matrix(int r, int c);//rows and coloms
        
    Deconstructor:
        ~Matrix();
        
    Operators:
         Matrix& operator =(Matrix& o);
         Matrix& operator +(Matrix& o);
         Matrix& operator -(Matrix& o);
         Matrix& operator *(Matrix& o);
         Matrix& operator ^(int power);
        
    Functions:
         void clear();
         void resize(int r, int c);
         void print();
