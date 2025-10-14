#include <iostream>
using namespace std;

int main()
{
    int n;
    int fact = 1;

    cout << "Enter number for factorial: ";
    cin >> n;

    if(n<0){
        cout << "Enter a positive number!\n";
    }
    else if(n==0){
        cout << "Factorial of 0 is 1.\n";
    }
    else{
        for(int i=1; i<=n; i++){
            fact = i*fact;
        }
    }
    cout << "Factorial of " << n << " is " << fact << endl;
    
    return 0;
}
