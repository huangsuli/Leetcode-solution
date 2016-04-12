class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int high = nums.size()-1;
    int low = 1;
    int medium = 0;
    
    
    while(low < high){
        medium = (low + high)/2;
        cout<<medium<<'\n';
        int counter = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <= medium){
                counter ++;
            }

        }
        if(counter > medium){
            high = medium;
        }
        else{
            low = medium+1;
        }
    }
    return low;
    }
};