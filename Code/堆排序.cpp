#include<iostream>
#include<vector>
using namespace std;

// 堆调整：（最大堆，有序区）。从堆顶把根卸出来放在有序区之前，再恢复堆。
void heapAdjust(vector<int>& nums, int start, int end){
    int dad = start, son = dad * 2 + 1;// 建立父节点下标和子节点下标 父节点下标从0开始
    while (son <= end) {// 若子节点在范围内才做比较
        if (son + 1 <= end && nums[son] < nums[son + 1]) son++;// 先比较两个子节点值，选择最大的
        if (nums[dad] > nums[son]) {// 如果父节点大于子节点代表调整完成，直接跳出函数
            return;
        } else {// 否则交换父子內容再继续子节点与孙节点比較
            swap(nums[dad], nums[son]);
            /*
            int temp = nums[dad];
            nums[dad] = nums[son];
            nums[son] = temp;
            */
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

// 堆排序
void heapSort(vector<int>& nums){
    // 初始建堆,从最后一个非叶子节点(父节点)开始，左半边为非叶子节点，右半边为叶子节点。
    for (int i = nums.size() / 2 - 1; i >= 0; i--) {
        heapAdjust(nums, i, nums.size() - 1);
    }
    // 取堆顶，并且调整
    for (int i = nums.size() - 1; i > 0 ; i--){
        swap(nums[0], nums[i]);// 把堆顶元素交换至后面。
        heapAdjust(nums, 0, i - 1);// 对剩下的元素进行排序
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
    heapSort(nums);
    cout << "After Sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}