#include <iostream>
using namespace std;

int main()
{
    string questions[] = {
        "1. What year was C++ invented?:",
        "2. Who invented C++?:",
        "3. What is the predecessor of C++?:",
        "4. What is the size of int in C++?:",
        "5. Which operator is used for dynamic memory allocation?:",
        "6. What does STL stand for?:",
        "7. Which header file is needed for cout?:",
        "8. What is the default access specifier in a class?:"
    };
    
    string options[][4] = {
        {"A) 1979", "B) 1983", "C) 1985", "D) 1991"},
        {"A) Dennis Ritchie", "B) Bjarne Stroustrup", "C) James Gosling", "D) Linus Torvalds"},
        {"A) C", "B) Pascal", "C) FORTRAN", "D) Assembly"},
        {"A) 2 bytes", "B) 4 bytes", "C) 8 bytes", "D) Depends on system"},
        {"A) malloc", "B) new", "C) alloc", "D) create"},
        {"A) Standard Template Library", "B) System Type Library", "C) Standard Type Library", "D) System Template Library"},
        {"A) <stdio.h>", "B) <iostream>", "C) <conio.h>", "D) <string.h>"},
        {"A) public", "B) protected", "C) private", "D) default"}
    };
    
    char answers[] = {'C', 'B', 'A', 'B', 'A', 'A', 'A', 'A'};

    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    for(int i = 0; i < size; i++)
    {
        cout << "----------------------------------------" << endl;
        cout << questions[i] << endl;
        cout << "----------------------------------------" << endl;

        for(int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++)
        {
            cout << options[i][j] << endl;
        }
        cout << "Enter your answer (A, B, C, D): ";
        cin >> guess;
        guess = toupper(guess);

        if(guess == answers[i])
        {
            cout << "Correct!" << endl;
            score++;
        }
        else
        {
            cout << "Wrong!" << endl;
            cout << "Correct answer is " << answers[i] << endl;
        }
    }

    switch(score){
        case 1:
            cout << "You got 1/8 answer correct!" << endl;
            break;
        case 2:
            cout << "You got 2/8 answers correct!" << endl;
            break;
        case 3:
            cout << "You got 3/8 answers correct!" << endl;
            break;
        case 4:
            cout << "You got 4/8 answers correct!" << endl;
            break;
        case 5:
            cout << "You got 5/8 answers correct!" << endl;
            break;
        case 6:
            cout << "You got 6/8 answers correct!" << endl;
            break;
        case 7:
            cout << "You got 7/8 answers correct!" << endl;
            break;
        case 8:
            cout << "You got 8/8 answers correct!" << endl;
            break;
        default:
            cout << "You didn't get any answers correct!" << endl;
            break;
    }

    return 0;
}
