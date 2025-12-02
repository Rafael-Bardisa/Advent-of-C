#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

    printf("%d\n", argc);


    if(argc != 2) return -1; // use first arg of program as file to search, assuming I will pass the correct filename later

    size_t size = 0;

    FILE* input = fopen(argv[1], "r");


    char* buf = malloc(128);

    int spin = 50; int new_spin; int password = 0;

    char mode; char prev_mode = 'R'; int change; int tick_number;

    while(getline(&buf, &size, input) != -1) {
        sscanf(buf, "%c%d", &mode, &change);
        // instead of a switch on the mode, keep track of the previous mode. If it is different, pivot the spin to 100 - spin and continue as positive
        if (mode != prev_mode) spin = (100 - spin) % 100;
        prev_mode = mode;

        new_spin = spin + change;
        // use the modulo to know how many times we loop through the dial. Edge cases on L mode and spin/new spin 0
        spin = new_spin % 100;

        spin = spin < 0 ? spin + 100: spin;

        tick_number = abs((new_spin - spin) / 100);

        printf("%c%d | %d -> %d: %d ticks\n", mode, change, new_spin, spin, tick_number);

        password += tick_number;

    }

    printf("%d\n", password);

    fclose(input);

    return 0;
}