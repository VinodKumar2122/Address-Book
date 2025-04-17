#include <stdio.h>
#include "contact.h"

int main() {
	int choice;
	AddressBook addressBook;
	initialize(&addressBook); // Initialize the address book

	do {
		printf("\nAddress Book Menu:\n");
		printf("1. Create contact\n");
		printf("2. Search contact\n");
		printf("3. Delete contact\n");
		printf("4. Edit contact\n");
		printf("5. Display contacts\n");
		printf("6. Save contacts\n");		
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				createContact(&addressBook);
				break;
			case 2:
				searchContact(&addressBook);
				break;
			case 3:
				deleteContact(&addressBook);
				break;
			case 4:
				editContact(&addressBook);
				break;
			case 5:          
				listContacts(&addressBook);
				break;
			case 6:
				saveContactsToFile(&addressBook);
				printf("Saving and Exiting...\n");
				//load_Contact(&addressBook);
				//saveContactsToFile(&addressBook);
				//load_Contact(&addressBook);
				break;
			case 7:printf("exit\n");
			       return 0;
			       break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 7);

	return 0;
}
