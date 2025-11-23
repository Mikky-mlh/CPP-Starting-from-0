#include <iostream>
using namespace std;

class A {
public:
    int x, y;

    A(int a, int b) {
        x = a;
        y = b;
    }
    
    A operator+(const A& o) { 
        return A(x + o.x, y + o.y);
    }
};

int main() {
    A a1(10, 45);
    A a2(20, 46);
    A a3(30, 47);
    A  result = a1 + a2 + a3;
    cout << "Sum is: (" << result.x << ", " << result.y << ")" << endl;
    return 0;
}