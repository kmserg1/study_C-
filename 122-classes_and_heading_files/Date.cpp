#include "Date.h"

Date::Date(int d, int m, int y){
	setDate(d,m,y);
}

void Date::setDate(int d, int m, int y){
	m_day=d;
	m_month=m;
	m_year=y;
}
