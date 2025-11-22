#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0)
                    h = mid - 2;
                else
                    l = mid + 1;
            } 
            else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0)
                    l = mid + 2;
                else
                    h = mid - 1;
            } 
            else {
                return nums[mid];
            }
        }

        return nums[l];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << sol.singleNonDuplicate(nums) << endl;
    return 0;
}
