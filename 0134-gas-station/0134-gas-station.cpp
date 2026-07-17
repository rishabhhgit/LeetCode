class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost=0;
        int gasTotal=0;

        for(int i=0;i<gas.size();i++){
            gasTotal+=gas[i];
            totalCost+=cost[i];
        }

        if(totalCost>gasTotal) return -1;

        int ansIdx=-1;
        int currCost=0;

        int i=0;
        while(i<gas.size()){
            currCost=currCost+gas[i]-cost[i];
            if(currCost>0){
                ansIdx=i;
                i++;
                while(currCost>0 && i<gas.size()){
                    currCost=currCost+gas[i]-cost[i];
                    if(currCost<0) break;
                    i++;
                }
            }
            else{
                currCost=0;
                ansIdx=0;
                i++;
            } 
        }
        return ansIdx;
    }
};