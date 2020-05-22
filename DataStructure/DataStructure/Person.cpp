#include "Person.h"
#include "string.h"

Person::Person()
{
	m_firstName = nullptr;
	m_lastName = nullptr;
	m_id = 0;
}

int Person::getId()
{
	return m_id;
}

char* Person::getFirstName()
{
	return m_firstName;
}

char* Person::getLastName()
{
	return m_lastName;
}

void Person::setId(int id)
{
	m_id = id;
}

void Person::setFirstName(char* firstName)
{
	m_firstName = _strdup(firstName);
}

void Person::setLastName(char* lastName)
{
	m_lastName = _strdup(lastName);
}


Person::~Person()
{
}
