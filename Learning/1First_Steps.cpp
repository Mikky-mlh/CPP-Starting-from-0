// TODO:  Demonstrating basic C++ concepts

#include <iostream>  // Input/output operations
#include <vector>    // Vector container
#include <cmath>     // Mathematical functions
using namespace std; // to not use std

typedef vector<int> vi;  // Alias for vector<int>

int main(){

    //! Basic Output
    cout << "Hello World" << endl;
    
    //? Variable Declarations & Arithmetic
    int x = 10;
    int y = 20;
    int z = x + y;
    cout << z << endl;

    //? Different Data Types
    double price = 10.5;
    char grade = 'A';
    int age = 25;
    string name = "John";
    cout << "Hello " << name << "Your age is " << age << endl;
    const double PI = 3.14159;  // Constant variable

    //! Vector Operations
    vi v = {1,2,3,4,5};
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    //? ASCII Character
    char x1 = 100;  // ASCII 100 = 'd'
    cout << x1 << endl;

    //! Percentage Calculation
    int correct = 8;
    int questions = 10;
    double score = correct / (double)questions * 100;  // Type casting
    cout << score << "%" << endl;

    //? User Input
    string a;
    cin >> a;
    cout << a << endl;

    //! Mathematical Functions
    int q = pow(2, 3);       // Power: 2^3
    cout << q << endl;
    int o = max(3, 10);      // Maximum
    cout << o << endl;
    int i = round(3.14);     // Rounding
    cout << i << endl;
    int u = sqrt(9);         // Square root
    cout << u << endl;
    int t = abs(-10);        // Absolute value
    cout << t << endl;
    int r = ceil(3.14);      // Round up
    cout << r << endl;
    int e = floor(3.14);     // Round down
    cout << e << endl;
    int w = trunc(3.14);     // Truncate shorten decimals
    cout << w << endl;

    return 0;
}