class Solution {
public:
    bool is_valid(char c, int row, int col, vector<vector<char>>& board) {
        // check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
        }

        // check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;
        }

        // check 3x3 box
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == c) return false;
            }
        }

    return true; // safe hai
    }
   
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col]=='.'){
                    for(int i='1'; i<='9'; i++){
                        if(is_valid(i, row, col, board)) {
                            board[row][col]=i;

                            if (solve(board)) return true;
                            else board[row][col] = '.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};