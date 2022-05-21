#include<iostream>
#include<vector>
using namespace std;

void InsertSort(vector<int>& nums){
    for (int i = 1; i < nums.size(); i++) {// 从第二位开始
        if (nums[i] < nums[i - 1]) {// 若第i个元素大于第i-1个元素，则直接插入。反之，需要移动有序表后插入
            int key = nums[i];// 设置哨兵
            int j;
            for (j = i - 1; key < nums[j]; j--) {//每次都和基准key比较，最小值往前插
                nums[j + 1] = nums[j];//后移
            }
            nums[j + 1] = key;// 插入到正确位置
        }
    }
}

int main() {
    vector<int> nums = {3, 5, 10, 16, 32, 23, 7, 4, 6};
    cout << "Before Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    InsertSort(nums);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}