#include <iostream>
#include <string>
#include <vector>

class Worker
{
private:
	std::string m_name;

public:
 	Worker(std::string name)
 		: m_name(name)
 	{
//		std::cout << m_name << '\n';
 	}

 	std::string getName() { return m_name; }
 };

class Department
{
private:
	std::vector<Worker*>m_list;
public:
	Department()
	{
	}

	void add_worker(Worker *w)
	{
		m_list.push_back(w);
	}
	void list_workers()
	{
		std::cout << "In this depasrtment is " << m_list.size() << " workers:\n";
		for(int i=0;i<m_list.size();++i)
		{
			std::cout << m_list[i]->getName() << '\n';
		}
	}
};

 int main()
 {
        Worker *anton = new Worker("Anton");
        Worker *boris = new Worker("Boris");
        Worker *steve = new Worker("Steve");

	Department count;
	count.add_worker(anton);
	count.add_worker(boris);
	count.add_worker(steve);
	count.list_workers();	
 	return 0;
 }
