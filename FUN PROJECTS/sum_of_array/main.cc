#include <iostream>

void sum_array(float *arr, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; 
    }
    std::cout << "The sum of the array is " << sum << std::endl;
}

int main()
{
    float price[] = {12.3, 23.4, 56, 87.1};
    int n = sizeof(price) / sizeof(price[0]);
    sum_array(price, n);
    int rate[] = {24, 25, 30, 26};
    std::cout << sum(rate, n) << std::endl;

    return 0;
}