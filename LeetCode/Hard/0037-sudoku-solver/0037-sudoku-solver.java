class Solution {
    public void solveSudoku(char[][] board) {
        solve (board);
    }
    boolean solve(char[][] board){
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='.'){   //finding empty spot
                    for(char c = '1'; c<='9';c++){  //tries all values from 1-9
                        if(isValid(board,i,j,c)){   //checks if placement is valid
                            board[i][j]=c;  //if valid places the number
                            if(solve(board))    //recursive method, returns true if recursion succeeds
                            return true;
                            else
                            board[i][j] = '.'; 
                        }
                    }
                    return false;   //backtracks if it fails during recursion, no number 1-9 works for this cell
                }
            }
        }
        return true;    //returns true when all empty spots are filled
    }
    boolean isValid(char[][] board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)    //column check
            return false;
            if(board[row][i]==c)    //row check
            return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)  //3*3 block check
            return false;
        }
        return true;
    }
}