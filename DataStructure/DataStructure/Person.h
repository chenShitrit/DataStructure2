#ifndef __PERSON
#define __PERSON
#include <iostream>
using namespace std;


class Person
{
public:
	Person();
	Person(int id, char* name, char* lastName);
	Person::Person(const Person& p);
	Person::Person(Person&& p);
	~Person();
	int getId() const;
	void setId(int id);
	void setFirstName(char* firstName);
	void setLastName(char* lastName);
	char* getLastName() const;
	char* getFirstName() const;
	void operator=(const Person& p);
	friend ostream& operator<<(ostream& os, const Person& p);

private:
	int m_id;
	char* m_firstName;
	char* m_lastName;
};

#endif // __PERSON