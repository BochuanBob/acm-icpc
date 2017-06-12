#include <stdio.h>
#include <stdlib.h>

int main() {
	long n, i;
	long pivot;
	if (scanf("%ld", &n) != 1) {
		return 0;
	}
	char greater[n];
	long arr[n];
	long count = 0;
	for (i = 0; i < n; i++) {
		if (scanf("%ld", &arr[i]) != 1) {
			return 0;
		}
		if (i == 0) {
			pivot = arr[i];
			greater[0] = 1;
		} else {
			if (pivot <= arr[i]) {
				greater[i] = 1;
				pivot = arr[i];
			} else {
				greater[i] = 0;
			}
		}
	}
	pivot = arr[n-1];
	if (greater[n-1] == 1) {
		count++;
	}
	for (i = n - 2; i >= 0; i--) {
		if (arr[i] < pivot) {
			if (greater[i] == 1) {
				count++;
			}
			pivot = arr[i];
		}
	}
	printf("%ld\n", count);
	return 0;
}