#include <iostream>

int deposit;
void balance()
{
    std::cout << "How much would you like to deposit? $";
    std::cin >> deposit;
    std::cout << "You have succesfully deposited $" << deposit << std::endl;
    std::cout << std::endl;
}

void play(int stake)
{
    char cards[] = {'A', 'B', 'C'};
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
        std::cout << "What is cashout?" << std::endl;
        std::cout << "you have $" << deposit << " left." << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl;
    int stake;
    std::cout << "Welcome to sportybet" << std::endl;
    balance();
    while (deposit > 0)
    {
        std::cout << "How much do you want to stake?   $";
        std::cin >> stake;
        int winning = stake * 5;
        std::cout << "Your potential cashout is $" << winning << std::endl;
        if (stake == 0 || stake > deposit)
        {
            std::cout << "Insufficient fund!" << std::endl;
            break;
        }
        else
        {
            play(stake);
        }

        std::string answer;
        std::cout << "Would you like to bet again? ";
        std::cin >> answer;
        std::cout << std::endl;

        if (answer == "no" || answer != "yes")
        {
            break;
        }
        continue;
    }

    return 0;
}
