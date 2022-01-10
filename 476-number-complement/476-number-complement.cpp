#include <math.h>
class Solution {
public:
    
    string convertDecToBin(int n){
       string s;
        string r;
        while(n){
            if(n%2){
                s.push_back('1');
            }else{
                s.push_back('0');
            }
            n/=2;
            
        }
        while(s!=""){
            r.push_back(s.back());
            s.pop_back();
        }
        return r;
           
    }
    
    int convertBinToDec(string r){
        int dec = 0,i=0;
        while(r!=""){
            char rem = r.back();
            r.pop_back();
         
            dec+=((pow(2,i))*(rem-'0'));
            cout<<rem<<" "<<dec<<endl;
            i++;
            
        }
        return dec;
    }
    int findComplement(int num) {
        
        string r = convertDecToBin(num);
       
      
        for(int i =0;i<r.length();i++){
            if(r[i]=='1'){
                r[i] = '0';
            }else{
                r[i] = '1';
            }
        }
        cout <<r<<endl;
        return convertBinToDec(r);
      
        
    }
};