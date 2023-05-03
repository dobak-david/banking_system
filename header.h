#ifndef BANKING_H
#define BANKING_H

typedef enum menupoints {DEFAULT, NEWACC, EDIT, TRANSACT, ERASE, SHOW, LIST, EXIT} menupoints;

typedef struct costumerNode {
    char Firstname[15];
    char Secondname[15];
    int birthYear;
    int birthMonth;
    int birthDay;
    char phoneNumber[16];
} costumerNode;

typedef struct account {
    int amountOfMoney;
    costumerNode costumer;
} account;

typedef struct listOfAccounts {
    int capacity;
    int size;
    account** list;
} listOfAccounts;

void printOptions();

void erase(listOfAccounts* Accounts);

int searchAccount(listOfAccounts* Accounts, char *fstname, char *sndname);

void transact(listOfAccounts* Accounts);

void chooseService(menupoints* state);

void newAccount(listOfAccounts* Accounts);

void readIn(listOfAccounts* Accounts);

void editAccount(listOfAccounts* Accounts);

void menu(menupoints* state,listOfAccounts* Accounts);

void freeListOfAccounts(listOfAccounts* ptr);

void loadAccountsBack(listOfAccounts* Accounts);

void printAccounts(listOfAccounts* Accounts);

#endif