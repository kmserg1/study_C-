#include <iostream>

class A
{
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
};

 class B : public A
 {
 public:
 	virtual const char* getName1(short int x) override { return "B"; } // ошибка компиляции, метод не является переопределение
 	virtual const char* getName2(int x) const override { return "B"; } // ошибка компиляции, метод не является переопределение
 	virtual const char* getName3(int x) override { return "B"; } // всё хорошо, метод является переопределением A::getName3(in

 };

 int main()
 {
 	return 0;
 }
