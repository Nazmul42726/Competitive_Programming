class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(target==nums[mid]) return mid;
            if(target<nums[mid]){
                if(target<nums[0] and nums[mid]>nums[0])
                    l=mid+1;
                else r=mid-1;
            }
            else{
                if(target<nums[0] and nums[mid]<nums[0])
                    l=mid+1;
                else if(target>nums[0] and nums[mid]>nums[0])
                    l=mid+1;
                else r=mid-1;
            }
        }
        if(nums[l]==target) return l;
        else if(nums[r]==target) return r;
        return -1;
    }
};