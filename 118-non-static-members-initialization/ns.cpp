#include <iostream>
 
class Something
{
private:
    double m_length = 3.5;
    double m_width = 3.5;
 
public:
 
    Something(){}
    Something(double length = 3.5, double width = 3.5)
        : m_length(length), m_width(width)
    {
 
    }
 
    void print()
    {
        std::cout << "length: " << m_length << " and width: " << m_width << '\n';
    }
 
};
 
int main()
{
    Something a;
    a.print();
 
    return 0;
}
