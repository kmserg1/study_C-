#include <iostream>
 
int main()
{
    int outer = 5;
    while (outer >= 1)
    {
        int inner = 5;
        while (inner >= 1){
            if(6-outer<inner)
                std::cout << ' ' << ' ';
            else
                std::cout << inner << ' ';
            --inner;
            }
        // Вставляем символ новой строки в конце каждого ряда
        std::cout << "\n";
        --outer;
        }
 
    return 0;
}