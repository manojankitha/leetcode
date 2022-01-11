class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
       
       unordered_set<int> storeI;
        unordered_set<int> storeJ;
       
        for(int i = 0;i<m;i++){
            for(auto it = matrix[i].begin();it!=matrix[i].end();it++){
                if (*it == 0){
                storeI.insert(i);
                storeJ.insert(it-matrix[i].begin());
            
            }
        }}
        for(auto d:storeJ){
            cout<<d<<endl;
        }
            
        for(int i=0;i<m;i++){
            for(int j=0;j<matrix[i].size();j++){
                if (storeI.count(i)>0 || storeJ.count(j) > 0){
                   matrix[i][j] = 0; 
                }
               
        }
            
            
        }
        
    }
};