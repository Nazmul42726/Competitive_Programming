class Solution {
public:
    int firstIndex(vector<int>& nums, int target){
        int l=0,r=(int)(nums.size())-1;
        if(r==-1) return -1;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if(nums[l]==target) return l;
        if(nums[r]==target) return r;
        return -1;

    }
    int lastIndex(vector<int>& nums, int target){
        int l=0,r=(int)(nums.size())-1;
        if(r==-1) return -1;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        if(nums[r]==target) return r;
        if(nums[l]==target) return l;
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0]=firstIndex(nums,target);
        res[1]=lastIndex(nums,target);
        return res;
    }
};