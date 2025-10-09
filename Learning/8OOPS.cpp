//Todo: Enums & OOPS

#include <iostream>
using namespace std;

enum Day {Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6};

class Human
{
public:
    string name;
    string occupation;
    int age;

    void eat()
    {
        cout << name << " is eating" << endl;
    }
    void drink()
    {
        cout << name << " is drinking" << endl;
    }
    void sleep()
    {
        cout << name << " is sleeping" << endl;
    }
};


class Car
{
public:
    string brand;
    string model;
    int year;

    Car(string b, string m, int y)
    {
        brand = b;
        model = m;
        year = y;
    }

    void drive()
    {
        cout << brand << " " << model << " is driving" << endl;
    }
};

class Pizza
{
public:
    string topping1;
    string topping2;

    Pizza(string t1, string t2)
    {
        this->topping1 = t1;
        this->topping2 = t2;
    }

    Pizza()
    {
    
    }

    Pizza(string t1)
    {
        this->topping1 = t1;
    }
};

// ABSTRACTION: Hide sensitive data using private access modifier
// GETTERS/SETTERS: Control access to private attributes
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

// POLYMORPHISM & VIRTUAL FUNCTIONS
class Animal{
    public:
        bool alive = true;
    
    // Virtual function: can be overridden by child classes
    virtual void makeSound(){
        cout << "Some generic animal sound\n";
    }
    
    void eat(){
        cout << "This animal is eating\n";
    }
};

class Dog : public Animal{
    public:
    // METHOD OVERRIDING: redefine parent's method
    void makeSound() override {
        cout << "Woof! Woof!\n";
    }
    
    void bark(){
        cout << "The dog goes woof!\n";
    }
};

class Cat : public Animal{
    public:
    void makeSound() override {
        cout << "Meow! Meow!\n";
    }
};

class Shape{
    public:
        double area;
        double volume;
};

class Cube : public Shape{
    public:
        double side;
        Cube(double s){
            this->side = s;
            this->area = s * s * 6;
            this->volume = s * s * s;
        }
};

class Sphere : public Shape{
    public:
        double radius;
        Sphere(double r){
            this->radius = r;
            this->area = 4 * 3.14159 * r * r;
            this->volume = (4.0/3.0) * 3.14159 * r * r * r;  // Fixed: use 4.0/3.0
        }
};

// STATIC MEMBERS: shared across all objects
class Counter{
    public:
        static int count;  // Static variable
        
        Counter(){
            count++;  // Increment for each object created
        }
        
        static int getCount(){  // Static method
            return count;
        }
};

// Initialize static variable outside class
int Counter::count = 0;

