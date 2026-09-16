class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R,D;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') R.push(i);
            else D.push(i);
        }
        int n=senate.size();
        while((!R.empty())&&(!D.empty())){
            int r=R.front(),d=D.front();
            D.pop();
            R.pop();
            cout<<r<<" "<<d<<endl;
            if(r<d){
                R.push(n++);
            }else{
                D.push(n++);
            }
        }
        return R.empty() ? "Dire" : "Radiant";
    }
};