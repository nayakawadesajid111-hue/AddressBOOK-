#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    
    AddressBook addressBook;  //declaration of nested structure 
    initialize(&addressBook); // Initialize the address book

    do
    {  
        /*Menu diaplay
         *Switch used to work according user choice.
         */
        dash();
        printf("%37s\n", "WELCOME");
        dash();
        printf("Address Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        dash();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            dash();
            printf("%41s\n", "CREATE CONTACT");
            dash();
            //function call
            createContact(&addressBook);
            dash();
            printf("%48s\n", "Successfully created contact...");
            dash();
            break;
        case 2:
            dash();
            printf("%41s\n", "SEARCH CONTACT");
            dash();
            //function call
            searchContact(&addressBook);
            dash();
            printf("%37s\n", "THANK YOU");
            dash();
            printf("\n");
            break;
        case 3:
            dash();
            printf("%41s\n", "EDIT CONTACT");
            dash();
            //function call
            editContact(&addressBook);
            dash();
            printf("%45s\n", "...Returning main menu...");
            dash();
            printf("\n");
            break;
        case 4:
            dash();
            printf("%41s\n", "DELETE CONTACT");
            dash();
            //function call
            deleteContact(&addressBook);
            dash();
            printf("%45s\n", "...Returning main menu...");
            dash();
            printf("\n");
            break;
        case 5:
            printf("\n");
            dash();
            printf("%37s%25s %d\n", "Addressbook", "Members:", addressBook.contactCount);
            dash();
            //function call
            listContacts(&addressBook);
            dash();
            printf("%37s\n", "THANK YOU");
            dash();
            printf("\n");
            break;
        case 6:
            printf("%45s\n", "Saving and Exiting...");
            dash();
            printf("%37s\n", "THANK YOU");
            dash();
            printf("\n");
            //function call 
            saveContactsToFile(&addressBook);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
