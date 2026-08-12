class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++) {
            factorial *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k--;
        string ans = "";
        while (true) {
            ans += to_string(numbers[k / factorial]);
            numbers.erase(numbers.begin() + k / factorial);
            if (numbers.empty()) {
                break;
            }
            k %= factorial;
            factorial /= numbers.size();
        }
        return ans;
    }
};