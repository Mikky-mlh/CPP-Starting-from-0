#include <iostream>
using namespace std;

class A {
public:
    int x, y;

    A(int a, int b) {
        x = a;
        y = b;
    }
    
    void operator+(const A& o) { 
        cout << "Sum is: (" << x + o.x << ", " << y + o.y << ")" << endl;
    }
};

int main() {
    A a1(10, 45);
    A a2(20, 46);
    a1 + a2;
    return 0;
}