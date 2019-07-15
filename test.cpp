#include"simplex_kichyr.cpp"
#include<iostream>

using namespace std;



int main()
{

int colSizeA=6;  //should initialise columns size in A
    int rowSizeA = 3;  //should initialise columns row in A[][] vector

    double C[]={6,5,4, 0 , 0, 0};  //should initialis the c arry here
    double B[]={180,300,240};  // should initialis the b array here



    double a[rowSizeA][colSizeA] =   {
                 { 2,  1,  1,   1,  0, 0},
                { 1,  3,  2,   0,  1, 0 },
                {   2,    1,  2,   0,  0,  1}
                };

        std::vector <std::vector<double> > vec2D(rowSizeA, std::vector<double>(colSizeA, 0));
        std::vector<double> b(rowSizeA,0);
        std::vector<double> c(colSizeA,0);




       for(int i=0;i<rowSizeA;i++){         //make a vector from given array
            for(int j=0; j<colSizeA;j++){
                vec2D[i][j] = a[i][j];
            }
       }


       for(int i=0;i<rowSizeA;i++){
            b[i] = B[i];
       }

        for(int i=0;i<colSizeA;i++){
            c[i] = C[i];
       }

        cout << vec2D;
      // hear the make the class parameters with A[m][n] vector b[] vector and c[] vector
    Simplex simplex;
    cout << simplex.do_Simplex(vec2D, b, c, 0);
    return 0;
}