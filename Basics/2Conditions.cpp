//TODO: Demonstrating if, switch & ternary functions 

#include <iostream>
using namespace std;

int main() 
{
//*if statements = do something if a condition is true. if not, don't do it
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (60 >= age && age >= 18)
    {
        cout << "Welcome to the club!\n";
    }
    else if (age >= 60)
    {
        cout << "You are too old to enter!\n";
    }
    else
    {
        cout << "You are too young to enter!\n";
    }

//*Switch = alt to using many "else if"
//! ONLY TAKE ONE CHARACTER

    char Grade;
    cout << "Enter your grade: ";
    cin >> Grade;

    switch (Grade)
    {
    case 'A':
        cout << "You did great!\n";
        break;
        
        //! if you don't put break, it will print all the cases after it
    
    case  'B':
        cout << "You did good!\n";
        break;
    
    case 'C':
        cout << "You did okay!\n";
        break;
    
    case 'D':
        cout << "You did poorly!\n";
        break;

    case 'F':
        cout << "You failed!\n";
        break;

    default:
        cout << "Please only enter A-F\n";
        break;
    }

//*Ternary ? output if true : output if false

    bool Tired = true;

    Tired ? cout << "Rest" : cout << "Work";

    int marks = 50;

    cout << "\n" << (marks >= 66 ? "Good work!\n" : "Work more!\n");

/* &&: Must true for both
    || : Atleast one true
    ! : Used to say "If not true"
*/

    int num;

    cout << "Enter a number: ";
    cin >> num;

    num % 2 == 0 && num < 50 ? cout << "Ideal\n" : cout << "Not Ideal\n";

    7 - num > 0 || num > 30 ? cout << "Or1\n" : cout << "Or2\n";

    bool Sunny = true;

    if (!Sunny){
        cout << "False";
    }
    else{
        cout << "True";
    }

    return 0;
}