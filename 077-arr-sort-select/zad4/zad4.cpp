#include <iostream>
#include <algorithm>

bool oneiteration(int a[],int length,int cur_it){
    bool is_inacivity{true};
    for(int i=0;i<length-1-cur_it;++i) 
        if (a[i]>a[i+1]){
            std::swap(a[i],a[i+1]);
            is_inacivity = false;
    }       
    for(int i=0;i<length;++i)
                std::cout << a[i] << " ";        
    std::cout << "\n";
    return is_inacivity;
}

int main(){
	const int length(9);
	int array[length] = { 1, 7, 3, 4, 5, 6, 1, 9, 8 };
    std::cout << "start array: ";
	for(int i=0;i<length;++i)
		std::cout << array[i] << " ";
    std::cout << "\n\n";
    int i, j;
    j=0;
    bool question;
    for(i=0;i<length;++i)
        if (question=oneiteration(array,length,i)){
            std::cout << question << "\n";
            if(question)
                ++j;
        break;
        }
    std::cout << "array is sorted; " << i+1-j <<" iterations done\n";
	
    std::cout << "final array: ";
	for(int i=0;i<length;++i)
		std::cout << array[i] << " ";

	std::cout << "\n";
	return 0;
}
