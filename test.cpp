#include"simplex_kichyr.cpp"
#include<iostream>

using namespace std;



int main()
{
    std::vector <std::vector<double> > vec2D = {
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                { 2, 1, 1,0,0,0},
                { 1, 3, 2,0,0,0},
                { 2, 1, 2,0,0,0}
                };
        std::vector<double> b = {0, 0, 0, 180,300,240};
        std::vector<double> c = {6, 5, 4, 0 , 0, 0};

        cout << vec2D;
      // hear the make the class parameters with A[m][n] vector b[] vector and c[] vector
    Simplex simplex;
    cout << simplex.do_Simplex(vec2D, b, c, 0);
    return 0;
}