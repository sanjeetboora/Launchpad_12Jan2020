#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{

	unordered_map<string, int> mp;

	pair<string, int> p = make_pair("abc", 10);

	mp.insert(p);

	mp.insert( make_pair("jkl", 20));

	mp["xyz"] = 70;


	for (auto i : mp) {
		cout << i.first << ", " << i.second << endl;
	}

	//mp.begin(), mp.end()

	if (mp.find("xyz") != mp.end()) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}

	cout << mp.count("jkl") << endl;
	cout << mp.count("jko") << endl;



	// int arr[10] = {1, 2, 3, 4, 5};

	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout << arr[i] << ", ";
	// }
	// cout << endl;

	// //for each loop

	// for (int i : arr)
	// {
	// 	cout << i << ", ";
	// }
	// cout << endl;

	// for (auto i : arr)
	// {
	// 	cout << i << ", ";
	// }
	// cout << endl;









	return 0;
}