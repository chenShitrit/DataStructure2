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
void inOrderPrintRec(TreeNode* t, int k);
int PrintBySort(Person* arr, int n, int k); 
void swap(Person* a, Person* b);
int quickSort(Person* arr, int low, int high);
int partition(Person arr[], int low, int high, int* counter);

void main()
{
	int id, coupleNum;
	char* firstName = new char[MAX_SIZE];
	char* lastName = new char[MAX_SIZE];
	cin >> coupleNum;
	Person* arr = new Person[coupleNum];
	for (int i = 0; i < coupleNum; i++)
	{
		cin >> id >> firstName >> lastName; //need to check space
		arr[i] = Person(id, firstName, lastName);
	}
	int k;
	cin >> k;
	int counter = naivePrint(arr, coupleNum, k);
	cout << endl << "NaivePrint: " << counter << " compraison" << endl;
	counter = BSTPrint(arr, coupleNum, k);
	cout << endl << "BST Print: " << counter << " compraison" << endl;
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
	inOrderPrintRec(tree.getRoot(), k);
	return counter;
}


void inOrderPrintRec(TreeNode* t, int k)
{
	if (t == nullptr)
		return;
	inOrderPrintRec(t->getLeft(), k);
	if (t->getData().getId() < k)
	{
		cout << t->getData() << endl;
		inOrderPrintRec(t->getRight(), k);
	}
}

int PrintBySort(Person* arr, int n, int k)
{
	int counter = 0;
	counter += quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i].getId() < k)
		{
			cout << arr[i].getId() << endl;
		}
		counter++;
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
		if (arr[j].getId() <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		(*counter)++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int quickSort(Person* arr, int low, int high)
{
	int counter = 0;
	if (low < high)
	{
		int pi = partition(arr, low, high, &counter);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
		counter++;
	}
	return counter;
}