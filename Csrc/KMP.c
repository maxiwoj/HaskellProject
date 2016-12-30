#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void failure(int *table, char* pattern);
int* KMP(char* pattern, char* data);

int main(int argc, char **argv){
    //main body for test purpose. Maybe should be different method in real test
    if(argc < 3) {
        printf("to few arguments\n");
        return 2;
    }
    int * res = KMP(argv[1], argv[2]);
    int i;
    printf("[ ");
    for(i = 0; res[i] != -1; i++){
        printf(" %d,", res[i]);
    }
    printf("\b]\n");
    return 0;
}

int* KMP(char* pattern, char* data){
    int size = strlen(pattern);
    int* table = (int*) malloc (size*sizeof(int));
    failure(table, pattern);
    int sizeOfResault = 2048;
    int resaultIndex = 0;
    int* resault = (int*) malloc (sizeOfResault*sizeof(int));

    int i, j;
    for(i = 0, j = 0; data[i] != '\0'; ++i){
        while(j > 0 && pattern[j] != data[i]){
            j = table[j-1];
        }
        if (pattern[j] == data[i]) {
            j++;
        }
        if(size <= j){
            if(sizeOfResault < resaultIndex - 2){
                sizeOfResault *= 2;
                int* more_resault = (int*) realloc (resault, sizeOfResault * sizeof(int));
                if (more_resault != NULL) {
                    resault = more_resault;
                }
                else {
                    free (resault);
                    puts ("Error (re)allocating memory");
                    exit (1);
                }
            }
            resault[resaultIndex] = i - size + 1;
            resaultIndex++;
        }
    }
    resault[resaultIndex] = -1;
    free(table);
    return resault;
}

void failure(int *table, char* pattern){
    int i, j;
    table[0] = 0;
    for(i = 1, j = 0; pattern[i] != '\0'; ++i){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        table[i] = j;
    }
}
