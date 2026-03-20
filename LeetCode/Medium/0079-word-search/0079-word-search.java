class Solution {
    int[][] directions = {{0,1},{0,-1},{1,0},{-1,0}};
    
    private boolean find(char[][] board, int i, int j, String word, int idx, int m, int n) {
        if (idx >= word.length()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word.charAt(idx))
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        for (int[] dir : directions) {
            if (find(board, i + dir[0], j + dir[1], word, idx + 1, m, n)){
                 board[i][j] = temp;
                return true;
        }
        }
         board[i][j] = temp;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        if (board.length == 0 || board[0].length == 0) return false;
        int m = board.length;
        int n = board[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {  // j < n
                if (board[i][j] == word.charAt(0) && find(board, i, j, word, 0, m, n))
                    return true;
            }
        }
        return false;
    }
}
