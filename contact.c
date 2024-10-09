#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
// Validate that the name contains only alphabets and spaces
int validate_name(char *name) {
    int i = 0;
    while (name[i] != '\0') {
        if (!(isalpha(name[i]) || name[i] == ' ')) {
            return 1;  // Invalid name
        }
        i++;
    }
    return 0;  // Valid name
}

// Validate that the phone number has exactly 10 digits
int validate_number(char *num) {
    int len = strlen(num);
    if (len != 10) {
        return 1;  // Invalid length
    }
    int i = 0;
    while (num[i] != '\0') {
        if (!isdigit(num[i])) {
            return 1;  // Invalid character
        }
        i++;
    }
    return 0;  // Valid number
}

// Check if the phone number is unique in the address book
int unique_number(AddressBook *addressBook, char *num) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].phone, num) == 0) {
            return 1;  // Phone number already exists
        }
    }
    return 0;  // Phone number is unique
}

// Validate that the email ends with '@gmail.com'
int validate_gmail(char *email) {
    char check[100] = "@gmail.com";
    // Check if email ends with "@gmail.com"
    if (!(strstr(email, check))) {
        return 1;  // Invalid email
    }
    return 0;  // Valid email
}

// Check if the email is unique in the address book
int unique_email(AddressBook *addressBook, char *email) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].email, email) == 0) {
            return 1;  // Email is not unique
        }
    }
    return 0;  // Email is unique
}

// Create a new contact and validate the inputs
void createContact(AddressBook *addressBook) {
    // Input name
    char name[50];
    printf("Enter the name: ");
    scanf(" %[^\n]", name);
    while (validate_name(name) == 1) {
        printf("Name validation not done, please enter a valid name...\n");
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);

    // Input phone number
    char num[11];  // 10 digits + null terminator
    printf("Enter the mobile number: ");
    scanf(" %[^\n]", num);
    while (validate_number(num) == 1 || unique_number(addressBook, num) == 1) {
        printf("Phone numberis not valid & already exist, Please enter a valid unique number...\n");
        printf("Enter the mobile number: ");
        scanf(" %[^\n]", num);
    }
    strcpy(addressBook->contacts[addressBook->contactCount].phone, num);

    // Input email address
    char email[50];
    printf("Enter the email address: ");
    scanf(" %[^\n]", email);
    while (validate_gmail(email) == 1 || unique_email(addressBook, email) == 1) {
        printf("Email is not valid &  already exist , Please enter a valid unique email...\n");
        printf("Enter the email address: ");
        scanf(" %[^\n]", email);
    }
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
   
    
    // Successfully added a new contact
    addressBook->contactCount++;
    printf("Contact created successfully.\n");
     
}

// Search for a contact based on name, phone number, or email
void searchContact(AddressBook *addressBook) {
    int flag = 1;  // Control the search loop
    int n;

    while (flag) 
    {
        // Prompt the user to choose the search criteria
        printf("Enter your choice:\n1. Name\n2. Mobile number\n3. Email\n4. Exit\n enter choice:");
        scanf("%d", &n);
        
        // If user chooses to exit, break the loop
        if (n == 4) 
        {
            flag = 0;
            break;
        }

        // Variables to store search input and control flags
        char name[50];
        char phone[11];
        char email[50];
        int found = 0;
        int matchCount = 0;
        int i;

        // Perform search based on the user's choice
        switch (n) {
        case 1:  // Search by Name
            printf("Enter the name: ");
            scanf(" %[^\n]", name); 
             // Read the full name
            for ( i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].name, name) == 0) {
                    found = 1;
                    matchCount++;
                }
                printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);    
            }
            if(matchCount==1){
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);    
            }
            if(matchCount>1)
            {
               printf("similar contact found");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);   
            }
                break;
            
                
            
            if (found == 0) {
                printf("Contact not found\n");
            }
            break;

        case 2:  // Search by Mobile Number
            printf("Enter the mobile number: ");
            scanf(" %[^\n]", phone);  // Read the phone number
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].phone, phone) == 0) {
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Contact not found\n");
            }
            break;

        case 3:  // Search by Email
            printf("Enter the email: ");
            scanf(" %[^\n]", email);  // Read the email
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].email, email) == 0) {
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Contact not found\n");
            }
            break;

        default:  // Invalid choice
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}


    
void editContact(AddressBook *addressBook) {
    if (addressBook->contactCount == 0) {
        printf("No contacts available to edit!\n");
        return;
    }

    char modify[50];
    printf("Enter the name, phone number, or email of the contact to edit: ");
    scanf(" %[^\n]", modify);

    int found = 0;
    int index = -1;

    // Search for the contact by name, phone number, or email
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, modify) == 0 ||
            strcmp(addressBook->contacts[i].phone, modify) == 0 ||
            strcmp(addressBook->contacts[i].email, modify) == 0) 
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
        return;
    }

    // Contact found, display current details
    printf("Contact found!\n");
    printf("Name: %s\n", addressBook->contacts[index].name);
    printf("Phone: %s\n", addressBook->contacts[index].phone);
    printf("Email: %s\n", addressBook->contacts[index].email);



    // Ask user what they want to edit
    int choice;
    printf("What would you like to edit?\n1. Name\n2. Phone number\n3. Email\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Edit Name
            printf("Enter new name: ");
            char newName[50];
            scanf(" %[^\n]", newName);
            while (validate_name(newName) == 1) {
                printf("Invalid name. Please enter a valid name: ");
                scanf(" %[^\n]", newName);
            }
            strcpy(addressBook->contacts[index].name, newName);
            printf("Name updated successfully!\n");
            break;
        case 2:
            // Edit Phone Number
            printf("Enter new phone number: ");
            char newPhone[20];
            scanf(" %[^\n]", newPhone);
            while (validate_number(newPhone) == 1) {
                printf("Invalid phone number. Please enter a valid 10-digit number: ");
                scanf(" %[^\n]", newPhone);
            }
            strcpy(addressBook->contacts[index].phone, newPhone);
            printf("Phone number updated successfully!\n");
            break;
        case 3:
            // Edit Email
            printf("Enter new email: ");
            char newEmail[50];
            scanf(" %[^\n]", newEmail);
            while (validate_gmail(newEmail) == 1) {
                printf("Invalid email. Please enter a valid Gmail address: ");
                scanf(" %[^\n]", newEmail);
            }
            strcpy(addressBook->contacts[index].email, newEmail);
            printf("Email updated successfully!\n");
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
    }
} 


void deleteContact(AddressBook *addressBook) 
{
    if (addressBook->contactCount == 0) {
        printf("No contacts available to delete!\n");
        return;
    }

    char delete[50];
    printf("Enter the name or phone number or email of the contact to delete: ");
    scanf(" %[^\n]", delete);

    int found = 0;

    // Iterate through the contacts to find a match
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, delete) == 0 ||
            strcmp(addressBook->contacts[i].phone, delete) == 0 ||
            strcmp(addressBook->contacts[i].email, delete) == 0) 
        {
            found = 1;
            printf("Contact found!\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);


            // Shift the rest of the contacts up to delete the found contact
            for (int j = i; j < addressBook->contactCount - 1; j++) {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;  // Decrease the contact count
            printf("Contact deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}


void listContacts(AddressBook *addressBook)
{

     printf("List of the contacts:\n\n");
     printf("Name:\t\t\t Number:\t\t\tgmail:\t\t\n\n");
      for (int i = 0; i < addressBook->contactCount; i++)
    {
         printf("%-20s\t %-20s\t %-20s\n",  addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    } 
}

