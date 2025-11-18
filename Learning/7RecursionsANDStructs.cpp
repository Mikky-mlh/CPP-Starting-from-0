//TODO: Recursions, templates & structs

#include <iostream>
#include <string>

using namespace std;

template <typename T, typename U> //! Can use any data type with T, but function should be just below template!
auto myMax(T a, U b) //Auto function helps to automatically identify which data type is being used.
{
    return (a > b) ? a : b;
}

int rec_factorial(int num)
{
    if (num < 0)
    {
        throw invalid_argument("Factorial not defined for negative numbers"); //Throws error
    }
    if (num == 0 || num == 1)
    {
        return 1;
    }
    return num * rec_factorial(num - 1);
}

int itr_factorial(int num)
{
    if (num < 0)
    {
        throw invalid_argument("Factorial not defined for negative numbers"); //will not get called because of error thrown in rec_factorial
    }
    if (num == 0 || num == 1)
    {
        return 1;
    }
    
    int result = 1;
    for (int i = num; i > 1; i--)
    {
        result *= i;
    }
    return result;
}

struct student{
    string name;
    double gpa;
    bool enrolled = true;
};

struct car{
    string model;
    int year;
    string color;
};

void printCar(car &c) //! Pass by reference. If &c is not used it creates a copy of the original and work on it instead of original.
{
    cout << &c << endl; //! Memory address of car
    cout << c.model << endl;
    cout << c.year << endl;
    cout << c.color << endl;
}

void paintCar(car &c, string color)
{
    c.color = color;
}

int main()
{
    //* Recursions: a programming technique where a function invokes itself from within.
    //* Break a complex concept into a repeatable single steps

    //& Advantages : less and cleaner code , useful for sorting and searching algorithms
    //& Disadvantages : uses more memory, slower
    
    int fact;

    cout << "Enter number to find factorial: ";
    cin >> fact;

    try {
        cout << rec_factorial(fact) << endl;
        cout << itr_factorial(fact) << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    //* Function Template: descries what a function looks like.
    //* Can be used to generate as many overloaded functions as needed.

    cout << myMax(10, 20) << endl;
    cout << myMax(10.5, 20.5) << endl;
    cout << myMax('a', 'b') << endl;
    cout << myMax("Hello", "World") << endl;

    /* 
    * struct: a structure that grp related variables under one name.
    ^ Structs can contain many different data types (strings, doubles, int, bool, etc.,) 
    & Var in a struct are known as members.) 
    ! They can be accessed by  "Class Member Access Operator"
    ^ Structs are useful for representing a record
   */

    student student1;
    student1.name = "John";
    student1.gpa = 3.2;

    cout << student1.name << endl;
    cout << student1.gpa << endl;
    cout << student1.enrolled << endl;
    
    car car1;
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "red";

    car car2;
    car2.model = "Corvette";
    car2.year = 2024;
    car2.color = "blue";
    
    paintCar(car1, "purple");
    paintCar(car2, "yellow");

    printCar(car1);
    printCar(car2);

    return 0;
}