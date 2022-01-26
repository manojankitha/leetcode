class Solution {
public:
    int minCharacters(string a, string b) {
        int arr1[26]={0},arr2[26]={0};
        int sum1=a.length(),sum2=b.length();
        
        for(int i=0;i<sum1;i++){
            arr1[a[i]-'a']++;
        }
         for(int i=0;i<sum2;i++){
            arr2[b[i]-'a']++;
        }
        
        
        int res=sum1+sum2;
        for(int i=0;i<26;i++){
            // third case
            res = min(res,sum1+sum2-arr1[i]-arr2[i]);
            if(i>0){
                arr1[i] +=arr1[i-1];
                arr2[i] +=arr2[i-1];
            }
            if(i<25){
                res = min(res, sum1-arr1[i]+arr2[i]);
                res = min(res, sum2-arr2[i]+arr1[i]);
            }
        }
        return res;
        
    }
};