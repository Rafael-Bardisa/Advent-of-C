#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define RACK_LEN 100


//quick look at input data suggests long should be enough size
long concatenate_long(long x, long y){
    long digit = 10;
    while(y >= digit) digit *= 10;
    return x * digit + y;
}


int main(int argc, char* argv[]){

    printf("%d\n", argc);


    if(argc != 2) return -1; // use first arg of program as file to search, assuming I will pass the correct filename later

    size_t size = 0;

    FILE* input = fopen(argv[1], "r");


    char* buf = calloc(128, sizeof(char));

    int battery_line[RACK_LEN];

    long long voltage = 0;

    


    while(getline(&buf, &size, input) != -1) {
        for(int i = 0; i < RACK_LEN; i++){
            battery_line[i] = buf[i] -'0';
            printf("%d", battery_line[i]);
        }
        

        // find the earliest maximum number in the above sequence digits times for the maximum number
        int left_index = -1;
        long long line_voltage = 0;
        for(int digits = 12; digits > 0; digits--){
            int val = 0;
            for (int i = left_index +1; i <= (RACK_LEN - digits); i++){
                if (battery_line[i] > val){
                    val = battery_line[i];
                    left_index = i;
                }
            }
            line_voltage += val * pow(10, digits -1);
        }
        printf(" -> %lld\n", line_voltage);
        voltage += line_voltage;

    }


    fclose(input);

    free(buf);
    printf("\n<%lld>\n", voltage);

    return 0;
}