#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, k;
	string str;

	cin>>n>>k>>str;
	int maxLength = 0, left =0, right = 0;

	int arr[2] ={0};
	while(right < str.length()){

		arr[str[right] - 'a']++;
		if(min(arr[0], arr[1]) <= k){
			maxLength++;
		}
		else{
			arr[ str[left] - 'a']--;
			left++;
		}
		right++;
	}

	cout<<maxLength<<endl;
	return 0;
}

//HW -> max in k size window for an array











