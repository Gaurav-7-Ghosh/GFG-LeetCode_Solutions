class Solution {
    public:
        // This method essentially checks if all the tasks can be allocated. 
        // If they can it that we can try for a higher number of tasks. if it cannot we look for a smaller number of tasks

        bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            multiset<int> availableWorkers(workers.end() - k, workers.end());
    
            for (int i = k - 1; i >= 0; i--) {
                int task = tasks[i];
                auto it = availableWorkers.lower_bound(task);
                if (it != availableWorkers.end()) {
                    // Assign without pill
                    availableWorkers.erase(it);
                } else {
                    // Try to assign with pill
                    if (pills == 0) return false;
                    it = availableWorkers.lower_bound(task - strength);
                    if (it == availableWorkers.end()) return false;
                    availableWorkers.erase(it);
                    pills--;
                }
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int low = 0, high = min((int)tasks.size(), (int)workers.size()), answer = 0;
            // performing a check in a binary search to see how many tasks can be accomplished with the given set of values
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (canAssign(mid, tasks, workers, pills, strength)) {
                    answer = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return answer;
        }
    };
    