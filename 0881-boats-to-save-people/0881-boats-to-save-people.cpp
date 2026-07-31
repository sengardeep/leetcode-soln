class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int n=people.size();
        int ans=0;
        int i=0,j=n-1;
        while(j>=i){
            int curr=people[j];
            if(i<j && curr+people[i]<=limit){
                curr+=people[i];
                i++;
            }
            ans++;
            j--;
        }
        return ans;
    }
};