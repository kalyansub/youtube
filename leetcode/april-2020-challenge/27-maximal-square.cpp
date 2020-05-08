/* Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H = matrix.size();
        if(H == 0 || matrix[0].empty()) {
            return 0;
        }
        int W = matrix[0].size();
        vector<vector<int>> dp(H, vector<int>(W));
        int answer = 0;
        // dp[r][c] - best square ending at (r, c)
        for(int row = 0; row < H; ++row) {
            for(int col = 0; col < W; ++col) {
                if(matrix[row][col] == '1') {
                    dp[row][col] = 1;
                    if(row > 0 && col > 0) {
                        dp[row][col] += min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]});
                    }
                    answer = max(answer, dp[row][col]);
                }
            }
        }
        return answer * answer;
    }
};
