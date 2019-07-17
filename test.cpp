#include"simplex_kichyr.cpp"
#include<iostream>

using namespace std;

// C++ template to print vector container elements 
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 


int main()
{
    std::vector <std::vector<double> > vec2D = {
                {1, 0, 0},
                {0, 2, 1},
                {0, 0, 2}
                };
        std::vector<double> b = {30,24,36};
        std::vector<double> c = {3, 1, 2};

    /* here we solve this task: 
        max:3x + y + 2z
        subject to: x <= 30
                    2y + z <= 24
                    2z <= 36
    */
    Simplex simplex;
    /*
    the last one parametr is free member of max function,
    for example if max f = x + y + z + 3, than last parametr will be equal to 3
    */
    cout << simplex.do_Simplex(vec2D, b, c, 0);
    return 0;
}