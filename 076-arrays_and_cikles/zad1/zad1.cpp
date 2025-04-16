#include <iostream>
 
int main()
{
    int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
    const int arrayLength = sizeof(array) / sizeof(array[0]);
 
    for (int index=0; index < arrayLength; ++index)
        std::cout << array[index] << " ";
    return 0;
}