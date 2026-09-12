class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //Need to put this outside the for loops because it depends on both i and j 
        unordered_set<char> box[9]; //Creates 9 seperate unordered_sets 
        
        for(int i = 0; i < 9; i++){
            unordered_set<char> row; 
            unordered_set<char> col;
            for(int j = 0; j < 9; j++){
                //Get index of the box for current element
                int boxIdx = (i/3) * 3 + j/3; //9 boxes, calculated based on current i & j from 0-9 
                //Box index is 0, 1, 2 for first 3 rows, 3, 4, 5 for next 3 rows, and 6, 7, 8 for last 3 rows
                int boxNum = board[i][j]; 
                if(row.count(board[i][j]) || col.count(board[j][i]) || box[boxIdx].count(boxNum))
                    return false; 

                //Not a empty grid '.' 
                if(board[i][j] != '.')
                    row.insert(board[i][j]);
                if(board[j][i] != '.')
                    col.insert(board[j][i]); 
                if(boxNum != '.'){
                    box[boxIdx].insert(boxNum); 
                }

            }
        }
        return true; 
    }
};