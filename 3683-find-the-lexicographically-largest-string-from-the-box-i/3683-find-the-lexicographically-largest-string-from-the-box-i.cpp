class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        vector<string> ans;
        int n=word.size();
        int len = n - numFriends + 1;
        for(int i=0;i<n;i++)
        {
            if(i+len <= n) ans.push_back(word.substr(i,len));
            else ans.push_back(word.substr(i,n-i));
        }
        sort(ans.begin(),ans.end());
        return ans.back();
    }
};