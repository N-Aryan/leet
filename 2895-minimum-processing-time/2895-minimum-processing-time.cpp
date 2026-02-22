#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {

        // Step 1: Sort processors in ascending order
        sort(processorTime.begin(), processorTime.end());

        // Step 2: Sort tasks in descending order
        sort(tasks.begin(), tasks.end(), greater<int>());

        int answer = 0;

        // Step 3: Assign 4 tasks to each processor
        for(int i = 0; i < processorTime.size(); i++) {

            // Since tasks are sorted descending,
            // the largest task in this group is at index i*4
            int finishTime = processorTime[i] + tasks[i * 4];

            // Track maximum finish time
            answer = max(answer, finishTime);
        }

        return answer;
    }
};