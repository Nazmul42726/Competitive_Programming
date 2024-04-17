class Solution {
public:
    bool isPerfectSquare(int num) {
        long long n=num;
        long long left=1,right=n;
        while(right-left>1){
            long long mid=left+(right-left)/2;
            long long sqMid=mid*mid;
            if(sqMid<n) left=mid+1;
            else right=mid;
        }
        return (left*left==n or right*right==n);
    }
};