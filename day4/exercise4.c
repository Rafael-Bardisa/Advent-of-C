#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define WIDTH 135
#define HEIGHT 135


int has_paper(int** floor, int col_index, int row_index){
    if ((col_index < 0) || (col_index >= HEIGHT)) return 0;
    if ((row_index < 0) || (row_index >= WIDTH)) return 0;
    return floor[col_index][row_index];
}


int removable(int** floor, int col_index, int row_index){
    int papers = 0;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if (!i && !j) continue;
            papers += has_paper(floor, col_index+i, row_index+j);
        }
    }
    return (papers < 4) ? 1 : 0;
}


int main(int argc, char* argv[]){

    printf("%d\n", argc);


    if(argc != 2) return -1; // use first arg of program as file to search, assuming I will pass the correct filename later

    size_t size = 0;

    FILE* input = fopen(argv[1], "r");


    char* buf = calloc(200, sizeof(int));

    int** floor = calloc(HEIGHT, sizeof(int*));

    long long voltage = 0;

    

    for(int i = 0; getline(&buf, &size, input) != -1; i++) {
        floor[i] = calloc(WIDTH, sizeof(int));
        for(int j = 0; j < WIDTH; j++){
            floor[i][j] = buf[j] == '@' ? 1 : 0;
        }
    }

    int result = 0; int old_result = -1;

    while(result != old_result){
        old_result = result;
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                int can_be_removed = removable(floor, i, j);
                printf("%s", can_be_removed ? "\033[94m" : "\033[0m");
                printf("%c", floor[i][j] ? can_be_removed ? '%':'X': '.');
                result += can_be_removed && floor[i][j];
                if (can_be_removed) floor[i][j] = 0;
            }
            printf("\033[95m -> %d\n", result);
        }
    }
    for(int i = 0; i < HEIGHT; i++){
        free(floor[i]);
    }
    free(floor);

    fclose(input);

    free(buf);
    printf("\n<%d>\033[0m\n", result);

    return 0;
}