#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int counter = 0;
void print_number(int n){
    printf( "%10d", n);         // 10 ger plats som kan fyllas av nummer
    counter++;
    if (counter != COLUMNS){
        printf("\n");
        return;
    }
}

void print_sieves(int n){
    _Bool *array [n];

    if ((array = malloc(sizeof(_Bool) * n)) == NULL){
        printf("n/a");
        exit(0);
    }
    for (int i = 0; i < n-1; i++)
        array[i] = 1;

    for (int i = 2; <= (int)sqrt(n); i++){
        if (array[i] == 1)
            for (int j = i * i; j < n; j += i)
                array[j] = 0;
    }
    for (int i = 2; i < n-1; i++){
        if (array[i] == 1)
            print_number(1);
    }
    free(array);
}

int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

