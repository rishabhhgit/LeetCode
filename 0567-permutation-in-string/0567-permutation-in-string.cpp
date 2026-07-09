class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        sort(s1.begin(),s1.end());
         
        vector<int>freqS1(26,0);
        vector<int>freqS2(26,0);
        
        for(int i=0;i<s1.size();i++){
            freqS1[s1[i]-'a']++;
        }
        
        int i=0;
        int j=0;

        while(j<s2.size()){
            freqS2[s2[j]-'a']++;

            while(j-i+1>s1.size()){
                freqS2[s2[i]-'a']--;
                i++;
            }
            if(freqS1==freqS2) return true;
            j++;
        }
        return false;
    }
};