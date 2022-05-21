#include <iostream>
#include <vector>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

void BinaryInsertSort(vector<int>& nums){
	for (int i = 1; i < nums.size(); i++) {// 从第二位开始
		int key = nums[i];// 设置哨兵
		int low = 0, high = i - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (key < nums[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		for (int j = i - 1; j >= high + 1; j--) {
			nums[j + 1] = nums[j];// 后移
		}
		nums[high + 1] = key;// 插入到正确位置 
	}
}

int main() {
	vector<int> nums = {3, 5, 10, 16, 32, 23, 7, 4, 6};
	cout << "Before Sort: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	BinaryInsertSort(nums);
	cout << "After Sort: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}