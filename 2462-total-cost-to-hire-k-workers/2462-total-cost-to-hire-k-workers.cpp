class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> leftMinHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;

        int i = 0;
        int j = costs.size() - 1;
        long long totalCost = 0;

        while (k--) {
            while (leftMinHeap.size() < candidates && i <= j) {
                leftMinHeap.push(costs[i]);
                i++;
            }
            while (rightMinHeap.size() < candidates && j >= i) {
                rightMinHeap.push(costs[j]);
                j--;
            }

            if (leftMinHeap.empty()) {
                totalCost += rightMinHeap.top();
                rightMinHeap.pop();
            } 
            else if (rightMinHeap.empty()) {
                totalCost += leftMinHeap.top();
                leftMinHeap.pop();
            } 
            else if (leftMinHeap.top() <= rightMinHeap.top()) {
                totalCost += leftMinHeap.top();
                leftMinHeap.pop();
            }
            else {
                totalCost += rightMinHeap.top();
                rightMinHeap.pop();
            }
        }
        return totalCost;
    }
};