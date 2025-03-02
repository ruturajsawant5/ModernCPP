#include <iostream>

int Add(int *a, int *b) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument


int main()
{
    int a = 10;
    int b = 20;

    int res = 0;
   
    res = Add(&a, &b);
    std::cout << "Sum of " << a <<" and " << b <<" is " << res << std::endl;

    res = 0;
    a = -15;
    b = 40;
    AddVal(&a, &b, &res);
    std::cout << "Sum of " << a <<" and " << b <<" is " << res << std::endl;

    a = 1888;
    b = 7878;
    std::cout << "Before Swap: a = " << a << " b = " << b << std::endl;
    Swap(&a, &b);
    std::cout << "After Swap: a = " << a << " b = " << b << std::endl;

    int f = 5;
    Factorial(&f, &res);
    std::cout << "Factorial of " << f << " is " << res << std::endl;

    return 0;
}

int Add(int *a, int *b)
{
    int sum = *a + *b;
    return sum;
}

void AddVal(int *a, int *b, int *result)
{
    *result = *a + *b;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Factorial(int *a, int *result)
{
    int fact = 1;
    
    for(int i = 1; i <= *a; i++)
        fact *= i;

   *result = fact;
}
