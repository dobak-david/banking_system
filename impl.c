#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

void printOptions() {
    printf("Welcome to the main menu\n\n");
    printf("1. create new account\n");
    printf("2. Update information of existing account\n");
    printf("3. For transactions\n");//hianyzik
    printf("4. Show a clients\n");//hianyzik
    printf("5. Delete a client\n");//hianyzik
    printf("6. View costumer's list\n");
    printf("7. Exit\n\n");
}

void chooseService(menupoints* state) {
    printOptions();
    printf("Choose service: ");
    scanf("%d",&(*state));
}

void newAccount(listOfAccounts* Accounts) {
    account newAccount;
    printf("Please enter your personal information");
    printf("\nEnter the Firstname: ");
    scanf("%s",newAccount.costumer.Firstname);
    printf("\nEnter the Secondname: ");
    scanf("%s",newAccount.costumer.Secondname);
    printf("\nEnter the date of birth(yyyy/mm/dd):");
    scanf("%d/%d/%d",&newAccount.costumer.birthYear,&newAccount.costumer.birthMonth,&newAccount.costumer.birthDay);
    printf("Enter your phone numer: ");
    scanf("%s",newAccount.costumer.phoneNumber);
    printf("Enter the money you want store on your account: ");
    scanf("%d",&newAccount.amountOfMoney);
    Accounts->list[Accounts->size] = malloc(sizeof(account));
    Accounts->list[Accounts->size]->amountOfMoney=newAccount.amountOfMoney;
    Accounts->list[Accounts->size]->costumer.birthYear=newAccount.costumer.birthYear;
    Accounts->list[Accounts->size]->costumer.birthMonth=newAccount.costumer.birthMonth;
    Accounts->list[Accounts->size]->costumer.birthDay=newAccount.costumer.birthDay;
    strcpy(Accounts->list[Accounts->size]->costumer.Firstname,newAccount.costumer.Firstname);
    strcpy(Accounts->list[Accounts->size]->costumer.Secondname,newAccount.costumer.Secondname);
    strcpy(Accounts->list[Accounts->size]->costumer.phoneNumber,newAccount.costumer.phoneNumber);
    Accounts->size++;
    printf("The registration is successfull\n");
}

void readIn(listOfAccounts* Accounts) {
    FILE *fp;
    fp = fopen("data.txt","r");
    account result;
    while(fscanf(fp,"%s %s %d/%d/%d %s %d",result.costumer.Firstname,result.costumer.Secondname,&result.costumer.birthYear,&result.costumer.birthMonth,&result.costumer.birthDay,result.costumer.phoneNumber,&result.amountOfMoney)==7) {
        Accounts->list[Accounts->size] = malloc(sizeof(account));
        Accounts->list[Accounts->size]->amountOfMoney=result.amountOfMoney;
        Accounts->list[Accounts->size]->costumer.birthYear=result.costumer.birthYear;
        Accounts->list[Accounts->size]->costumer.birthMonth=result.costumer.birthMonth;
        Accounts->list[Accounts->size]->costumer.birthDay=result.costumer.birthDay;
        strcpy(Accounts->list[Accounts->size]->costumer.Firstname,result.costumer.Firstname);
        strcpy(Accounts->list[Accounts->size]->costumer.Secondname,result.costumer.Secondname);
        strcpy(Accounts->list[Accounts->size]->costumer.phoneNumber,result.costumer.phoneNumber);
        Accounts->size++;
        if (Accounts->size==Accounts->capacity) {
            Accounts->capacity*=2;
            Accounts->list=realloc(Accounts->list,sizeof(account)*Accounts->capacity);
        }
    }
    fclose(fp);
}

