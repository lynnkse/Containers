#include "Container_t.h"
#include "Array_t.h"
#include "Dlist.h"
#include <iostream>

#define APPEND 1 
#define	PREPEND 2
#define	CONTAINS 3
#define FIND 4
#define	INDEX 5	
#define	INSERT 6
#define	REMOVE 7
#define	REMOVE_ALL 8
#define	REMOVE_AND_DELETE 9 
#define	REMOVE_AND_DELETE_ALL 10	 
#define	EXIT 11

using namespace std;

void Run();
void ContRun();
void RunList();
void AppendTest();
void PrependTest();
void ContainsTest();
void FindTest();
void IndexTest();
void InsertTest();
void RemoveTest();
void RemoveAllTest();
void RemoveAndDeleteTest();
void RemoveAndDeleteAllTest();

Container_t<int>* g_array;

int main()
{
	Run();
	
	return 0;
}

void Run()
{
	int choice;
	while(choice != 3)
	{
		cout << "1. Test list 2. Test array 3. Exit" << endl;
		cin >> choice;		
		switch(choice)
		{
			case 1:
				g_array = new Dlist_t<int>();
				ContRun();
				delete g_array;
				break;
			case 2:
				g_array = new Array_t<int>();
				ContRun();
				delete g_array;
				break;
			case 3:
				cout << "Invalid input" << endl;
				break;
		}
	}	
}

void ContRun()
{
	int choice = 1;
	while(choice != EXIT)
	{	
		cout << "1. Append" << endl 
			 << "2. Prepend" << endl
			 << "3. Contains" << endl
			 << "4. Find" << endl
			 << "5. Index" << endl
			 << "6. Insert" << endl 
			 << "7. Remove" << endl
			 << "8. RemoveAll" << endl
			 << "9. RemoveAndDelete" << endl
			 << "10. RemoveAndDeleteAll" << endl
			 << "11. Exit" << endl << endl;
	
		cin >> choice;

		switch(choice)
		{
			case APPEND:
				AppendTest();
				break;
			case PREPEND:
				PrependTest();
				break;
			case CONTAINS:
				ContainsTest();
				break;
			case FIND:
				FindTest();
				break;
			case INDEX:
				IndexTest();
				break;
			case INSERT:
				InsertTest();
				break;
			case REMOVE:
				RemoveTest();
				break;
			case REMOVE_ALL:
				RemoveAllTest();
				break;
			case REMOVE_AND_DELETE:
				RemoveAndDeleteTest();
				break;
			case REMOVE_AND_DELETE_ALL:
				RemoveAndDeleteAllTest();
				break;
			case EXIT:
				break;
			default:
				cout << "Invalid input" << endl;
				break;

		}
	}
}

void AppendTest()
{
	int* num = new int();
	size_t index;
	cout << "Enter integer" << endl;
	cin >> *num;
	cout << "Enter index" << endl;
	cin >> index;
	if(g_array->Append(num, index))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
}

void PrependTest()
{
	int* num = new int();
	size_t index;
	cout << "Enter integer" << endl;
	cin >> *num;
	cout << "Enter index" << endl;
	cin >> index;
	if(g_array->Prepend(num, index))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
}

void ContainsTest()
{
	cout << "Enter integer" << endl;
	int num;
	cin >> num;
	if(g_array->Contains(num))
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

void FindTest()
{
	cout << "Enter integer" << endl;
	int num;
	cin >> num;
	if(*(g_array->Find(num)) == num)
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

void IndexTest()
{
	cout << "Enter integer" << endl;
	int num;
	cin >> num;
	if(g_array->Index(num) != -1)
	{
		cout << "Index: " << g_array->Index(num) << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

void InsertTest()
{
	int* num = new int();
	cout << "Enter integer" << endl;
	cin >> *num;
	g_array->Insert(num);	
	cout << "Success" << endl;
}

void RemoveTest()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	if(g_array->Remove(num))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}	
}

void RemoveAllTest()
{
	g_array->RemoveAll();
	cout << "Done" << endl;
}

void RemoveAndDeleteTest()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	if(g_array->RemoveAndDelete(num))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}	
}

void RemoveAndDeleteAllTest()
{
	g_array->RemoveAndDeleteAll();
	cout << "Done" << endl;
}








































