#include "matrice.h"
#include <iostream>
using namespace std;
using namespace mat;

int main()
{
    matrice M(2, 2);
    matrice A(2, 2);
    M.remplissage(3);
    A.remplissage(4);
    M.printf();
    A.printf();
    //M.operator+(A);
    //M.printf();
    M.operator*(A);
    M.printf();
    //(M.operator*(A)).printf();
    //cout << endl;*/
    //cout << "Hello World!\n";
    //cout << endl;
}

