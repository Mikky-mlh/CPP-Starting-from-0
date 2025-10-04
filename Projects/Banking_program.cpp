//TODO: MAKE A SIMPLE DEPOSIT & WITHDRAWING BANKING FUNCTION

#include <iostream>

using namespace std;


double balance;
double depositAmount;
double withdrawAmount;



void showBalance()
{
    cout << "Your current balance is: $" << balance << endl;
}

void deposit()
{
    cout << "Enter amount to deposit: ";
    cin >> depositAmount;
    balance += depositAmount;
    cout << "You deposited: $" << depositAmount << endl;
}

void withdraw()
{
    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmount;
    if (withdrawAmount > balance)
    {
        cout << "Insufficient funds" << endl;
    }
    else
    {
        balance -= withdrawAmount;
        cout << "You withdrew: $" << withdrawAmount << endl;
    }
}

int main() 
{
    char task;
    cout << "Welcome to the Banking Program" << endl;
    cout << "Please enter your initial balance: ";
    cin >> balance;

    do {
        cout << "What would you like to do? (1=Deposit, 2=Withdraw, 3=Exit): ";
        cin >> task;
        
        switch (task) {
            case '1':
                deposit();
                showBalance();
                break;
            case '2':
                withdraw();
                showBalance();
                break;
            case '3':
                cout << "Goodbye! Your final balance is $" << balance << endl;
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
                break;
        }
    } while (task != '3'); //Loop again and again to make sure the program only ends when the user wants it to.
    

    return 0;
}