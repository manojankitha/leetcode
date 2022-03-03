class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        sum = 0;
        temp = abs(x);
        while(temp):
            sum = sum*10+(temp%10);
            temp/=10;
        
        if x<0:
            sum*=-1;
   
        if sum>pow(2,31)-1 or sum<-pow(2,31):
            return 0;
        return sum;
        
        
        