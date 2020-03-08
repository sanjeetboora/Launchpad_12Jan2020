#include <iostream>
using namespace std;
bool isPossible(int mid, int cows, int* stalls, int n) {
	cows--; //cow placed at 0th index
	int lastCowPlacedAtIndex =0;

	for (int i = 1; i <n ; ++i)
	{
		if(stalls[i] - stalls[lastCowPlacedAtIndex] >= mid){
			cows--;
			lastCowPlacedAtIndex = i;
		}
		if(cows <= 0){
			return true;
		}
	}
	if(cows >0){
		return false;
	}

}


int aggCows(int* stalls, int n, int cows) {
	sort(stalls, stalls + n);
	int minDis = 1, maxDis = stalls[n - 1] - stalls[0];
	int ans = 1;
	while (minDis <= maxDis) {
		int mid = minDis + (maxDis - minDis) / 2;
		if (isPossible(mid, cows, stalls, n)) {
			ans = mid;
			minDis = mid + 1;
		}
		else {
			maxDis = mid - 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int test;
	cin >> test;

	while (test--) {
		int n,  cows;
		cin >> n >> cows;
		int* stalls = new int [n];
		for (int i = 0; i < n; ++i)
		{
			cin >> stalls[i];
		}
		cout << aggCows( stalls, n, cows) << endl;
	}

	return 0;
}



//H.w

//book allocation
// painters problem
// CB scholarship
//https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650