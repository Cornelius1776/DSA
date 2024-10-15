#include <iostream>

// Tower of hanoi
// Time Complexity O(2^n) n = number of disk
void tower_of_hanoi(int no_of_disk, char source, char destination, char auxiliary)
{
    if (no_of_disk == 1)
    {
        std::cout << "Move disk from rod " << source << " to rod " << destination << '\n';
        return;
    }
    else
    {
        tower_of_hanoi(no_of_disk - 1, source, auxiliary, destination);
        std::cout << "Move disk " << no_of_disk << " from rod " << source << " to rod " << destination << '\n';
        tower_of_hanoi(no_of_disk - 1, auxiliary, destination, source);
    }
}

// Tower of hanoi using iteraton

int main()
{
    // Recursion
    int disks = 5;                        // Number of disks
    tower_of_hanoi(disks, 'A', 'C', 'B'); // A, C and B are rods.

    // Iteraion
    // std::cout << "\no_of_disk\nTower of Hanoi Iterative Solution:\no_of_disk";
    // tower_of_hanoi_iteration(disks, 'A', 'C', 'B');

    return 0;
}