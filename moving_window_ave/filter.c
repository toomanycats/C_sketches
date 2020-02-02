#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define A (0.25)
#define CONST 5.0
#define TIME 4096
#define BSIZE 256
#define WEIGHT (BSIZE * 1.0)
#define Freq (1000.0)
#define T (1.0 / Freq)
#define PI (3.1415)

void set_time_vector(float* ptest_time){

    int part = TIME / 4;

    int j;
    for (j=0; j < part; j++)
        *(ptest_time+j) = 0;

    int i;
    for (i=0, j=part; j <= 3*part; j++, i++)
        *(ptest_time+j) = 0.01 * T * i;

    for (j=3*part; j < TIME; j++)
        *(ptest_time+j) = 0;
}

void zero_buffer(float* buff){
	int j;
	for (j=0; j < BSIZE; j++)
		*(buff+j) = 0;
}

int main(){
	int head = 0, tail = BSIZE, test_counter = 0;
	double ave = 0;
	float buff[BSIZE];
    float test_time[TIME];

    zero_buffer(buff);
    set_time_vector(test_time);

	while(test_counter < TIME){
		buff[head] = A * sinf(2 * PI * Freq * test_time[test_counter]) + CONST;

		ave = ave + (buff[head]-ave) / WEIGHT - (buff[tail]-ave) / WEIGHT;

		printf("%f,%f\n", buff[head], ave);

		head++;
		head = (uint8_t)head;  // wrap head around 256 values
		tail = (uint8_t)(head + 1);
        test_counter++;
	}
return 0;
}
