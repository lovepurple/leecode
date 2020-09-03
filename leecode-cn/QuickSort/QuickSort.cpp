/**
 * 快速排序
 */
#include <iostream>

void quickSort(int* arr, int low, int high);

void quickSortAsc(int* arr, int low, int high);

int partition(int* arr, int low, int high);

int main()
{
	//int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50 };
	int arr[] = { 1,2,3,4,5,6,7,7,8,9 };
	int arrSize = sizeof(arr) / sizeof(int);

	//quickSort(arr, 0, arrSize - 1);
	quickSortAsc(arr, 0, arrSize - 1);

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << std::endl;
	}

	return 0;
}

void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}


}

void quickSortAsc(int* arr, int low, int high)
{
	if (low >= high)
		return;

	int pivot = arr[low];
	int left = low + 1;
	int right = high;

	while (left < right)
	{
		while (pivot > arr[right] && left < right)
			right--;

		while (pivot < arr[left] && left < right)			//每次用left<right控制 以防最后一次left++ 越界
			left++;

		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	int partionIndex = left;
	if (pivot < arr[partionIndex])
	{
		int temp = arr[partionIndex];
		arr[partionIndex] = arr[low];
		arr[low] = temp;
	}
	else
		partionIndex = low;

	quickSortAsc(arr, low, partionIndex - 1);
	quickSortAsc(arr, partionIndex + 1, high);
}

//分割函数
int partition(int* arr, int low, int high)
{
	if (high - low > 0)
	{
		int pivot = arr[low];

		int i = low + 1;
		int j = high;

		while (i < j)
		{
			while (arr[j] > pivot && i < j)
				j--;

			while (arr[i] < pivot && i < j)
				i++;

			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j--;
		}

		if (arr[i] < pivot)
		{
			int temp = arr[i];
			arr[i] = pivot;
			arr[low] = temp;

			return i;
		}
		else
		{
			return low;
		}
	}

	return -1;
}

void PrintArr(int* arr, int arrLength)
{
}
