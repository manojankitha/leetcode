class Solution {
public:
    

    
    bool recursionFn(int i, int j, string word, vector<vector<char>>& board, int m, int n,int currIndex){
        if(currIndex>=word.length()){
            return true;
        }
        
        if(i<0 || i==m || j<0 || j==n || board[i][j]!=word[currIndex]){
            return false;
        }
        
       // matched case  board[i][j]==word[currIndex]
        // check for neighbours for next index
        // change temporarily so same char is not visited
        board[i][j]='0';
        int arrx[4] = {-1,1,0,0};
        int arry[4] = {0,0,1,-1};
        bool retVal = false;
        for(int k=0;k<4;k++){
           retVal = recursionFn(i+arrx[k], j+arry[k],word, board,m,n,currIndex+1);
            if(retVal==true){
               break;
            }
        }
        // change it back
        board[i][j]=word[currIndex];
        return retVal;
        
        
    }
    
     bool exist(vector<vector<char>>& board, string word) {
         int m = board.size();
         int n = board[0].size();
         
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 // start with index 0
                 if(recursionFn(i,j, word,board,m,n,0)){
                     return true;
                 }
             }
         }
         return false;
         
     }
    
};
    
    
    
    
    
   