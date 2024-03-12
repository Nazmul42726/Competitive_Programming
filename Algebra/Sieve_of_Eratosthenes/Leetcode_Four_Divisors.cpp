class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            set<int> a;
            for(int j=1; j*j<=nums[i]; j++){
                if(nums[i]%j==0){
                    a.insert(j);
                    a.insert(nums[i]/j);
                }
            }
            if(a.size()==4){
                for(auto it:a){
                    ans+=it;
                }
            }
        }
        return ans;
    }
};