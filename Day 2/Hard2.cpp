Ques 5. You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
Return the minimum possible maximum working time of any assignment.

Program code:
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
bool canAssign(const vector<int>& jobs, vector<int>& workers, int maxWorkingTime, int index) {
    if (index == jobs.size()) {
        return true;
    }
for (int i = 0; i < workers.size(); ++i) {
        if (workers[i] + jobs[index] <= maxWorkingTime) {
            workers[i] += jobs[index];
            if (canAssign(jobs, workers, maxWorkingTime, index + 1)) {
                return true;
            }
            workers[i] -= jobs[index];
        }
        if (workers[i] == 0) {
            break;
        }
    }
    return false;
}
int minimumTimeRequired(vector<int>& jobs, int k) {
    int left = *max_element(jobs.begin(), jobs.end());
    int right = accumulate(jobs.begin(), jobs.end(), 0);
    
    sort(jobs.rbegin(), jobs.rend());
    while (left < right) {
        int mid = left + (right - left) / 2;
        vector<int> workers(k, 0);
        if (canAssign(jobs, workers, mid, 0)) {
            right = mid;
        } else {
            left = mid + 1;
        }
}
    return left;
}
int main() {
    vector<int> jobs = {3, 2, 3};
    int k = 3;
    cout << "Minimum possible maximum working time: " << minimumTimeRequired(jobs, k) << endl;
    return 0;
}
