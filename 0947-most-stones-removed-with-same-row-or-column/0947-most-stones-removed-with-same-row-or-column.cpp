class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n, 0);
        iota(begin(parent), end(parent), 0);
        vector<int> size(n, 1);

        function<int(int)> find = [&](int x){
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b){
            int pA = find(a);
            int pB = find(b);
            if (pA != pB) {
                if (size[pA] < size[pB]) {
                    parent[pA] = pB;
                    size[pB] += size[pA];
                } else {
                    parent[pB] = pA;
                    size[pA] += size[pB];
                }
            }
        };
        auto check = [&](int a, int b){
            if(find(a) == find(b)) return 1;
            return 0;
        };

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unite(i,j);
                }
            }
        }
        unordered_set<int> us;
        for(int i=0;i<n;i++){
            int p=find(i);
            if(p!=i) us.insert(p);
        }
        int ans=0;
        for(auto x : us) ans+=size[x]-1;
        return ans;
    }
};