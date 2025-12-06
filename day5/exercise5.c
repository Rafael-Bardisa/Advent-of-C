#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ARRAY_LEN 200


int main(int argc, char* argv[]){

    printf("%d\n", argc);


    if(argc != 2) return -1; // use first arg of program as file to search, assuming I will pass the correct filename later

    size_t size = 0;

    FILE* input = fopen(argv[1], "r");


    char* buf = calloc(200, sizeof(int));

    long long ** spoiled_list = calloc(ARRAY_LEN, sizeof(long long *));

    int true_list_size = 0;
    

    for(int i = 0; getline(&buf, &size, input) != -1; i++) {
        if (buf[0] == '\n') break;
        spoiled_list[i] = calloc(2, sizeof(long long));
        sscanf(buf, "%llu-%llu", &spoiled_list[i][0], &spoiled_list[i][1]);
        printf("%llu-%llu\n", spoiled_list[i][0], spoiled_list[i][1]);
        true_list_size++;
    }

    printf("\n<%u>\n", true_list_size);

    long long ingredient;
    int result = 0;

    for(int i = 0; getline(&buf, &size, input) != -1; i++) {
        sscanf(buf, "%llu", &ingredient);
        printf("%llu <- %s", ingredient, buf);

        for (int j=0; j < true_list_size; j++){
            printf("%u\r", j);
            if ((ingredient >= spoiled_list[j][0]) && (ingredient <= spoiled_list[j][1])){
                result++;
                break;
            }
        }
        printf("\n");
    }

    for(int i = 0; i < true_list_size; i++){
        free(spoiled_list[i]);
    }
    free(spoiled_list);

    fclose(input);

    free(buf);
    printf("\n<%u>\033[0m\n", result);

    return 0;
}