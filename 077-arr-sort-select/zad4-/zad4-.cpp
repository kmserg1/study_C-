#include <iostream> 
#include <algorithm> 
#define ARPRINT(ARR,N) for(int i=0;i<N;++i) std::cout << ARR[i] << " "; std::cout << "\n"

int main(){
    int const n = 9;
	int arr[n]{1, 2, 3, 4, 5, 6, 7, 9, 8};
    std::cout << "Initial array: \n";
    ARPRINT(arr,n);
    int i;
    for(i=0;i<n-i;++i){
        bool swapped = false;
        for(int j=0;j<n-1;++j){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    std::cout << "Stopped after iteration "  << i+1 << "\n";
    std::cout << "Final array: \n";
    ARPRINT(arr,n);
    

    return 0;   
}
