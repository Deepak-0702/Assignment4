#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        int minLen = INT_MAX, maxLen = 0;
        for (auto &word : wordDict) {
            int len = word.size();
            minLen = min(minLen, len);
            maxLen = max(maxLen, len);
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true; 

        for (int i = 1; i <= n; i++) {
            // Check substrings ending at i
            for (int len = minLen; len <= maxLen && len <= i; len++) {
                if (!dp[i - len]) continue;
                string sub = s.substr(i - len, len);
                if (dict.count(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (sol.wordBreak(s, wordDict))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
