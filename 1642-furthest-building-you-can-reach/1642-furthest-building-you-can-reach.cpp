class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        priority_queue<int>maxHeap;
        int i=0;
        while(i<nums.size()-1){
            int diff=nums[i+1]-nums[i];
            if(diff>0){
                if(bricks>=diff){
                    bricks-=diff;
                    maxHeap.push(diff);
                }
                else if(ladders>0 && !maxHeap.empty()){
                    int currTop=maxHeap.top();
                    if(currTop>=diff){
                        bricks+=currTop;
                        bricks-=diff;
                        maxHeap.pop();
                        maxHeap.push(diff);
                        ladders--;
                    }
                    else if(ladders>0){
                        ladders--;
                    }
                }
                else if(ladders>0){
                    ladders--;
                }
                else break;
            }
            i++;
        }
        return i;
    }
};