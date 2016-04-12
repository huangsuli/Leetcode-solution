class Solution {
public:
    bool isStrobogrammatic(string num) {
        std::map<char,char> smap;
        std::map<char,char>::iterator it1;
        std::map<char,char>::iterator it2;
        
        smap['0'] = '0';
        smap['1'] = '1';
        smap['6'] = '9';
        smap['8'] = '8';
        smap['9'] = '6';
        
        int length = num.length() - 1;
        int i = 0;
        
        while(i <= length){
            it1 = smap.find(num.at(i));
            it2 = smap.find(num.at(length));
            if(it1 == smap.end() || it2 == smap.end()) return false;
            if(it1->second != num.at(length) ) return false;
            i ++;
            length --;
        }
        return true;
    }
};