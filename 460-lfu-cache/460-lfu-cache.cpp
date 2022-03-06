struct Node {
    int value;
    list<int>::iterator itr;
};


class LFUCache {

    unordered_map<int,Node> mValues;
    unordered_map<int,int> mCounts;
    unordered_map<int,list<int>>mCountsKeyMap;
    int mLowestFreq;
    int maxCap;
    
    public:
    
    LFUCache(int capacity){
        maxCap = capacity;
        mLowestFreq = 0;
    }
    
    int get(int key) {
        if(mValues.find(key)==mValues.end() || maxCap<=0){
            return -1;
        }
        put(key,mValues[key].value);
        return mValues[key].value;
    }
    
    void put(int key,int value) {
        if(maxCap<=0) {
            return ;
        }
        
        // if key is not present and maxCap is reached. 
        // evict LFU element  
        if(mValues.find(key)==mValues.end()){
            if(mCounts.size()==maxCap) {
                int keyToDel = mCountsKeyMap[mLowestFreq].back();
                mCountsKeyMap[mLowestFreq].pop_back();
                if(mCountsKeyMap[mLowestFreq].empty()){
                    mCountsKeyMap.erase(mLowestFreq);
                }
                mCounts.erase(keyToDel);
                mValues.erase(keyToDel);    
                
            }
            
            mValues[key].value = value;
            mCounts[key] = 0;
            mLowestFreq=0;
            mCountsKeyMap[mCounts[key]].push_front(key);
            mValues[key].itr=mCountsKeyMap[0].begin();
        } else {
        
        // if key is present, increment frequency only - dont need to add any new elements
           
            mCountsKeyMap[mCounts[key]].erase(mValues[key].itr);

            if(mCountsKeyMap[mCounts[key]].empty()){
                if(mLowestFreq == mCounts[key]){
                    mLowestFreq++;
                }
                mCountsKeyMap.erase(mCounts[key]);
            }
            mValues[key].value = value; // updated value
            mCounts[key]++;
            mCountsKeyMap[mCounts[key]].push_front(key);
            mValues[key].itr = mCountsKeyMap[mCounts[key]].begin();
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */