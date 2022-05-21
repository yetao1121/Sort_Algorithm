#include<iostream>
#include<vector>
using namespace std;
 
// 求数据的最大位数,决定排序次数
int maxbit(vector<int>& nums, int n) {
    int t = 1; // 保存最大的位数
    int m = 10;
    for (int i = 0; i < n; i++) {
        while (nums[i] >= m) {
            m *= 10;
            ++t;
        }
    }
    return t;
}

//基数排序
void radixSort(vector<int>& nums, int n) {
    int t = maxbit(nums, n);// 确定最大位数即排序次数
    vector<int> temp(n);// 创建容纳这n个数的临时数组
    vector<int> count(10); // 计数器 统计每个记录数出现的次数
    int i, j, k;
    int radix = 1;// 位数的权重
    for (i = 1; i <= t; i++) {// 进行t次排序
        for (j = 0; j < 10; j++) {
            count[j] = 0; // 每次分配前清空计数器
        }
        for (j = 0; j < n; j++) {// 统计每个桶中的记录数
            k = (nums[j] / radix) % 10; 
            count[k]++;
        }
        for (j = 1; j < 10; j++) {
            count[j] = count[j - 1] + count[j]; // 将temp中的位置依次分配给每个桶
        }
        for (j = n - 1; j >= 0; j--) {// 将所有桶中记录依次收集到temp中
            k = (nums[j] / radix) % 10;
            temp[count[k] - 1] = nums[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) {// 将临时数组的内容赋给原数组
            nums[j] = temp[j];
        }
        radix = radix * 10;
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
    radixSort(nums, 9);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}