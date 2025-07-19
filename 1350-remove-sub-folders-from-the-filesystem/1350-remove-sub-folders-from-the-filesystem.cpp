class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_map<string,bool> mp;
        vector<string> ans;
        for(auto it :  folder) 
        {
            string temp="";
            bool flag=true;
            for(int i=0;i<it.size();i++)
            {
                if(it[i]=='/'){
                    if(mp[temp]==true){
                        flag=false;
                        break;
                    }
                }
                temp+=it[i];
            }
            if(flag){
                ans.push_back(it);
                mp[it]=true;
            }
        }

        return ans;
    }
};