// array-это массив, в котором мы проводим поиски.
// target - это искомое значение.
// min -это индекс минимальной границы массива, в котором мы осуществляем поиск.
// max -это индекс максимальной границы массива,в котором мы осуществляем поиск.
// Функция binarySearch() должна возвращать индекс искомого значения, если он обнаружен. В противном случае, возвращаем -1

#include <iostream>
#include <cassert>

int binarySearch(int *ar, int x, int min, int max){
	assert ((x>0 && min>=0 && max>0 && (ar) && ar[min]<=x && ar[max]>=x) && " Incorrect arguments");
	//assert ((x>0) && " Incorrect arguments");
    int mid;
	while(1)
	{
        if(ar[min] == x)
            return min;
        if(ar[max] == x)
            return max;
		if( (max-min<=1))
			return -1;

		mid=min+(max-min)/2;
		if(x == ar[mid])
				return mid;
        else
                (x < ar[mid]) ? max=mid : min=mid;
	}
}

int binarySearchR(int *ar, int x, int min, int max){
    assert ((x>0 && min>=0 && max>0 && (ar) && ar[min]<=x && ar[max]>=x) && " Incorrect arguments");
    int mid;

       	if(ar[min] == x)
       		return min;
       	if(ar[max] == x)
       		return max;
	if( (max-min<=1))
       		return -1;

	mid=min+(max-min)/2;

	if(x == ar[mid])
		return mid;
        else
	{
       	        (x < ar[mid]) ? max=mid : min=mid;
		return binarySearch(ar,x,min,max);
	}

}





 int main()
 {
 //int array[] = {1,4,8};
 int array[] = { 4, 7, 9, 13, 15,19, 22, 24, 28, 33, 37,41, 43,47, 50};
 std::cout<<"Enter a number: ";

 int x;
 std::cin >> x;

 int index = binarySearchR(array, x, 0, 14);

 if (index >= 0)
 	std::cout << "Good! Your value " << x << " is on position "<< index<<" in array!\n";
 else
 	std::cout << "Fail! Your value " << x << " isn't in array!\n";
 return 0;
 }
