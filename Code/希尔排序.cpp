#include<iostream>
#include<vector>
using namespace std;

void ShellInsert(vector<int>& nums, int dk) {
    for (int i = dk; i < nums.size(); i++) {// 从增量步长开始
        int key = nums[i];// 设置哨兵
        int j;
        for (j = i - dk; key < nums[j]; j = j - dk) {
            nums[j + dk] = nums[j];// 后移
        }
        nums[j + dk] = key;// 插入到正确位置 
    }
}

void ShellSort(vector<int>& nums) {
    int dk = nums.size() / 2;// 步长
    while (dk >= 1) {
        ShellInsert(nums, dk);
        dk /= 2;
    }
}

int main() {
    vector<int> nums = {3, 5, 10, 16, 32, 23, 7, 4, 6};
    cout << "Before Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    ShellSort(nums);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}