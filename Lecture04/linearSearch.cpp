#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[10]  = {1,2,3,4,5,6,7,44,55,66};
	int key = 45;
	bool found = false;
	for (int i = 0; i < 10; ++i)
	{
		if(arr[i] == key){
			cout<<key <<" found"<<endl;
			found = true;
			break;
		}
	}
	if(found == false){
		cout<<key<<" not found"<<endl;
	}
}










