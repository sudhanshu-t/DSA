#include <bits/stdc++.h>
using namespace std;

int convert(string time){
	string h = time.substr(0, 2);
	string m = time.substr(3, 2);

	int hr = stoi(h);
	int min = stoi(m);

	int t = hr*60 + min;
	return t;
}

vector<vector<string>> meetingTime(vector<vector<string>>& cal1, vector<string>& bound1, vector<vector<string>>& cal2, vector<string>& bound2, int time){
	vector<vector<string>> res;
	stack<pair<int, int>> st;
	vector<pair<int, int>> meetings;

	for(int i = 0; i < cal1.size(); i++){
		int st = convert(cal1[i][0]);
		int end = convert(cal1[i][1]);
        meetings.push_back(make_pair(st, end));
    }
    for(int i = 0; i < cal2.size(); i++){
		int st = convert(cal2[i][0]);
        int end = convert(cal2[i][1]);
        meetings.push_back(make_pair(st, end));
    }
    meetings.push_back(make_pair(INT_MIN, convert(bound1[0])));
    meetings.push_back(make_pair(convert(bound1[1]), INT_MAX));
    meetings.push_back(make_pair(INT_MIN, convert(bound2[0])));
    meetings.push_back(make_pair(convert(bound2[1]), INT_MAX));
    cout << meetings.size() << endl;

    sort(meetings.begin(), meetings.end());
    for(int i = 0; i < meetings.size(); i++){
        cout << meetings[i].first << " -> " << meetings[i].second << endl;
    }

    st.push(meetings[0]);
    for(int i = 1; i < meetings.size(); i++){
        pair<int, int> m1 = st.top();
        // cout << m1.first << " " << m1.second << endl;
        if(meetings[i].first <= m1.second){
            st.pop();
            st.push(make_pair(m1.first, max(m1.second, meetings[i].second)));

            cout << "Merged interval " << st.top().first << " " << st.top().second << endl;
        } else {
            st.push(meetings[i]);
        }
    }

    meetings.resize(0);
    while(!st.empty()){
        meetings.push_back(st.top());
        st.pop();
    }

    cout << meetings.size() << endl;
    sort(meetings.begin(), meetings.end());

    for(int i = 0; i < meetings.size(); i++){
        cout << meetings[i].first << " -> " << meetings[i].second << endl;
    }

    for(int i = 0; i < meetings.size()-1; i++){
        int st = meetings[i].second;
        int en = meetings[i+1].first;

        cout << st << " - " << en << endl;
        if(en - st >= time){
            string start, end;
            start = to_string(st/60) + ":" + to_string(st%60);
            end = to_string(en/60) + ":" + to_string(en%60);

            if(st%60 == 0){
                start += '0';
            }
            if(en%60 == 0){
                end += '0';
            }
            vector<string> temp (2);
            temp[0] = start;
            temp[1] = end;

            res.push_back(temp);
        }
    }

    return res;
}

int main(){
	vector<vector<string>> cal1 = {{"09:00", "10:30"},{"12:00", "13:00"},{"16:00", "17:30"}};
	vector<vector<string>> cal2 = {{"10:00", "11:30"},{"12:30", "14:30"},{"14:30", "15:00"},{"16:00", "17:00"}};

	vector<string> bound1 = {"09:00", "20:00"};
	vector<string> bound2 = {"10:00", "18:30"};

	vector<vector<string>> res = meetingTime(cal1, bound1, cal2, bound2, 300);

    cout << res.size() << endl;

	for(int i = 0; i < res.size(); i++){
        cout << res[i][0] << " - " << res[i][1] << endl;
    }

    return 0;
}
