class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> vis;
        for(auto s : bank) vis.insert(s);
        vector<char> gene = {'A','C','G','T'};
        queue<pair<string,int>> q;
        q.push({startGene,0});
        while(!q.empty()){
            auto [s,step] = q.front();
            q.pop();
            if(s==endGene) return step;
            string temp = s;
            for(int i=0;i<8;i++){
                for(auto c : gene){
                    s[i]=c;
                    if(vis.count(s)){
                        q.push({s,step+1});
                        vis.erase(vis.find(s));
                    }
                    s[i]=temp[i];
                }
            } 
        }
        return -1;
    }
};