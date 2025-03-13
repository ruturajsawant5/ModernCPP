#include <iostream>

int ProcessRecords(int count)
{
    int* ptr = new int[count];
    int &ref = ptr[0];

    if(count < 10)
    {
        throw std::out_of_range("Invalid Input");
        //memory leak
    }

    std::cout  << "ProcessRecords()" << std::endl;
    return 0;
}

int main()
{
    try
    {
        ProcessRecords(5);
    }
    catch (std::bad_alloc &e)
    {
        //catch by ref to avoid copy
        std::cout << e.what() << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        //catch all other exception
        std::cout << e.what() << std::endl;
    }
    catch (...)
    {
        //catch even undocumented errors
        //but cant get which error caused this
    }
    return 0;
}