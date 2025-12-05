#include <stdio.h>
#include "file.h"
/*Function definition saving contact to text file*/
void saveContactsToFile(AddressBook *addressBook)
{

    FILE *fptr;//file pointer

    fptr = fopen("contacts.txt", "w");//file opened in write mode
    
    if(fptr == NULL)
    {
        printf("File not availble\n");
        return ;
    }
    fprintf(fptr, "%d\n", addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fptr);
}

/*Fuction definition for loading contact text file to program*/
void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr;
   
    fptr = fopen("contacts.txt", "r");//opened in read mode
   //file presence checking.
    if(fptr == NULL)
    {
        printf("File not availble\n");
        return ;
    }

    fscanf(fptr, "%d\n", &addressBook->contactCount);
    for (int i = 0; i <addressBook->contactCount;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fptr);
}
