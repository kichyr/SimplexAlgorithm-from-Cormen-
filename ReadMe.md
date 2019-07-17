## simplex-algorithm (whatch Introduction to Algorithms by Thomas Cormen, chapter about Linear programming)
This include C++ implementation for Linear programming Simplex method

To use it you shoud just go implment *simplex_kichyr.cpp*, create object of class Simplex and call do_Simplex, it's return the vector of values of the variables that maximize fun.
```C++
	Simplex simplex;
    	cout << simplex.do_Simplex(A, b, c, 0);
```
Input data for method *do_Simplex* is matrix A and vector b represents constraints: Ax <= b, vector c is vector of coefficients of the max function, and last parameter is free member of the max fun.

**example**
for task:

max:3x + y + 2z
        subject to: x <= 30
                    2y + z <= 24
                    2z <= 36


A = { {1, 0, 0}, { 0, 2, 1 }, {0, 0, 2} };
b = { 30, 24, 36 }
c = { 3, 1, 2 }
last_paramter = 0

