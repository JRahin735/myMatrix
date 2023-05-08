/*mymatrix.h*/

#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;
template<typename T>

class mymatrix
{
private:
    struct ROW
    {
        T*  Cols;     // dynamic array of column elements
        int NumCols;  // total # of columns (0..NumCols-1)
    };

    ROW* Rows;     // dynamic array of ROWs
    int  NumRows;  // total # of rows (0..NumRows-1)

public:

    mymatrix()
    {
        Rows = new ROW[4];  // an array with 4 ROW structs:
        NumRows = 4;

        // initialize each row to have 4 columns:
        for (int r = 0; r < NumRows; ++r)
        {
            Rows[r].Cols = new T[4];  // an array with 4 elements of type T:
            Rows[r].NumCols = 4;

            // initialize the elements to their default value:
            for (int c = 0; c < Rows[r].NumCols; ++c)
            {
                Rows[r].Cols[c] = T{};  // default value for type T:
            }
        }
    }

    mymatrix(int R, int C)
    {
        if (R < 1)
        {
            throw invalid_argument("mymatrix::constructor: # of rows");
        }
        if (C < 1)
        {
            throw invalid_argument("mymatrix::constructor: # of cols");
        }

        Rows = new ROW[R];  // an array with R num of ROW structs:
        NumRows = R;

        // initialize each row to have 4 columns:
        for (int r = 0; r < NumRows; ++r)
        {
            Rows[r].Cols = new T[C];  // an array with C num of elements of type T:
            Rows[r].NumCols = C;

            // initialize the elements to their default value:
            for (int c = 0; c < Rows[r].NumCols; ++c)
            {
                Rows[r].Cols[c] = T{};  // default value for type T:
            }
        }
    }

    mymatrix(const mymatrix<T>& other)
    {
        NumRows = other.NumRows;
        Rows = new ROW[other.numrows()];

        // For every row, we access each column one by one and save it with its "other" counterpart
        for (int r = 0; r < numrows(); r++)
        {
            Rows[r].NumCols = other.numcols(r);
            Rows[r].Cols = new T [other.numcols(r)];

            // For every row, and for every column in each row. We access the elements of the array one by one
            // and save it with its "other" counterpart
            for (int c = 0; c < Rows[r].NumCols; c++)
            {
                Rows[r].Cols[c] = other.Rows[r].Cols[c];
            }
        }
    }

    // Returns the total number of rows in a matrix
    int numrows() const
    {
        return NumRows;
    }

    // Returns the total number of columns in r row
    int numcols(int r) const
    {
        if (r < 0 || r >= NumRows)
        {
            throw invalid_argument("mymatrix::numcols: row");
        }
        int col_num = Rows[r].NumCols;
        return col_num;
    }

    // Increases the number of columns in r row by size C
    void growcols(int r, int C)
    {
        // error checkings
        if (r < 0 || r >= NumRows)
            throw invalid_argument("mymatrix::growcols: row");
        if (C < 1)
            throw invalid_argument("mymatrix::growcols: columns");

        // Make a new array of size prompted by user and init all values ith 0
        if(C > numcols(r)) 
        {
            T *new_cols = new T[C];
            // save values from orig arr to the new arr , rest remains to be 0
            for (int i = 0; i < C; i++) 
            {
                new_cols[i] = this->Rows[r].Cols[i];
            }
            for (int i = numcols(r); i < C; i++) 
            {
                new_cols[i] = T{};
            }

            Rows[r].Cols = new_cols;
            // re init the size on NumCols
            Rows[r].NumCols = C;
        }
    }

