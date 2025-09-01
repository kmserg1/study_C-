 class Parent
 {
 public:
 	const char* sayHi() { return "Hi"; } // обычная невиртуальная функция

 	virtual const char* getName() { return "Parent"; } // обычная виртуальная функция

 	virtual int getValue() = 0; // чистая виртуальная функция

 	int doSomething() = 0; // ошибка компиляции: нельзя присвоить невиртуальным функциям значение 0
 };


 int main()
 {
 	Parent parent; // мы не можем создавать объекты абстрактного класса, но, ради эксперимента, представьте, что это возможно
 	parent.getValue(); // какой результат выполнения этой строки кода?
 }
