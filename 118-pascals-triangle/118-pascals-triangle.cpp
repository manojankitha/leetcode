class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows== 1) {  
            result = {{1}};  return result; 
        }      
        else if (numRows == 2) { 
            result = {{1}, {1,1}};  
            return result;
        }
        result = {{1}, {1,1}};
        for(int i = 2;i<numRows;i++){
            vector<int> arr;
            arr.push_back(1);
            for (int j = 1;j<i;j++){
                arr.push_back(result[i-1][j]+result[i-1][j-1]);
            }
            arr.push_back(1);
            result.push_back(arr);      
        }
       
        return result;
        
    }
};