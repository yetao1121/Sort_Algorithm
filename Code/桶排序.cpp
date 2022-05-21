#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucketSort(vector<int>& nums) {
    // 计算最大值与最小值
    int maxValue = INT_MIN;
    int minValue = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        maxValue = max(maxValue, nums[i]);
        minValue = min(minValue, nums[i]);
    }
    
    // 计算桶的数量
    int bucketNum = (maxValue - minValue) / nums.size() + 1;
    vector<vector<int>> bucketArr(bucketNum);// 分配桶
    
    // 将每个元素放入桶
    for (int i = 0; i < nums.size(); i++) {
        int num = (nums[i] - minValue) / (nums.size());
        bucketArr[num].push_back(nums[i]);
    }
    
    // 对每个桶进行排序
    for (int i = 0; i < bucketArr.size(); i++) {
        sort(bucketArr[i].begin(), bucketArr[i].end());
    }
    
    // 将桶中的元素赋给原数组
    nums.clear(); // 清空原数组
    for (int i = 0; i < bucketArr.size(); i++) {
        for (int j = 0; j < bucketArr[i].size(); j++) {
            nums.push_back(bucketArr[i][j]);
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
    bucketSort(nums);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}