class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, 
                     vector<char>& changed, vector<int>& cost) {
    // 1. Initialize a 26x26 matrix with a large value (10^9)
    vector<vector<int>> dist(26, vector<int>(26, 1000000000));
    
    // 2. Set diagonal to 0 (no cost to stay at same character)
    for (int i = 0; i < 26; i++) dist[i][i] = 0;
    
    // 3. Populate direct edges
    for (int i = 0; i < original.size(); i++) {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        dist[u][v] = min(dist[u][v], cost[i]);
    }
    
    // 4. Run Floyd-Warshall (26³ operations)
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    // 5. Calculate total cost
    long long ans = 0;
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == target[i]) continue;
        int u = source[i] - 'a';
        int v = target[i] - 'a';
        if (dist[u][v] >= 1000000000) return -1;
        ans += dist[u][v];
    }
    return ans;
}
};