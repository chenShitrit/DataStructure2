#include <iostream>
#include "Person.h"
#include "string.h"
using namespace std;
#pragma warning (disable: 4996)

Person::Person()
{
	m_id = 0;
	m_firstName = nullptr;
	m_lastName = nullptr;
}

Person::Person(int id, char* name, char* lastName)
{
	m_id = id;
	setFirstName(name);
	setLastName(lastName);
}

Person::Person(const Person& p)
{
	m_id = p.getId();
	setFirstName(p.getFirstName());
	setLastName(p.getLastName());
}

Person::Person(Person&& p)
{
	m_id = p.getId();
	m_firstName = p.m_firstName;
	p.m_firstName = nullptr;
	m_lastName = p.m_lastName;
	p.m_lastName = nullptr;
}

int Person::getId()const
{
	return m_id;
}

char* Person::getFirstName()const
{
	return m_firstName;
}

char* Person::getLastName()const
{
	return m_lastName;
}

void Person::setId(int id)
{
	m_id = id;
}

void Person::setFirstName(char* firstName)
{
	m_firstName = strdup(firstName);
}

void Person::setLastName(char* lastName) 
{
	m_lastName = strdup(lastName);
}


Person::~Person()
{
	delete[] m_firstName;
	delete[] m_lastName;
}

void Person::operator=(const Person& p)
{
	m_id = p.m_id;
	delete m_firstName;
	m_firstName = strdup(p.m_firstName);
	delete m_lastName;
	m_lastName = strdup(p.m_lastName);
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << p.getId() << " " << p.getFirstName() << " " << p.getLastName();
	return os;
}
