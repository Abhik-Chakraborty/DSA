class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, int drow[], int dcol[], int m, int n) {
        visited[row][col] = 1;

        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, visited, drow, dcol, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, board, visited, drow, dcol, m, n);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
                dfs(i, n - 1, board, visited, drow, dcol, m, n);
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, board, visited, drow, dcol, m, n);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j])
                dfs(m - 1, j, board, visited, drow, dcol, m, n);
        }

        // Flip all unvisited 'O's to 'X'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};