/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if(reader.get(0)==target){
            return 0;
        }
        int l = 0,r = 1;
        while(reader.get(r)<target){
            l=r;
            r<<=1;
        }
        return binarySearch(reader, l,r,target);   
    }
    
    int binarySearch(const ArrayReader& reader, int l, int r, int target){
        while(l<=r){
            int mid = l+ (r-l)/2;
            int x = reader.get(mid);
            
            if(x==target){
                return mid;
            }
            if(x<target){
                return binarySearch(reader,mid+1,r,target);
            } else {
                return binarySearch(reader,l,mid-1, target);
            }
        }
        return -1;
    }
};