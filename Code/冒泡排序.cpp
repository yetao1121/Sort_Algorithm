#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& nums) {// 假设nums有n个元素
	for (int m = 1; m <= nums.size() - 1; m++) {// n个记录需要总共需要n - 1趟
		for (int j = 0; j < nums.size() - m; j++) {// 每趟需要比较n - m次
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				/*
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				*/
			}
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
	bubbleSort(nums);
	cout << "After Sort: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}