
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
       ostringstream out;
        string s;
        for(int i=0;i<strs.size();i++){
           out<<strs[i]<<"\t";
        }
        return out.str();
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        istringstream ss(s);
        vector<string> out;
        string temp;
       
    
       while(std::getline(ss, temp, '\t')) {
            out.push_back(temp);
        }
        return out;
        
        
    }
};

// // Encodes a list of strings to a single string.
// string encode(vector<string>& strs) {
//     ostringstream out;
    
//     for ( auto str : strs) {
//         out << str << "\t";
//     }
    
//     return out.str();
// }

// // Decodes a single string to a list of strings.
// vector<string> decode(string s) {
//     istringstream in(s);
//     std::vector<string> vec;
//     string token;
//     while(std::getline(in, token, '\t')) {
//         vec.push_back(token);
        
//     }
    
//     return vec;
// }

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));