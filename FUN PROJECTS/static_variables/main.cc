#include <iostream>

/*Static variable preserves their value even when they are out of scope. For this reason, a static variable
will keep the value from its previous scope, and will not be initiallized in the new scope. Hence the
previous value remains in memory till the end of the program running. E.g giving different output for the same
function call. Unlike ordinary variables which are stored on the stack segment of the memory, static variables
are stored on the data segment. Static variable are initialized with 0, just like global variables, but normal
variables will hold a garbage value.*/

// With static
void increment()
{
    static int num;
    num += 2;
    std::cout << "num = " << num << std::endl;
}

// without static
void increment_1()
{
    int num = 0;
    num += 2;
    std::cout << "num = " << num << std::endl;
}

int c;

int assign(void)
{
    return 10;
}

int main()
{
    int static a = 10;
    std::cout << a << std::endl;
    a = 23;
    std::cout << a << std::endl;
    std::cout << std::endl;

    // Initialized to 0
    int static b;
    std::cout << "static " << b << std::endl;
    int d;
    std::cout << "normal " << d << std::endl;
    std::cout << "global " << c << std::endl;
    std::cout << std::endl;

    std::cout << "With static" << std::endl;
    increment(); // num value of 2 remains in memory
    increment(); // num increments on the previous value of 2
    std::cout << std::endl;

    std::cout << "Without static" << std::endl;
    increment_1(); // num value of 2 is removed from memory when the function is done executing.
    increment_1(); // num is initallized afresh with a value of 2.
    std::cout << std::endl;

    static int e = assign();
    std::cout << e << std::endl;
    printf("%d", e); // This might not work in C, depending on the compiler. it works here in a C++ file.

    return 0;
}