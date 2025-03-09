#include <iostream>

class Printer
{
    int* p_int;
    public:
    explicit Printer(int* p) : p_int(p)
    {
    }
    void print() const
    {
        std::cout << *p_int << std::endl;
    }
};

int main ()
{
    int* p_int = new int(10);
    Printer printer (p_int);
    printer.print();

    if (*p_int < 10)
    {
        delete p_int;
        p_int = nullptr;
    }

    printer.print();

    delete p_int;
}