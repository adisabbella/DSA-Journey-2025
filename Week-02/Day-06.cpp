// Implement Router
// 20-09-2025
// Difficulty - Hard (Leetcode Medium)

#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    set<vector<int>> packets;
    deque<vector<int>> buffer;
    unordered_map<int, deque<int>> destAndTimes;
    int capacity;

public:
    Router(int memoryLimit) {
        capacity = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        if (packets.find(packet) != packets.end()) return false;
        if (capacity == 0) {
            packets.erase(buffer.front());
            destAndTimes[buffer.front()[1]].pop_front();
            buffer.pop_front();
        }
        else {
            capacity--;
        }
        packets.insert(packet);
        buffer.push_back(packet);
        destAndTimes[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets.empty()) {
            return {};
        }
        capacity++;
        vector<int> firstPacket = buffer.front();
        destAndTimes[firstPacket[1]].pop_front();
        packets.erase(firstPacket);
        buffer.pop_front();
        return firstPacket;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        deque<int> &dq = destAndTimes[destination];
        int l = lower_bound(dq.begin(), dq.end(), startTime) - dq.begin();
        int r = upper_bound(dq.begin(), dq.end(), endTime) - dq.begin();
        return r - l;
    }
};

int main() {
    Router router(3);
    cout << router.addPacket(1, 2, 10) << endl;
    cout << router.addPacket(3, 2, 12) << endl;
    cout << router.addPacket(1, 3, 15) << endl;
    cout << router.addPacket(4, 2, 20) << endl;
    vector<int> fwd = router.forwardPacket();
    if (!fwd.empty()) {
        for (int x : fwd) cout << x << " ";
        cout << endl;
    }
    cout << router.getCount(2, 10, 20) << endl;
    return 0;
}
