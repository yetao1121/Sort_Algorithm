# C++实现十大排序算法

## 分类

![image-20220510095521806](C:\Users\Peach\AppData\Roaming\Typora\typora-user-images\image-20220510095521806.png)

## 各排序算法比较

<img width="1251" alt="表格" src="https://user-images.githubusercontent.com/66712995/120634062-6c406080-c49d-11eb-9be8-98e6bb62e4d1.png">

## ==插入排序==

- 基本思想：边插入边排序，保证子序列中随时都是排好序的。

- 按插入位置方法的不同分类：1)顺序法：直接插入排序  2)二分法：折半插入排序 3)缩小增量：希尔排序

### 直接插入排序

**原理**：从第二位数据开始， 当前数（第一趟是第二位数）与前面的数依次比较，如果前面的数大于当前数，则将这个数放在当前数的位置上，当前数的下标-1，直到当前数不大于前面的某一个数为止，直到遍历至最后一位元素。

```c++
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
```

### 折半插入排序

**原理**：采用二分法在直接插入排序基础上进行查找插入，**要求原数组有序！**

```c++
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
```

### 希尔排序

**原理**：希尔排序是插入排序改良的算法，是插入排序的一种更高效的改进版本，也称递减增量排序，但是非稳定排序算法。希尔排序步长从大到小调整，先将整个待排序记录序列分割成为若干子序列，分别进行直接插入排序，待整个序列中的记录基本有序时，再对全体记录进行一次直接插入排序。所以步长是关键，最终步长为1，做最后的排序。

```c++
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
```

## ==交换排序==

* 基本思想：两两交换，如果发生逆序则交换，直到所有记录都排好序为止

* 常见的交换排序方法：1) 冒泡排序 2) 快速排序

### 冒泡排序

**原理**：每趟不断将记录两两比较，并按“前小后大”或者“前大后小”规则交换。具体的说就是重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。把最小的数浮上来，或者把最大的数据沉下去。

```c++
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
```

### 快速排序

**原理**：任取一个元素(第一个)为中心点，所有比它小的元素一律前放，比它大的元素一律后放，形成左右两个子数组，对各子数组重新选择中心元素并依此规则调整，直到每个子数组的元素只剩一个。

```c++
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

```



## ==选择排序==

### 简单选择排序

**原理**：在待排序的数据中选出最小(大)的元素放在其最终的位置。这里以从小到大排序为例，具体操作是首先通过n-1次比较，从n个数中找出最小数，将它和第一个元素交换，然后通过n-2次比较，从剩余n-1个数中找最小数，将它和第二个数交换，重复上述过程，共进行n-1趟排序，排序结束。

```c++
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
```

### 堆排序

**原理**：分为两点，第一是堆排序，若在输出堆顶的最小值(最大值)后，使得剩余n-1个元素的序列重又建成一个堆，则得到n个元素的次小(大)值，如此反复，便能得到一个有序序列，这个过程称之为堆排序。第二是堆调整，以小根堆为例，输出堆顶元素之后，以堆中最后一个元素替代之，然后将根节点值与左右子树的根节点值进行比较，并与其中小者进行交换，重复上述步骤，直到叶子节点，将得到新的堆，称这个从堆顶到叶子的调整过程为“筛选”。

```c++
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
```



## ==归并排序==

原理：把待排序序列分为若干个子序列，每个子序列是有序的。然后再把有序子序列合并为整体有序序列。

```c++
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
```

## ==计数排序==

原理：当待排序的数的值都是在一定的范围内的整数时，可以用待排序的数作为计数数组的下标，统计每个数的个数，然后依次输出即可。

```c++
void countSort(vector<int>& nums){
    // 找出数组中的最大值
    int maxValue = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        maxValue = max(maxValue, nums[i]);
    }

    vector<int> count(maxValue + 1); // 开辟最大值+1的数组空间。
    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;// 开始计数 对应位置存放数组中元素的个数
    }
    
    int id = 0;
    // 更新原数组
    for (int i = 0; i <= maxValue; i++) {
        for (int j = 0; j < count[i]; j++) {// 个数
            nums[id++] = i;
        }
    }
}

```

## ==桶排序==

原理：将值为i的元素放入i号桶，最后依次把桶里的元素倒出来。具体的说是每个桶存储一定范围的元素，通过映射函数，将待排序数组中的元素映射到各个对应的桶中，对每个桶中的元素进行排序，最后将非空桶中的元素逐个放入原序列中。

```c++
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
```

## ==基数排序==

原理：设置若干个箱子，将关键字为k的记录放入第k个箱子(按照个位、十位、百位等的数字为关键字)，然后再按序号将非空箱子中的记录收集起来，循环往复直至排序完成。

```c++
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
```
