// Design Task Manager
// 18-09-2025
// Difficulty - Hard (Leetcode Medium)

#include<bits/stdc++.h>
using namespace std;

class TaskManager {
private:
    unordered_map<int, pair<int, int>> priorityAndUser;
    priority_queue<pair<int, int>> executionOrder;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task: tasks) {
            priorityAndUser[task[1]] = {task[2], task[0]};
            executionOrder.push({task[2], task[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        priorityAndUser[taskId] = {priority, userId};
        executionOrder.push({priority, taskId});        
    }
    
    void edit(int taskId, int newPriority) {
        priorityAndUser[taskId].first = newPriority;
        executionOrder.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        priorityAndUser[taskId].first = -1;
    }
    
    int execTop() {
        while (!executionOrder.empty() && priorityAndUser[executionOrder.top().second].first != executionOrder.top().first) {
            executionOrder.pop();
        }
        if (executionOrder.empty()) {
            return -1;
        } 
        pair<int, int> p = executionOrder.top();
        priorityAndUser[p.second].first = -1;
        executionOrder.pop();
        return priorityAndUser[p.second].second;
    }
};

int main() {
    vector<vector<int>> tasks = {
        {1, 101, 10},
        {2, 102, 20},
        {3, 103, 15}
    };

    TaskManager tm(tasks);

    tm.add(4, 104, 5);
    tm.edit(102, 8);
    cout << tm.execTop() << endl;
    tm.rmv(101);
    tm.add(5, 105, 15);
    cout << tm.execTop() << endl;
    cout << tm.execTop() << endl;

    return 0;
}