    // increases the number of rows by size R, where each new row has columns of size C
    void grow(int R, int C)
    {
        // errors checkings
        if (R < 1)
            throw invalid_argument("mymatrix::grow: # of rows");
        if (C < 1)
            throw invalid_argument("mymatrix::grow: # of cols");

        if(NumRows < R)
        {
            ROW* new_row = new ROW[R];
            for(int r = 0; r < R; r++)
            {
                if(r < NumRows)
                {
                    if(C < Rows[r].NumCols)
                    {
                        new_row[r].Cols = new T[numcols(r)];
                        for(int c = 0; c < numcols(r); c++)
                        {
                            new_row[r].Cols[c] = Rows[r].Cols[c];
                        }
                        new_row[r].NumCols = Rows[r].NumCols;
                    }
                    else
                    {
                        new_row[r].Cols = new T[C];
                        for(int c = 0; c < C; c ++)
                        {
                            if(c < numcols(r))
                            {
                                new_row[r].Cols[c] = Rows[r].Cols[c];
                            }
                            else
                            {
                                new_row[r].Cols[c] = T{};
                            }
                        }
                        new_row[r].NumCols = C;
                    }
                }
                else
                {
                    new_row[r].Cols = new T[C];
                    for(int c = 0; c < C; c++)
                    {
                        new_row[r].Cols[c] = T{};
                        new_row[r].NumCols = C;
                    }
                }
            }
            NumRows = R;
            Rows = new_row;
        }
        else
        {
            for( int r = 0; r < NumRows; r++)
            {
                if( C > Rows[r].NumCols)
                {
                    growcols(r,C);
                }
            }
        }
    }

    // returns the total number of cells in the cells
    int size() const
    {
        int size_count = 0;
        for (int r = 0; r < NumRows; r++)
        {
            size_count += Rows[r].NumCols;
        }
        return size_count;
    }

    // .at() returns the int (T) element at coordinates (r,c) of the matrix
    T& at(int r, int c) const
    {
        if (r < 0 || r >= NumRows)
            throw invalid_argument("mymatrix::at: row");
        if (c < 0 || c >= Rows[r].NumCols)
            throw invalid_argument("mymatrix::at: col");

        return Rows[r].Cols[c];
    }

    // () similar as previous .at() function. Provides the int (T) value at coordinates (r,c)
    T& operator()(int r, int c) const
    {
        if (r < 0 || r >= NumRows)
            throw invalid_argument("mymatrix::(): row");
        if (c < 0 || c >= Rows[r].NumCols)
            throw invalid_argument("mymatrix::(): col");

        return Rows[r].Cols[c];
    }

    // Scalar multiplication of Matrix
    // Matrix B = Matrix A * 2;
    // Multiplies all values of the matrix with int scalar
    mymatrix<T> operator*(T scalar)
    {
        mymatrix<T> result(numrows(),1);
        for(int i = 0; i < numrows(); i++)
        {
            result.growcols(i, numcols(i));
        }
        for(int i = 0; i < NumRows; i++)
        {
            for(int j = 0; j < Rows[i].NumCols; j++)
            {
                int value = Rows[i].Cols[j];
                result.Rows[i].Cols[j] = value * scalar;
            }
        }
        return result;
    }

    // Helper function
    // returns 1 when the matrix is not rectangular ie. all the columns are not the same size
    // else returns false. Required criterion for matrix multiplication
    int rectangleCheck(mymatrix<T>test_matrix)
    {
        int col_size = test_matrix.numcols(0);
        for(int i = 0; i < test_matrix.NumRows; i++)
        {
            if(col_size != test_matrix.numcols(i))
            {
                return 1;
            }
        }
        return 0;
    }

    // Matrix Multiplication
    // matrix A * Matrix B = Matrix C
    mymatrix<T> operator*(const mymatrix<T>& other)
    {
        // error checking for matrix A
        if(rectangleCheck(*this) == 1)
        {
            throw runtime_error("mymatrix::*: this not rectangular");
        }
        // error checking for matrix B
        if((rectangleCheck(other)) == 1)
        {
            throw runtime_error("mymatrix::*: this not rectangular");
        }
        // compatibility check
        if((this->numcols(0)) != (other.numrows()))
        {
            throw runtime_error("mymatrix::*: the matrix is not compatible");
        }
        int cell = 0;
        mymatrix<T> product_matrix(NumRows, other.numcols(0));
        for(int i = 0;i<NumRows;i++)
        {
            for(int j = 0; j< other.numcols(0);j++)
            {
                for(int k = 0;k < other.NumRows; k++)
                {
                    cell += Rows[i].Cols[k]*other.Rows[k].Cols[j];
                }
                product_matrix(i,j) = cell;
                cell = 0;
            }
        }
        return product_matrix;
    }

    // .output()
    // outputs each cell from the matrix
    void _output()
    {
        for (int r = 0; r < this->NumRows; ++r)
        {
            for (int c = 0; c < this->Rows[r].NumCols; ++c)
            {
                cout << this->Rows[r].Cols[c] << " ";
            }
            cout << endl;
        }
    }

};