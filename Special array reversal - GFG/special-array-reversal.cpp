// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    void swap(char& A,char& B){
        char x = A;
        A = B;
        B = x;
    }
    string reverse(string str)
    { 
        //code here.
        
        
        int i=0,j=str.length();
        
        while(i<j){
           while(isalpha(str[i])==false){
               i++;
           }
           while(isalpha(str[j])==false){
               j--;
           }
           if(i>=j){
               break;
           }
          
            swap(str[i],str[j]);
            i++;
            j--;
           
       }
       return str;
        
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}

  // } Driver Code Ends