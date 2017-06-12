#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getCurrentTime(double* currentTime, char* line) {
	int hour, min, sec;
	hour = (line[1]-'0') + (line[0]-'0')*10;
	min = (line[4]-'0') + (line[3]-'0')*10;
	sec = (line[7]-'0') + (line[6]-'0')*10;
	*currentTime = hour*1.0 + min*1.0/60 + (sec-1)*1.0/3600;
}

int main () {
	int hour, min, sec;
	double currentTime, lastTime = 0.0;
	int speed = 0;
	double dist = 0;
	char input[200];
	char time[20];
	while (1) {
		if(fgets(input, 200, stdin) == NULL) {
			return 0;
		}
		if (strlen(input) < 8) {
			return 0;
		}
		getCurrentTime(&currentTime, input);
		dist = dist + (currentTime-lastTime) * speed;
		lastTime = currentTime;
		if (strlen(input) > 9) {
			sscanf(input, "%s %d", time, &speed);
		} else {
			input[8] = '\0';
			printf("%s %.2lf km\n",input, dist);
		}
	}
}