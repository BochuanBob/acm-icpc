#include <stdio.h>
#include <stdlib.h>
typedef struct {
	long win;
	long lose;
} Player;

void calWin(Player* players, int x, int y, char* move1, char* move2) {
	if (move1[0] == move2[0]) {
		return;
	}
	if ((move1[0] == 'r' && move2[0] == 's') ||
		(move1[0] == 'p' && move2[0] == 'r') ||
		(move1[0] == 's' && move2[0] == 'p')) {
		players[x].win++;
		players[y].lose++;
	} else {
		players[y].win++;
		players[x].lose++;
	}
}

int main() {
	long n = 0, k;
	long i;
	int x, y;
	char move1[10], move2[10];
	while(1) {
		if (n != 0) {
			printf("\n");
		}
		if (scanf("%ld", &n) != 1) {
			return 0;
		}
		if (n == 0) {
			return 0;
		}
		if (scanf("%ld", &k) != 1) {
			return 0;
		}
		Player players[n];
		for(i = 0; i < n; i++) {
			players[i].win = 0;
			players[i].lose = 0;
		}
		for (i = 0; i < k*n*(n-1)/2; i++) {
			if (scanf("%d %s %d %s", &x, move1, &y, move2) != 4) {
				return 0;
			}
			calWin(players, x-1, y-1, move1, move2);
		}
		for (i = 0; i < n; i++) {
			if (players[i].win == 0 && players[i].lose == 0) {
				printf("-\n");
			} else {
				printf("%.3lf\n", ((double) players[i].win)/((double)(players[i].win+players[i].lose)));
			}
		}
	}
}
