//TODO: Demonstrating strings and loop functions

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//!STRINGS
	
	string name;
	
	cout << "Enter your name: ";
	getline(cin , name); //Can't get string the usual way
	if (name.empty()){
		cout << "You did not enter name!\n";
	}
	
	else{
	
		if (name.length() >  10){
			cout << "Name too big!\n";
			}
		else{
			cout << "Welcome " << name <<endl;
			}
			
	}
	
	//name.empty() checks if name is empty
	
	name.append("@gmail.com");
	cout << name << endl;
	cout << name.at(1) << endl;
	cout << name.find(' ');
	/*
	clear: clears name
	insert(index, edit)
	erase(index start, index end)
	*/

	//!LOOPS

	/*
	while loops: repeat until true
	do-while loops: do a task first and then loop if condition is true
	for loops: decide how much times you want to loop
	nested loops: loop in a loop 
	Break: break out of loop
	continue: skip current iteration
	*/

	for(int i = 1 ; i <= 20; i ++){
		if (i == 13){ 
			continue;//*13 SKIPPED
		}
		cout << i << "\n";
	}
	for(int i = 1 ; i <= 20; i ++){
		if (i == 13){ 
			break;//* STOPPED AT 13
		}
		cout << i << "\n";
	}
	
	string name;
	
	do{
	
	cout << "Enter your name: ";
	getline(cin , name);
	} while (name.empty());
	
	int rows;
	int col;
	char sym;
	
	cout << "Enter number of rows: ";
	cin >> rows;
	
	cout << "Enter number of columns: ";
	cin >> col;
	
	cout << "Enter number of symbol: ";
	cin >> sym;
	
	for(int i = 0; i <= rows; i ++){
		for(int j = 0; j <= col; j ++){
			cout << sym;	
		}
    cout << "\n";
	}
	return 0;
}