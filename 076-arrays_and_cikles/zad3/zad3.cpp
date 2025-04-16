#include <iostream>
 
int main()
{
    int scores[] = { 73, 85, 184, 99, 78 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);
 
    int maxScore = 0; // отслеживаем самую высокую оценку
    int maxIndex = 0; // отслеживаем индекс самой высокой оценки
    int student;
    for (student = 0; student < numStudents; ++student){
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
	        maxIndex = student;
        }
    }
    std::cout << "The best score was " << maxScore << '\n';
    std::cout << "The index of best score is " << maxIndex << '\n';
 
    return 0;
}