class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string> stack;
        for(int i=0;i<n;i++){
            if(path[i]=='/') continue;
            else{
                string temp="";
                while(i<n && path[i]!='/') temp+=path[i++];
                i--;
                if(temp==".") continue;
                if(temp==".." && !stack.empty()) stack.pop();
                else if(temp!="..") stack.push(temp);  
            }
        }
        vector<string> v;
        string ans="";
        while(!stack.empty()){
            string temp=stack.top();
            v.push_back(temp);            
            stack.pop();
        }
        reverse(begin(v),end(v));
        for(auto s : v) ans+=('/'+s);
        if(ans=="") ans="/"; 
        return ans;
    }
};