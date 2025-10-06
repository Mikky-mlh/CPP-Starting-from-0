#include <iostream>
#include <cstddef>
using namespace std;

//*Pass by Value - copies the value, original unchanged
//!Use when: small data types (int, char, bool), don't want to modify original
void passByValue(int x) {
    x = 100;  // only changes the copy
}

//*Pass by Reference - uses the original variable's address
//!Use when: need to modify original, large objects (arrays, strings), avoid copying
void passByReference(int& x) {
    x = 100;  // changes the original variable
}

//*Pass by Const Reference - efficient but read-only
//!Use when: large objects, don't want to modify, avoid copying
void passByConstReference(const int& x) {
    cout << "Value: " << x << endl;  // can read but not modify
    //x = 200;  // ERROR: cannot modify const parameter
}

int main()
{
    //!Memory Address = a location in memory where data is stored
    //*A memory address can be accessed with & (address-of operator)
    //!Memory addresses are displayed in HEXADECIMAL format (base 16)
    //!Hexadecimal uses 0-9 and A-F (A=10, B=11, C=12, D=13, E=14, F=15)
    //!Example: 0x7fff5fbff5ac (0x prefix indicates hexadecimal)
    
    //!USES OF MEMORY ADDRESSES:
    //* 1. Variable location tracking
    //* 2. Pointer functionality (indirect access)
    //* 3. Dynamic memory allocation (new, malloc)
    //* 4. Pass by reference implementation
    //* 5. Array indexing (array name = address of first element)
    //* 6. Data structure linking (linked lists, trees)
    //* 7. Function pointers and callbacks
    //* 8. Hardware interface and system programming
    //* 9. Memory optimization and leak prevention
    //* 10. Efficient data sharing between program parts

    string name = "Bro";
    int age = 21;
    bool student = true;
    int x = 10;

    int* ptr = &x;  // ptr stores hexadecimal address of x
    cout << "Address of name (hex): " << &name << endl;
    cout << "Address of age (hex): " << &age << endl;
    cout << "Address of student (hex): " << &student << endl;
    cout << "Address of x (hex): " << &x << endl;
    cout << "Pointer ptr holds (hex): " << ptr << endl;
    
    //!WHY HEXADECIMAL FOR ADDRESSES?
    //* More compact than binary (4 bits = 1 hex digit)
    //* Easier to read than long binary numbers
    //* Standard in computer systems and debugging
    //* Memory is organized in bytes (8 bits), hex aligns perfectly
    //* Example: 11111111 (binary) = FF (hex) = 255 (decimal)
    
    //!Pass by Value vs Pass by Reference Examples
    
    int num = 50;
    cout << "Original: " << num << endl;
    
    passByValue(num);
    cout << "After pass by value: " << num << endl;  // still 50
    
    passByReference(num);
    cout << "After pass by reference: " << num << endl;  // now 100
    
    //!When to use Pass by Value:
    //* Small data types (int, char, bool, float)
    //* When you don't want to modify the original variable
    //* Mathematical calculations where original data should remain unchanged
    //* Security - prevents accidental modification
    
    //!When to use Pass by Reference:
    //* Large objects (arrays, strings, custom classes)
    //* When you need to modify the original variable
    //* Swapping values between variables
    //* Performance critical code (avoids copying)
    //* Functions that return multiple values

    //!Const Parameter Example
    int value = 75;
    cout << "\nConst reference example:" << endl;
    passByConstReference(value);  // efficient, safe, no copying
    cout << "Value unchanged: " << value << endl;
    
    //!When to use Const Reference:
    //* Large objects (strings, arrays, classes) for efficiency
    //* When you only need to read the data, not modify it
    //* Best of both worlds: no copying + protection from modification
    //* Most common for function parameters that shouldn't change
    
    //!MEMORY ADDRESS PRACTICAL EXAMPLES:
    cout << "\nMemory layout demonstration:" << endl;
    int arr[3] = {10, 20, 30};
    cout << "Array address: " << arr << endl;  // same as &arr[0]
    cout << "First element: " << &arr[0] << endl;
    cout << "Second element: " << &arr[1] << endl;  // typically +4 bytes on 32-bit
    cout << "Third element: " << &arr[2] << endl;   // typically +8 bytes on 32-bit
    
    //!Notice: consecutive elements have addresses that differ by data type size
    //!int = 4 bytes, so addresses increment by 4 in hexadecimal

    //? pointers = variables that store memory addresses of other variables.
    // & = address-of operator, * = dereference operator
    string myname = "Yuvraj";
    string *ptr1 = &myname;

    string freepizzas[3] = {"pizza1", "pizza2", "pizza3"};
    string *ptr2 = freepizzas;

    cout << "\nPointer example:" << endl;
    cout << "Name by myname: " << myname << " or by *ptr1: " << *ptr1 << endl;
    cout << "Memory address of myname by &myname: " << &myname << "or by ptr1: " << ptr1 << endl;

    cout << "\nArray pointer example:" << endl;
    cout << ptr2 << " = " << *ptr2 << endl;
    cout << freepizzas << " = " << *freepizzas << endl;

    //? Null value = a special value that means something has no value
    //? nullptr = keyword represents an empty pointer, helpful to check if an address was assign to a pointer
    //? nullptr provided by <cstddef> header file
    int *ptr3 = nullptr;
    int y = 123;
    ptr3 = &y;

    if(ptr3 == nullptr) {
        cout << "\nAddress was not assigned!" << endl;
        
    } else {
        cout << "\nAddress was assigned!" << endl;
        cout << "Value at that address: " << *ptr3 << endl;
    }

    //* When using ptrs, be careful that your code isn't dereferencing nullptr or pointing to free memory, this will cause undefined behaviour 


    //! Dynamic Memory : Memory allocated after program is already compiled and running
    //* Use 'new' operator to allocate memory in heap instead of stack
    //* Useful when w edo not know how much memory will be needed especially when taking user input.

    int *ptr4 = new int;
    *ptr4 = 42;
    cout << "\nDynamic memory example:" << endl;
    cout << "Value at ptr4: " << *ptr4 << endl;
    cout << "Address of ptr4: " << ptr4 << endl;

    delete ptr4;

    char *pGrades = new char[5];
    int size = 5;

    cout << "\nDynamic array example:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Enter a grade: ";
        cin >> pGrades[i];
    }

    for(int i = 0; i < size; i++) {
        cout << pGrades[i] << " ";
    }

    return 0;
}
