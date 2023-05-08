#include <iostream>
#include "mymatrix.h"


// --------------------------
//Test cases

// Parameterised constructor should throw an error when user tries to init matrix of row size 0
bool Test1 () {

    try {
        mymatrix<int>matA(0,4);
    }
    catch (...){
        return true;
    }
    
    cout << "TEST 1 FAILED" << endl;
    
    return false;
}

// Parameterised constructor should throw an error when user tries to init matrix of col size 0
bool Test2 () {

    try {
        mymatrix<int>matA(1,0);
    }
    catch (...){
        return true;
    }
    
    cout << "TEST 2 FAILED" << endl;
    
    return false;
}

// Parameterised constructor should throw an error when user tries to init matrix of row and col size 0
bool Test3 () {

    try {
        mymatrix<int>matA(0,0);
    }
    catch (...){
        return true;
    }
    
    cout << "TEST 3 FAILED" << endl;
    
    return false;
}

// Does copy constructor copy all rows
bool Test4 () {

    mymatrix<int> A(8,8);
    mymatrix<int> B = A;
    int check = 0;
    if (B.numrows() == A.numrows()) {
        check--;
    }
    if (check != 0) {
        return true;
    } else {
        
        cout << "TEST 4 FAILED" << endl;
        
        return false;
    }
}

// Checks if numrows() is working properly or not.
bool Test5 () {

    mymatrix<int>matA(4,6);
    if (matA.numrows() != 4) {
        
        cout << "TEST 5 FAILED" << endl;
        
        return false;
    } else {
        return true;
    }
}

// Checks if numrows() returns updated values after updating the matrix properties.
bool Test6 () {

    mymatrix<int>matA;
    matA.grow(6,8);

    if (matA.numrows() != 6) {
        
        cout << "TEST 6 FAILED" << endl;
        
        return false;
    } else {
        return true;
    }
}

// Checks if numcols() is working properly or not.
bool Test7 () {

    mymatrix<int> matA(4,6);
    int count=0;
    for (int r = 0; r < 4; r++){
        if (matA.numcols(r) == 6) {
            count++;
        }
    }
    if (count!=4) {
        
        cout << "TEST 7 FAILED" << endl;
        
        return false;
    } else {
        return true;
    }
}

// Checks if .numcols(r) works when user tries to access a row that does not exist
bool Test8 () {

    mymatrix<int> A; // row size 4 by default
    try {
        A.numcols(5);
    }
    catch(...) {
        return true;
    }
    
    cout << "TEST 8 FAILED" << endl;
    
    return false;
}

// checking if program throws error if user tries to access negative rows
bool Test9 () {
    mymatrix<int>A; // size (4,4)
    try {
        A.growcols(-1, 6);
    }
    catch (...) {
        return true;
    }
    
    cout << "TEST 9 FAILED" << endl;
    
    return false;
}

// checking if program throws error if user tries to access a row that doesn't exist
bool Test10 () {
    mymatrix<int>A; // size (4,4)
    try {
        A.growcols(7, 6);
    }
    catch (...) {
        return true;
    }
    
    cout << "TEST 10 FAILED" << endl;
    
    return false;
}

// checking if program throws error if user tries to grow col to be 0
bool Test11 () {
    mymatrix<int>A; // size (4,4)
    try {
        A.growcols(3, 0);
    }
    catch (...) {
        return true;
    }
    
    cout << "TEST 11 FAILED" << endl;
    
    return false;
}

// checking if program throws error if user tries to grow cols with less vals than what already exists
bool Test12 () {
    mymatrix<int>A; // size (4,4)
    A.growcols(3, 1);

    if(A.numcols(3) == 4)
    {
        return true;
    }
    
    cout << "TEST 12 FAILED" << endl;
    return false;
}


// checking if program throws error if user tries to grow cols with negative vals
bool Test13 () {
    mymatrix<int>A; // size (4,4)
    try {
        A.grow(2, -1);
    }
    catch (...) {
        return true;
    }
    
    cout << "TEST 13 FAILED" << endl;
    
    return false;
}

