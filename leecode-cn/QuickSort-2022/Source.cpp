#include <iostream>

using namespace std;

void quickSortInternal(int* arr, int segmentFromIndex, int segmentEndIndex)
{
	if (segmentFromIndex >= segmentEndIndex)
		return;

	int pivot = arr[segmentEndIndex];

	int left = segmentFromIndex;
	int right = segmentEndIndex - 1;

	while (left < right)
	{
		while (arr[left] < pivot && left < right)
			left++;

		while (arr[right] > pivot && left < right)
			right--;

		if (arr[left] > arr[right])
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			left++;
		}
	}

	int partionIndex = left;
	if (arr[left] > pivot)
	{
		int temp = arr[left];
		arr[left] = pivot;
		arr[segmentEndIndex] = temp;
	}
	else
		partionIndex = segmentEndIndex;


	quickSortInternal(arr, segmentFromIndex, partionIndex - 1);
	quickSortInternal(arr, partionIndex + 1, segmentEndIndex);

}


int* quicSort(int* arr, int length)
{
	quickSortInternal(arr, 0, length - 1);
	return arr;
}


int main()
{
	int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50 };
	int arrLength = sizeof(arr) / sizeof(int);
	quicSort(arr, arrLength);

	for (int i = 0; i < arrLength - 1; ++i)
	{
		cout << arr[i] << "->";
	}


	return 0;

}