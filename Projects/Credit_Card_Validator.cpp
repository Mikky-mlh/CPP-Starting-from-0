//TODO: Make a program to validate a credit card number

//!Luhn Algorithm Rules:
//!1. Start from the rightmost digit (check digit)
//!2. Moving left, double every second digit
//!3. If doubling results in a two-digit number, add the digits together
//!4. Sum all the digits
//!5. If the total sum is divisible by 10, the number is valid

//!Example: 6011000990139424
//!Step 1: 6011 0009 9013 9424 (start from right)
//!Step 2: 6*2 0 1*2 1 0 0 0 9 9*2 0 1*2 3 9*2 4 2*2 4 (* = double these)
//!Step 3: 12(3) 0 2 1 0 0 0 9 18(9) 0 2 3 18(9) 4 4 4
//!Step 4: 3+0+2+1+0+0+0+9+9+0+2+3+9+4+4+4
//!Step 5: 50/10=5 (VALID)

#include <iostream>
#include <string>
using namespace std;

//!Why string is better than int for credit cards:
//* Credit cards have 13-19 digits - exceeds int range (max ~2 billion)
//* Leading zeros preserved (0123 vs 123)
//* Easy character-by-character processing
//* Handles input with spaces/dashes naturally
//* No overflow issues

//!Significance of const string& cardNumber:
//* const - prevents accidental modification (read-only)
//* & (reference) - avoids copying the entire string (efficient)
//* Without &: copies whole string (slow for large data)
//* With &: uses original string's memory address (fast)

int getDigit(int digit) {
    return digit < 10 ? digit : (digit % 10) + (digit / 10);
}

int sumEvenPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}

int sumOddPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.size() - 1; i >= 0; i -= 2) {
        sum += cardNumber[i] - '0';
    }
    return sum;
}

bool isValid(const string& cardNumber) {
    return (sumEvenPlace(cardNumber) + sumOddPlace(cardNumber)) % 10 == 0;
}


int main() {
    string cardNumber;
    cout << "Enter credit card number: ";
    cin >> cardNumber;
    
    cout << cardNumber << (isValid(cardNumber) ? " is valid" : " is invalid") << endl;
    return 0;
}