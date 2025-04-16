#include <iostream>     

int main(){
std::cout << "Введите 1-е число (double): ";
double a;
std::cin >> a;
std::cout << "Введите 2-е число (double): ";
double b;
std::cin >> b;
std::cout << "Введите операцию (один из символов  +, -, *, или / ) : ";
char op='a';
std::cin >> op;
double res;
if(op=='+') res= a+b;
    else 
    if(op=='-') res= a-b;
        else 
        if(op=='*') res= a*b;
            else
                if(op=='/') res= a/b;
                    else return 1;
std::cout << res << std::endl;
return 0;
}