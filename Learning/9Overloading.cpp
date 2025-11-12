#include <iostream>
using namespace std;

//! FUNCTION OVERLOADING: functions with the same name but different parameters
int add(int a, int b){
    return a + b;
}

double add(double a, double b){
    return a + b;
}

void print(int a){
    cout << "Integer: " << a << endl;
}

void print(double a){
    cout << "Double: " << a << endl;
}

void print(string a){
    cout << "String: " << a << endl;
}

//! OPERATOR OVERLOADING: redefine operators for custom classes
class Point
{
    public:
        int x;
        int y;
        
        Point(int xVal = 0, int yVal = 0)
        {
            x = xVal;
            y = yVal;
        }

        //! STREAM OPERATOR (<<): For printing with cout
        // MUST be 'friend' because left operand is ostream, not Point
        // Usage: cout << p1;
        // Returns: ostream& to allow chaining (cout << p1 << p2)
        friend ostream& operator << (ostream& out, const Point& p)
        {
            out << "(" << p.x << ", " << p.y << ")";
            return out;              // Returns (x,y) point
        }
        
        /* 
        ! BINARY OPERATOR (+): Adds two Point objects
        * Syntax: Point operator + (const Point& other)
        * Usage: Point p3 = p1 + p2;
        * 'const' = parameter won't be modified
        * '&' = pass by reference (efficient, no copy)
        */

        Point operator + (const Point& o)
        {
            Point result;
            result.x = x + o.x;      // this->x + o.x
            result.y = y + o.y;      // this->y + o.y
            return result;
        }
        
        //! SUBTRACTION OPERATOR (-): Example of another binary operator
        Point operator - (const Point& o)
        {
            return Point(x - o.x, y - o.y);
        }
        
        //! COMPARISON OPERATOR (==): Checks if two Points are equal
        //* Returns: bool (true/false)
        //* Usage: if(p1 == p2) { ... }
        bool operator == (const Point& o)
        {
            return (x == o.x && y == o.y);
        }
        
};

int main()
{

    cout << "\n=== Overloading ===" << endl;
    cout << add(1, 2) << endl;
    cout << add(1.5, 2.5) << endl;
    cout << add(1.5, 2.0) << endl;

    cout << "\n=== Overloading (print) ===" << endl;
    print(1);
    print(1.5);
    print("Hello World!");

    /*
    * OPERATOR OVERLOADING = redefine operators (+, -, *, ==, <<, etc.)
    * Makes custom classes behave like built-in types
    * Syntax: ReturnType operator Symbol (parameters)
    */
    
    cout << "\n=== Operator Overloading Demo ===" << endl;
    Point p1(3, 4);
    Point p2(1, 2);

    // << operator: Chaining (cout << p1 << p2 works because << returns ostream&)
    cout << "Chaining: " << p1 << " and " << p2 << endl;
    
    // + operator: Add two points
    Point p3 = p1 + p2;  // (3,4) + (1,2) = (4,6)
    cout << p1 << " + " << p2 << " = " << p3 << endl;
    
    // - operator: Subtract two points
    Point p5 = p1 - p2;  // (3,4) - (1,2) = (2,2)
    cout << p1 << " - " << p2 << " = " << p5 << endl;
    
    // == operator: Compare points
    Point p4(3, 4);
    cout << p1 << " == " << p4 << " ? " << (p1 == p4 ? "true" : "false") << endl;
    cout << p1 << " == " << p2 << " ? " << (p1 == p2 ? "true" : "false") << endl;
    
    return 0;
}
