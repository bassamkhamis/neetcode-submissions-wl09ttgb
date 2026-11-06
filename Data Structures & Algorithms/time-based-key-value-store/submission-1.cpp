class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& values = mp[key];
        string res;
        int left = 0, right = values.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].second == timestamp)
                return values[mid].first;
            else if (values[mid].second > timestamp)
                right = mid - 1;
            else { // timestamp > values[mid]
                left = mid + 1;
                res =  values[mid].first;
            }       
        }

        return res;
    }
};
