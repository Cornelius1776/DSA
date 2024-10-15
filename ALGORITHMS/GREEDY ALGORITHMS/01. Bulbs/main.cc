#include <iostream>
/* Given N bulbs, the ones that are on(1), off(0). Turning on the bulb at the ith position will cause all
the bulb on it's right side to flip(1 becomes 0 and vice versa). find the minimum number of switches to
turn all of them on.
constraints:  1 <= N <= 10^5
Time complexity = 0(n * n) space complexty = 0(1) */

int bulbs(int arr[], int n)
{
    int count = 0; // To keep track of the number of switches so far

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == 1)
                    arr[j] = 0;
                else
                    arr[j] = 1;
            }
            count++;
        }
    }
    return count;
}

int main()
{

    int states[] = {0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1};
    int n = sizeof(states) / sizeof(states[0]);
    std::cout << "The minimum number of switches needed are " << bulbs(states, n) << std::endl;

    return 0;
}