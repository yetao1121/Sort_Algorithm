#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countSort(vector<int>& nums){
    // 找出数组中的最大值
    int maxValue = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        maxValue = max(maxValue, nums[i]);
    }

    vector<int> count(maxValue + 1); // 开辟最大值+1的数组空间。
    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;// 开始计数 对应位置存放数组中元素的个数
    }
    
    int id = 0;
    // 更新原数组
    for (int i = 0; i <= maxValue; i++) {
        for (int j = 0; j < count[i]; j++) {// 个数
            nums[id++] = i;
        }
    }
}

int main()
{
    vector<int> nums = {3, 5, 10, 16, 32, 23, 7, 4, 6};
    cout << "Before Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    countSort(nums);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}