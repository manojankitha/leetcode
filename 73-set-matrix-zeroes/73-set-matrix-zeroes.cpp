class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      // you need to traverse all elements - no other choice to find indexes where 0 is present
        
        unordered_set<int> storeI;
        unordered_set<int> storeJ;
        int m = matrix.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<matrix[i].size();j++)
                if(matrix[i][j]==0){
                    storeI.insert(i);
                    storeJ.insert(j);
                }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(storeI.find(i)!=storeI.end() || storeJ.find(j)!=storeJ.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};