#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

int main() {
    menupoints state = DEFAULT;
    listOfAccounts* Accounts=malloc(sizeof(listOfAccounts));
    Accounts->capacity = 2;
    Accounts->size=0;
    Accounts->list=malloc(sizeof(account)*Accounts->capacity);
    readIn(Accounts);
    while(1) {
        chooseService(&state);
        menu(&state,Accounts);
    }
    return 0;
}