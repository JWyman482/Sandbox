// Example program
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int firstNum = 0;
        int secondNum = 0;
        for (int num : nums) {
            if (num > target) continue;
            for (int i = num + 1; i < nums.size(); i++) {
                if (num + i == target) {
                    firstNum = num;
                    secondNum = i;
                    return vector<int> temp{ firstNum, secondNum };
                }
            }
        }
        return vector<int> temp{ firstNum, secondNum };
    }
};

int main()
{
    Solution s;
    vector<int> temp;
    vector<int> nums{ 2, 7, 11, 15 };

    temp = s.twoSum(nums, 9);
    temp[0] + temp[1] == 9 ? cout << "Success\n" : cout << "Failure\n";

}
