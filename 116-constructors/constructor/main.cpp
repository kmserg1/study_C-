#include <iostream>
#include <string>

enum Colors{Red,Orange,Yellow,Green,Blue,Fiolet,Black,White};


class Ball{
	Colors m_color;
	double m_radius;
public:
	Ball(Colors col=Red, double rad=20.0) {
		m_color=col;
		m_radius=rad;
	}
	Ball(double rad) {
		m_color=Red;
		m_radius=rad;
	}

	void print(){
        std::string name;
        switch (m_color){
            case Red:
                name="Red";
                break;
            case Orange:
                name="Orange";
                break;
            case Yellow:
                name="Yellow";
                break;
            case Green:
                name="Green";
                break;
            case Blue:
                name="Blue";
                break;
            case Fiolet:
                name="Fiolet";
                break;
            case Black:
                name="Black";
                break;
            case White:
                name="White";
                break;
            default:
                name="ERROR!!!";
                break;
        }
		std::cout << "color: " << name << ", radius: " <<  m_radius << "\n";
	}
};

int main()
{
Ball def;
def.print();

Ball black(Black);
black.print();

Ball thirty(30.0);
 thirty.print();

 Ball blackThirty(Black, 30.0);
 blackThirty.print();

 return 0;
 }