int main()
{
    //* ENUMS = user-defined data type with named integer constants

    Day today;
    int input; 

   //! You can't directly use cin with an enum. You need to read an integer first, then cast it to the enum type:

    cout << "Enter the day of the week (0-6):";
    cin >> input;

   //* STATIC_CAST = converts a value of one type to another type.

    today = static_cast<Day>(input);

    switch (today)
    {
    case Sunday: cout << "It's Sunday!" << endl;
        break;
    case Monday: cout << "It's Monday!" << endl;
        break;
    case Tuesday: cout << "It's Tuesday!" << endl;
        break;
    case Wednesday: cout << "It's Wednesday!" << endl;
        break;
    case Thursday: cout << "It's Thursday!" << endl;
        break;
    case Friday: cout << "It's Friday!" << endl;
        break;
    case Saturday: cout << "It's Saturday!" << endl;
        break;
    }
    
    /*
    * OBJECT-ORIENTED PROGRAMMING (OOP)
    * Objects = collection of attributes and methods
    * Class = blueprint for creating objects
    * Can mimic real-world items (cars, people, etc.)
    */

    Human human1;
    human1.name = "Rick";
    human1.occupation = "Scientist";
    human1.age = 70;  
    
    cout << "\n=== Human ===" << endl;
    cout << "Name: " << human1.name << endl;
    cout << "Occupation: " << human1.occupation << endl;
    cout << "Age: " << human1.age << endl;
    human1.eat();
    human1.drink();
    human1.sleep();

    /*
    * CONSTRUCTORS = special method automatically called when object is created
    *  Same name as the class
    *  No return type (not even void)
    *  Used to initialize object attributes
    *  Can have parameters to set initial values
    */

    // Create Car objects using constructor - cleaner than setting each attribute
    Car car1("Toyota", "Camry", 2020);
    Car car2("Tesla", "Model 3", 2023);
    
    cout << "\n=== Car 1 ===" << endl;
    cout << "Brand: " << car1.brand << endl;
    cout << "Model: " << car1.model << endl;
    cout << "Year: " << car1.year << endl;
    car1.drive();
    
    cout << "\n=== Car 2 ===" << endl;
    cout << "Brand: " << car2.brand << endl;
    cout << "Model: " << car2.model << endl;
    cout << "Year: " << car2.year << endl;
    car2.drive();

    Pizza pizza1("pepperoni");
    Pizza pizza2("mushroom", "peppers");
    Pizza pizza3;

    cout << "\n=== Pizza 1 ===" << endl;
    cout << "Topping 1: " << pizza1.topping1 << endl;
    cout << "Topping 2: " << pizza1.topping2 << endl;
    
    cout << "\n=== Pizza 2 ===" << endl;
    cout << "Topping 1: " << pizza1.topping1 << endl;
    cout << "Topping 2: " << pizza1.topping2 << endl;

    cout << "\n=== Pizza 3 ===" << endl;
    cout << "Topping 1: " << pizza3.topping1 << endl;

    /*
    ! ABSTRACTION = hiding sensitive data from outside the class
    * GETTER = function that makes a private attribute READABLE
    * SETTER = function that makes a private attribute WRITEABLE
    */

    BankAccount account("ACC123456", 1000.0);
    
    cout << "\n=== Bank Account ===" << endl;
    cout << "Account: " << account.getAccountNumber() << endl;
    cout << "Balance: $" << account.getBalance() << endl;
    
    // Cannot access private attributes directly:
    // account.balance = 5000;  // ERROR! balance is private
    
    // Must use setters (with validation)
    account.deposit(500);
    cout << "New Balance: $" << account.getBalance() << endl;
    
    account.withdraw(200);
    cout << "New Balance: $" << account.getBalance() << endl;
    
    account.withdraw(5000);  // Will fail - insufficient funds
    cout << "Final Balance: $" << account.getBalance() << endl;

    /*
    * INHERITANCE = class receives attributes and methods from another class
    * Child class (Dog) inherits from Parent class (Animal)
    * Syntax: class Child : public Parent
    */
    
    Dog dog;
    cout << "\n=== Dog (Inheritance Demo) ===" << endl;
    cout << "Is alive: " << dog.alive << endl;  // Inherited attribute
    dog.eat();   // Inherited method
    dog.bark();  // Dog's own method

    /*
    * POLYMORPHISM = "many forms" - same method name, different behavior
    * VIRTUAL FUNCTIONS = enable runtime polymorphism
    * METHOD OVERRIDING = child class redefines parent's method
    */
    
    cout << "\n=== Polymorphism Demo ===" << endl;
    Animal* animal1 = &dog;  // Parent pointer to child object
    Cat cat;
    Animal* animal2 = &cat;
    
    animal1->makeSound();  // Calls Dog's version
    animal2->makeSound();  // Calls Cat's version
    
    // Same method name, different behavior based on object type

    Cube cube(10);
    Sphere sphere(5);

    cout << "\n=== Cube ===" << endl;
    cout << "Area: " << cube.area << endl;
    cout << "Volume: " << cube.volume << endl;

    cout << "\n=== Sphere ===" << endl;
    cout << "Area: " << sphere.area << endl;
    cout << "Volume: " << sphere.volume << endl;

    /*
    * STATIC MEMBERS = belong to class, not individual objects
    * Shared across all instances
    */
    
    cout << "\n=== Static Members Demo ===" << endl;
    Counter c1, c2, c3;
    cout << "Objects created: " << Counter::getCount() << endl;  // Access via class name
    
    return 0;
}
