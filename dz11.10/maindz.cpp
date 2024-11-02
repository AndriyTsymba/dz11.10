#include <iostream>
#include <string>

using namespace std;
class Pet {
protected:
    string name;     
    string food;       

public:
    Pet(const string& name, const string& food) : name(name), food(food) {}
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Food: " << food << endl;
    }
    virtual ~Pet() {}  
};
class Dog : public Pet {
public:
    Dog(const string& name) : Pet(name, "Meat, bones, dry food") {}
    void displayInfo() const override {
        cout << "Type: Dog" << endl;
        Pet::displayInfo();  
    }
};
class Cat : public Pet {
public:
    Cat(const string& name) : Pet(name, "Fish, meat, dry food") {}
    void displayInfo() const override {
        cout << "Type: Cat" << endl;
        Pet::displayInfo();
    }
};
class Parrot : public Pet {
public:
    Parrot(const string& name) : Pet(name, "Seeds, fruits, vegetables") {}
    void displayInfo() const override {
        cout << "Type: Parrot" << endl;
        Pet::displayInfo();
    }
};
int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");
    Parrot parrot("Polly");
    dog.displayInfo();
    cout << endl;
    cat.displayInfo();
    cout << endl;
    parrot.displayInfo();

    return 0;
}

