#include <iostream>
using std::string;

int age = 14;
const int LIGHT_SPEED = 2997; // cant change this value (const)
const int SOUND_SPEED = 1299; // cant change this value (const)
int salary = 2000;

int main() {
    int age = 17;
    std::cout << age + age << std::endl;
    std::cout << age << std::endl;
    std::cout << LIGHT_SPEED << std::endl;
    std::cout << SOUND_SPEED << std::endl;
    std::cout << salary << std::endl;

}