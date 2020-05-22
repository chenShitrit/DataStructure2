#ifndef __PERSON
#define __PERSON
class Person

{
public:
	Person();
	~Person();
	int getId();
	void setId(int id);
	void setFirstName(char* firstName);
	void setLastName(char* lastName);
	char* getLastName();
	char* getFirstName();

private:
	int m_id;
	char* m_firstName;
	char* m_lastName;
};

#endif // __PERSON