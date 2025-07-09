class Solution {


    public:
        int maxEvents(vector<vector<int>>& events) {
            sort(events.begin(), events.end()); // Sorting the events by date to check on each day the available events 
            priority_queue<int, vector<int>, greater<int>> pq;
            
            int day = 0, i = 0, n = events.size(), count = 0;
    
            while (i < n || !pq.empty()) {
                if (pq.empty()) {
                    day = events[i][0]; // first event insertion 
                }
    
                // Add all events that start today
                while (i < n && events[i][0] == day) {
                    pq.push(events[i][1]); // Storing the end dates of events in the queue
                    i++;
                }
    
                // Remove all events that have already expired
                while (!pq.empty() && pq.top() < day) {
                    pq.pop();
                }
    
                // Attend one event today
                if (!pq.empty()) {
                    pq.pop();
                    count++;
                }
    
                day++;
            }
    
            return count;
        }
    };
    
    
        
    