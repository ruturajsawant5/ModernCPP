#include <iostream>
#include <string>
#include <memory>
#include <utility>

// Example class Employee (assuming it's defined elsewhere)
class Employee {
public:
    std::string name;
    int id;
    int salary;

    Employee(std::string name, int id, int salary) : name(name), id(id), salary(salary) {
        std::cout << "Employee created with name: " << name << ", id: " << id << ", salary: " << salary << std::endl;
    }
};

// Example class Contact (assuming it's defined elsewhere)
class Contact {
public:
    std::string name;
    long long phoneNumber;
    std::string address;
    std::string email;

    Contact(std::string name, long long phoneNumber, std::string address, std::string email) :
        name(name), phoneNumber(phoneNumber), address(address), email(email) {
        std::cout << "Contact created with name: " << name << ", phone: " << phoneNumber
                  << ", address: " << address << ", email: " << email << std::endl;
    }

    Contact() {
        std::cout << "Default Contact created" << std::endl;
    }
};

template <typename T, typename... Args>
T* CreateObject(Args&&... args) {
    return new T(std::forward<Args>(args)...);
}

int main() {
    int *p1 = CreateObject<int>(5);
    std::cout << "*p1 = " << *p1 << std::endl;

    std::string *s = CreateObject<std::string>();
    std::cout << "*s = \"" << *s << "\"" << std::endl;

    Employee *emp = CreateObject<Employee>(
        "Bob",    // Name
        101,      // Id
        1000      // Salary
    );
    std::cout << "Employee name: " << emp->name << ", id: " << emp->id << ", salary: " << emp->salary << std::endl;

    Contact *p = CreateObject<Contact>(
        "Joey",                  // Name
        987654321,               // Phone number
        "Boulevard Road, Sgr",  // Address
        "joey@poash.com"         // Email
    );
    std::cout << "Contact name: " << p->name << ", phone: " << p->phoneNumber
              << ", address: " << p->address << ", email: " << p->email << std::endl;

    // Don't forget to deallocate the memory when you're done
    delete p1;
    delete s;
    delete emp;
    delete p;

    return 0;
}