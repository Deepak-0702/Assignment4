#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false), diag1(2 * n, false), diag2(2 * n, false);
        int count = 0;
        solve(0, n, col, diag1, diag2, count);
        return count;
    }

private:
    void solve(int row, int n, vector<bool>& col,
               vector<bool>& diag1, vector<bool>& diag2, int &count) {
        if (row == n) {
            count++; 
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n] || diag2[row + c]) continue;

            col[c] = diag1[row - c + n] = diag2[row + c] = true;

            solve(row + 1, n, col, diag1, diag2, count);

            col[c] = diag1[row - c + n] = diag2[row + c] = false;
        }
    }
};

int main() {
    Solution sol;
    int n = 4; // Change n for testing

    cout << "Number of distinct solutions for " << n << "-Queens: "
         << sol.totalNQueens(n) << endl;

    return 0;
}
