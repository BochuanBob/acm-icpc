#include <stdio.h>
#include <stdlib.h>

char inRange(double x, double x1, double x2) {
	if (x1 < x2) {
		if (x < x2 && x > x1) {
			return 1;
		}
		return 0;
	} else {
		if (x > x2 && x < x1) {
			return 1;
		}
		return 0;
	}
}

char isIntersect(double* line1, double* line2) {
	double k1 = (line1[3]-line1[1])/(line1[2]-line1[0]);
	double k2 = (line2[3]-line2[1])/(line2[2]-line2[0]);
	if (k2 == k1) {
		return 0;
	}
	double c1 = line1[1]-k1*line1[0];
	double c2 = line2[1]-k2*line2[0];
	double x = (c2-c1)/(k1-k2);
	if (inRange(x, line1[0], line1[2]) && inRange(x, line2[0], line2[2])) {
		return 1;
	}
	return 0;
}

int main() {
	int n;
	int i, j, k;
	int count;
	while(1) {
		count = 0;
		if (scanf("%d", &n) <= 0) {
			return 0;
		}
		double lines[n][4];
		char intersect[n][n];
		if (n == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			if (scanf("%lf %lf %lf %lf", &lines[i][0], &lines[i][1],
				&lines[i][2], &lines[i][3]) <= 0) {
				return 0;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				intersect[i][j] = isIntersect(lines[i], lines[j]);
			}
		}
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (intersect[i][j] == 1) {
					for (k = j + 1; k < n; k++) {
						if (intersect[i][k] == 1 && intersect[j][k] == 1) {
							count++;
						}
					}
				}
			}
		}
		printf("%d\n", count);
	}
}