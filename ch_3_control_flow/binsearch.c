#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
	int arr[6] = {2, 3, 4, 2, 7, 6};
	printf("Index is %d\n", binsearch(4, arr, 6));
	return 0;
}

int binsearch(int x, int v[], int n) {
	int start, mid, end;

	start = 0;
	end = n - 1;
	mid = (start + end) / 2;
	while (start < end && v[mid] != x) {
		if (x > v[mid]) 
			start = mid + 1;
		else 
			end = mid - 1;
		mid = (start + end) / 2;
	}
	return x == v[mid] ? mid : -1;
}