// checking if program throws error if user tries to grow rows with negative vals
bool Test14 () {
    mymatrix<int>A; // size (4,4)
    try {
        A.grow(-1, 5);
    }
    catch (...) {
        return true;
    }
    
    cout << "TEST 14 FAILED" << endl;
    
    return false;
}

// Checks whether .grow() increases the column size for all rows and row size properly
bool Test15()
{
    mymatrix<int>A;
    A.grow(6,6);
     int correctSize = 0;
     for(int i = 0; i < A.numrows();i++)
     {
         if(A.numcols(i) == 6)
         {
             correctSize++;
         }
     }
     if(A.numrows() == 6 && correctSize == 6)
     {
         return true;
     }
    
    cout << "TEST 15 FAILED" << endl;
    
    return false;
}

// Checks whether .grow() function does not reduce the size of the matrix when currSize>newSize is entered
bool Test16()
{
    mymatrix<int>A(8,8);
    A.grow(5,5);
    int correctSize = 0;
    for(int i = 0; i < A.numrows();i++)
    {
        if(A.numcols(i) == 8)
        {
            correctSize++;
        }
    }
    if(A.numrows() == 8 && correctSize == 8)
    {
        return true;
    }
    
    cout << "TEST 16 FAILED" << endl;
    
    return false;
}

// Checks whether .size() function returns size correctly
bool Test17 ()
{
    mymatrix<int>A(6,6);
    if(A.size() == 36)
    {
        return true;
    }
    
    cout << "TEST 17 FAILED" << endl;
    
    return false;
}

// Checks whetehr .size() updates the size of the matrix after changing the num of rows and cols
bool Test18()
{
    mymatrix<int>A;
    A.grow(6,11);
    if(A.size()==66)
    {
        return true;
    }
    
    cout << "TEST 18 FAILED" << endl;
    
    return false;
}

// Checks whether .aT() function works properly
bool Test19()
{
    mymatrix<int>A;
    A.at(1,1) = 35;
    if(A.at(1,1) == 35)
    {
        return true;
    }
    
    cout << "TEST 19 FAILED" << endl;
    
    return false;
}

// Checks whether .at() throws error if user tries to access a matrix position which doesn't exist.
bool Test20()
{
    mymatrix<int>A;
    try
    {
    A.at(7,4) = 67;

    }
    catch(...)
    {
        return true;
    }
    
    cout << "TEST 20 FAILED" << endl;
    
    return false;


}

// checks whether () operator returns the element correctly
bool Test21 ()
{
    mymatrix<int>A;
    A(1,3) = 27;
    if(A(1,3) == 27)
    {
        return true;
    }
    
    cout << "TEST 21 FAILED" << endl;
    
    return false;
}

// Checks whether () operator throws error if user tries to access a matrix position which doesn't exist.
bool Test22()
{
    mymatrix<int>A;
    try {
        A(5, 7) = 82;
    }
    catch(...)
    {
        return true;
    }
    
    cout << "TEST 22 FAILED" << endl;
    
    return false;
}

bool Test23()
{
    mymatrix<int>A(2,2);
    A(0,0) = 5;
    A(0,1) = 10;
    A(1,0) = 15;
    A(1,1) = 20;
    mymatrix<int>B = A*2;
    if(B(0,0) == 10 && B(0,1) == 20 && B(1,0) == 30 && B(1,1) == 40)
    {
        return true;
    }
    
    cout << "TEST 23 FAILED" << endl;
    
    return false;
}

bool  Test24()
{
    mymatrix<float>A(2,2);
    A(0,0) = 1.2;
    A(0,1) = 1.3;
    A(1,0) = 1.4;
    A(1,1) = 1.6;
    mymatrix<float>B = A*2;
    if(B(0,0)-2.4 < 0.001 && B(0,1)-2.6 < 0.001 && B(1,0)-2.8 < 0.001 && B(1,1)-3.2 < 0.001)
    {
        return true;
    }
    
    cout << "TEST 24 FAILED" << endl;
    
    return false;
}

