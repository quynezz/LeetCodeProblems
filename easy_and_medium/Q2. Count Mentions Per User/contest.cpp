struct Event {
    int timestamp;
    int userId;
};

struct CompareEvent {
    bool operator()(const Event& a, const Event& b) const {
        return a.timestamp > b.timestamp;
    }
};

class Solution {
public:
    vector<int> countMentions(int totalUsers, vector<vector<string>>& eventLogs) {
        // Sort events based on timestamp
        sort(eventLogs.begin(), eventLogs.end(), [&](const vector<string>& a, const vector<string>& b) -> bool {
            return stoi(a[1]) < stoi(b[1]);
        });

        // Initialize mentions and online status arrays
        vector<int> mentionCount(totalUsers, 0);
        vector<bool> isOnline(totalUsers, true);

        // Priority queue to manage users coming online
        priority_queue<Event, vector<Event>, CompareEvent> onlineQueue;
        
        int totalEvents = eventLogs.size();
        int index = 0;
        
        // Process each event
        while (index < totalEvents) {
            int currentTimestamp = stoi(eventLogs[index][1]);

            // Process users who should be online by the current timestamp
            while (!onlineQueue.empty() && onlineQueue.top().timestamp <= currentTimestamp) {
                int userToActivate = onlineQueue.top().userId;
                if (userToActivate >= 0 && userToActivate < totalUsers) {
                    isOnline[userToActivate] = true;
                }
                onlineQueue.pop();
            }

            int nextIndex = index;
            // Group all events with the same timestamp together
            while (nextIndex < totalEvents && stoi(eventLogs[nextIndex][1]) == currentTimestamp) {
                nextIndex++;
            }

            // Handle "OFFLINE" events
            for (int eventIndex = index; eventIndex < nextIndex; ++eventIndex) {
                if (eventLogs[eventIndex][0] == "OFFLINE") {
                    int userId = stoi(eventLogs[eventIndex][2]);
                    if (userId >= 0 && userId < totalUsers && isOnline[userId]) {
                        isOnline[userId] = false;
                        Event newEvent;
                        newEvent.timestamp = currentTimestamp + 60;  // User comes online after 60 seconds
                        newEvent.userId = userId;
                        onlineQueue.push(newEvent);
                    }
                }
            }

            // Handle "MESSAGE" events
            for (int eventIndex = index; eventIndex < nextIndex; ++eventIndex) {
                if (eventLogs[eventIndex][0] == "MESSAGE") {
                    string mentionedUsers = eventLogs[eventIndex][2];
                    
                    // Handle "ALL" mentions
                    if (mentionedUsers == "ALL") {
                        for (int user = 0; user < totalUsers; ++user) {
                            mentionCount[user]++;
                        }
                    }
                    // Handle "HERE" mentions
                    else if (mentionedUsers == "HERE") {
                        for (int user = 0; user < totalUsers; ++user) {
                            if (isOnline[user]) {
                                mentionCount[user]++;
                            }
                        }
                    }
                    // Handle specific user mentions
                    else {
                        stringstream userStream(mentionedUsers);
                        string mention;
                        while (userStream >> mention) {
                            if (mention.size() >= 3 && mention.substr(0, 2) == "id") {
                                string idStr = mention.substr(2);
                                bool isValid = true;
                                for (char c : idStr) {
                                    if (!isdigit(c)) {
                                        isValid = false;
                                        break;
                                    }
                                }
                                if (isValid) {
                                    int userId = stoi(idStr);
                                    if (userId >= 0 && userId < totalUsers) {
                                        mentionCount[userId]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // Move to the next set of events with a different timestamp
            index = nextIndex;
        }
        
        return mentionCount;
    }
};