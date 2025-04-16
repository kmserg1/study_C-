#include <iostream>
#include <algorithm>

int main(){
	const int length(9);
	int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	for(int i=0;i<length;++i){
		for(int j=i;j<length;++j)
			if(array[i]>array[j]) std::swap(array[i],array[j]);
	}
	for(int i=0;i<length;++i)
		std::cout << array[i] << " ";

	std::cout << "\n";
	return 0;
}
