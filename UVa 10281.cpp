#include <bits/stdc++.h>
using namespace std;

int timeToSeconds(const string &timeStr) {
    int h, m, s;
    sscanf(timeStr.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

string secondsToTime(int totalSeconds) {
    int h = totalSeconds / 3600;
    totalSeconds %= 3600;
    int m = totalSeconds / 60;
    int s = totalSeconds % 60;
    char buffer[9];
    string st = (h-10) < 0 ? "0"+h : ""+h;
    st += ":";
    st += (m-10) < 0 ? "0"+m : ""+m;
    st += ":";
    st += (s-10) < 0 ? "0"+s : ""+s;
    return st;
}

int main() {
    string line;
    vector<string> results;

    double totalDistance = 0.0;
    int currentSpeed = 0;
    int lastTime = 0;

    while (getline(cin, line)) {
        int spacePos = line.find(' ');
        string timeStr = line.substr(0, 8);

        if (spacePos == -1) {
            int queryTime = timeToSeconds(timeStr);
            int deltaTime = queryTime - lastTime;
            double queryDistance = totalDistance + (currentSpeed * deltaTime) / 3600.0;

            cout<<timeStr<<" "<<fixed<<setprecision(2)<<queryDistance<<" km"<<endl;
        } else {
            int newSpeed = stoi(line.substr(spacePos + 1));

            int newTime = timeToSeconds(timeStr);
            int deltaTime = newTime - lastTime;
            totalDistance += (currentSpeed * deltaTime) / 3600.0;

            currentSpeed = newSpeed;
            lastTime = newTime;
        }
    }
}
