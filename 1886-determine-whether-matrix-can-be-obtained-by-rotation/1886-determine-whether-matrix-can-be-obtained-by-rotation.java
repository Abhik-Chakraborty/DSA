class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;

        for(int k = 0; k < 4; k++){
            if(areEqual(mat, target)){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
    private boolean areEqual(int[][] mat, int[][]target){
        int n = mat.length;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    private void rotate(int[][] mat){
        int n = mat.length;

        //Transpose
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        //reverse each row
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[i][n - 1 - j];
                mat[i][n - 1 - j] = temp;
            }
        }
    }
}