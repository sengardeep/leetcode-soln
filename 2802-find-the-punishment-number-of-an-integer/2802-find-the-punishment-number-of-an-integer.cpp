class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int sq=i*i;
            string s=to_string(sq);
            if(possibleSum(s,i,0,0)) ans+=sq;
        }
        return ans;
    }

private:
    bool possibleSum(string &s, int target, int idx, int sum) {
        if (idx == s.size()) {
            return sum == target;
        }
        
        int num = 0;
        for (int i = idx; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0'); // Forming the number incrementally
            if (num + sum > target) break; // Prune unnecessary calls
            
            if (possibleSum(s, target, i + 1, sum + num)) return true;
        }
        
        return false;
    }
};