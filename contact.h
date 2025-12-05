#ifndef CONTACT_H
#define CONTACT_H

/*Macro defining maximum contact*/
#define MAX_CONTACTS 100

/*Strucure declaration
 *Member -> Name
         -> phone 
         -> email
*/
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

/*Nested structure*/
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;


/*Function prototype*/

/*Function prototype for creating new contact*/
void createContact(AddressBook *addressBook);
/*Function prototpe for search contatct*/
void searchContact(AddressBook *addressBook);
/*Function prototpe for edit contatct*/
void editContact(AddressBook *addressBook);
/*Function prototpe for delete contatct*/
void deleteContact(AddressBook *addressBook);
/*Function prototpe for listcontact contatct*/
void listContacts(AddressBook *addressBook);
/*Function prototpe for Initialization of addressbook*/
void initialize(AddressBook *addressBook);
/*Function prototpe for save contatct*/
void saveContactsToFile(AddressBook *AddressBook);
void dash();

#endif
