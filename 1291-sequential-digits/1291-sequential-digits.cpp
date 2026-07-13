class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits ="123456789";
        vector<int>ans;
        for(int len=2;len<10;len++){
            int i=0;
            int j=0;

            while(j<digits.size()){
                if(j-i+1==len){
                    string s=digits.substr(i,len);
                    int num_s=stoi(s);
                    if(num_s>=low && num_s<=high){
                        ans.push_back(num_s);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};