#include <ranges>
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char, char>> D;
        for (pair<char, char>&& xy : views::zip(s1, s2))
            if (xy.first != xy.second)
                D.push_back(xy);
        return D.size() == 0 || (D.size() == 2 && D[0].first == D[1].second &&
                                 D[0].second == D[1].first);
    }
};