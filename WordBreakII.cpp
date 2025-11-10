#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(0, s, dict, memo);
    }

private:
    vector<string> dfs(int start, const string &s, unordered_set<string>& dict,
                       unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) return memo[start];
        vector<string> res;

        if (start == s.size()) {
            res.push_back(""); 
            return res;
        }

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) {
                vector<string> subList = dfs(end, s, dict, memo);
                for (string &sub : subList) {
                    string sentence = word + (sub.empty() ? "" : " " + sub);
                    res.push_back(sentence);
                }
            }
        }

        return memo[start] = res;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> ans = sol.wordBreak(s, wordDict);

    cout << "Possible sentences:\n";
    for (auto &sentence : ans) {
        cout << sentence << endl;
    }

    return 0;
}
