#include <stdio.h>
#include <string.h>

int main() {
    char name[25] = "david";
    char n[20] = "david";
    if(strcmp(name,n)==0) {
        printf("jooo");
    } else {
        printf("faszt");
    }
    return 0;
}