#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Return the maximum sum of any contiguous subarray of length k.
    // Convention for this file: if k <= 0 or k > nums.size(), return 0.
    int maxSumSubarray(vector<int>& nums, int k) {
        if(k > nums.size() || k == 0)  
            return 0; 
            int answer = INT_MIN; 
            for(int i = 0; i <= nums.size() - k; i++){
                int sum = 0; 
                for(int j = 0; j < k; j++){
                    if(i + j < nums.size())
                sum += nums[i + j];  
                }
            answer = max(sum, answer);
            }

        return answer; 
    }
};

// ---------------- test harness (no need to edit below) ----------------

struct TestCase {
    string name;
    vector<int> nums;
    int k;
    int expected;
};

int main() {
    vector<TestCase> tests = {
        {"basic example",            {2, 1, 5, 1, 3, 2},  3, 9},
        {"window of 2",              {2, 3, 4, 1, 5},     2, 7},
        {"best window in middle",    {3, -2, 7, -1, 4},   2, 6},
        {"all negative",             {-1, -2, -3, -4},    2, -3},
        {"k = 1 picks max element",  {4, -1, 2, 1},       1, 4},
        {"k = n uses whole array",   {1, 2, 3},           3, 6},
        {"single element",           {5},                 1, 5},
        {"best window at the end",   {1, 1, 1, 10, 10},   2, 20},
        {"best window at the start", {10, 10, 1, 1, 1},   2, 20},
        {"k larger than array",      {1, 2},              3, 0},
    };

    Solution sol;
    int passed = 0;
    for (auto& t : tests) {
        vector<int> input = t.nums;
        int got = sol.maxSumSubarray(input, t.k);
        bool ok = (got == t.expected);
        if (ok) passed++;
        cout << (ok ? "[PASS] " : "[FAIL] ") << t.name
             << "  (k=" << t.k << ", expected " << t.expected
             << ", got " << got << ")\n";
    }
    cout << "\n" << passed << " / " << tests.size() << " passed\n";
    return 0;
}