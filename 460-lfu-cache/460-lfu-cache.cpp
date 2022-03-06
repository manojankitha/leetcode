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


// //Just for better readability
// using Key_t = int;
// using Count_t = int;


// struct Node
// {
//     int value;
//     list<Key_t>::iterator itr;
// };

// class LFUCache
// {
//     unordered_map<Key_t, Node> m_values;
//     unordered_map<Key_t, Count_t> m_counts;
//     unordered_map<Count_t, list<Key_t>> m_countKeyMap;
//     int m_lowestFrequency;
//     int m_maxCapacity;

// public:
//     LFUCache(int capacity)
//     {
//         m_maxCapacity = capacity;
//         m_lowestFrequency = 0;
//     }

//     int get(int key)
//     {
//         if (m_values.find(key) == m_values.end() || m_maxCapacity <= 0)
//         {
//             return -1;
//         }
//         //update frequency, & return value
//         put(key, m_values[key].value);
//         return m_values[key].value;
//     }

//     void put(int key, int value)
//     {
//         if (m_maxCapacity <= 0)
//         {
//             return;
//         }

//         //If key is not present and capacity has exceeded,
//         //then remove the key entry with least frequency
//         //else just make the new key entry
//         if (m_values.find(key) == m_values.end())
//         {
//             if (m_values.size() == m_maxCapacity)
//             {
//                 int keyToDelete = m_countKeyMap[m_lowestFrequency].back(); 
//                 m_countKeyMap[m_lowestFrequency].pop_back();
//                 if (m_countKeyMap[m_lowestFrequency].empty())
//                 {
//                     m_countKeyMap.erase(m_lowestFrequency);
//                 }
//                 m_values.erase(keyToDelete);
//                 m_counts.erase(keyToDelete);
//             }
//             m_values[key].value = value;
//             m_counts[key] = 0;
//             m_lowestFrequency = 0;
//             m_countKeyMap[m_counts[key]].push_front(key);
//             m_values[key].itr = m_countKeyMap[0].begin();
//         }
//         //Just update value and frequency
//         else
//         {
//             m_countKeyMap[m_counts[key]].erase(m_values[key].itr);
//             if (m_countKeyMap[m_counts[key]].empty())
//             {
//                 if (m_lowestFrequency == m_counts[key])
//                     m_lowestFrequency++;
//                 m_countKeyMap.erase(m_counts[key]);
//             }
//             m_values[key].value = value;
//             m_counts[key]++;
//             m_countKeyMap[m_counts[key]].push_front(key);
//             m_values[key].itr = m_countKeyMap[m_counts[key]].begin();
//         }
//     }
// };

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */