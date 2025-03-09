#include <iostream>
#include <memory>

class Printer
{
    std::shared_ptr<int> p_int;
public:
    explicit Printer(const std::shared_ptr<int>& p) : p_int(p)
    {
    }
    void print() const
    {
        std::cout << *p_int << std::endl;
        std::cout << "Ref Cnt : " << p_int.use_count() << std::endl;
    }
};

int main ()
{
    int input;
    std::cout << "Enter number: ";
    std::cin >> input;
    std::shared_ptr<int> p_int(new int(input));
    Printer printer (p_int);
    printer.print();

    if (*p_int < 10)
    {
        p_int = nullptr;
    }

    printer.print();
    return 0;
}