void editAccount(listOfAccounts* Accounts) {
    printf("Give your first name: ");
    char editNameFst[25];
    char editNameSnd[25];
    scanf("%s",editNameFst);
    printf("Give your second name: ");
    scanf("%s",editNameSnd);
    int i=0;
    bool found = false;
    while (i<Accounts->size && found == false) {
        if(strcmp(editNameFst,Accounts->list[i]->costumer.Firstname)==0 && strcmp(editNameSnd,Accounts->list[i]->costumer.Secondname)==0) {
            printf("%s %s %d/%d/%d %s %d\n",Accounts->list[i]->costumer.Firstname,Accounts->list[i]->costumer.Secondname,Accounts->list[i]->costumer.birthYear,Accounts->list[i]->costumer.birthMonth,Accounts->list[i]->costumer.birthDay,Accounts->list[i]->costumer.phoneNumber,Accounts->list[i]->amountOfMoney);
            found = true;
        }
        i++;
    }
    i--;
    if (found == false) {
        printf("There is no such client\n");
        return;
    }
    printf("Which of the following data you want to refresh?\n1. Firstname\n2. Secondname\n3. Birthyear\n4. Birthmonth\n5. Birthday\n6. Phonenumber\n");
    printf("Choose number: ");
    int chosen;
    scanf("%d",&chosen);
    switch (chosen)
    {
    case 1:
        printf("Updating the firstname\n\nGive the new firstname: ");
        char newFirstName[25];
        scanf("%s",newFirstName);
        strcpy(Accounts->list[i]->costumer.Firstname,newFirstName);
        printf("The update was successfull\nThe new firstname is: %s",Accounts->list[i]->costumer.Firstname);
        break;
    case 2:
        printf("Updating the secondname\n\nGive the new secondname: ");
        char newSecondname[25];
        scanf("%s",newSecondname);
        strcpy(Accounts->list[i]->costumer.Secondname,newSecondname);
        printf("The update was successfull\nThe new secondname is: %s",Accounts->list[i]->costumer.Secondname);
        break;
    case 3:
        printf("Updating the birthyear\n\nGive the new birthyear: ");
        int newBirthyear;
        scanf("%d",&newBirthyear);
        Accounts->list[i]->costumer.birthYear=newBirthyear;
        printf("The update was successfull\nThe new birthyear is: %d",Accounts->list[i]->costumer.birthYear);
        break;
    case 4:
        printf("Updating the birthmonth\n\nGive the new birthmonth: ");
        int birthmonth;
        scanf("%d",&birthmonth);
        Accounts->list[i]->costumer.birthMonth=birthmonth;
        printf("The update was successfull\nThe new birthmonth is: %d",Accounts->list[i]->costumer.birthMonth);
        break;
    case 5:
        printf("Updating the birthday\n\nGive the new birthday: ");
        int birthday;
        scanf("%d",&birthday);
        Accounts->list[i]->costumer.birthDay=birthday;
        printf("The update was successfull\nThe new birthday is: %d",Accounts->list[i]->costumer.birthDay);
        break;
    case 6:
        printf("Updating the phonenumber\n\nGive the new phonenumber: ");
        char phonenumber[16];
        scanf("%s",phonenumber);
        strcpy(Accounts->list[i]->costumer.phoneNumber,phonenumber);
        printf("The update was successfull\nThe new phonenumber is: %s",Accounts->list[i]->costumer.phoneNumber);
        break;
    default:
        break;
    }
    printf("\n");
}

void printAccounts(listOfAccounts* Accounts) {
    printf("\n\nThe list of the costumers with their data:\n\n");
    printf("Firstname       Secondname        Birthyear   Birthmonth   Birthday   Phonenumber      Amount of Money\n");
    for(int i=0;i<Accounts->size;i++) {
        printf("%-15s %-15s   %-4d        %-2d           %-2d         %-15s  %-8d\n",Accounts->list[i]->costumer.Firstname,
        Accounts->list[i]->costumer.Secondname,
        Accounts->list[i]->costumer.birthYear,
        Accounts->list[i]->costumer.birthMonth,
        Accounts->list[i]->costumer.birthDay,Accounts->list[i]->costumer.phoneNumber,
        Accounts->list[i]->amountOfMoney);
    }
    printf("\n\n");
}

int searchAccount(listOfAccounts* Accounts, char *fstname, char *sndname) {
    int i=0;
    bool Found=false;
    while(i<Accounts->size && Found == false) {
        if (strcmp(Accounts->list[i]->costumer.Firstname,fstname)==0 &&
        strcmp(Accounts->list[i]->costumer.Secondname,sndname)==0) {
            Found=true;
        }
        i++;
    }
    if (Found) {
        i--;
        return i;
    } else {
        return i;
    }
}

