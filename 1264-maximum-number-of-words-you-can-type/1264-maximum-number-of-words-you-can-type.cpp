class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool flag=false;
        map<char,int> map;
        for(auto c : brokenLetters) map[c]++;
        int ans=0;
        for(auto it : text){
            if(it==' '){
                if(!flag) ans++;
                flag=false;
                continue;
            }
            if(map.count(it)){
                if(flag) continue;
                else flag=true;
            }
        }
        if(!flag) ans++;
        return ans;
    }
};