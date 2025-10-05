//TODO: Learning about arrays & foreach loops

#include <iostream>
#include <algorithm>  // For fill() function
#include <vector>     // For vector container

using namespace std;

// Function declarations: we need to declare them before using them in main function
double getTotal(double prices[], int size);
void sortArray(int arr[], int size);
void searchArray(string arr[], int size, string target);
void fillArrayFromUser();  // Fill function with multiple user values
void vectorInputDemo();    // Vector-based dynamic input function

int main()
{

//! Array[] = variable(data structure) able to hold multiple values which can be accessed via index

    string f1cars[] = {"Mercedes", "Alpine", "Williams", "Ferrari"};
    cout << f1cars[2] << endl; //gives 3rd value in array (in index everything is saved as a number less than what we read)
    f1cars[1] = "Cadillac"; //replaces 2nd value in array
    string names[] = {"John", "Mary", "Bob", "Alice"};

    cout << sizeof(f1cars) << " bytes" << endl; //returns size of any variable
    cout << sizeof(names)/sizeof(string) << " elements" << endl; //returns number of elements in array

    //* Array iteration
    for (int i = 0; i < sizeof(f1cars)/sizeof(string); i++) //returns all elements of array one by one
    {
        cout << f1cars[i] << endl;
    }
    for (int i = 0; i < 4; i++) //will give same result as earlier but we dom't need to type  all the command to find number of elements i array, we can just write it out.
    {
        cout << f1cars[i] << endl;
    }

//! FOREACH LOOP: less steps, more readable. Traverses over an iterable data structure

    int arr[] = {1, 2, 3, 4, 5};
    cout << "foreach loop" << endl;

    for (int elements : arr) //You can use anything in place of elements but will need to use that variable in order to print it out
    {
        cout << elements << endl;
    }

    //* Passing an array to a function
    double prices[] = {49.99, 15.05, 75, 9.99};
    int size = sizeof(prices)/sizeof(prices[0]); //we need to decide size in main function
    double total = getTotal(prices, size); //line 201

    cout << "$" << total << endl;

    //* Search for an element in an array using function
    string food[] = {"pizza", "hamburger", "hotdog", "fries", "chicken", "wine", "orange juice"};
    int foodSize = sizeof(food)/sizeof(food[0]);
    string myFood;

    cout << "Enter the food you want: ";
    cin >> myFood;
    searchArray(food, foodSize, myFood); //line 208

    //* Sorting an array using function
    int nums[] = {10, 5, 8, 3, 6, 2, 7, 1, 9, 4};
    int sortSize = sizeof(nums)/sizeof(nums[0]);

    cout << "Original array: ";
    for(int i = 0; i < sortSize; i++) {
        cout << nums[i] << " ";
    }

    sortArray(nums, sortSize); //line 248

    cout << "\nSorted array: ";
    for(int i = 0; i < sortSize; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    //*fill(): fills a range of elements with aspecified value. 
    //*fill(begin, end, value)

    const int SIZE = 100;
    string foods[SIZE]; 
    
    fill(foods, foods + SIZE/3, "pizza");  
    fill(foods + SIZE/3, foods + SIZE/3*2, "hamburger");
    fill(foods + SIZE/3*2, foods + SIZE, "hotdog");

    //*If the size decided by you is not divisible by the number of sections you want to add of different words or numbers then the last one will take more portion than the others(other will follow the divisibility to the closest integer. For example 100 isn't divisible by 3 so the first 2 portions follow as if the size is 99 and have 33 sections each but the last one hae 34 to compensate for the 1 remaining section)

    for(string food : foods) {
        cout << food << endl;
    }

    //* Custom fill function with user input
    fillArrayFromUser(); // line 282
    
    //* Vector-based dynamic input demonstration
    vectorInputDemo(); //line 367

    //! MULTIDIMENSIONAL ARRAYS
    
    //* 2D ARRAY DECLARATION AND INITIALIZATION
    string cars[][3] = {{"Mustang", "Escape", "F-150"},      // Row 0 (Ford)
                        {"Corvette", "Equinox", "Silverado"}, // Row 1 (Chevy) 
                        {"Challenger", "Corvette", "Ram 1500"}}; // Row 2 (Dodge)
    //? STRUCTURE EXPLANATION:
    //* [][3] means: unspecified rows, 3 columns each
    //* C++ can figure out rows from initialization (3 rows here)
    //* Each {} represents one row with 3 elements
    //* VISUAL REPRESENTATION:
    //*     Col 0      Col 1      Col 2
    //* Row 0: Mustang   Escape    F-150
    //* Row 1: Corvette  Equinox   Silverado  
    //* Row 2: Challenger Corvette Ram 1500

    int rows = sizeof(cars)/sizeof(cars[0]); //? Total array size ÷ size of first row = number of rows
    int cols = sizeof(cars[0])/sizeof(cars[0][0]); //? Size of one row ÷ size of one element = number of columns
    
    cout << "\n=== 2D ARRAY CONTENTS ===\n";
    for (int i = 0; i < rows; i++) {        
        for (int j = 0; j < cols; j++) {   
            cout << cars[i][j] << " ";
        }
        cout << endl; 
    }
    
    // ACCESSING SPECIFIC ELEMENTS in 2D Array
    cout << "\n=== ACCESSING SPECIFIC ELEMENTS ===\n";
    cout << "cars[0][2] = " << cars[0][2] << endl; // Row 0, Column 2 = "F-150"
    //? INDEXING EXPLANATION:
    // cars[0][2] means: Go to row 0, then go to column 2
    // Row 0 = {"Mustang", "Escape", "F-150"}
    // Column 2 in row 0 = "F-150"
    // Remember: indexing starts from 0, not 1!
    
    cout << "cars[1][0] = " << cars[1][0] << endl; // Row 1, Column 0 = "Corvette"
    cout << "cars[2][1] = " << cars[2][1] << endl; // Row 2, Column 1 = "Corvette"
    
    //? 3D ARRAY STRUCTURE EXPLANATION: Think of 3D arrays as multiple 2D arrays stacked on top of each other
    
    //* 3D ARRAY DECLARATION AND INITIALIZATION
    int cube[2][3][4] = {
        {  // Layer 0 (First 2D array)
            {1, 2, 3, 4},     // Row 0 of Layer 0
            {5, 6, 7, 8},     // Row 1 of Layer 0  
            {9, 10, 11, 12}   // Row 2 of Layer 0
        },
        {  // Layer 1 (Second 2D array)
            {13, 14, 15, 16}, // Row 0 of Layer 1
            {17, 18, 19, 20}, // Row 1 of Layer 1
            {21, 22, 23, 24}  // Row 2 of Layer 1
        }
    };
    //? STRUCTURE BREAKDOWN:
    //* cube[2][3][4] = 2 layers, 3 rows per layer, 4 columns per row
    //* Total elements = 2 × 3 × 4 = 24 elements
    //* ACCESS PATTERN: cube[layer][row][column]
    //* EXAMPLE: cube[1][2][3] = element at layer 1, row 2, column 3 = 24
    
    //! TRIPLE NESTED LOOPS TO TRAVERSE 3D ARRAY
    cout << "\n=== 3D ARRAY CONTENTS ===\n";
    for(int layer = 0; layer < 2; layer++) {      // OUTERMOST LOOP: layers/depth
        cout << "Layer " << layer << ":\n";
        for(int row = 0; row < 3; row++) {         // MIDDLE LOOP: rows
            cout << "  Row " << row << ": ";
            for(int col = 0; col < 4; col++) {     // INNERMOST LOOP: columns
                cout << cube[layer][row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    //? OUTPUT STRUCTURE:
    //* Layer 0:
    //*   Row 0: 1 2 3 4
    //*   Row 1: 5 6 7 8  
    //*   Row 2: 9 10 11 12
    //* Layer 1:
    //*   Row 0: 13 14 15 16
    //*   Row 1: 17 18 19 20
    //*   Row 2: 21 22 23 24
    
    //! ACCESSING SPECIFIC ELEMENTS IN 3D ARRAY
    cout << "=== 3D ARRAY ELEMENT ACCESS ===\n";
    cout << "cube[0][1][2] = " << cube[0][1][2] << endl; // Layer 0, Row 1, Column 2 = 7
    cout << "cube[1][0][3] = " << cube[1][0][3] << endl; // Layer 1, Row 0, Column 3 = 16
    cout << "cube[1][2][1] = " << cube[1][2][1] << endl; // Layer 1, Row 2, Column 1 = 22
    //? MEMORY LAYOUT: 3D arrays are stored as continuous 1D arrays in memory
    //* All elements of layer 0 first, then all elements of layer 1
    //* But we access them using [layer][row][column] for convenience

    return 0;
}

//! ========== FUNCTION 1: CALCULATE TOTAL PRICE ==========
double getTotal(double prices[], int size) 
{
    //! STEP 1: Initialize accumulator variable
    double total = 0;  // Start with zero - we'll add each price to this

    //! STEP 2: Loop through each element and add to total
    for (int i = 0; i < size; i++)  // i goes from 0 to size-1
    {
        //? LOGIC: total = total + prices[i]
        total += prices[i];
    }

    //! STEP 3: Return the final sum
    return total; 
}

//! ========== FUNCTION 2: LINEAR SEARCH ALGORITHM ==========
void searchArray(string arr[], int size, string target)
{
    //! STEP 1: Initialize search result flag
    int index = -1;  //? -1 means "not found" (impossible array index)

    //! STEP 2: Linear search - check each element one by one
    for (int i = 0; i < size; i++)  // Start from index 0, go to size-1
    {
        //? COMPARISON: Does current element match what we're looking for?
        if (arr[i] == target)  // Compare current array element with target
        {
            //! Record the position and stop searching
            index = i;  // Save the position where we found it
            break;
        }
        //? If not found, continue to next element
    }

    //! STEP 3: Report search results to user
    if (index != -1) {  //? Did we find it? (index changed from -1)
        //! SUCCESS: Item found - tell user the location
        cout << target << " is at location " << index + 1 << endl;
        //? +1 because users think in 1,2,3... but arrays use 0,1,2...
    } else {
        //! Item not found
        cout << target << " is not in our menu" << endl;
    }
}

//! ========== FUNCTION 3: BUBBLE SORT ALGORITHM ==========
void sortArray(int arr[], int size)
{
    //? BUBBLE SORT CONCEPT: Like bubbles rising to surface, largest numbers "bubble up" to the end
    //? WHY IT'S CALLED BUBBLE SORT: Adjacent elements are compared and swapped, like air bubbles

    //! OUTER LOOP: Controls how many passes we make through the array
    for(int i = 0; i < size - 1; i++)  //? size-1 because after n-1 passes, array is sorted
    {
        //? PASS EXPLANATION:
        //* Pass 1: Find largest element, move it to last position
        //* Pass 2: Find 2nd largest, move it to 2nd last position
        //* Pass 3: Find 3rd largest, move it to 3rd last position... and so on
        
        //! INNER LOOP: Compare adjacent elements in current pass
        for(int j = 0; j < size - i - 1; j++)  //? size-i-1 because last 'i' elements are already sorted
        {
            //? COMPARISON LOGIC: Is left element bigger than right element?
            if(arr[j] > arr[j + 1])  // Compare current element with next element
            {
                //! SWAP NEEDED: Left > Right, so swap them to put smaller one first
                //? SWAPPING PROCESS (3-step dance):
                int temp = arr[j];        // Step 1: Save left element in temporary storage
                arr[j] = arr[j + 1];      // Step 2: Move right element to left position  
                arr[j + 1] = temp;        // Step 3: Move saved element to right position
            }
            //? If arr[j] <= arr[j+1], no swap needed - they're already in correct order
        }
        //? After each inner loop: One more element is in its final sorted position
    }
    //? After all passes: Array is completely sorted in ascending order!
    //? TIME COMPLEXITY: O(n²) - not the fastest, but easy to understand
}

//! ========== FUNCTION 4: FILL ARRAY WITH MULTIPLE VALUES ==========
void fillArrayFromUser()
{
    //! STEP 1: Get array size from user
    int size;
    cout << "\n=== FILL FUNCTION WITH MULTIPLE VALUES ===\n";
    cout << "Enter the size of the array: ";
    cin >> size;

    //! STEP 2: Create dynamic array
    string* arr = new string[size];

    //! STEP 3: Get number of sections from user
    int sections;
    cout << "How many different values do you want? ";
    cin >> sections;
    //? Sections = how many different "zones" with different values

    //! STEP 4: Calculate section size and initialize position tracker
    int sectionSize = size / sections;
    //? DIVISION LOGIC: Divide total array size by number of sections
    
    int currentPos = 0;
    //? POSITION TRACKER: Keeps track of where we are in the array

    //! STEP 5: Loop through each section and fill with user values
    for(int i = 0; i < sections; i++) {
        
        string value;
        cout << "Enter value for section " << i + 1 << ": ";
        cin >> value;
        
        //! CALCULATE END POSITION FOR CURRENT SECTION
        int endPos = (i == sections - 1) ? size : currentPos + sectionSize;
        //? TERNARY OPERATOR LOGIC: condition ? value_if_true : value_if_false
        //? IF this is the last section (i == sections - 1):
        //*    endPos = size (use remaining space to handle uneven division)
        //? ELSE:
        //*    endPos = currentPos + sectionSize (normal section size)
        //? EXAMPLE: Array size 10, 3 sections (sectionSize = 3)
        //*    Section 1: positions 0-2 (3 elements)
        //*    Section 2: positions 3-5 (3 elements) 
        //*    Section 3: positions 6-9 (4 elements - gets the extra 1)
        
        //! USE FILL() FUNCTION TO FILL THE SECTION
        fill(arr + currentPos, arr + endPos, value);
        //? FILL SYNTAX: fill(start_iterator, end_iterator, value)
        //? arr + currentPos = pointer to starting position of this section
        //? arr + endPos = pointer to ending position (exclusive)
        //? value = what to fill the section with
        //? POINTER ARITHMETIC: arr + 3 means "3 positions after arr[0]"
        //? EXAMPLE: fill(arr + 0, arr + 4, "pizza") fills positions 0,1,2,3 with "pizza"
        
        currentPos = endPos;
        //? MOVE POSITION TRACKER: Update for next section
        //? currentPos now points to where next section should start
        //? EXAMPLE: After filling positions 0-3, currentPos becomes 4
    }
    //? AFTER LOOP: All sections filled, array completely populated with user values

    //! STEP 6: Display the complete filled array
    cout << "\nArray filled with multiple values:\n";
    for(int i = 0; i < size; i++) {
        cout << "[" << i + 1 << "] = " << arr[i] << endl;
        //? Display each element with 1-based indexing for user readability
        //? i + 1 because users think in 1,2,3... but arrays use 0,1,2...
    }
    //? Shows the result of our sectioned filling

    //! STEP 7: Clean up dynamically allocated memory
    delete[] arr;
    //? CRITICAL: Free the memory we allocated with 'new'
    //? delete[] is used for arrays, delete is used for single objects
    //? Without this, we get memory leaks (wasted memory that can't be reused)
    cout << "Array memory freed successfully!\n";
    
    //? FUNCTION SUMMARY:
    //? 1. Creates user-sized dynamic array
    //? 2. Divides array into user-specified number of sections
    //? 3. Uses fill() function to fill each section with different values
    //? 4. Handles uneven division by giving extra elements to last section
    //? 5. Demonstrates proper pointer arithmetic with fill() function
    //? 6. Manages dynamic memory allocation and cleanup properly
}

//! ========== FUNCTION 5: VECTOR-BASED DYNAMIC INPUT ==========
void vectorInputDemo()
{
    //? FUNCTION PURPOSE: Demonstrates vector advantages over arrays for user input
    //? KEY BENEFIT: No need to know size beforehand, automatic memory management
    
    cout << "\n=== VECTOR DYNAMIC INPUT DEMO ===\n";
    
    //! STEP 1: Create empty vector (no size needed!)
    vector<string> items;
    
    //! STEP 2: Get input until user says "done"
    string input;
    cout << "Enter items one by one (type 'done' to finish):\n";
    
    while(true) {
        cout << "Item " << items.size() + 1 << ": ";
        cin >> input;
        
        //? CHECK FOR EXIT CONDITION
        if(input == "done" || input == "DONE") {
            break;  // Exit the loop when user types "done"
        }
        
        //! ADD ELEMENT TO VECTOR
        items.push_back(input); //Adds element to the end of vector
    }
    
    //! STEP 3: Check if vector is empty
    if(items.empty()) {
        //? EMPTY() METHOD: Returns true if vector has no elements
        cout << "No items were entered.\n";
        return;  // Exit function early
    }
    
    //! STEP 4: Display vector contents using different methods
    cout << "\n=== VECTOR CONTENTS ===\n";
    for(int i = 0; i < items.size(); i++) {
        //? SIZE() METHOD: Returns number of elements in vector
        //? ACCESS: items[i] works just like arrays
        cout << "[" << i + 1 << "] = " << items[i] << endl;
    }
    
    //! STEP 5: Demonstrate vector methods
    cout << "\n=== VECTOR INFORMATION ===\n";
    cout << "Total items: " << items.size() << endl;
    //? SIZE(): Number of elements currently in vector
    
    cout << "Vector capacity: " << items.capacity() << endl;
    //? CAPACITY(): How much memory is allocated (usually >= size)
    //? Vector allocates extra space for efficiency
    
    cout << "First item: " << items.front() << endl;
    //? FRONT(): Returns reference to first element (same as items[0])
    
    cout << "Last item: " << items.back() << endl;
    //? BACK(): Returns reference to last element (same as items[size-1])
    
    //! STEP 6: Demonstrate vector modification
    cout << "\n=== VECTOR MODIFICATION DEMO ===\n";
    
    // Add element at the end
    items.push_back("NewItem");
    cout << "Added 'NewItem' at the end. New size: " << items.size() << endl;
    
    // Remove last element
    items.pop_back();
    //? POP_BACK(): Removes the last element from vector
    cout << "Removed last item. New size: " << items.size() << endl;
}
