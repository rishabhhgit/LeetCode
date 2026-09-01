class Solution {
public:
    int trailingZeroes(int n) {
        unsigned long long count=0;
        for(unsigned long long i=5; i<=n; i*=5){
            count+=n/i;
        }
        return count;
    }
};