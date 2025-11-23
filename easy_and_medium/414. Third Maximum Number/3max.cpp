
class Solution
{
public:
  int thirdMax(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int i = nums.size();
    if (nums.size() < 3)
      return nums[i - 1];
    return nums[i - 3];
  }
};
