#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// int arr1[3] = {1, 2, 6};
	// int arr2[2] = {5, 7};
	// int arr3[3] = {8, 10, 11};

	int arr1[4] = {1, 2, 6, 21};
	int arr2[3] = {5, 9, 10};
	int arr3[3] = {7, 8, 12};

	int i = 0, j = 0, k = 0, size1 = 4, size2 = 3, size3 = 3;
	int triplet1 = 0, triplet2 = 0, triplet3 = 0;
	int minDiff = INT_MAX;

	while ( i < size1 && j < size2 && k < size3){
		int minimum = min(arr1[i], min(arr2[j], arr3[k]));
		int maximum = max(arr1[i], max(arr2[j], arr3[k]));
		int diff = maximum - minimum;
		//cout<<diff<<endl;
		if(diff < minDiff){
			minDiff = diff;
			triplet1 = arr1[i];
			triplet2 = arr2[j];
			triplet3 = arr3[k];
		}
		if(minDiff == 0){
			break;
		}

		if(arr1[i] == minimum){
			i++;
		}
		else if(arr2[j] == minimum){
			j++;
		}
		else{
			k++;
		}
	}

	cout<<triplet1<<", "<<triplet2<<", "<<triplet3<<endl;


		return 0;
}

// HW -> generate all triplet and find the closest (n^3)












