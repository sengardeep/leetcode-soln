class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans,copy;
        copy=words;
        for(auto &it : copy) sort(it.begin(),it.end());
        int n=words.size();
        for(int i=0;i<n;i++){
            ans.push_back(words[i]);
            while(i<n-1 && copy[i]==copy[i+1]) i++;
        }
        return ans;
    }
};