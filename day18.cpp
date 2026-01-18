#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<bool> col, diag1, diag2;

    void solve(int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !diag1[row + c] && !diag2[row - c + n - 1]) {
                board[row][c] = 'Q';
                col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;

                solve(row + 1, n);

                board[row][c] = '.';
                col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        col.assign(n, false);
        diag1.assign(2 * n, false);
        diag2.assign(2 * n, false);

        solve(0, n);
        return result;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);

    cout << "Total solutions: " << ans.size() << "\n\n";
    for (auto &board : ans) {
        for (auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
