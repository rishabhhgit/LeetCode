class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int currNumberOf1s=0;
        int currNumberOf0s=0;

        int i=0;
        int j=0;
        int maxi=0;
        int ans=0;
        while(j<s.size()){

            if(s[j]=='1') currNumberOf1s++;
            if(s[j]=='0') currNumberOf0s++;

            while(currNumberOf1s>k && currNumberOf0s>k){
                if(s[i]=='1'){
                    currNumberOf1s--;
                }
                else{
                    currNumberOf0s--;
                }
                i++;
            }
            ans+=j-i+1;
            maxi=max(maxi,ans);
            j++;
        }

        return maxi;
    }
};