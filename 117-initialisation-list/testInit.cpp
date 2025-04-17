#include <iostream>

class Values{                    
private:             
	const int m_value {7};   
                     
public:              
	Values() 
	{                    
	}
	int get_m_value(){
		return m_value;
	}
};

int main(){
	Values val;
	std::cout << val.get_m_value() << '\n';
	return 0;
}
