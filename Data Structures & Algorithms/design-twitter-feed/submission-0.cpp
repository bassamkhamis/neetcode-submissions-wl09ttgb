class Twitter {
    unordered_map<int, unordered_set<int>> followee_followers;
    priority_queue<pair<int, pair<int,int>>> tweets;
    int time;
public:
    Twitter() {
       time = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push({time++, {userId, tweetId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        vector<pair<int, pair<int,int>>> temp;

        for (;tweets.empty() == false;) {
            auto [t, userTweetIds] = tweets.top();
            tweets.pop();
            temp.push_back({t, userTweetIds});

            if (followee_followers[userId].count(userTweetIds.first) || userId == userTweetIds.first) {
                res.push_back(userTweetIds.second);
            }

            if (res.size() == 10)
                break;
        }

        while (temp.empty() == false) {
            tweets.push(temp.back());
            temp.pop_back();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
       followee_followers[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        followee_followers[followerId].erase(followeeId);
    }
};
