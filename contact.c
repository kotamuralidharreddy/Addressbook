#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
// Validate that the name contains only alphabets and spaces
int validate_name(char *name)
{
    int i = 0;
    while (name[i] != '\0')
    {
        if (!(isalpha(name[i]) || name[i] == ' '))
        {
            return 1; // Invalid name
        }
        i++;
    }
    return 0; // Valid name
}

// Validate that the phone number has exactly 10 digits
int validate_number(char *num)
{
    int len = strlen(num);
    if (len != 10)
    {
        return 1; // Invalid length
    }
    int i = 0;
    while (num[i] != '\0')
    {
        if (!isdigit(num[i]))
        {
            return 1; // Invalid character
        }
        i++;
    }
    return 0; // Valid number
}

// Check if the phone number is unique in the address book
int unique_number(AddressBook *addressBook, char *num)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, num) == 0)
        {
            return 1; // Phone number already exists
        }
    }
    return 0; // Phone number is unique
}

// Validate that the email ends with '@gmail.com'
int validate_gmail(char *email)
{
    char check[100] = "@gmail.com";
    // Check if email ends with "@gmail.com"
    if (!(strstr(email, check)))
    {
        return 1; // Invalid email
    }
    return 0; // Valid email
}

// Check if the email is unique in the address book
int unique_email(AddressBook *addressBook, char *email)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, email) == 0)
        {
            return 1; // Email is not unique
        }
    }
    return 0; // Email is unique
}

// Create a new contact and validate the inputs
void createContact(AddressBook *addressBook)
{
    // Input name
    char name[50];
    printf("Enter the name: ");
    scanf(" %[^\n]", name);
    while (validate_name(name) == 1)
    {
        printf("Name validation not done, please enter a valid name...\n");
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);

    // Input phone number
    char num[11]; // 10 digits + null terminator
    printf("Enter the mobile number: ");
    scanf(" %[^\n]", num);
    while (validate_number(num) == 1 || unique_number(addressBook, num) == 1)
    {
        printf("Phone numberis not valid & already exist, Please enter a valid unique number...\n");
        printf("Enter the mobile number: ");
        scanf(" %[^\n]", num);
    }
    strcpy(addressBook->contacts[addressBook->contactCount].phone, num);

    // Input email address
    char email[50];
    printf("Enter the email address: ");
    scanf(" %[^\n]", email);
    while (validate_gmail(email) == 1 || unique_email(addressBook, email) == 1)
    {
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
void searchContact(AddressBook *addressBook)
{
    int flag = 1; // Control the search loop
    int n;

    while (flag)
    {
        // Prompt the user to choose the search criteria
        printf("Enter your choice:\n1. Name\n2. Mobile number\n3. Email\n4. Exit\nEnter choice: ");
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
        int found = 0;      // Flag to check if any match is found
        int matchCount = 0; // Count of similar contacts
        int i;

        // Perform search based on the user's choice
        switch (n)
        {
        case 1: // Search by Name
            printf("Enter the name: ");
            scanf(" %[^\n]", name); // Read the full name

            for (i = 0; i < addressBook->contactCount; i++)
            {
                // Use strcasecmp to compare names in a case-insensitive manner
                if (strcasecmp(addressBook->contacts[i].name, name) == 0)
                {
                    // If a match is found
                    found = 1;
                    matchCount++;

                    // Print the contact details
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                }
            }

            // Check if no contact was found
            if (found == 0)
            {
                printf("Contact not found.\n");
            }
            else if (matchCount > 1)
            {
                printf("Note: %d similar contacts found.\n", matchCount);
            }
            break;

        case 2: // Search by Mobile Number
            printf("Enter the mobile number: ");
            scanf(" %[^\n]", phone); // Read the phone number
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].phone, phone) == 0)
                {
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Contact not found\n");
            }
            break;

        case 3: // Search by Email
            printf("Enter the email: ");
            scanf(" %[^\n]", email); // Read the email
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].email, email) == 0)
                {
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Contact not found\n");
            }
            break;

        default: // Invalid choice
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}

