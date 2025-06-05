#include <iostream> 
#include <string> 
#include <vector> 
#include <cassert>

struct StudentGrade {
	std::string name;
	char grade;
};

class GradeMap{
private:     
	std::vector <StudentGrade> m_map;
public:
	GradeMap(){
	}
	GradeMap(int i){
		m_map.resize(i);
	}

	char& operator[](const std::string &n);

	StudentGrade& operator[](const int i);

};

char& GradeMap::operator[](const std::string &n){

		for(auto &student : m_map)
			if(student.name==n)
				return student.grade;

		m_map.push_back(StudentGrade {n,'C'});
		return m_map.back().grade;
	}

StudentGrade& GradeMap::operator[](const int i){
	assert(i>=0 and i<=m_map.size());
	return m_map.at(i);
}

int main(){
	GradeMap group;

	group["John"]='B';
	group["Ieshua"]='C';
	group["Alex"]='D';
	group["Vu"]='E';
	group["Alberto"]='A';
	group["Fil"]='B';
	group["Ivan"]='C';

	std::string name;
	for(int i=0; i<7; ++i ){
		name=group[i].name;
		std::cout << name << '\t' << group[name] << '\n';
	}
		
	name="XXX";
	std::cout << name << '\t' << group[name] << '\n';
	return 0;
}