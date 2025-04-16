#include <iostream>

struct Student {
std::string name;
int score;
};

void sortStudents(Student *array, int length){
	for (int startIndex = 0; startIndex < length; ++startIndex){
		int smallestIndex = startIndex;	
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex){
			if (array[currentIndex].score > array[smallestIndex].score)			
				smallestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main(){
	int numStudents;
	std::cout << "Enter numer of students: ";
	std::cin >> numStudents;

	Student *student = new Student[numStudents];

	for(int i=0; i< numStudents; ++i){
		std::cout << "Enter the name of student " << i+1 << ": ";
		std::cin >> student[i].name;
		std::cout << "Enter the score of student " << i+1 << ": ";;
		std::cin >> student[i].score;
        std::cout << "\n";;
		}

	sortStudents(student,numStudents);

	for(int i=0; i< numStudents; ++i)
		std::cout << student[i].name <<" got a grade of " << student[i].score << "\n";

	delete[] student;
	student=nullptr;
	return 0;
}

