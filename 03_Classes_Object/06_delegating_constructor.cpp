#include <iostream>

class Car
{
  int fuel;
  int speed;

public:
  Car () : Car (0, 0) { std::cout << "Car()" << std::endl; }
  Car (int _fuel, int _speed) : fuel (_fuel), speed (_speed)
  {
    std::cout << "Car(fuel, speed)" << std::endl;
  }
};

int
main ()
{
  Car c1;
  std::cout << "_________" << std::endl;
  Car c2 (1, 10);
  return 0;
}