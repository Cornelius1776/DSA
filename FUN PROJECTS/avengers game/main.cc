#include <iostream>

main()
{
    const int iron_man = 300,
              doctor_strange = 400,
              thor = 500,
              captain_america = 295;

    int attack_pair;

    int thanos = 2000;

    int pair_1 = 1,
        pair_2 = 2,
        pair_3 = 3,
        pair_4 = 4;

    int attack_count;
    std::string motivation = "Avenger assemble!";
    std::string win = "Our superheroes won";
    std::string lose = "Earth is defeated";

    while (true)
    {

        if (attack_count <= 3 && thanos <= 0)
        {
            std::cout << win << std::endl;
            break;
        }
        else if (attack_count >= 3 && thanos > 0)
        {
            std::cout << lose << std::endl;
            break;
        }

        std::cout << motivation << std::endl;
        std::cout << "Attack with: ";
        std::cin >> attack_pair;

        if (attack_pair == pair_1)
        {
            std::cout << "Iron Man and Doctor Strange on the attack..." << std::endl;
            thanos = thanos - (iron_man + doctor_strange);
            // std::cout << thanos << std::endl;
            // attack_count++;
        }
        else if (attack_pair == pair_2)
        {
            std::cout << "Captain America and Thor on the attack..." << std::endl;
            thanos = thanos - (captain_america + thor);
            // std::cout << thanos << std::endl;
            // attack_count++;
        }
        else if (attack_pair == pair_3)
        {
            std::cout << "Thor and Iron Man on the attack..." << std::endl;
            thanos = thanos - (thor + iron_man);
            // std::cout << thanos << std::endl;
            // attack_count++;
        }
        else if (attack_pair == pair_4)
        {
            std::cout << "Doctor Strange and Captain America on the attack..." << std::endl;
            thanos = thanos - (doctor_strange + captain_america);
            // std::cout << thanos << std::endl;
            // attack_count++;
        }

        if (thanos >= 0)
            std::cout << thanos << std::endl;
        else
            std::cout << std::endl;

        attack_count++;
    }

    return 0;
}