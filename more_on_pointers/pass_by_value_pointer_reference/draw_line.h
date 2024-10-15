#include <iostream>
#ifndef DRAW_LINE_H
#define DRAW_LINE_H

void draw_line()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;
}

#endif // DRAW_LINE_H