void editContact(AddressBook *addressBook)
{
    int n;
    int flag = 1; // Control flag for menu loop
    while (flag)
    {
        // Menu for searching contacts
        printf("Search the contact by:\n1.Name\n2.Mobile number\n3.Email\n4.Exit\n enter the chioce:");
        scanf("%d", &n);
        if (n == 4)
        {
            flag = 0; // Exit the loop
            break;
        }

        char name[100];
        char phone[100];
        char email[100];
        int found = 0;
        int count = 0;
        int j = -1;  // Index of found contact

        // Switch case to search by different criteria
        switch (n)
        {
            case 1:
                printf("Enter the current contact name: ");
                scanf(" %[^\n]", name);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcasecmp(addressBook->contacts[i].name, name) == 0)
                    {
                        found = 1;
                        j = i; // Store index of found contact
                        count++;
                     printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                    }
                }

                if (count > 1)
                {
                    printf("Similar names found and then select exit  choice Please refine your search \n");
                    break;
                }
                if (!found)
                {
                    printf("Contact not found.\n");
                    break;
                }

                break;

            case 2:
                // Search by mobile number
                printf("Enter the current contact mobile number: ");
                scanf(" %[^\n]", phone);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].phone, phone) == 0)
                    {
                        found = 1;
                        j = i;
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                        break;  // Assume there's only one unique mobile number
                    }
                }

                if (!found)
                {
                    printf("Contact not found.\n");
                    break;
                }

                break;

            case 3:
                printf("Enter the current contact email: ");
                scanf(" %[^\n]", email);
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].email, email) == 0)
                    {
                        found = 1;
                        j = i;
                    printf("Contact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n\n", addressBook->contacts[i].email);
                        break;  // Assume there's only one unique email
                    }
                }

                if (!found)
                {
                    printf("Contact not found.\n");
                    break;
                }

                break;

            case 4:
                printf("Exiting menu.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        

        // If contact was found, proceed to edit
        if (found && j != -1)
        {
           /* printf("Name: %s\n", addressBook->contacts[j].name);
            printf("Mobile Number: %s\n", addressBook->contacts[j].phone);
            printf("Email: %s\n", addressBook->contacts[j].email);
            */

            int modify;
            printf("What do you want to edit?\n1.Name\n2.Mobile number\n3.Email\n4.Exit\n enter the choice:");
            scanf("%d", &modify);

            switch (modify)
            {
                case 1:
                    printf("Enter the new name: ");
                    scanf(" %[^\n]", name);
                    while (validate_name(name) == 1)
                    {
                        printf(" Name validation failed. Please enter a valid name: ");
                        scanf(" %[^\n]", name);
                    }
                    strcpy(addressBook->contacts[j].name, name);
                    printf("Name successfully edited.\n");
                    break;

                case 2:
                    printf("Enter the new mobile number: ");
                    scanf(" %[^\n]", phone);
                    while (validate_number(phone) == 1)
                    {
                        printf("Mobile number validation failed. Please enter a valid number: ");
                        scanf(" %[^\n]", phone);
                    }
                    while (unique_number(addressBook, phone) == 1)
                    {
                        printf("Number already exists. Please enter a unique mobile number: ");
                        scanf(" %[^\n]", phone);
                    }
                    strcpy(addressBook->contacts[j].phone, phone);
                    printf("Mobile number successfully edited.\n");
                    break;

                case 3:
                    printf("Enter the new email: ");
                    scanf(" %[^\n]", email);
                    while (validate_gmail(email) == 1)
                    {
                        printf(" Email validation failed. Please enter a valid email: ");
                        scanf(" %[^\n]", email);
                    }
                    while (unique_email(addressBook, email) == 1)
                    {
                        printf("Email already exists. Please enter a unique email: ");
                        scanf(" %[^\n]", email);
                    }
                    strcpy(addressBook->contacts[j].email, email);
                    printf("Email successfully edited.\n");
                    break;

                case 4:
                    printf("Exiting edit menu.\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    }
}


void deleteContact(AddressBook *addressBook) 
{
    int flag = 1; // Control flag for menu loop
    while (flag)
     {
        // Menu for deleting contacts
        printf("Delete the contact by:\n1.Name\n2.Mobile number\n3.Email\n4.Exit\nEnter your choice: ");
        int n;
        scanf("%d", &n);

        if (n == 4) {
            flag = 0; // Exit the loop
            break;
        }

        char name[100];
        char phone[100];
        char email[100];
        int found = 0; // Flag to check if a contact is found
        int count = 0; // Counter for similar contacts
        int j = -1; // Index of found contact

        switch (n) {
            case 1:
                // Delete by name
                printf("Enter the contact name to delete: ");
                scanf(" %[^\n]", name);
                for (int i = 0; i < addressBook->contactCount; i++) {
                    if (strcasecmp(addressBook->contacts[i].name, name) == 0) {
                        found = 1;
                        j = i; // Store index of found contact
                        count++;
                        printf("Contact found:\n");
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);
                    }
                }

                if (count > 1) {
                    printf("Multiple similar names found. Please refine your search.\n");
                } else if (!found) {
                    printf("Contact not found.\n");
                } else {
                    // Confirm deletion
                    char confirm;
                    printf("Are you sure you want to delete this contact? (y/n): ");
                    scanf(" %c", &confirm);

                    if (confirm == 'y') {
                        // Remove contact from the array
                        for (int i = j; i < addressBook->contactCount - 1; i++) {
                            addressBook->contacts[i] = addressBook->contacts[i + 1];
                        }
                        addressBook->contactCount--;
                        printf("Contact deleted successfully!\n");
                    } else {
                        printf("Deletion cancelled.\n");
                    }
                }
                break;

            case 2:
                // Delete by mobile number
                printf("Enter the contact mobile number to delete: ");
                scanf(" %[^\n]", phone);
                for (int i = 0; i < addressBook->contactCount; i++) {
                    if (strcmp(addressBook->contacts[i].phone, phone) == 0) {
                        found = 1;
                        j = i; // Store index of found contact
                        printf("Contact found:\n");
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Mobile number: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);
                        break; // Assume there's only one unique mobile number
                    }
                }

                if (!found) {
                    printf("Contact not found.\n");
                } else {
                    // Confirm deletion
                    char confirm;
                    printf("Are you sure you want to delete this contact? (y/n): ");
                    scanf(" %c", &confirm);

                    if (confirm == 'y') {
                        // Remove contact from the array
                        for (int i = j; i < addressBook->contactCount - 1; i++) {
                            addressBook->contacts[i] = addressBook->contacts[i + 1];
                        }
                        addressBook->contactCount--;
                        printf("Contact deleted successfully!\n");
                    } else {
                        printf("Deletion cancelled.\n");
                    }
                }
                break;

            case 3:
                // Delete by email
                printf("Enter the contact email to delete: ");
                scanf(" %[^\n]", email);
                for (int i = 0; i < addressBook->contactCount; i++) {
                    if (strcmp(addressBook->contacts[i].email, email) == 0) {
                        found = 1;
                        j = i; // Store index of found contact
                        printf("Contact found:\n");
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Mobile number: %s\n", addressBook->contacts[i].phone);


                    }
                }
        }
     }
}
   

void listContacts(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0) 
    {
        printf("No contacts available.\n");
        return;
    }

    // Sorting contacts alphabetically by name
    // Bubble sort for simplicity ( more efficient sorting algorithms)
    for (int i = 0; i < addressBook->contactCount - 1; i++) 
    {
        for (int j = i + 1; j < addressBook->contactCount; j++) 
        {
            if (strcasecmp(addressBook->contacts[i].name, addressBook->contacts[j].name) > 0)
             {
                // Swap contacts[i] and contacts[j]
                Contact temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }

    // Print the list of contacts
    printf("List of Contacts:\n");
    printf("------------------------------------------------------------\n");
    printf("%-20s %-20s %-30s\n", "Name", "Number", "Email");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("%-20s %-20s %-30s\n", 
            addressBook->contacts[i].name, 
            addressBook->contacts[i].phone, 
            addressBook->contacts[i].email);
    }

    printf("------------------------------------------------------------\n");
    printf("Total Contacts: %d\n", addressBook->contactCount);
}
