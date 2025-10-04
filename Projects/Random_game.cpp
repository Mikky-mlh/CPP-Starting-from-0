//TODO: Making a game that includes 2 games based on randomization


#include <iostream>
#include <string>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <limits>   // For numeric_limits

using namespace std;

//! Global variables
int guess; 
int num_GTN;
int num_RPS;
char playerChoice;

void clearInputBuffer() {
    cin.clear(); //*clears cin error
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //*clears garbage from input buffer & checks for valid inputs
}

void GTN() {
    int tries = 0;
    num_GTN = rand() % 10 + 1;
    
    cout << "\n=== GUESS THE NUMBER ===\n";
    cout << "I'm thinking of a number between 1 and 10. Can you guess it?\n\n";
    
    do{
        cout << "Enter your guess (1-10): ";

        // Input validation for GTN
        if(!(cin >> guess)) {
            cout << "Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        if(guess < 1 || guess > 10) {
            cout << "Please enter a number between 1 and 10!\n";
            continue;
        }
        
        tries++;

        if(guess == num_GTN) {
            cout << "🎉 You guessed correctly!\n";
            cout << "It took you " << tries << " tries!\n";
        } else {
            if(guess > num_GTN) {
                cout << "Your guess is too high! Try again.\n";
            } else {
                cout << "Your guess is too low! Try again.\n";
            }
        }
    } while (guess != num_GTN);
}

void RPS() {
    num_RPS = rand() % 3 + 1;  
    
    cout << "\n=== ROCK PAPER SCISSORS ===\n";
    cout << "Rules: Rock beats Scissors, Scissors beats Paper, Paper beats Rock\n\n";
    
    // Input validation loop for RPS
    bool validInput = false;
    do {
        cout << "Choose R for Rock, P for Paper or S for Scissors: ";
        cin >> playerChoice;
        
        if((playerChoice == 'R' || playerChoice == 'r' || 
            playerChoice == 'P' || playerChoice == 'p' || 
            playerChoice == 'S' || playerChoice == 's')) {
            validInput = true;
        } else {
            cout << "Invalid choice! Please enter R, P, or S.\n";
        }
    } while(!validInput);


    string computerChoice;
    if(num_RPS == 1) computerChoice = "Rock";
    else if(num_RPS == 2) computerChoice = "Paper";
    else computerChoice = "Scissors";
    
    cout << "\nYou chose: ";
    if(playerChoice == 'R' || playerChoice == 'r') cout << "Rock";
    else if(playerChoice == 'P' || playerChoice == 'p') cout << "Paper";
    else cout << "Scissors";
    cout << "\nComputer chose: " << computerChoice << "\n\n";

    if((playerChoice == 'R' || playerChoice == 'r') && num_RPS == 1) {
        cout << "🤝 It's a tie!\n";}
    else if((playerChoice == 'R' || playerChoice == 'r') && num_RPS == 2) {
        cout << "😞 You lost! Paper covers Rock.\n";}
    else if((playerChoice == 'R' || playerChoice == 'r') && num_RPS == 3) {
        cout << "🎉 You won! Rock crushes Scissors.\n";}
    else if((playerChoice == 'P' || playerChoice == 'p') && num_RPS == 1) {
        cout << "🎉 You won! Paper covers Rock.\n";}
    else if((playerChoice == 'P' || playerChoice == 'p') && num_RPS == 2) {
        cout << "🤝 It's a tie!\n";}
    else if((playerChoice == 'P' || playerChoice == 'p') && num_RPS == 3) {
        cout << "😞 You lost! Scissors cuts Paper.\n";}
    else if((playerChoice == 'S' || playerChoice == 's') && num_RPS == 1) {
        cout << "😞 You lost! Rock crushes Scissors.\n";}
    else if((playerChoice == 'S' || playerChoice == 's') && num_RPS == 2) {
        cout << "🎉 You won! Scissors cuts Paper.\n";}
    else if((playerChoice == 'S' || playerChoice == 's') && num_RPS == 3) {
        cout << "🤝 It's a tie!\n";}
}

char askPlayAgain() {
    char choice;
    do {
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
        if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Please enter 'y' for yes or 'n' for no.\n";
        }
    } while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
    return choice;
}

int main() {
    //! Random number Setup
    srand(time(NULL));
    
    cout << "🎮 Welcome to the Game Center! 🎮\n";
    cout << "==============================\n";
    
    char game;
    char playAgain;
    
    do {
        // Game selection
        bool validGameChoice = false;
        do {
            cout << "\nChoose your game:\n";
            cout << "1 - Guess The Number (GTN)\n";
            cout << "2 - Rock Paper Scissors (RPS)\n";
            cout << "Enter your choice (1 or 2): ";
            cin >> game;
            
            if(game == '1' || game == '2') {
                validGameChoice = true;
            } else {
                cout << "Invalid choice! Please enter 1 or 2.\n";
                clearInputBuffer(); // Clear any extra input
            }
        } while(!validGameChoice);

        // Play selected game
        if(game == '1') {
            GTN();
        } else {
            RPS();
        }
        
        // Ask to play again
        playAgain = askPlayAgain();
        
    } while(playAgain == 'y' || playAgain == 'Y');
    
    cout << "\n🎉 Thanks for playing! See you next time! 🎉\n";
    return 0;
}