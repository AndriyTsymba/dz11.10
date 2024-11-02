#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string name;
    string surname;
    int age;
    double averageMark;

public:
    Student(string name, string surname, int age, double averageMark)
        : name(name), surname(surname), age(age), averageMark(averageMark) {}

    // Метод для отримання інформації про студента
    virtual void getInfo() const {
        cout << "Name " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
        cout << "Average : " << averageMark << endl;
    }

    virtual ~Student() {}
};

class Aspirant : public Student {
private:
    string thesisTopic;  
    bool isThesisDefended;  

public:
    Aspirant(string name, string surname, int age, double averageMark, string thesisTopic, bool isThesisDefended)
        : Student(name, surname, age, averageMark), thesisTopic(thesisTopic), isThesisDefended(isThesisDefended) {}

    void getInfo() const override {
        Student::getInfo();  
        cout << "Candidate thesis topic: " << thesisTopic << endl;
        cout << "Thesis defense:" << (isThesisDefended ? "Yes" : "NO") << endl;
    }
};

int main() {
  
    Student student("Ivan", "Smernov", 20, 4.5);
    student.getInfo();
    cout << endl;

    Aspirant aspirant("Olga", "Rebak", 25, 4.8, "Thesis defense:", true);
    aspirant.getInfo();

    return 0;
}


//2

#include <iostream>
#include <string>

using namespace std;

class Passport {
protected:
    string name;
    string surname;
    string nationality;
    string passportNumber;
    string birthDate;
    string issueDate;
    string expirationDate;

public:

    Passport(string name, string surname, string nationality, string passportNumber, string birthDate, string issueDate, string expirationDate)
        : name(name), surname(surname), nationality(nationality), passportNumber(passportNumber), birthDate(birthDate), issueDate(issueDate), expirationDate(expirationDate) {}

    virtual void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Passport Number: " << passportNumber << endl;
        cout << "Date of Birth: " << birthDate << endl;
        cout << "Issue Date: " << issueDate << endl;
        cout << "Expiration Date: " << expirationDate << endl;
    }
    virtual ~Passport() {}
};

class ForeignPassport : public Passport {
private:
    string foreignPassportNumber;  
    string visas[5];               
    int visaCount;                

public:
 
    ForeignPassport(string name, string surname, string nationality, string passportNumber, string birthDate, string issueDate, string expirationDate, string foreignPassportNumber)
        : Passport(name, surname, nationality, passportNumber, birthDate, issueDate, expirationDate), foreignPassportNumber(foreignPassportNumber), visaCount(0) {}

    void addVisa(const string& visa) {
        if (visaCount < 5) {
            visas[visaCount] = visa;
            visaCount++;
        }
        else {
            cout << "Cannot add more visas, maximum limit is 5." << endl;
        }
    }
    void getInfo() const override {
        Passport::getInfo();  
        cout << "Foreign Passport Number: " << foreignPassportNumber << endl;
        if (visaCount > 0) {
            cout << "Visas: " << endl;
            for (int i = 0; i < visaCount; ++i) {
                cout << "- " << visas[i] << endl;
            }
        }
        else {
            cout << "Visas: None" << endl;
        }
    }
};

int main() {
    Passport passport("Ivan", "Petrenko", "Ukrainian", "AA123456", "01.01.1985", "10.05.2010", "10.05.2025");
    passport.getInfo();
    cout << endl;

    ForeignPassport foreignPassport("Olga", "Kovalenko", "Ukrainian", "BB654321", "15.03.1990", "20.07.2015", "20.07.2025", "FP987654");
    foreignPassport.addVisa("Schengen Visa");
    foreignPassport.addVisa("USA Visa");
    foreignPassport.getInfo();

    return 0;
}
//3

#include <iostream>
#include <string>

using namespace std;
class TransportVehicle {
protected:
    double distance; 

public:
    TransportVehicle(double distance) : distance(distance) {}
    virtual double calculateTime() const = 0;  
    virtual double calculateCost() const = 0; 

    virtual ~TransportVehicle() {}
};
class Car : public TransportVehicle {
private:
    double speed;    
    double costPerKm;
public:
    Car(double distance, double speed, double costPerKm)
        : TransportVehicle(distance), speed(speed), costPerKm(costPerKm) {}
    double calculateTime() const override {
        return distance / speed;
    }
    double calculateCost() const override {
        return distance * costPerKm;
    }
};
class Bicycle : public TransportVehicle {
private:
    double speed;    
public:
    Bicycle(double distance, double speed)
        : TransportVehicle(distance), speed(speed) {}
    double calculateTime() const override {
        return distance / speed;
    }

    double calculateCost() const override {
        return 0.0;
    }
};
class Cart : public TransportVehicle {
private:
    double speed;     
    double costPerKm; 

public:
    Cart(double distance, double speed, double costPerKm)
        : TransportVehicle(distance), speed(speed), costPerKm(costPerKm) {}
    double calculateTime() const override {
        return distance / speed;
    }
    double calculateCost() const override {
        return distance * costPerKm;
    }
};

int main() {
    double distance = 100.0; 
    Car car(distance, 80.0, 5.0);       
    Bicycle bicycle(distance, 20.0);    
    Cart cart(distance, 10.0, 2.0);    
    cout << "Transport time: " << car.calculateTime() << " hours" << endl;
    cout << "Transport cost: " << car.calculateCost() << endl << endl;
    cout << "Bicycle:" << endl;
    cout << "Transport time: " << bicycle.calculateTime() << " hours" << endl;
    cout << "Transport cost: " << bicycle.calculateCost() << endl << endl;
    cout << "Cart:" << endl;
    cout << "Transport time: " << cart.calculateTime() << " hours" << endl;
    cout << "Transport cost: " << cart.calculateCost() << endl;

    return 0;
}
