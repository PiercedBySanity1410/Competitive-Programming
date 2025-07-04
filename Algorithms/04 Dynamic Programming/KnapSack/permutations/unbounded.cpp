#include <iostream>
#include <vector>
using namespace std;

unsigned long long countOrderedCombinations(vector<int>& nums, int target) {
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1; // One way to make sum 0

    for (int i = 1; i <= target; ++i) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;

    cout << "Number of ordered combinations to make " << target << " = "
         << countOrderedCombinations(nums, target) << endl;

    return 0;
}
