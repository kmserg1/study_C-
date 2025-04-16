#include <iostream>

enum things_types {
    ZILLYA,
    TORCH,
    ARROW
};


int countTotalItems(int *ar, int num){
int count=0;
for(int i=0; i<num; ++i)
    count+=ar[i];	
return count;
}

int main(){
    things_types thing {TORCH};
    std::cout << "thing: " << thing << "\n";
	int userThings[3]{3,6,12};
	std::cout << "Items quantity: " << countTotalItems(userThings,3) << "\n";
    return 0;
}
