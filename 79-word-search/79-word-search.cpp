class Solution {
public:
    
    
    
    
//     bool recursionFn(int i, int j, string currentWord, vector<vector<char>>& board,int m, int n, int index){
    
       
//         if(index>=currentWord.length()){
//             return true;
//         } 
        
        
//         if (i<0 || i==m || j<0 || j==n || board[i][j]!=currentWord[index]){   
//             return false;
//         }
        
//         // matched
     
//         board[i][j] = '0';
//         int arr1[4] = {1,-1,0,0};
//         int arr2[4] = {0,0,1,-1};
//         bool retVal;
//         for(int x=0;x<4;x++){
//             retVal = recursionFn(i+arr1[x], j+arr2[x], currentWord,  board,m, n,index+1);
//                 if(retVal == true){
//                    break;
//                 }   
//         }
        
        
//         board[i][j] = currentWord[index];
        
//         return retVal;
        
             
//     }
    
//     bool exist(vector<vector<char>>& board, string word) {
        
      
//         // m = no of rows , i -> 0 to m-1
//         // n = no of columns, j-> 0 to n-1
        
//        int m = board.size();
//        int n = board[0].size();
      
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if (recursionFn(i, j, word, board, m,n,0)){
//                     return true;
//                 }
//             }
//         }
//         return false;
        
//     }

    
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
    
    
    
    
    
   