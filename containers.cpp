#include "Container_t.h"
#include "Array_t.h"
#include "Dlist.h"
#include <iostream>

using namespace std;

int main()
{
	Dlist_t<int> arr;
	int myArr[5] = {10, 20, 30, 40, 50};
	
	for(int i = 0; i < 5; ++i)
	{
		arr.Insert(myArr[i]);
	}

	arr.Find(30);

	cout << arr.Index(50) << endl;
	
	return 0;
}

