class Solution {
public:
 
    int compareVersion(string version1, string version2) {
        
    // Storing the whole string
    // into string stream
        version1+=".n";
        version2+=".n";
    stringstream ss1(version1);
    stringstream ss2(version2);
    string temp1, temp2;
  
  
    getline(ss1, temp1, '.');
     getline(ss2,temp2,'.');

    while ( temp1!="n" || temp2!="n" ) {
    
        if(temp1=="n"){
            while(temp2!="n"){
                int x = stoi(temp2);
                if (x!=0){return -1;}
                getline(ss2,temp2,'.');
            }
            return 0;
        }
        
        else if(temp2=="n"){
            while(temp1!="n"){
                int x = stoi(temp1);
                if (x!=0){return 1;}
                getline(ss1,temp1,'.');
            }
            return 0;
        }
        else{
           if(stoi(temp1)==stoi(temp2)){
                 getline(ss1, temp1, '.');
                getline(ss2,temp2,'.'); 
           }else if(stoi(temp1)>stoi(temp2)){
               return 1;
           }else if(stoi(temp2)>stoi(temp1)){
               return -1;
           }
     
        }
    }
  return 0;
        
    }
};