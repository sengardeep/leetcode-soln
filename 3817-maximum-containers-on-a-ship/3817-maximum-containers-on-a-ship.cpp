class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int maxPossible = maxWeight / w;
        return (maxPossible < n * n) ? maxPossible : n * n;
    }
};