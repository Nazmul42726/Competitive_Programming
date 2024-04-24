class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums.size()==2) return nums[0]>nums[1]?0:1;
        int l=0,r=nums.size()-1;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[mid-1])
                l=mid;
            else
                r=mid-1;
        }
        if(l==0 and nums[l]>nums[l+1]) return l;
        else if(l and nums[l-1]<nums[l] and nums[l]>nums[l+1]) return l;
        return r;
    }
};