void transact(listOfAccounts* Accounts) {
    printf("Which is your account?\nGive your firstname: ");
    char FirstNameIn[15];
    scanf("%s",FirstNameIn);
    char SecondNameIn[15];
    printf("Give your Secondname: ");
    scanf("%s",SecondNameIn);
    int i=searchAccount(Accounts,FirstNameIn,SecondNameIn);
    if (i<Accounts->size) {
        char forFstname[15];
        char forSndname[15];
        printf("For who you want to transact money?\nFirstname: ");
        scanf("%s",forFstname);
        printf("Secondname: ");
        scanf("%s",forSndname);
        int j=searchAccount(Accounts,forFstname,forSndname);
        if (j<Accounts->size) {
            bool failed=false;
            int MoneyToTransfer;
            do {
                printf("How much money do you want to transfer? ");
                scanf("%d",&MoneyToTransfer);
                failed=MoneyToTransfer>Accounts->list[j]->amountOfMoney;
            } while (failed);
            Accounts->list[j]->amountOfMoney-=MoneyToTransfer;
            Accounts->list[i]->amountOfMoney+=MoneyToTransfer;
            printf("The transaction was successfull\n");
        } else {
            printf("There is no account with these names\n\n");
        }
    } else {
        printf("There is no account with these names\n\n");
    }
}

void erase(listOfAccounts* Accounts) {
    printf("Which account do you want to delete?\nFirstname: ");
    char FirstNameIn[15];
    scanf("%s",FirstNameIn);
    char SecondNameIn[15];
    printf("Give your Secondname: ");
    scanf("%s",SecondNameIn);
    int i=searchAccount(Accounts,FirstNameIn,SecondNameIn);
    if (i<Accounts->size) {
        for(int j=i;j<Accounts->size-1;j++) {
            Accounts->list[j]->amountOfMoney=Accounts->list[j+1]->amountOfMoney;
            Accounts->list[j]->costumer.birthYear=Accounts->list[j+1]->costumer.birthYear;
            Accounts->list[j]->costumer.birthMonth=Accounts->list[j+1]->costumer.birthMonth;
            Accounts->list[j]->costumer.birthDay=Accounts->list[j+1]->costumer.birthDay;
            strcpy(Accounts->list[j]->costumer.Firstname,Accounts->list[j+1]->costumer.Firstname);
            strcpy(Accounts->list[j]->costumer.Secondname,Accounts->list[j+1]->costumer.Secondname);
            strcpy(Accounts->list[j]->costumer.phoneNumber,Accounts->list[j+1]->costumer.phoneNumber);
        }
        Accounts->size--;
        printf("The delete was successfull\n\n");
    } else {
            printf("There is no account with these names\n\n");
    }
}

void menu(menupoints* state,listOfAccounts* Accounts) {
    switch (*state)
    {
    case 1:
        newAccount(Accounts);
        break;
    case 2:
        editAccount(Accounts);
        break;
    case 3:
        transact(Accounts);
        break;
    case 4:
        //show
        break;
    case 5:
        erase(Accounts);
        break;
    case 6:
        printAccounts(Accounts);
        break;
    case 7:
        printf("BYEEE");
        loadAccountsBack(Accounts);
        freeListOfAccounts(Accounts);
        exit(0);
    default:
        printf("There is no such options\nChoose another");
        break;
    }
}

void freeListOfAccounts(listOfAccounts* ptr) {
    for(int i=0;i<ptr->size;i++) {
        free(ptr->list[i]);
    }
    free(ptr->list);
    free(ptr);
}

void loadAccountsBack(listOfAccounts* Accounts) {
    FILE *fp;
    fp = fopen("data.txt","w");
    for(int i=0;i<Accounts->size;i++) {
        fprintf(fp,"%s %s %d/%d/%d %s %d\n",Accounts->list[i]->costumer.Firstname,
        Accounts->list[i]->costumer.Secondname,
        Accounts->list[i]->costumer.birthYear,
        Accounts->list[i]->costumer.birthMonth,
        Accounts->list[i]->costumer.birthDay,Accounts->list[i]->costumer.phoneNumber,
        Accounts->list[i]->amountOfMoney);
    }
    fclose(fp);
}