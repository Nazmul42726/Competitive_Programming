// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int n){
        int left=1,right=n;
        while(right-left>1){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)) right=mid;
            else left=mid+1;
        }
        if(isBadVersion(left)) return left;
        return right;
    }
    int firstBadVersion(int n) {
        return binarySearch(n);
    }
};