#include<iostream>
#include<vector>
using namespace std;

//partition为一趟排序 寻找中心点位置
int partition(vector<int>& nums, int low, int high) {
	int key = nums[low];// 先将下限第一个元素作为中心点设为哨兵
	while (low < high) {
		while (low < high && nums[high] >= key) high--;// 右边查找 比中心点大的元素一律后放
		nums[low] = nums[high];// 比中心点小的元素一律前放
		while (low < high && nums[low] <= key) low++;// 左边查找 比中心点小的元素一律前放
		nums[high] = nums[low];// 比中心点大的元素一律后放
	}
	nums[low] = key;// 中心点元素最后插入至中心点处
	return low;// 返回中心点位置
}

void quickSort(vector<int>& nums, int low, int high) {// 快速排序
	if (low >= high) return;
	int keyloc = partition(nums, low, high);//一次排序，找中心点位置，keyloc将数据分成左右两个子数组
	quickSort(nums, low, keyloc - 1);// 对低位左数组递归快排
	quickSort(nums, keyloc + 1, high);// 对高位右数组递归快排
}

int main()
{
	vector<int> nums = {3, 5, 10, 16, 32, 23, 7, 4, 6};
	cout << "Before Sort: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	quickSort(nums, 0, nums.size() - 1);// 分别指向两端的数据
	cout << "After Sort: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}