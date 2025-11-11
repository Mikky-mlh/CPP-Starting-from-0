//TODO: MAKE A SIMPLE DEPOSIT & WITHDRAWING BANKING FUNCTION

#include <iostream>

using namespace std;


class BankAccount
{
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
    }

    /*
    ! ABSTRACTION = hiding sensitive data from outside the class
    * GETTER = function that makes a private attribute READABLE
    * SETTER = function that makes a private attribute WRITEABLE
    */

    // GETTER: Read private attribute
    double getBalance()
    {
        return balance;
    }

    // GETTER: Read account number
    string getAccountNumber()
    {
        return accountNumber;
    }

    // SETTER: Modify balance with validation
    void deposit(double amount)
    {
        if(amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    // SETTER: Withdraw with validation
    void withdraw(double amount)
    {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid withdrawal amount" << endl;
        }
    }
};

int main() 
{
    char task;
    double initialBalance;
    cout << "Welcome to the Banking Program" << endl;
    cout << "Please enter your initial balance: ";
    cin >> initialBalance;

    BankAccount account("ACC001", initialBalance);

    do {
        cout << "What would you like to do? (1=Deposit, 2=Withdraw, 3=Exit): ";
        cin >> task;
        
        switch (task) {
            case '1': {
                double amount;
                cout << "Enter deposit amount: $";
                cin >> amount;
                account.deposit(amount);
                cout << "Current balance: $" << account.getBalance() << endl;
                break;
            }
            case '2': {
                double amount;
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                account.withdraw(amount);
                cout << "Current balance: $" << account.getBalance() << endl;
                break;
            }
            case '3':
                cout << "Goodbye! Your final balance is $" << account.getBalance() << endl;
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
                break;
        }
    } while (task != '3');

    return 0;
}