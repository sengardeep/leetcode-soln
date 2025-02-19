class Solution {
public:
    string getHappyString(int n, int k) {
        // string s = "abc";
        set<string> ans;
        string temp;
        generate(ans, n, temp);
        // for (auto it : ans)
        //     cout << it << endl;
        vector<string> res(ans.begin(),ans.end());
        if(k>res.size()) return "";
        return res[k-1];
    }

private:
    void generate(set<string>& ans, int n,string& temp) {
        if (temp.size() == n) {
            ans.insert(temp);
            return;
        }
        for (char i='a';i<='c';i++) {
            if (temp.empty() || temp.back() != i) // Take
            {
                temp.push_back(i);
                generate(ans, n, temp);
                temp.pop_back();
            } 
        }
    }
};