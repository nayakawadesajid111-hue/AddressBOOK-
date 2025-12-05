#ifndef FILE_H
#define FILE_H

/*Header file of declaration structure and working function*/
#include "contact.h"

/*Declaration
 *Saving contact to text file */
void saveContactsToFile(AddressBook *addressBook);

/*Declaration
 *Initialization of addressbook using contact saved in text file*/
void loadContactsFromFile(AddressBook *addressBook);

#endif
