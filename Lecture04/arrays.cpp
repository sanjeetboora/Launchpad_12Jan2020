#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// dataType array_name[array_size];

	//int arr[10]; // declaration
	//int arr[10] = {0}; //initialize
	int arr[10] = {1,2};
	//arr[3] = 5;
	//arr[6] = 89;

	for (int i = 0; i < 10; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;




	return 0;
}