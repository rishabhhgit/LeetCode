class Solution {
public:
    int minPartitions(string n) {
        int ans=0;

        for ( char ch : n){
            int num = (ch - '0');
            if(num>ans) ans = num;
        }
        return ans;
    }
};