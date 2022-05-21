#include<iostream>
#include<vector>
using namespace std;

void selectSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {// 趟数 n-1次比较
        int minIndex = i;// 记录最小索引
        for (int j = i + 1; j < nums.size(); j++) {// 每趟
            if (nums[j] < nums[minIndex]) {// 寻找最小值
                minIndex = j;// 记录最小值位置
            }
        }
        if (minIndex != i) { // 每趟遍历完发现最小值位置不在一开始记录的位置
            swap(nums[minIndex], nums[i]);// 交换最小值与一开始设置最小值的元素
            /*
            int temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
            */
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
    selectSort(nums);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}