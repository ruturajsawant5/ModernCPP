#include <iostream>

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
    Test *t = new Test; //wont be free in case of exception
    if (count < 10)
        throw std::out_of_range("Count should be greater than 10");

    int *p = new int[count];

    int *pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr) {
        throw std::runtime_error("Failed to allocate memory");
    }

    //Process the records
    for (int i = 0; i < count; ++i) {
        pArray[i] = i;
    }

    //Unreachable code in case of an exception
    free(pArray);
    delete[] p;
    delete t;

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
