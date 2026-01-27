class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i =0; i<n-1;i++){
            for(int j=i+1;j<n;j++){
                //only swap once, for the upper triangle of the matrix.
                //j starts from i+1
                //diagonal (i == j) is skipped (no need to swap)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0 ; i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};