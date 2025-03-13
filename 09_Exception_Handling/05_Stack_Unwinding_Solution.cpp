#include <iostream>
#include <vector>

class Test
{
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
    }
    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
};

void ProcessRecords(int count) {
    std::unique_ptr<Test> t(new Test); //wont be free in case of exception
    if (count < 10)
        throw std::out_of_range("Count should be greater than 10");

    std::unique_ptr<int> p(new int[count]);

    std::vector<int> vec;
    vec.reserve(count);
    //Process the records
    for (int i = 0; i < count; ++i) {
        vec[i] = i;
    }
}

int main() {
    try {
        //ProcessRecords(std::numeric_limits<int>::max());
        ProcessRecords(5);
    }
    catch (std::runtime_error &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::out_of_range &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc &ex) {
        std::cout << ex.what() << std::endl;

    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Exception" << std::endl;
    }
    return 0;
}
