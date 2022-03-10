class Solution {
public:
    
    
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int yCorrDef = m/2;
        int xCorrDef = n/2;
        int xCorr=0,yCorr=0;
        int i=0,j=0;
        vector<int> out;
        int count = m*n;
        int counter=0;
      while(xCorr<=xCorrDef && yCorr<=yCorrDef){ 
            if(counter==count){
                 break;}
            else{
                  i = yCorr;
                for(j=xCorr;j<n-xCorr;j++){
                    out.push_back(matrix[i][j]);
                        counter++;
                }
            }
        
            if(counter==count){
                 break;}
            else{
                j=n-xCorr-1;
                for(i=yCorr+1;i<m-yCorr;i++){
                    out.push_back(matrix[i][j]);
                    counter++;
                }
             }
            if(counter==count){
                 break;}
            else{
                i=m-yCorr-1;
                for(j=n-xCorr-2;j>=xCorr;j--){
                    out.push_back(matrix[i][j]);
                    counter++;
                }
            }
            if(counter==count){
                 break;}
            else{
                j=xCorr;
                for(i=m-yCorr-2;i>yCorr;i--){
                    out.push_back(matrix[i][j]);
                    counter++;
                }
            }
            yCorr++;
            xCorr++;
       }
        return out;
        
        
    }
};