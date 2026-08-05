class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(),
             [](const auto &a, const auto &b) {
                 return a.second > b.second;
             });

        string ans;

        for (auto &p : vec)
            ans.append(p.second, p.first);

        return ans;
    }
};