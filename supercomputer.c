#include <stdio.h>
#include <stdlib.h>

long getRange(long left, long right, long* s, long n) {
	long count = 0;
	left += n;
	right += n;
	while(left < right) {
		if (left % 2 == 1) {
			count += s[left];
			left++;
		}
		if (right % 2 == 1) {
			right--;
			count += s[right];
		}
		left = left / 2;
		right = right / 2;
	}
	return count;
}

int main() {
	long n, k;
	long i;
	char c[10];
	long index;
	long s[2000002];
	long left, right;
	for (i = 0; i < 2000002; i++) {
		s[i] = 0;
	}
	if (scanf("%ld %ld", &n, &k) <= 0) {
		return 0;
	}
	for (i = 0; i < k; i++) {
		if (scanf("%s ", c) <= 0) {
			return 0;
		}
		if (c[0] == 'F') {
			if (scanf("%ld\n", &index) <= 0) {
				return 0;
			}
			index = index + n;
			s[index] = s[index] ^ 1;
			while(index > 1) {
				index /= 2;
				s[index] =s[2*index] + s[2*index+1];
			}
		} else {
			if (scanf("%ld %ld", &left, &right) <= 0) {
				return 0;
			}
			printf("%ld\n", getRange(left, right+1, s, n));
		}
	}
	return 0;
}
