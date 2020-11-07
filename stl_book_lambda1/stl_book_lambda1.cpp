// stl_book_lambda1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// section 6.9 using Lambdas

/*
Lambdas, introduced with C++11, define a way to specify functional behavior inside an expression
or statement (see Section 3.1.10, page 28). As a consequence, you can define objects that represent
functional behavior and pass these objects as inline argument to algorithms to be used as predicates
or for other purposes.
For example, in the following statement:
// transform all elements to the power of 3
std::transform (coll.begin(), coll.end(), // source
coll.begin(), // destination
[](double d) { // lambda as function object
return d*d*d;
});
the expression
[](double d) { return d*d*d; }
defines a lambda expression, which represents a function object that returns a double raised to the
power of 3. As you can see, this provides the ability to specify the functional behavior passed to
transform() directly where it is called.

*/


#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<int> coll = { 1, 3, 19, 5, 13, 7, 11, 2, 17 };
    int x = 5;
    int y = 12;
    auto pos = find_if(coll.cbegin(), coll.cend(), //range
        [=](int i) {                                // search criterion
            return i > x && i < y;
        }); //this makes up the lambda expression

    cout << "first elem >5 and <12: " << *pos << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
