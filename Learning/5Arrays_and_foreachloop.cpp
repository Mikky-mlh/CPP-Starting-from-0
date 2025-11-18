//TODO: Learning about arrays & foreach loops

#include <iostream>
#include <algorithm>  // For fill() function
#include <vector>     // For vector container

using namespace std;

// Function declarations

double getTotal(double prices[], int size) // Calculate sum of all array elements
{
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += prices[i];
    }
    return total; 
}
void searchArray(string arr[], int size, string target) // Linear search: find element in array
{
    int index = -1;  // -1 means not found

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << target << " is at location " << index + 1 << endl;
    } else {
        cout << target << " is not in our menu" << endl;
    }
}
void sortArray(int arr[], int size) // Bubble sort: sort array in ascending order: Compares adjacent elements and swaps if needed
{
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}         
void fillArrayFromUser();   
void vectorInputDemo();     

int main()
{

//* Array: data structure holding multiple values accessed via index
    string f1cars[] = {"Mercedes", "Alpine", "Williams", "Ferrari"};
    cout << f1cars[2] << endl;  // Access 3rd element (index 2)
    f1cars[1] = "Cadillac";     // Modify 2nd element
    string names[] = {"John", "Mary", "Bob", "Alice"};

    cout << sizeof(f1cars) << " bytes" << endl;
    cout << sizeof(names)/sizeof(string) << " elements" << endl;  // Calculate array length

    // Array iteration with for loop
    for (int i = 0; i < sizeof(f1cars)/sizeof(string); i++) {
        cout << f1cars[i] << endl;
    }
    for (int i = 0; i < 4; i++) {
        cout << f1cars[i] << endl;
    }

    //! Foreach loop: cleaner syntax for iterating arrays
    int arr[] = {1, 2, 3, 4, 5};
    cout << "foreach loop" << endl;
    for (int elements : arr) {
        cout << elements << endl;
    }

    // Passing array to function
    double prices[] = {49.99, 15.05, 75, 9.99};
    int size = sizeof(prices)/sizeof(prices[0]);
    double total = getTotal(prices, size);
    cout << "$" << total << endl;

    // Search array for element
    string food[] = {"pizza", "hamburger", "hotdog", "fries", "chicken", "wine", "orange juice"};
    int foodSize = sizeof(food)/sizeof(food[0]);
    string myFood;
    cout << "Enter the food you want: ";
    cin >> myFood;
    searchArray(food, foodSize, myFood);

    // Sort array
    int nums[] = {10, 5, 8, 3, 6, 2, 7, 1, 9, 4};
    int sortSize = sizeof(nums)/sizeof(nums[0]);

    cout << "Original array: ";
    for(int i = 0; i < sortSize; i++) {
        cout << nums[i] << " ";
    }

    sortArray(nums, sortSize);

    cout << "\nSorted array: ";
    for(int i = 0; i < sortSize; i++) {
        cout << nums[i] << " " << endl;
    }

    //* fill(): fills array range with specified value
    // Syntax: fill(begin, end, value)
    const int SIZE = 100;
    string foods[SIZE]; 
    fill(foods, foods + SIZE/3, "pizza");  
    fill(foods + SIZE/3, foods + SIZE/3*2, "hamburger");
    fill(foods + SIZE/3*2, foods + SIZE, "hotdog");

    for(string food : foods) {
        cout << food << endl;
    }

    cout << "\nDynamic array example:" << endl;
    int gradeSize = 5;  // Number of grades
    double* pGrades = new double[gradeSize];  // Dynamic array for grades

    for(int i = 0; i < gradeSize; i++) {
        cout << "Enter grade" << i + 1 << "(integer between 0 and 100): ";
        cin >> pGrades[i];
        if(pGrades[i] < 0 || pGrades[i] > 100) {
            cout << "Invalid grade. Please enter a grade between 0 and 100." << endl;
            i--;  // Decrement i to re-enter the grade
        }
        cout << endl;
    }

    for(int i = 0; i < gradeSize; i++) {
        cout << pGrades[i] << " ";
    }
    
    delete[] pGrades;  // Free memory

    fillArrayFromUser();
    vectorInputDemo();

    //! 2D ARRAY: array of arrays (rows and columns)
    string cars[][3] = {{"Mustang", "Escape", "F-150"},
                        {"Corvette", "Equinox", "Silverado"},
                        {"Challenger", "Corvette", "Ram 1500"}};
    // [][3] means: auto rows, 3 columns

    int rows = sizeof(cars)/sizeof(cars[0]);        // Calculate rows
    int cols = sizeof(cars[0])/sizeof(cars[0][0]);  // Calculate columns
    
    cout << "\n=== 2D ARRAY CONTENTS ===\n";
    for (int i = 0; i < rows; i++) {        
        for (int j = 0; j < cols; j++) {   
            cout << cars[i][j] << " ";
        }
        cout << endl; 
    }
    
    // Access 2D array elements: array[row][column]
    cout << "\n=== ACCESSING SPECIFIC ELEMENTS ===\n";
    cout << "cars[0][2] = " << cars[0][2] << endl;
    cout << "cars[1][0] = " << cars[1][0] << endl;
    cout << "cars[2][1] = " << cars[2][1] << endl;
    
    //! 3D ARRAY: multiple 2D arrays stacked together
    int cube[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    // cube[2][3][4] = 2 layers, 3 rows, 4 columns
    // Access: cube[layer][row][column]
    
    // Traverse 3D array with triple nested loop
    cout << "\n=== 3D ARRAY CONTENTS ===\n";
    for(int layer = 0; layer < 2; layer++) {
        cout << "Layer " << layer << ":\n";
        for(int row = 0; row < 3; row++) {
            cout << "  Row " << row << ": ";
            for(int col = 0; col < 4; col++) {
                cout << cube[layer][row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Access 3D array elements
    cout << "=== 3D ARRAY ELEMENT ACCESS ===\n";
    cout << "cube[0][1][2] = " << cube[0][1][2] << endl;
    cout << "cube[1][0][3] = " << cube[1][0][3] << endl;
    cout << "cube[1][2][1] = " << cube[1][2][1] << endl;

    return 0;
}


// Fill array sections with different user values
void fillArrayFromUser()
{
    int size;
    cout << "\n=== FILL FUNCTION WITH MULTIPLE VALUES ===\n";
    cout << "Enter the size of the array: ";
    cin >> size;

    string* arr = new string[size];  // Dynamic array

    int sections;
    cout << "How many different values do you want? ";
    cin >> sections;

    int sectionSize = size / sections;
    int currentPos = 0;

    for(int i = 0; i < sections; i++) {
        string value;
        cout << "Enter value for section " << i + 1 << ": ";
        cin >> value;
        
        // Last section gets remaining elements
        int endPos = (i == sections - 1) ? size : currentPos + sectionSize;
        
        fill(arr + currentPos, arr + endPos, value);  // Fill section
        currentPos = endPos;
    }

    cout << "\nArray filled with multiple values:\n";
    for(int i = 0; i < size; i++) {
        cout << "[" << i + 1 << "] = " << arr[i] << endl;
    }

    delete[] arr;  // Free memory
    cout << "Array memory freed successfully!\n";
}

// Vector: dynamic array with automatic memory management
void vectorInputDemo()
{
    cout << "\n=== VECTOR DYNAMIC INPUT DEMO ===\n";
    
    vector<string> items;  // No size needed
    string input;
    cout << "Enter items one by one (type 'done' to finish):\n";
    
    while(true) {
        cout << "Item " << items.size() + 1 << ": ";
        cin >> input;
        
        if(input == "done" || input == "DONE") {
            break;
        }
        
        items.push_back(input);  // Add to end
    }
    
    if(items.empty()) {
        cout << "No items were entered.\n";
        return;
    }
    
    // Display contents
    cout << "\n=== VECTOR CONTENTS ===\n";
    for(int i = 0; i < items.size(); i++) {
        cout << "[" << i + 1 << "] = " << items[i] << endl;
    }
    
    // Vector methods
    cout << "\n=== VECTOR INFORMATION ===\n";
    cout << "Total items: " << items.size() << endl;
    cout << "Vector capacity: " << items.capacity() << endl;
    cout << "First item: " << items.front() << endl;
    cout << "Last item: " << items.back() << endl;
    
    // Modification demo
    cout << "\n=== VECTOR MODIFICATION DEMO ===\n";
    items.push_back("NewItem");
    cout << "Added 'NewItem' at the end. New size: " << items.size() << endl;
    
    items.pop_back();  // Remove last element
    cout << "Removed last item. New size: " << items.size() << endl;
}
