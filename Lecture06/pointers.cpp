#include<bits/stdc++.h>
using namespace std;
void fun1(int arr[10]){
	cout<<arr<<endl;
	for (int i = 0; i < 5; ++i)
	{	cout<<arr[i]<<", ";
	}
	cout<<"inside fun1"<<endl;
}
void fun2(int* arr){
	cout<<arr<<endl;
	for (int i = 0; i < 5; ++i)
	{	cout<<arr[i]<<", ";
	}
	cout<<"inside fun2"<<endl;
}

int main(int argc, char const *argv[])
{	
	// pointers -> * -> address store
	// int n = 10;
	// cout<<"address of n -> " <<&n <<endl;
	// int* pn = &n;
	// cout<<"pn -> " <<pn<<endl;

	// bool b;
	// bool* pb = &b;
	// cout<<"address of b -> " <<&b <<endl;
	// cout<<"pb -> " <<pb<<endl;

	// cout<<"address of pb -> " <<&pb <<endl;
	// bool** addpb = &pb;
	// cout<<"addpb -> " <<addpb<<endl;

	// * -> dereference operator 

	// int n = 10;
	// cout<<"address of n -> " <<&n <<endl;
	// int* pn = &n;
	// cout<<"pn -> " <<pn<<endl;

	// cout<<"*pn -> " <<*pn <<endl;
	// cout<<"*(&n) -> " <<*(&n) <<endl;

	// int** addpn = &pn;
	// cout<<"addpn -> " <<addpn<<endl;
	// cout<<"*addpn -> " <<*addpn<<endl;
	// cout<<"**addpn -> " <<**addpn<<endl;


	// bool b;
	// bool* pb = &b;
	// double n = 10000;
	// double* pn = &n;

	// cout<<"sizeof(pb) -> "<<sizeof(pb)<<endl;
	// cout<<"sizeof(pn) -> "<<sizeof(pn)<<endl;
	// cout<<*pn<<endl;
	// cout<<*((double *)pn)<<endl;
	// cout<<*((int *)pn)<<endl;


	// int arr[10] ={1,2,3,4,5};
	// cout<<arr<<endl;
	// for (int i = 0; i < 5; ++i)
	// {
	// 	cout<<&arr[i]<<endl;
	// 	cout<<(arr + i)<<endl;
	// 	cout<<arr[i]<<endl;
	// 	cout<< *(arr + i)<<endl;
	// }
	// fun1(arr);
	// fun2(arr);


	int a1[5] = {1,3,5}; 
	int num = 100;
	int* adnum = &num;
	int** addnum = &adnum;
	cout<< &num <<endl;
	cout<<adnum<<endl;
	cout<<**addnum<<endl;
	cout<<*adnum<<endl;
	cout<<*addnum<<endl;
	cout<<a1<<endl;
	cout<<*a1<<endl;
	//cout<<**(a1+1)<<endl; // error
	cout<<*(a1+1)<<endl;
	cout<<*(a1+2)<<endl;
// 0x7ffee0303adc
// 0x7ffee0303adc
// 100
// 100
// 0x7ffee0303adc
// 0x7ffee0303af0
// 1
// 3
// 5





	return 0;
}














