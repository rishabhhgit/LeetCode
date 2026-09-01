class Solution {
public:
    //optimal
    int maxArea(vector<int>& height) {
        int maxi=0;
        int i=0;
        int j=height.size()-1;

        while(j>i){
            int currans=min(height[j],height[i])*(j-i);
            maxi=max(maxi,currans);
            if(height[i]>height[j]){
                j--;
            }
            else i++;
        }
        return maxi;
    }
};