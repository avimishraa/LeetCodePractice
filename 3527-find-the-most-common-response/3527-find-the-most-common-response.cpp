class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freq;
        
        for (const auto& day : responses) {
            // Remove duplicates within the current day
            unordered_set<string> unique_day_responses(day.begin(), day.end());
            
            // Count unique occurrences across days
            for (const string& response : unique_day_responses) {
                freq[response]++;
            }
        }
        
        string best_response = "";
        int max_freq = 0;
        
        for (const auto& [response, count] : freq) {
            if (count > max_freq) {
                max_freq = count;
                best_response = response;
            } else if (count == max_freq) {
                // Pick lexicographically smaller response on tie
                if (response < best_response) {
                    best_response = response;
                }
            }
        }
        
        return best_response;
    }
};