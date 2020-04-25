#include <bits/stdc++.h>
using namespace std;

int minRooms(vector<vector<int> >meetings) {

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minStartTime;
	priority_queue<int, vector<int>, greater<int> > minEndTime; // min heap

	int i = 0;
	//push all meetings in minStartTime heap

	while (i < meetings.size()) {
		minStartTime.push( make_pair(meetings[i][0], meetings[i][1]));
		i++;
	}

	int rooms = 0;

	if ( !minStartTime.empty()) {
		pair<int, int> firstMeeting = minStartTime.top();
		int firstMeetingEndTime = firstMeeting.second;
		minEndTime.push(firstMeetingEndTime);
		minStartTime.pop();
		rooms++;
	}

	while (!minStartTime.empty()) {
		pair<int, int> currMeeting = minStartTime.top();
		minStartTime.pop();

		if(currMeeting.first < minEndTime.top()){
			minEndTime.push(currMeeting.second);
			int heapSize = minEndTime.size();
			rooms = max(rooms, heapSize);
		}
		else{
			while(!minEndTime.empty() and minEndTime.top() <= currMeeting.first ){
				minEndTime.pop();
			}
			minEndTime.push(currMeeting.second);
		}
	}
	return rooms;
}


int main(int argc, char const *argv[])
{
	vector<vector<int> >v = {{0, 40},
		{10, 20},
		{25, 30},
		{15, 25}};

	int rooms = minRooms(v);
	cout << rooms << endl;

	return 0;
}