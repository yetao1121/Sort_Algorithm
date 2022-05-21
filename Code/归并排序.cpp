#include<iostream>
#include<vector>
using namespace std;

// 将两个已经排序好的序列[low, mid]和[mid + 1, high]归并到临时数组temp中
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp(high - low + 1);// 开辟临时数组
    int m = high - low;// 临时数组的最后一个元素下标
    int i = mid, j = high;// 从2个序列的末尾开始遍历
    while (i >= low && j >= mid + 1) {
        if (nums[i] > nums[j]) temp[m--] = nums[i--];// nums[i]是剩余元素的最大值
        else temp[m--] = nums[j--];// nums[j]是剩余元素的最大值
    }
    while (i >= low) temp[m--] = nums[i--];// 剩余元素直接放入
    while (j >= mid + 1) temp[m--] = nums[j--];// 剩余元素直接放入
    for(int k = low; k <= high; k++) {// 将临时数组元素全部赋给相应的原数组
        nums[k] = temp[k - low];
    }
}

void mergeSort(vector<int>& nums, int low, int high){
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);// 分割
    mergeSort(nums, mid + 1, high);// 分割
    merge(nums, low, mid, high);// 排序
}

int main()
{
    vector<int> nums = {3, 5, 10, 16, 32, 23, 7, 4, 6};
    cout << "Before Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    mergeSort(nums, 0, nums.size() - 1);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}