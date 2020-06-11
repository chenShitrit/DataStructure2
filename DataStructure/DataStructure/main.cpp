#pragma warning (disable: 4996)
#include <iostream>
#include "Person.h"
#include "AccessList.h"
#include "ListNode.h"
#include <string.h>
#include "BST.h"

using namespace std;
#define MAX_SIZE 128
int naivePrint(Person* arr, int n, int k);
int BSTPrint(Person* arr, int n, int k);
void inOrderPrintRec(TreeNode* t, int k, int* counter);
int PrintBySort(Person* arr, int n, int k); 
void swap(Person* a, Person* b);
void quickSort(Person* arr, int low, int high, int* counter);
int partition(Person arr[], int low, int high, int* counter);
void inputData(int* id, char* firstName, char* lastName)throw(const char*);

void main()
{
	int id, coupleNum;
	char* firstName = new char[MAX_SIZE];
	char* lastName = new char[MAX_SIZE];
	cin >> coupleNum;
	Person* arr = new Person[coupleNum];
	for (int i = 0; i < coupleNum; i++)
	{
		try
		{
			inputData(&id, firstName, lastName);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			exit(1);
		}
		arr[i] = Person(id, firstName, lastName);
	}
	int k;
	cin >> k;
	int counter = naivePrint(arr, coupleNum, k);
	cout << endl << "NaivePrint: " << counter << " compraison" << endl;
	counter = BSTPrint(arr, coupleNum, k);
	cout << endl << "BST Print: " << counter << " compraison" << endl;
	counter = PrintBySort(arr, coupleNum, k);
	cout << endl << "qSortPrint: " << counter << " compraison" << endl;
	delete[] firstName;
	delete[] lastName;
	system("pause");
}

void inputData(int* id, char* firstName, char* lastName)throw(const char*)
{
	char checkSpace;
	if (!(cin >> *id))
		throw "Invalid input!";
	cin >> firstName;
	checkSpace = getchar();
	if (checkSpace != ' ')
	{
		cout << "invalid input";
		exit(1);
	}
	cin >> lastName;
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

int BSTPrint(Person* arr, int n, int k)
{
	BST tree;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		counter += tree.insertNode(arr[i]);
	}
	inOrderPrintRec(tree.getRoot(), k, &counter);
	return counter;
}

void inOrderPrintRec(TreeNode* t, int k, int* counter)
{
	if (t == nullptr)
		return;
	inOrderPrintRec(t->getLeft(), k, counter);
	(*counter)++;
	if (t->getData().getId() < k)
	{
		cout << t->getData() << endl;
		inOrderPrintRec(t->getRight(), k, counter);
	}
}

int PrintBySort(Person* arr, int n, int k)
{
	int counter = 0;
	quickSort(arr, 0, n - 1, &counter);
	for (int i = 0; i < n; i++)
	{
		counter++;
		if (arr[i].getId() < k)
			cout << arr[i].getId() << endl;
		else
			break;
	}
	return counter;
}

void swap(Person* a, Person* b)
{
	Person t = *a;
	*a = *b;
	*b = t;
}

int partition(Person arr[], int low, int high, int* counter)
{
	int pivot = arr[high].getId();
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		(*counter)++;
		if (arr[j].getId() <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(Person* arr, int low, int high, int* counter)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, counter);
		quickSort(arr, low, pi - 1, counter);
		quickSort(arr, pi + 1, high, counter);
	}
}
