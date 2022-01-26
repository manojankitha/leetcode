class Solution {
public:
    
    long returnSquareDigits(int n){
        long sum=0;
        while(n){
            sum+=pow((n%10),2);
            n/=10;
        }
        return sum; 
    }
    
    bool isHappy(int n) {
       long first_sum = returnSquareDigits(n);

            long slow = first_sum;
        long fast = returnSquareDigits(slow);
            if(fast==1){
                return true;
            }
        while(slow!=fast and fast!=1){
           
          
            if(fast == slow){
                return false;
            }
            slow = returnSquareDigits(slow);
            fast = returnSquareDigits(returnSquareDigits(fast));
          
        }
         if(fast==1){
                    return true;
                }
     
        return false;
      
    }
};