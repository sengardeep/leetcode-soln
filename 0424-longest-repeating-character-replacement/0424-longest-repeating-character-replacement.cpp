class Solution {
public:
    int characterReplacement(string s, int k) {
        // Alternative :- Need max(length-maxFreq) at most to k

        vector<int> hash(26, 0);

        int left = 0, right = 0, maxLength = 0;
        int length = 0, maxFreq = 0;
        // bool flag=false;
        while (right < s.size()) {
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq,hash[s[right]-'A']);
            length = (right - left + 1) - maxFreq;
            if (length > k && left <= right) {
                hash[s[left] - 'A']--;
                maxFreq = *max_element(hash.begin(),hash.end());
                length = (right - left + 1) - maxFreq;
                left++;
            }
            
            if (length <= k) {
                maxLength = max(right - left + 1, maxLength);
            }
            
            right++; 
        }
        return maxLength;
    }
};