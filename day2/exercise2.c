#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){

    printf("%d\n", argc);


    if(argc != 2) return -1; // use first arg of program as file to search, assuming I will pass the correct filename later

    size_t size = 0;

    FILE* input = fopen(argv[1], "r");


    char* buf = malloc(128);

    // we know what numbers to check, trivial to solve in O(n²)
    long lower_bound, upper_bound;

    long invalid_sum = 0;

    while(getdelim(&buf, &size, ',', input) != -1) {
        sscanf(buf, "%ld-%ld", &lower_bound, &upper_bound);
        printf("%ld - %ld\n", lower_bound, upper_bound);

        int i = 0; long ii = 0;

        while (ii < upper_bound){
            sprintf(buf, "%d%d", i, i);
            ii = atol(buf);

            i++;
            printf("%d - %ld\r", i, ii);

            if ((ii < lower_bound) ||(ii > upper_bound)) continue;
            invalid_sum += ii;
            
        }

    }


    fclose(input);
    printf("%ld\n", invalid_sum);

    return 0;
}