#include <iostream>

using namespace std;

void addMatrix(double a[][100], double b[][100], double resultsum[][100], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            resultsum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(double a[][100], double b[][100], double resultproduct[][100], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            resultproduct[i][j] = 0;
            for(int k = 0; k < c; k++){
                resultproduct[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(){
    int r, c;
    double a[100][100], b[100][100], resultsum[100][100], resultproduct[100][100];
    
    cout << "Enter rows: ";
    cin >> r;
    cout << "Enter columns: ";
    cin >> c;
    cout << "\n";
    
    cout << "=================Matrix A=================" << endl << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << "Enter element A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> a[i][j];
        }
    }
    
    cout << "\n";
    
    cout << "=================Matrix B=================" << endl << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << "Enter element B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> b[i][j];
        }
    }
    
    addMatrix(a, b, resultsum, r, c);
    cout << "\nSum:\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << resultsum[i][j] << "\t";
        }
        cout << endl;
    }
    
    if(r == c){
        multiplyMatrix(a, b, resultproduct, r, c);
        cout << "\nProduct:\n";
        for(int i = 0; i < r; i++){
            for(int j = 0; j < r; j++){
                cout << resultproduct[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "\nMultiplication not possible (matrix must be square for this implementation)\n";
    }

    return 0;
}