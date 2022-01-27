#include<regex>
class Solution {
public:
    bool isPalindrome(string s) {
     
        regex reg("[^A-Za-z0-9]+");
        string S= regex_replace(s,reg,"");
           int n = S.length();
        cout<<S<<n;
        if(n==1 || n==0){
                return true;
            }
            
        int front,rear;
        for(front=0,rear=n-1;front<=rear;front++,rear--){
            
      
            cout<<front<<rear;
            if(front<=rear){
                
                if(tolower(S[front])!=tolower(S[rear])){
                    return false;
                }
            } else{
                
            }
        }
        
       return true;
   
        
    }
};