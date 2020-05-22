#pragma warning (disable: 4996)
#include <iostream>
#include "Person.h"
#include "AccessList.h"
#include "ListNode.h"
#include <string.h>

using namespace std;
#define MAX_SIZE 128
int naivePrint(Person* arr, int n, int k);

void main()
{
	int id, coupleNum;
	char* firstName = new char[MAX_SIZE];
	char *lastName = new char[MAX_SIZE];

	cin >> coupleNum;
	Person* arr = new Person[coupleNum];
	for (int i = 0; i < coupleNum; i++)
	{
		cin >> id >> firstName >> lastName; //need to check space
		arr[i].setId(id);
		arr[i].setFirstName(firstName);
		arr[i].setLastName(firstName);
	}
	int k;
	cin >> k;
	int counter = naivePrint(arr, coupleNum, k);
	cout << endl << "NaivePrint: " << counter << " compraison" << endl;
	system("pause");
}

int naivePrint(Person* arr, int n, int k)
{
	AccessList accessList;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		counter++;
		if (arr[i].getId() < k)
			accessList.addSortedNode(arr[i], &counter);
	}
	accessList.printAccessList();
	return counter;

}