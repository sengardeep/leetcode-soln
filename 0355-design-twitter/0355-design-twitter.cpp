class Twitter {
public:

    int timer;

    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        // Own tweets
        for(auto &t : tweets[userId])
            pq.push(t);

        // Tweets of followees
        for(auto followee : following[userId]){

            for(auto &t : tweets[followee])
                pq.push(t);
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if(followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};