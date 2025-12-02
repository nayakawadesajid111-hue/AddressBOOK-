#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"

/*Function definition  for listing contact*/
void listContacts(AddressBook *addressBook)
{
  dash();
  printf("%40s\n", "List of contact");
  dash();
  printf("%-10s%25s%25s\n", "NAME", "PHONE NUMBER", "EMAIL");
  dash();
  for (int i = 0; i < addressBook->contactCount; i++)
  {
    printf("%-20s\t%-20s\t%-35s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }
  dash();
// sorted option 
  char chr;
  printf("Do you want sort list (y/n): ");
  scanf(" %c", &chr);
  dash();

  if (chr == 'y' || chr == 'Y')
  {
    int choice;
    printf("1. Sort names (from A to Z)\n2. Sort phone numbers (from 0 to 9)\n3. Sort Emails(from a to z)\n");
    dash();
    printf("Enter choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      int ch;
      dash();
      printf("%40s\n", "List of contact");
      dash();
      printf("%-10s%25s%25s\n", "NAME", "PHONE NUMBER", "EMAIL");
      dash();
      for (ch = 'A'; ch <= 'Z'; ch++)
      {
        for (int i = 0; i < addressBook->contactCount; i++)
        {

          if (addressBook->contacts[i].name[0] == ch)
          {
            printf("%-20s\t%-20s\t%-35s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
          }
        }
      }

      break;
    case 2:
      dash();
      printf("%40s\n", "List of contact");
      dash();
      printf("%-10s%25s%25s\n", "NAME", "PHONE NUMBER", "EMAIL");
      dash();
      for (ch = '0'; ch <= '9'; ch++)
      {
        for (int i = 0; i < addressBook->contactCount; i++)
        {

          if (addressBook->contacts[i].phone[0] == ch)
          {
            printf("%-20s\t%-20s\t%-35s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
          }
        }
      }

      break;
    case 3:
      dash();
      printf("%40s\n", "List of contact");
      dash();
      printf("%-10s%25s%25s\n", "NAME", "PHONE NUMBER", "EMAIL");
      dash();
      for (ch = 'a'; ch <= 'z'; ch++)
      {
        for (int i = 0; i < addressBook->contactCount; i++)
        {

          if (addressBook->contacts[i].email[0] == ch)
          {
            printf("%-20s\t%-20s\t%-35s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
          }
        }
      }
      break;

    default:
      printf("Invalid choice\n");
      break;
    }
  }
  else
  {
    printf("%45s\n", "...Returning main menu...");
  }
}

/*Initialization of program*/
void initialize(AddressBook *addressBook)
{
  addressBook->contactCount = 0;

  // Load contacts from file during initialization (After files)
  loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
  saveContactsToFile(addressBook); // Save contacts to file
  exit(EXIT_SUCCESS);              // Exit the program
}

/*Function for checking  phone number is present or not*/
int phonecheck(char phone[], AddressBook *AddressBook)
{
  for (int i = 0; i < AddressBook->contactCount; i++)
  {
    if (strcmp(phone, AddressBook->contacts[i].phone) == 0)
    {
      return 1;
    }
  }
  return 0;
}
/*Function definition for email exist or not*/
int emailcheck(char email[], AddressBook *AddressBook)
{
  for (int i = 0; i < AddressBook->contactCount; i++)
  {
    if (strcmp(email, AddressBook->contacts[i].email) == 0)
    {
      return 1;
    }
  }
  return 0;
}

/*Function def for creating new contact*/
void createContact(AddressBook *addressBook)
{
  int res = 0;
  char name[35];
  char phone[20];
  char email[35];
  printf("Enter name: ");
  scanf(" %34[^\n]", name);
  if (name[0] >= 'a' || name[0] <= 'z')
  {
    /*  first character of name get in uppercase if user enter in lowercase. */
    int ch = toupper(name[0]);
    name[0] = ch;
  }
  do
  {
    printf("Enter phone number : ");
    scanf(" %19[^\n]", phone);
    res = phonecheck(phone, addressBook);
    if (res == 1)
    {
      printf("\tPhone number already exist in addressbook.\n");
    }
    else
    {
      int len = strlen(phone);
      if (len != 10)
      {
        res = 1;
        printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
      }
    }
  } while (res == 1);
  // reading email
  do
  {
    printf("Enter Email Id : ");
    scanf(" %34[^\n]", email);
    res = emailcheck(email, addressBook);
    if (res == 1)
    {
      printf("Email already exist in addressbook.\n");
    }
    else
    {
      char ch = '@';
      char str[] = ".com";
      char *ptr, *ptr1;
      ptr = strchr(email, ch);
      ptr1 = strstr(email, str);
      if (ptr == NULL || ptr1 == NULL)
      {
        res = 1;
        printf("\tEnter valid email(must contain @ or .com extension )\n");
      }
    }

  } while (res == 1);
  // adding contact.....
  strcpy(addressBook->contacts[addressBook->contactCount].name, name);
  strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
  strcpy(addressBook->contacts[addressBook->contactCount].email, email);

  (addressBook->contactCount)++;
}

/*Function def searching contact*/
void searchContact(AddressBook *addressBook)
{
  char namesearch[25];
  char phonesearch[20];
  char emailsearch[35];
  int option;
  int flag = 0;
  /*Menu for searching contact*/
  printf("1.Search by name\n2.Search by phone number\n3.Search by Email\n");
  dash();
  printf("Enter the choice : ");
  scanf("%d", &option);
  dash();

  switch (option)
  {
  case 1:
    // Searching input
    int count = 0;
    printf("Enter name : ");
    scanf(" %24[^\n]", namesearch);
    dash();

    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(namesearch, addressBook->contacts[i].name) == 0)
      {
        flag = 1;
        printf("\t\t%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        count++;
      }
    }
    if (flag == 0)
    {
      count = 0;
      printf("\t\t...Name not found in the Addressbook...\n");
    }
    if (flag)
      printf("%d %-10s\n", count, "match found ");
    break;

  case 2:
    printf("Enter phone number : ");
    scanf(" %19[^\n]", phonesearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(phonesearch, addressBook->contacts[i].phone) == 0)
      {
        flag = 1;
        printf("\t%s %s %s \n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      count = 0;
      printf("\t\t...Phone number not found in the Addressbook...\n");
    }
    break;

  case 3:
    printf("Enter Email ID : ");
    scanf(" %34[^\n]", emailsearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(emailsearch, addressBook->contacts[i].email) == 0)
      {
        flag = 1;
        printf("\t%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t...Email not found in the Addressbook...\n");
    }
    break;
  default:
    printf("Invalid Choice\n");
    break;
  }
}
/*Function def for edit contact*/
void editContact(AddressBook *addressBook)
{
  char namesearch[25];
  char phonesearch[20];
  char emailsearch[35];
  int option;
  int flag = 0;
  int index = -1;
  printf("1. Edit by name\n2. Edit by phone number\n3. Edit by Email\n");
  dash();
  printf("Enter the choice : ");
  scanf(" %d", &option);
  dash();

  switch (option)
  {
  case 1:
    printf("Enter name : ");
    scanf(" %24[^\n]", namesearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(namesearch, addressBook->contacts[i].name) == 0)
      {
        flag = 1;
        index = i;
        printf("\t>>%d %s %s %s\n", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t\tName not found in the Addressbook\n");
    }
    if (index != -1)
    {
      dash();
      printf("Enter the index to make changes : ");
      scanf("%d", &index);
      int option;
      dash();
      printf("1. Edit Name\n2. Edit phone\n3. Edit email\n4. All edit\n");
      dash();
      printf("Enter choice : ");
      scanf("%d", &option);
      dash();
      char newname[25];
      char newphone[20];
      char newemail[35];
      int res = 0;
      switch (option)
      {
      case 1:
        printf("Enter new name : ");
        scanf(" %24[^\n]", newname);
        if (newname[0] >= 'a' || newname[0] <= 'z')
        {
          /*  first character of name get in uppercase if user enter in lowercase. */
          int ch = toupper(newname[0]);
          newname[0] = ch;
        }
        strcpy(addressBook->contacts[index].name, newname);
        break;
      case 2:
        do
        {
          printf("Enter new phone number : ");
          scanf(" %19[^\n]", newphone);
          //checking valid number
          int len = strlen(newphone);
          if (len != 10)
          {
            printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
            res = 1;
          }
        } while (res == 1);
        strcpy(addressBook->contacts[index].phone, newphone);
        break;
      case 3:
        do
        {
          printf("Enter new email : ");
          scanf(" %34[^\n]", newemail);
          res = emailcheck(newemail, addressBook);
          if (res == 1)
          {
            printf("\t\tEmail already exist in addressbook.\n");
          }
          else
          {
            char ch = '@';
            char str[] = ".com";
            char *ptr, *ptr1;
            ptr = strchr(newemail, ch);
            ptr1 = strstr(newemail, str);
            if (ptr == NULL || ptr1 == NULL)
            {
              res = 1;
              printf("\tEnter valid email(must contain @ or .com extension )\n");
            }
          }

        } while (res == 1);
        strcpy(addressBook->contacts[index].email, newemail);
        break;
      case 4:
        printf("Enter new name : ");
        scanf(" %24[^\n]", newname);
        if (newname[0] >= 'a' || newname[0] <= 'z')
        {
          /*  first character of name get in uppercase if user enter in lowercase. */
          int ch = toupper(newname[0]);
          newname[0] = ch;
        }
        strcpy(addressBook->contacts[index].name, newname);

        do
        {
          printf("Enter new phone number : ");
          scanf(" %19[^\n]", newphone);
          int len = strlen(newphone);

          if (len != 10)
          {
            printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
            res = 1;
          }
        } while (res == 1);
        strcpy(addressBook->contacts[index].phone, newphone);

        do
        {
          printf("Enter new email : ");
          scanf(" %34[^\n]", newemail);
          res = emailcheck(newemail, addressBook);
          if (res == 1)
          {
            printf("\t\tEmail already exist in addressbook.\n");
          }
          else
          {
            char ch = '@';
            char str[] = ".com";
            char *ptr, *ptr1;
            ptr = strchr(newemail, ch);
            ptr1 = strstr(newemail, str);
            if (ptr == NULL || ptr1 == NULL)
            {
              res = 1;
              printf("\tEnter valid email(must contain @ or .com extension )\n");
            }
          }

        } while (res == 1);
        strcpy(addressBook->contacts[index].email, newemail);
        break;
      default:
        printf("Invalid choice\n");
        break;
      }
    }
    break;

  case 2:
    printf("Enter phone number : ");
    scanf(" %19[^\n]", phonesearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(phonesearch, addressBook->contacts[i].phone) == 0)
      {
        flag = 1;
        index = i;
        printf("\t>> %d %s %s %s\n ", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t\tPhone number not found in the Addressbook\n");
    }
    if (index != -1)
    {

      printf("Enter the index to make changes : ");
      scanf("%d", &index);
      dash();
      int option;
      printf("1. Edit Name\n2. Edit phone\n3. Edit email\n4. All edit\n");
      dash();
      printf("Enter choice : ");
      scanf("%d", &option);
      dash();
      char newname[25];
      char newphone[20];
      char newemail[35];
      int res = 0;
      switch (option)
      {
      case 1:
        printf("Enter new name : ");
        scanf(" %24[^\n]", newname);
        if (newname[0] >= 'a' || newname[0] <= 'z')
        {
          /*  first character of name get in uppercase if user enter in lowercase. */
          int ch = toupper(newname[0]);
          newname[0] = ch;
        }
        strcpy(addressBook->contacts[index].name, newname);
        break;
      case 2:
        do
        {
          printf("Enter new phone number : ");
          scanf(" %19[^\n]", newphone);
          int len = strlen(newphone);

          if (len != 10)
          {
            printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
            res = 1;
          }
        } while (res == 1);
        strcpy(addressBook->contacts[index].phone, newphone);
        break;
      case 3:
        do
        {
          printf("Enter new email : ");
          scanf(" %34[^\n]", newemail);
          res = emailcheck(newemail, addressBook);
          if (res == 1)
          {
            printf("\t\tEmail already exist in addressbook.\n");
          }
          else
          {
            char ch = '@';
            char str[] = ".com";
            char *ptr, *ptr1;
            ptr = strchr(newemail, ch);
            ptr1 = strstr(newemail, str);
            if (ptr == NULL || ptr1 == NULL)
            {
              res = 1;
              printf("\tEnter valid email(must contain @ or .com extension )\n");
            }
          }

        } while (res == 1);
        strcpy(addressBook->contacts[index].email, newemail);
        break;
      case 4:
        printf("Enter new name : ");
        scanf(" %24[^\n]", newname);
        if (newname[0] >= 'a' || newname[0] <= 'z')
        {
          /*  first character of name get in uppercase if user enter in lowercase. */
          int ch = toupper(newname[0]);
          newname[0] = ch;
        }
        strcpy(addressBook->contacts[index].name, newname);

        do
        {
          printf("Enter new phone number : ");
          scanf(" %19[^\n]", newphone);
          int len = strlen(newphone);

          if (len != 10)
          {
            printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
            res = 1;
          }
        } while (res == 1);
        strcpy(addressBook->contacts[index].phone, newphone);

        do
        {
          printf("Enter new email : ");
          scanf(" %34[^\n]", newemail);
          res = emailcheck(newemail, addressBook);
          if (res == 1)
          {
            printf("\t\tEmail already exist in addressbook.\n");
          }
          else
          {
            char ch = '@';
            char str[] = ".com";
            char *ptr, *ptr1;
            ptr = strchr(newemail, ch);
            ptr1 = strstr(newemail, str);
            if (ptr == NULL || ptr1 == NULL)
            {
              res = 1;
              printf("\tEnter valid email(must contain @ or .com extension )\n");
            }
          }

        } while (res == 1);
        strcpy(addressBook->contacts[index].email, newemail);

        break;
      default:
        printf("Invalid choice\n");
        break;
      }
    }
    break;

  case 3:
    printf("Enter Email Id : ");
    scanf(" %34[^\n]", emailsearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(emailsearch, addressBook->contacts[i].email) == 0)
      {
        flag = 1;
        index = i;
        printf("\t>> %d %s %s %s ", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t\tEmail not found in the Addressbook\n");
    }
    if (index != -1)
    {

      printf("\nEnter the index to make changes : ");
      scanf("%d", &index);
      dash();
      int option;
      printf("1. Edit Name\n2. Edit phone\n3. Edit email\n4. All edit\n");
      dash();
      printf("Enter choice : ");
      scanf("%d", &option);
      dash();
      char newname[25];
      char newphone[20];
      char newemail[35];
      int res = 0;
      switch (option)
      {
      case 1:
        printf("Enter new name : ");
        scanf(" %24[^\n]", newname);
        if (newname[0] >= 'a' || newname[0] <= 'z')
        {
          /*  first character of name get in uppercase if user enter in lowercase. */
          int ch = toupper(newname[0]);
          newname[0] = ch;
        }
        strcpy(addressBook->contacts[index].name, newname);
        break;
      case 2:
        do
        {
          printf("Enter new phone number : ");
          scanf(" %19[^\n]", newphone);
          int len = strlen(newphone);

          if (len != 10)
          {
            printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
            res = 1;
          }
        } while (res == 1);
        strcpy(addressBook->contacts[index].phone, newphone);
        break;
      case 3:
        do
        {
          printf("Enter new email : ");
          scanf(" %34[^\n]", newemail);
          res = emailcheck(newemail, addressBook);
          if (res == 1)
          {
            printf("\t\tEmail already exist in addressbook.\n");
          }
          else
          {
            char ch = '@';
            char str[] = ".com";
            char *ptr, *ptr1;
            ptr = strchr(newemail, ch);
            ptr1 = strstr(newemail, str);
            if (ptr == NULL || ptr1 == NULL)
            {
              res = 1;
              printf("\tEnter valid email(must contain @ or .com extension )\n");
            }
          }

        } while (res == 1);
        strcpy(addressBook->contacts[index].email, newemail);
        break;
      case 4:
        printf("Enter new name : ");
        scanf(" %24[^\n]", newname);
        if (newname[0] >= 'a' || newname[0] <= 'z')
        {
          /*  first character of name get in uppercase if user enter in lowercase. */
          int ch = toupper(newname[0]);
          newname[0] = ch;
        }
        strcpy(addressBook->contacts[index].name, newname);

        do
        {
          printf("Enter new phone number : ");
          scanf(" %19[^\n]", newphone);
          int len = strlen(newphone);

          if (len != 10)
          {
            printf("\tEnter valid phone number(Phone number must have 10 digit).\n");
            res = 1;
          }
        } while (res == 1);
        strcpy(addressBook->contacts[index].phone, newphone);
        do
        {
          printf("Enter new email : ");
          scanf(" %34[^\n]", newemail);
          res = emailcheck(newemail, addressBook);
          if (res == 1)
          {
            printf("\t\tEmail already exist in addressbook.\n");
          }
          else
          {
            char ch = '@';
            char str[] = ".com";
            char *ptr, *ptr1;
            ptr = strchr(newemail, ch);
            ptr1 = strstr(newemail, str);
            if (ptr == NULL || ptr1 == NULL)
            {
              res = 1;
              printf("\tEnter valid email(must contain @ or .com extension )\n");
            }
          }

        } while (res == 1);
        strcpy(addressBook->contacts[index].email, newemail);
        break;
      default:
        printf("Invalid choice\n");
        break;
      }
    }

    break;

  default:
    printf("Invalid choice\n");
    break;
  }
}
/*function for deleting  contact*/
/*Name delete*/
void deletenamestr(AddressBook *addressBook, char deletestr[], int index)
{

  int i = 0;

  while (deletestr[i] != '\0')
  {
    int j = 0;
    while (addressBook->contacts[index].name[j] != '\0')
    {
      if (deletestr[i] == addressBook->contacts[index].name[j])
      {

        int m = j;
        while (addressBook->contacts[index].name[m] != '\0')
        {
          addressBook->contacts[index].name[m] = addressBook->contacts[index].name[m + 1];
          m++;
        }
        j--;
      }
      j++;
    }
    i++;
  }
}
/*Phone delete*/
void deletephonestr(AddressBook *addressBook, char deletestr[], int index)
{

  int i = 0;

  while (deletestr[i] != '\0')
  {
    int j = 0;
    while (addressBook->contacts[index].phone[j] != '\0')
    {
      if (deletestr[i] == addressBook->contacts[index].phone[j])
      {

        int m = j;
        while (addressBook->contacts[index].phone[m] != '\0')
        {
          addressBook->contacts[index].phone[m] = addressBook->contacts[index].phone[m + 1];
          m++;
        }
        j--;
      }
      j++;
    }
    i++;
  }
}
/*Mail delete*/
void deleteemailstr(AddressBook *addressBook, char deletestr[], int index)
{

  int i = 0;

  while (deletestr[i] != '\0')
  {
    int j = 0;
    while (addressBook->contacts[index].email[j] != '\0')
    {
      if (deletestr[i] == addressBook->contacts[index].email[j])
      {

        int m = j;
        while (addressBook->contacts[index].email[m] != '\0')
        {
          addressBook->contacts[index].email[m] = addressBook->contacts[index].email[m + 1];
          m++;
        }
        j--;
      }
      j++;
    }
    i++;
  }
}
/*Function definition of delete contact*/
void deleteContact(AddressBook *addressBook)
{
  char namesearch[25];
  char phonesearch[20];
  char emailsearch[35];
  int option;
  int flag = 0;
  int index = -1;
  printf("1.Delete by name\n2.Delete by phone number\n3.Delete by Email\n4.All delete\n");
  dash();
  printf("Enter the choice : ");
  scanf(" %d", &option);

  switch (option)
  {
  case 1:
    printf("Enter name : ");
    scanf(" %24[^\n]", namesearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(namesearch, addressBook->contacts[i].name) == 0)
      {
        flag = 1;
        index = i;
        printf("\t>>%d %s %s %s\n", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t\tName not found in the Addressbook\n");
    }
    if (index != -1)
    {
      char deletename[25];
      char deletephone[20];
      char deleteemail[25];
      dash();
      printf("Enter the index to make changes : ");
      scanf("%d", &index);
      int option;
      dash();
      printf("1.Delete name.\n2.Delete phone number.\n3.Delete email.\n4.All delete.\n");
      dash();
      printf("Enter choice. : ");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);
        break;
      case 2:
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
        break;
      case 3:
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);
        break;
      case 4:
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);

        for (int i = index; i < addressBook->contactCount; i++)
        {
          addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        (addressBook->contactCount)--;
        break;
      default:
        printf("Invalid choice.\n");
        break;
      }
    }
    break;

  case 2:
    printf("Enter phone number : ");
    scanf(" %19[^\n]", phonesearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(phonesearch, addressBook->contacts[i].phone) == 0)
      {
        flag = 1;
        index = i;
        printf("\t>> %d %s %s %s\n", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\tPhone number not found in the Addressbook\n");
    }
    if (index != -1)
    {
      char deletename[25];
      char deletephone[20];
      char deleteemail[25];
      dash();
      printf("Enter the index to make changes : ");
      scanf("%d", &index);
      int option;
      dash();
      printf("1.Delete name.\n2.Delete phone number.\n3.Delete email.\n4.All delete.\n");
      dash();
      printf("Enter choice. : ");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);

        break;
      case 2:
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
        break;
      case 3:
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);
        break;
      case 4:
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);

        for (int i = index; i < addressBook->contactCount; i++)
        {
          addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        (addressBook->contactCount)--;
        break;

      default:
        printf("Invalid choice.\n");
        break;
      }
    }
    break;

  case 3:
    printf("Enter Email Id : ");
    scanf(" %34[^\n]", emailsearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if (strcmp(emailsearch, addressBook->contacts[i].email) == 0)
      {
        flag = 1;
        index = i;
        printf("\t>>%d %s %s %s\n ", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t\tEmail not found in the Addressbook\n");
    }
    if (index != -1)
    {
      char deletename[25];
      char deletephone[20];
      char deleteemail[25];
      dash();
      printf("Enter the index to make changes : ");
      scanf("%d", &index);
      int option;
      dash();
      printf("1.Delete name.\n2.Delete phone number.\n3.Delete email.\n4.All delete.\n");
      dash();
      printf("Enter choice. : ");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);
        break;
      case 2:
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
        break;
      case 3:
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);
        break;
      case 4:
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);

        for (int i = index; i < addressBook->contactCount; i++)
        {
          addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        (addressBook->contactCount)--;
        break;
      default:
        printf("Invalid choice.\n");
        break;
      }
    }
    break;

  case 4:
    char allsearch[50];
    dash();
    printf("Enter name or phone number or email id : ");
    scanf(" %49[^\n]", allsearch);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      if ((strcmp(allsearch, addressBook->contacts[i].name) == 0) || (strcmp(allsearch, addressBook->contacts[i].phone) == 0) || (strcmp(allsearch, addressBook->contacts[i].email) == 0))
      {
        flag = 1;
        index = i;
        printf("\t>>%d %s %s %s\n ", index, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
      }
    }
    if (flag == 0)
    {
      printf("\t\tName not found in the Addressbook\n");
    }
    if (index != -1)
    {
      dash();
      printf("Enter the index to make changes : ");
      scanf("%d", &index);
      {
        char deletename[25];
        strcpy(deletename, addressBook->contacts[index].name);
        deletenamestr(addressBook, deletename, index);
      }
      {
        char deletephone[20];
        strcpy(deletephone, addressBook->contacts[index].phone);
        deletephonestr(addressBook, deletephone, index);
      }
      {
        char deleteemail[25];
        strcpy(deleteemail, addressBook->contacts[index].email);
        deleteemailstr(addressBook, deleteemail, index);
      }
      for (int i = index; i < addressBook->contactCount; i++)
      {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
      }
      (addressBook->contactCount)--;
    }
    break;

  default:
    printf("Invalid choice.\n");

    break;
  }
}
void dash()
{
  int i = 1;
  while (i <= 70)
  {
    printf("-");
    i++;
  }
  printf("\n");
}
