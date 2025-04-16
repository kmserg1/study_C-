#include <iostream> 

int calculate(int x, int y, char op)
{
switch (op)
    {
	case '+':
		return x+y;
	case '-':	
	        return x-y;
	case '*':	
	        return x*y;
	case '/':	
	        return x/y;
   	case '%':	
	        return x%y;
	default:
		std::cout << "error!" << '\n';
		return -1;
    }
}

int main()
{
std::cout << calculate(3,5,'*') << '\n';
}
