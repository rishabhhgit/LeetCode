#include <vector>
#include <queue>

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                pq.push(diff);
                
                if (pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                
                if (bricks < 0) {
                    return i;
                }
            }
        }
        
        return heights.size() - 1;
    }
};
