class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true)
        {
            if(s.find(part)==string::npos) break;
            auto it=s.find(part);
            s.erase(it,part.size());
        }
        return s;
    }
};