bool Test25()
{
    try
    {
        mymatrix<int>A(2,2);
        A(0,0) = 5;
        A(0,1) = 6;
        A(1,0) = 7;
        A(1,1) = 8;
        mymatrix<int>B(3,3);
        B(0,0) = 15;
        B(0,1) = 16;
        B(0,2) = 18;
        B(1,0) = 18;
        B(1,1) = 34;
        B(1,2) = 12;
        B(2,0) = 17;
        B(2,1) = 18;
        B(2,2) = 19;
        mymatrix<int>C = A*B;
    }
    catch (...)
    {
        return true;
    }
    
    cout << "TEST 25 FAILED" << endl;
    
    return false;
}

bool Test26()
{
    try
    {
        mymatrix<int>A(2,2);
        A(0,0) = 2;
        A(0,1) = 3;
        A(1,0) = 4;
        A(1,1) = 5;
        A.growcols(1,4);
        mymatrix<int>B(2,2);
        B(0,0) = 9;
        B(0,1) = 8;
        B(1,0) = 7;
        B(1,1) = 6;
        mymatrix<int>C = A*B;
    }
    catch (...)
    {
        return true;
    }
    
    cout << "TEST 26 FAILED" << endl;
    
    return false;
}
bool Test27()
{
    mymatrix<int>B(3,2);
    B(0,0) = 10;
    B(0,1) = 20;
    B(1,0) = 30;
    B(1,1) = 40;
    B(2,0) = 50;
    B(2,1) = 60;
    mymatrix<int>A(2,3);
    A(0,0) = 2;
    A(0,1) = 3;
    A(0,2) = 4;
    A(1,0) = 5;
    A(1,1) = 6;
    A(1,2) = 7;

    mymatrix<int>C = A*B;

    if(C(0,0) == 310 && C(0,1) == 400 && C(1,0) == 580 && C(1,1) == 760 )
    {
        return true;
    }
    
    cout << "TEST 27 FAILED" << endl;
    
    return false;
}
bool Test28()
{
    mymatrix<float>B(3,2);
    B(0,0) = 2.1;
    B(0,1) = 2.2;
    B(1,0) = 2.3;
    B(1,1) = 2.4;
    B(2,0) = 2.5;
    B(2,1) = 2.6;
    mymatrix<float>A(2,3);
    A(0,0) = 1.1;
    A(0,1) = 1.2;
    A(0,2) = 1.3;
    A(1,0) = 1.4;
    A(1,1) = 1.5;
    A(1,2) = 1.6;

    mymatrix<float>C = A*B;

    if(C(0,0)-8.32 < 0.001 && C(0,1) - 8.68 < 0.001  && C(1,0) - 10.39 < 0.001 && C(1,1) - 10.84 < 0.001 )
    {
        return true;
    }
    
    cout << "TEST 28 FAILED" << endl;
    
    return false;

}


//  ----------- Running all tests -----------
int main() {

    int pass = 0;
    // test case call
    pass+= Test1();
    pass+= Test2();
    pass+= Test3();
    pass+= Test4();
    pass+= Test5();
    pass+= Test6();
    pass+= Test7();
    pass+= Test8();
    pass+= Test9();
    pass+= Test10();
    pass+= Test11();
    pass+= Test12();
    pass+= Test13();
    pass+= Test14();
    pass+= Test15();
    pass+= Test16();
    pass+= Test17();
    pass+= Test18();
    pass+= Test19();
    pass+= Test20();
    pass+= Test21();
    pass+= Test22();
    pass+= Test23();
    pass+= Test24();
    pass+= Test25();
    pass+= Test26();
    pass+= Test27();
    pass+= Test28();


    // end of tests
    if (pass != 28)
    {
        
        cout << "Not all cases passed" << endl;
        
    }
    else
    {
        
        cout << "All tests PASSED!"<<endl;
        
    }

    return 0;
}