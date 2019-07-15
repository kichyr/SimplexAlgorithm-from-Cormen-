
#include<vector>
#include<algorithm>

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

class Simplex {
private:
    std::vector< std::vector<double> > A;
    std::vector<double> b;
    std::vector<double> c;
    int nRows, nCol;
    int v; // free member of max function
    std::vector<int> N;
    std::vector<int> B;

    void initialize_Simplex(
    std::vector< std::vector<double> > & A,
    std::vector<double> & b,
    std::vector<double> & c,
    int v // free member of max function
    ) {
        this->A = A;
        this->b = b;
        this->c = c;
        this->v = v;
        nRows = A.size();
        nCol = A[0].size();
        N = range(0, nCol - nRows);
        B = range(nCol - nRows, nCol);

    }

    //utils
    std::vector<int> range(int from, int to) {
        std::vector<int> out = std::vector<int>(to - from);
        for(int i = from; i < to; i++)
            out[i - from] = i;
        return out;
    }
    //

public:
    std::vector<double> do_Simplex(
    std::vector< std::vector<double> > in_A,
    std::vector<double> in_b,
    std::vector<double> in_c,
    int in_v) { 
        initialize_Simplex(in_A, in_b, in_c, in_v);
        std::vector<double> delta = std::vector<double>(A.size());
        while(true){
            //exists index e in N : c[e] > 0
            int e = -1;
            for(auto i : N) {
                if(c[i] > 0) { 
                    e = i;
                }
            }
            cout << c << "\n" << N;
            if(e < 0) break;

            //
             for(auto i : B) {
                if(A[i][e] > 0)
                    delta[i] = b[i] / A[i][e];
                else
                    delta[i] = __INT_MAX__;
            }
            cout << "OK";
            // find l that minimized delta[l]
            int l = 0, curr_min = __INT_MAX__;
            for(int i = 0; i < delta.size(); i++)
                if(delta[i] < curr_min) {
                    l = i;
                    curr_min = delta[i];
                }
            if(delta[l] == __INT_MAX__)
                throw "unbounded";
            //pivot(A, l, e);
        }
        //generating answer
        std::vector<double> x = std::vector<double>(nCol);
        for(int i = 0; i < nCol; i++) {
            if(std::find(B.begin(), B.end(), i) != B.end())
                x[i] = b[i];
            else
                x[i] = 0;
        }
        return x;
    }

    void pivot(
    std::vector< std::vector<double> >  oldA,
    int l,
    int e
    ) {
        /* b[e] = b[l] / oldA[l][e];

        for(auto i : N) {
            if(i == e) continue;
            A[e][i] = oldA[l][i] / oldA[l][e];
        }
        A[e][l] = 1 / oldA[l][e];
    
         for(auto i : B) {
            if(i == l) continue;
            b[i] = b[i] - oldA[i][e] * b[e];
            for(auto j : N) {
                if(j == e) continue;
                    A[i][j] = oldA[i][j] - oldA[i][e] * A[e][j];
            }
            A[i][l] = -oldA[i][e] * A[e][l];
        }
        //Calc new func
        v = v + c[e] * b[e];
        for(auto j : N) {
            if(j == e) continue;
            c[j] = c[j] - c[e] * A[e][j];
        }
        c[l] = -c[e] * A[e][l];
        //Calc new Basis and NotBasis variables
        for(auto i = N.begin(); i < N.end(); i++)
            if(*i == e) {
                N.erase(i);
                break;
            }
        N.push_back(l);
        
        for(auto i = B.begin(); i < B.end(); i++)
            if(*i == l) {
                B.erase(i);
                break;
            }
        B.push_back(e); */
    }
};