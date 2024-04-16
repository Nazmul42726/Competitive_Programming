class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(right-left>1){
            int mid=left+(right-left)/2;
            if(nums[mid]<=target)
                left=mid;
            else
                right=mid-1;
        }
        if(nums[right]<target)
            return right+1;
        else if(nums[left]<target)
            return left+1;
        else
            return left;
    }
};