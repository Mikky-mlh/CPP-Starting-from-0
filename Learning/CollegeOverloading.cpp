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

    bool operator==(const A& o) {
        return x == o.x && y == o.y;
    }

};

int main() {
    A a1(10, 45);
    A a2(20, 46);
    a1 + a2;
    A a3(10, 45);
    cout << "Are a1 and a2 equal? " << (a1 == a2 ? "Yes" : "No") << endl;
    cout << "Are a1 and a3 equal? " << (a1 == a3 ? "Yes" : "No") << endl;
    cout << "Are a1, a2 and a3 equal? " << (a1 == a3 && a1 == a2 ? "Yes" : "No") << endl;
    return 0;
}
