

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int low = 0, high = size-1, mid = 0;
        while(low < high){
            mid = low + (high - low) / 2;
            //如果中值大于右值，那么最小值肯定在右边
            if(nums[mid] > nums[high]) 
                low = mid + 1;
            //如果中值小于右值，那么最小值肯定在左边
            else if(nums[mid] < nums[high])
                high = mid;
        }
        return nums[low];
    }
};
