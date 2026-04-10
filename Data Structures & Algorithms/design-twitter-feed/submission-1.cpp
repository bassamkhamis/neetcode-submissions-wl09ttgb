class Twitter {
    unordered_map<int, unordered_set<int>> follower_followee;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId, {time, tweetId}
    //priority_queue<pair<int, pair<int,int>>> tweets;
    int time;
public:
    Twitter() {
       time = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, tuple<int, int, int>>> max_heap;

        follower_followee[userId].insert(userId);

        for (int followeeId : follower_followee[userId]) {
            if (tweets.count(followeeId)) {
                vector<pair<int, int>> tweet_list = tweets[followeeId];
                int index = tweet_list.size() - 1;
                max_heap.push({tweet_list[index].first, {tweet_list[index].second, followeeId, index}});
            }
        }

        while (max_heap.empty() == false && res.size() < 10) {
            pair<int, tuple<int, int, int>> cur = max_heap.top();
            max_heap.pop();
            int tweetId = get<0>(cur.second);
            int followeeId = get<1>(cur.second);
            int index = get<2>(cur.second);

            res.push_back(tweetId);

            if (index > 0) {
                vector<pair<int, int>> tweet_list = tweets[followeeId];
                index--;
                max_heap.push({tweet_list[index].first, {tweet_list[index].second, followeeId, index}});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
       follower_followee[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        follower_followee[followerId].erase(followeeId);
    }
};
