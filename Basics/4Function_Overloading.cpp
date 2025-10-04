//TODO: Function overloading & variables

#include <iostream>
#include <string>

using namespace std;

//! FUNCTION OVERLOADING = Same function name, different parameters
//? Compiler decides which function to call based on arguments passed

//* MOST IMP RULE: Function must be known before it's used

int globalVar = 100;  // Global variable - accessible everywhere

//! Function with no parameters
void bakePizza() {
    cout << "Here is your pizza!" << endl;
}

//! Function with 1 parameter (overloaded)
void bakePizza(string topping1) {
    cout << "Here is your pizza with " << topping1 << endl;
}

//! Function with 2 parameters (overloaded)
void bakePizza(string topping1, string topping2) {
    cout << "Here is your pizza with " << topping1 << " and " << topping2 << endl;
}

//? Function demonstrating variable scope
void scopeExample() {
    int localVar = 50;  // Local variable - only accessible in this function
    cout << "Local variable: " << localVar << endl;
    cout << "Global variable from function: " << globalVar << endl;
}

int main() {

    //! FUNCTION OVERLOADING EXAMPLES:
    bakePizza();                           // Calls function with no parameters
    bakePizza("pepperoni");                // Calls function with 1 parameter
    bakePizza("pepperoni", "mushrooms");   // Calls function with 2 parameters

    //! VARIABLE SCOPE EXAMPLES:
    
    //* Local variables = declared inside a function or block {}
    //* - Only accessible within that scope
    //* - Destroyed when scope ends
    int localMain = 25;  // Local to main() function
    
    //* Global variables = declared outside all functions
    //* - Accessible from anywhere in the program
    //* - Exist for entire program duration
    
    cout << "\n--- Variable Scope Demo ---" << endl;
    cout << "Local variable in main: " << localMain << endl;
    cout << "Global variable from main: " << globalVar << endl;
    
    scopeExample();  // This function can access globalVar but not localMain
    
    //? Block scope example
    {
        int blockVar = 75;  // Only exists within these braces
        cout << "Block variable: " << blockVar << endl;
    }
    // blockVar is destroyed here - cannot access it outside the block

    return 0;
}



