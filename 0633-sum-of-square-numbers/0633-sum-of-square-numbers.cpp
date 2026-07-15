class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long i=0;
        long long j=sqrt(c);

        while(j>=i){
            long long ans=((i*i)+(j*j))*1LL;
            if(ans==c) return true;

            if(ans>c){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};