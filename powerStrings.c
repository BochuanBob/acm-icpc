#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long min(long a, long b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

void z_algorithm(char *s, long *Z, long length) {
	long L = 0, R = 0;
	long i;
	for (i = 1; i < length; ++i) {
		if (i > R) {
			L = R = i;
			while (R < length && s[R - L] == s[R]) { 
				R++;
			}
			Z[i] = R - L; 
			R--;
		} else if (Z[i - L] >= R - i + 1) {
			L = i;
			while (R < length && s[R - L] == s[R]){ 
				R++;
			}
			Z[i] = R - L;
			R--;
		} else {
			Z[i] = Z[i - L];
		}
	}
}

int main() {
	char s[2000005];
	long length;
	char isPow;
	long L;
	long cL;
	long i;
	while(1) {
		isPow = 0;
		if (scanf("%s", s) <= 0) {
			return 0;
		}
		length = strlen(s);
		if (s[0] == '.' && length == 1) {
			return 0;
		}
		long Z[length];
		for (i = 0; i < length; i++) {
			Z[i] = -1;
		}
		z_algorithm(s, Z, length);
		for (L = 1; L <= length; L++) {
			if (length % L != 0){
				continue;
			}
			isPow = 1;
			for (cL = L; isPow && cL < length; cL *= 2) {
				isPow = isPow && (cL + Z[cL] >= min(2 * cL, length));
			}
			if (isPow) {
				printf("%ld\n", length/L);
				break;
			}
		}
		if (!isPow) {
			printf("1\n");
		}
	}
}
