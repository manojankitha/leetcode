class Solution {
public:
    string addBinary(string a, string b) {
        string out="";
        int i=a.size()-1, j = b.size()-1;
        int carry = 0;
        while(i>=0 || j>=0||carry==1){
            carry += i>=0 ? a[i--] - '0':0;
            carry += j>=0 ? b[j--] - '0':0;
            out = char(carry%2 +'0')+out;
            carry/=2;
        }
        return out;
        
        
        
        
        
        
        
        
    }
};