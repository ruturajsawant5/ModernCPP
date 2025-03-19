#include <iostream>
#include <functional>
#include <string>
#include <unordered_set>

struct Person {
    std::string name;
    int age;

    // Need to overload the equality operator for unordered containers
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

namespace std {
    template <>
    struct hash<Person> {
        std::size_t operator()(const Person& person) const {
            // Combine hash values of member variables
            std::hash<std::string> name_hasher;
            std::hash<int> age_hasher;

            std::size_t hash_name = name_hasher(person.name);
            std::size_t hash_age = age_hasher(person.age);

            // A simple way to combine hash values (can be improved)
            return hash_name ^ (hash_age << 1);
        }
    };
} // namespace std

int primitive() {
    std::hash<int> int_hasher;
    std::hash<std::string> string_hasher;
    std::hash<double> double_hasher;

    int num = 42;
    std::string text = "hello";
    double pi = 3.14159;

    std::size_t hash_num = int_hasher(num);
    std::size_t hash_text = string_hasher(text);
    std::size_t hash_pi = double_hasher(pi);

    std::cout << "Hash of " << num << ": " << hash_num << std::endl;
    std::cout << "Hash of \"" << text << "\": " << hash_text << std::endl;
    std::cout << "Hash of " << pi << ": " << hash_pi << std::endl;

    return 0;
}

int main() {
    primitive();


    Person person1{"Alice", 30};
    Person person2{"Bob", 25};

    std::hash<Person> person_hasher;

    std::size_t hash1 = person_hasher(person1);
    std::size_t hash2 = person_hasher(person2);

    std::cout << "Hash of Alice (30): " << hash1 << std::endl;
    std::cout << "Hash of Bob (25): " << hash2 << std::endl;

    // You can now use Person as a key in std::unordered_set or std::unordered_map
    std::unordered_set<Person> people_set = {person1, person2};
    std::cout << "Size of people_set: " << people_set.size() << std::endl;

    return 0;
}