#include <iostream>

template<class T>
class Auto_ptr1
{
    T* m_ptr;
public:
// Получаем указатель для "владения" через конструктор
Auto_ptr1(T* ptr=nullptr)
    :m_ptr(ptr)
    {
    }

// Деструктор удаляет указатель
~Auto_ptr1()
{
    delete m_ptr;
}

// Перегружаем операторы разыменования и ->, чтобы иметь возможность использовать Auto_ptr1 как m_ptr
	T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }

};

// Класс для проверки. Ничего не делает. Только выводит на экран сообщения при создании экземпляра и при удалении экземпляра
class Item
{
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};

void passByValue(Auto_ptr1<Item> item)
{
}
 
int main()
{
	Auto_ptr1<Item> item1(new Item);
	passByValue(item1);
 
	return 0;
}