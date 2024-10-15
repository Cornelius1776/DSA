#include <iostream>
#ifndef BET_H
#define BET_h
int deposit;
void balance()
{
    std::cout << "How much would you like to deposit? $";
    std::cin >> deposit;
    std::cout << "You have succesfully deposited $" << deposit << std::endl;
}

void play(int stake)
{
    char cards[] = {'A', 'B', 'C'};
    // memory leak demonstrated with pointer char below
    /*   char *cards = new char[3];
      cards[0] = 'A';
      cards[1] = 'B';
      cards[2] = 'C'; */
    std::cout << "shuffling cards..." << std::endl;
    srand(time(nullptr));

    int i, count = 5;
    for (i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = cards[x];
        cards[x] = cards[y];
        cards[y] = temp;
    }

    int guess;
    std::cout << "What is the position of A: " << std::endl;
    std::cin >> guess;
    if (cards[guess - 1] == 'A')
    {
        int winning = 5 * stake;
        deposit += winning;
        std::cout << "Congratulations! You win $" << winning << std::endl;
        std::cout << "You now have $" << deposit << " in your sporty bet account." << std::endl;
    }
    else
    {
        deposit -= stake;
        std::cout << "You lose $" << stake << " stake." << std::endl;
        std::cout << "you have $" << deposit << " left." << std::endl;
    }
    // delete cards;
    std::cout << std::endl;
}

#endif // !BET_H
