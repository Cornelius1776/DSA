#include "bet.h"

// Array as argument
/* int sum_array(int arr[]) // int *arr also works. since an array is treated as a pointer to its first element
{
    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    std::cout << "size of arr[] inside sum_array() is " << sizeof(arr) << std::endl;
    return sum;
} */
/* Above implementation does not work well because arrays as function argument is treated by the compiler as
a reference argument. So, when sum_array() is invoked in main, the address of the array(which is also the
address of the first element) is taken and returned. sizeof(arr) inside the sum_array() is different from
sizeof(arr) inside main(), because array as an argument is treated as a reference, the size
is 8 bytes (size of the first element plus second element after increment) inside sum_array(). Whereas in main(),
sizeof(arr) is 24 bytes which is the size of all the int elements in the array. In the
implementation below, explicitly setting the size of the array (n) solves the problem. However, the sizeof()
behavior remains the same. In a nutshell arrays are called by reference not by value. */

int sum_array(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // std::cout << "size of arr[] inside sum_array is " << sizeof(arr) << std::endl;
    return sum;
}

// printing arrays and using them as argument
void print(int *a, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << a[i];
        if (i != count - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Print multi-dimensional arrays and using them as arguments
void print_md(int arr[][2][2], int count)
{
}

int main()
{
    // c
    // Manipulating elements of the array using pointers
    std::cout << "pass by pointer" << std::endl;
    int arr[] = {23, 10, 4, 2, 7, 20, 56, 67, 65};
    int n = sizeof(arr) / sizeof(arr[0]); // length of the array

    int *ptr = &arr[0];
    std::cout << ptr << std::endl;        // prints the memory address of the element at that index.
    std::cout << *ptr << std::endl;       // dereferenced to print the element
    std::cout << *(ptr + 1) << std::endl; // dereferenced to print the element at the next index

    int *ptr_1 = &arr[2];
    std::cout << ptr_1 << std::endl;
    std::cout << *ptr_1 << std::endl;
    ptr_1++; // next index in the array
    std::cout << ptr_1 << std::endl;
    std::cout << *ptr_1 << std::endl;

    /* The address of the first element in the array is the address of the array itself or base address. If
    the address of the array is to be printed, the output is the address of the first element, when the
    array also dereferenced, only the value of the first element will be printed, not all the elements.  */
    std::cout << std::endl;

    int *arr_ptr = arr;
    std::cout << arr_ptr << std::endl;
    std::cout << *arr_ptr << std::endl;
    std::cout << std::endl;

    // printing array elements
    std::cout << "printing array elements using different syntaxes" << std::endl;
    int arr_1[] = {10, 20, 30, 40};
    std::cout << arr_1[3] << std::endl;
    std::cout << *(arr_1 + 3) << std::endl;
    std::cout << *(3 + arr_1) << std::endl;
    std::cout << 3 [arr_1] << std::endl;
    std::cout << std::endl;

    // assigning the array functionalities to a pointer
    std::cout << "assigning the array functionalities to a pointer" << std::endl;
    int *p = arr_1;
    std::cout << arr << std::endl;
    std::cout << p << std::endl;
    std::cout << (p + 1) << std::endl;
    std::cout << &arr_1[1] << std::endl;
    std::cout << (p + 2) << std::endl;
    std::cout << &arr_1[2] << std::endl;

    // Looping through
    std::cout << "Looping through ------------------------ " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr + i << " : ";        // Address
        std::cout << *(arr + i) << std::endl; // Element
        /* // Alternative syntax for the output
        std::cout << &arr[i] << " : "; // Adrress
        std::cout << arr[i] << std::endl; // Element */
    }
    std::cout << std::endl;

    // Arrays as function argument
    /* int sum = sum_array(arr);
    std::cout << "The sum of the elements in the array is " << sum << std::endl;
    std::cout << "size of arr[] inside main() is " << sizeof(arr) << std::endl;*/

    int sum = sum_array(arr, n);
    std::cout << "The sum of the elements in the array is " << sum << std::endl;

    // Assigning the value of an array element to a variable
    std::cout << "Assigning the value of an array element to a variable" << std::endl;
    int ten = arr[1];
    std::cout << ten << std::endl;
    std::cout << std::endl;

    // Pointers and multi_dimensional arrays
    std::cout << "Pointers and multi_dimensional arrays" << std::endl;
    std::cout << std::endl;
    int arr_2d[2][3] = {
        {10, 24, 63},
        {44, 75, 66}};

    // Assigning the inner arrays to pointers.
    std::cout << "Assigning the inner arrays to pointers." << std::endl;
    int *arr_2d_ptr = arr_2d[0];
    std::cout << arr_2d_ptr << std::endl;
    int *arr_2d_ptr_1 = arr_2d[1];
    std::cout << arr_2d_ptr_1 << std::endl;

    std::cout << *(arr_2d_ptr + 1) << std::endl;     // prints second element of the first inner array
    std::cout << *(arr_2d_ptr + 1) + 3 << std::endl; // pointer arithmetic, adds 3 to the elemnt at index 1
    std::cout << *(arr_2d_ptr + 1) << std::endl;     // element was printed as 27 above, but remains unchanged in the array
    std::cout << std::endl;

    // Assigning the multi-dimensional array to a pointer
    std::cout << "Assigning the multi-dimensional array to a pointer" << std::endl;
    int(*ptr_2d)[3] = arr_2d;
    std::cout << *(ptr_2d) << std::endl;        // prints memory address of the first inner array
    std::cout << ptr_2d << std::endl;           // prints memory address of the first inner array
    std::cout << ptr_2d[0] << std::endl;        // prints memory address of the first inner array
    std::cout << ptr_2d[0][0] << std::endl;     // prints the first element of the first inner array
    std::cout << *(ptr_2d + 1) << std::endl;    // prints memory address of the second inner array
    std::cout << *(*ptr_2d + 1) << std::endl;   // prints second element of the first inner array
    std::cout << *(ptr_2d[1] + 2) << std::endl; // prints third element of the second inner array
    std::cout << std::endl;

    // Note: Address of an array is the address of the first element inside the array

    // performing the same operations using the parent array itself.
    std::cout << "performing the same operations using the parent array itself." << std::endl;
    std::cout << *(arr_2d) << std::endl;            // prints memory address of the first inner array
    std::cout << arr_2d << std::endl;               // prints memory address of the first inner array
    std::cout << arr_2d[0] << std::endl;            // prints memory address of the first inner array
    std::cout << arr_2d[0][0] << std::endl;         // prints the first element of the first inner array
    std::cout << *(arr_2d + 1) << std::endl;        // prints memory address of the second inner array
    std::cout << *(*arr_2d + 1) << std::endl;       // prints second element of the first inner array
    std::cout << *(arr_2d[0] + 1) + 6 << std::endl; // prints second element of the first inner array + 6 = 30
    std::cout << std::endl;

    // All the syntax above is valid for 3 or more dimensional array

    print(arr, n);
    std::cout << std::endl;

    // dynamic memory allocation
    std::cout << "Dynamic memory allocation" << std::endl;
    int size;
    std::cout << "Enter the size of the array ";
    std::cin >> size;
    int *score = new int[size]; // Only *score is the valid sytnax in this case, score[] won't work.

    std::cout << "Enter the elements \n";
    int element;
    for (int i = 0; i < size; i++)
    {
        std::cin >> element;
        score[i] = element;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << score[i] << " ";
    }
    std::cout << std::endl;
    /*  for (int i = 0; i < size; i++)
     {
         score[i] = i * 2;
         std::cout << score[i] << " ";
     } */

    delete score;
    std::cout << std::endl;
    /* score[2] = 67;
    for (int i = 0; i < size; i++)
    {
        std::cout << score[i] << " ";
    } */
    // C-style dynamic memory allocation
    // int *score = (int *)malloc(size * sizeof(int));
    // int *score = (int *)calloc(size, sizeof(int));

    // Bet driver code to demonstrate memory leak
    int stake;
    std::cout << "Welcome to sportybet" << std::endl;
    balance();
    while (deposit > 0)
    {
        std::cout << "How much do you want to stake? $";
        std::cin >> stake;
        if (stake == 0 || stake > deposit)
        {
            std::cout << "Insufficient fund!" << std::endl;
            break;
        }
        else
        {
            play(stake);
        }
    }

    return 0;
}
