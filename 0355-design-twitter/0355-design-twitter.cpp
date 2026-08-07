class Twitter {
public:
    vector<pair<int,int>> v;
    unordered_map<int,set<int>> mp;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int i=v.size()-1;
        vector<int> ans;
        while(i>=0 && ans.size()<10){
            int curr=v[i].first;
            if(curr==userId || mp[userId].count(curr)) ans.push_back(v[i].second);
            i--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(mp[followerId].count(followeeId)) mp[followerId].erase(mp[followerId].find(followeeId));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */