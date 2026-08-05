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
        string ans="";
        while(!stack.empty()){
            string temp=stack.top();
            reverse(begin(temp),end(temp));
            ans+=temp;
            ans+='/';
            stack.pop();
        }
        if(ans.empty()) ans="/";
        reverse(begin(ans),end(ans));
        return ans;
    }
};