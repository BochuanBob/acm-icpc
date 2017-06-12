#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double binomial(double n, double k) {
	if (k ==0 || k == n) {
		return 1.0;
	}
	return binomial(n-1, k-1) + binomial(n-1, k);
}

double calProb (double r, double s, double x, double y) {
	double probability = 0;
	double i;
	for (i = x; i <= y; i++) {
		probability += binomial(y, i) * pow((s-r+1.0)/s, i) * pow((r-1.0)/s, y-i);
	}
	return probability;
}

int main() {
	int n;
	double r, s, x, y, w;
	if (scanf("%d", &n) != 1) {
		return 0;
	}
	while (n--) {
		if (scanf("%lf %lf %lf %lf %lf", &r, &s, &x, &y, &w) != 5) {
			return 0;
		}
		if (calProb(r, s, x, y) > 1.0/(w)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
