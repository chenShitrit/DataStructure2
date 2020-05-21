#include "Person.h"
#include "string.h"

Person::Person()
{
}

int Person::getId()
{
	return m_id;
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
