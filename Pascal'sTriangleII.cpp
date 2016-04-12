class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascalarray(rowIndex+1, 0);
        pascalarray[0] = 1;
        
        for(int i = 1; i < rowIndex+1; i++){
            for(int j = i; j > 0; j-- ){
                pascalarray[j] = pascalarray[j] + pascalarray[j-1];
            }
        }
        return pascalarray;
    }
};