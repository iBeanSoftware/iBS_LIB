
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
         
     Example:
        iBS::Matrix matrix(2,4);
        iBS::Matrix matrix2();
        
        matrix.a[1][3] = 4;
        matrix.a[0][2] = 2;
        matrix.a[0][3] = 3;
        matrix.a[1][0] = 1;

        matrix2=matrix;
        matrix2 = matrix*matrix;
        
        matrix.print();
        matrix2.print();
