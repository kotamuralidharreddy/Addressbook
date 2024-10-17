
           
-------------------------------------------------------------------------------------------------------------------------------------------------


                                                       Title of the project
                                                      ----------------------

                                                       -------------------
                                                       |   Address Book |
                                                       -------------------


                                                     Name                 :kota muralidhar reddy
                                                     Batch                :24021E
                                                     Roll No              :24021__006
                                                     Institute            :Emertxe Information Technologies
                                                     Mentor               :Ms.Anusha
                                                     Lab mentor 1         :Mr.poorvasan
                                                     Lab mentor 2         :Mr.Biplap
                                                     Project Guides       :Mr.poorvasan,Mr.Biplap
                                                     Project title        :Address Book
                                                     Type                 :Individual project
                                                     Diffculty            :Intermediate
                                                     Estimated time       :120 hours
                                                     contact              :kota.muralidharreddy@gmail.com  
                                                     Available      :github:https://github.com/kotamuralidharreddy/Addressbook                  



Title of the project  :  Address Book
 mentor guidence: Mr.poorvasan,
                      Mr.Biplap
-------------------------------------------------------------------------------------------------------------------------------------------------

                                                        ------------- 
                                                       |  Contents  |
                                                       --------------
 Abstract:
 1.Introduction
 2.Requirements
 3.Prerequisites
 4.Design
 5.Output
 6.Artifacts
 7.Skeleton Code 
 8.References
-------------------------------------------------------------------------------------------------------------------------------------------------
                                                            ----------
                                                            |Abstract:|
                                                             ---------

Address Book is a small application written in C language. It keeps track of names and telephone/mobile numbers and e-mail addresses. It is a console based application which uses standard I/O for adding and deleting contact names, phone numbers and e-mail addresses, searching names and associated numbers and email addresses, updating numbers and email addresses, and deleting contacts.
-------------------------------------------------------------------------------------------------------------------------------------------------



                                                            -----------------
                                                           | 1.Introduction: |
                                                            -----------------

The Address Book application is a basic contact management tool written in C. It serves as a lightweight utility to store, manage, and organize personal contact information, such as names, phone numbers, and email addresses. Designed to be a console-based program, it allows users to perform various operations like adding new contacts, searching for existing ones, editing contact details, and deleting unwanted entries.

The primary goal of the Address Book is to provide a user-friendly way to handle contact information without the need for complex graphical interfaces. By leveraging standard input and output functions, the application delivers an interactive and straightforward experience. It also incorporates file handling capabilities, enabling users to save contact information for future retrieval, ensuring data persistence across sessions.

This project serves as a practical introduction to important programming concepts such as file I/O, data structures, dynamic memory allocation, and string manipulation, making it an ideal project for learners who want to strengthen their understanding of C programming while creating a functional application.


   
-------------------------------------------------------------------------------------------------------------------------------------------------

                                                            ------------------
                                                            | 2. Requirements: |
                                                            ------------------


     -------------
•   | Add Contact: |
     -------------

◦    Add a contact giving user name
◦    Add phone numbers to the newly added contact
◦    Add e-mail addresses to the newly added contact

     ---------------
•    |Search Contact:|
     ---------------

◦    Search a contact by name.
◦    Search contact by phone number.
◦    Search contact by e-mail address.

     --------------
•    |Edit Contact:|
     --------------

◦    Edit by name.
◦    Edit contact by phone number.
◦    Edit contact by email address.

     -----------------
•    |Delete contact:|
     -----------------

     Delete by name.
◦    Delete contact by phone number.
◦    Delete contact by email address.

◦    -------------------
•    |List all contacts:|
     -------------------

     list of contacts in sorted manner

     -----------------------
•   | Save the address book:|
     ----------------------

     created contact should be save in address book of .csvfile,.txtflie

      ----------------------
.    | Exit the application:|
      ----------------------

      save contact and exit the application

-------------------------------------------------------------------------------------------------------------------------------------------------


                                                        -----------------
                                                       |3. Prerequisites|
                                                       ------------------
• File I/O
• String Handling
• Pointers, Structures and Dynamic Memory Handling

-------------------------------------------------------------------------------------------------------------------------------------------------

                                                      --------------
                                                      |  4.Design  |
                                                      --------------








-------------------------------------------------------------------------------------------------------------------------------------------------

                                                       ------------
                                                       | 5.Output |
                                                       ------------
kota@murali:/mnt/c/Users/Mural/OneDrive/Desktop/emerxte course/projects/AddressBook-NewDesign/Addressbook$ gcc *.c
kota@murali:/mnt/c/Users/Mural/OneDrive/Desktop/emerxte course/projects/AddressBook-NewDesign/Addressbook$ ./a.out

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice:

                                                     
     -------------
•   | Add Contact: |
     -------------

     Add a contact giving user name
◦    Add phone numbers to the newly added contact
◦    Add e-mail addresses to the newly added contact

Enter your choice: 1
Enter the name: emertxe
Enter the mobile number:  8095557332
Enter the email address: training@emertxe.com
Email is not valid &  already exist , Please enter a valid unique email...
Enter the email address: training@gmail.com              
Contact created successfully.


Enter your choice: 6
Contacts saved successfully.
Saving and Exiting...

_________________________________________________________________________________________________________________________________________________
     -------------------
•    |List all contacts:|
     -------------------

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5

List of Contacts:
------------------------------------------------------------
Name                 Number               Email
------------------------------------------------------------
aditya               7829639797           aditya@gmail.com
Ajay                 1234567899           v@gmail.com
Amma                 7891252543           A@gmail.com
arun                 8289901703           arun@gmail.com
biplap sir           8789029730           bilap@gmail.com
----------------------------------------------------------------
|emertxe              8095557332           training@gmail.com  |
----------------------------------------------------------------
jay                  7550326052           aj@gmail.com
karthik              9535409589           karthik@gmail.com
mani                 9989356678           manikanta321@gmail.com
murali               7995287103           muralidhar@gmail.com
murali               9640204346           reddy@gmail.com
poorvasan sir        9360038223           poorvasan@gmail.com
praveen              9578572240           praveen17@gmail.com
roshan               9900694586           roshan@gmail.com
somu                 9381723305           gsomu@gmail.com
srinivasan           9629405162           srinivas@gmail.com
sudeep               6362841101           sudeep@gmail.com
varun                7892868298           varun@gmail.com
vishnu               9677835895           vk@gmail.com
vishwanth            8489061215           vishwanth@gmail.com
------------------------------------------------------------
Total Contacts: 20


-------------------------------------------------------------------------------------------------------------------------------------------------
     -----------------------
•   | Save the address book:|
     ----------------------

Enter your choice: 6
Contacts saved successfully.
Saving and Exiting...


_________________________________________________________________________________________________________________________________________________
    
                                                             ----------------
•                                                            |Search Contact:|
                                                              ---------------
_________________________________________________________________________________________________________________________________________________

◦    Search a contact by name.
◦    Search contact by phone number.
◦    Search contact by e-mail address.

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 2

---------------------------
{Search a contact by name.}
---------------------------

Enter your choice:
1. Name
2. Mobile number
3. Email
4. Exit
Enter choice: 1
Enter the name: emertxe
Contact found:
Name: emertxe
Mobile number: 8095557332
Email: training@gmail.com

---------------------------
{Search a contact by number.}
---------------------------

Enter your choice:
1. Name
2. Mobile number
3. Email
4. Exit
Enter choice: 2             
Enter the mobile number: 8095557332
Contact found:
Name: emertxe
Mobile number: 8095557332
Email: training@gmail.com

---------------------------
{Search a contact by email.}
---------------------------

Enter your choice:
1. Name
2. Mobile number
3. Email
4. Exit
Enter choice: 3
Enter the email: training@gmail.com
Contact found:
Name: emertxe
Mobile number: 8095557332
Email: training@gmail.com

------
{exit}
------
Enter your choice:
1. Name
2. Mobile number
3. Email
4. Exit
Enter choice: 4


_________________________________________________________________________________________________________________________________________________

                                                       --------------
                                                       |Edit Contact:|
                                                       --------------
_________________________________________________________________________________________________________________________________________________

◦    Edit by name.
◦    Edit contact by phone number.
◦    Edit contact by email address.

---------------
  Edit by name.
----------------


Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 3
Search the contact by:
1.Name
2.Mobile number
3.Email
4.Exit
 enter the chioce:1
Enter the current contact name: emertxe
Contact found:
Name: emertxe
Mobile number: 8095557332
Email: training@gmail.com

What do you want to edit?
1.Name
2.Mobile number
3.Email
4.Exit
 enter the choice:1
Enter the new name: emertxe info tech
Name successfully edited.


------------------------------
Edit contact by email address.|
------------------------------

What do you want to edit?
1.Name
2.Mobile number
3.Email
4.Exit
 enter the choice:3
Enter the new email: trainingemertxe@gmail.com            
Email successfully edited.


-----------------------------
Edit contact by phone number.|
-----------------------------


Search the contact by:
1.Name
2.Mobile number
3.Email
4.Exit
 enter the chioce:2 
Enter the current contact mobile number: 8095557332
Contact found:
Name: emertxe info tech
Mobile number: 8095557332
Email: trainingemertxe@gmail.com

What do you want to edit?
1.Name
2.Mobile number
3.Email
4.Exit
 enter the choice:2
Enter the new mobile number: 8095557332
Number already exists. Please enter a unique mobile number: 8095557331
Mobile number successfully edited.
Search the contact by:
1.Name
2.Mobile number
3.Email
4.Exit
 enter the chioce:4

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 6
Contacts saved successfully.
Saving and Exiting...
kota@murali:/mnt/c/Users/Mural/OneDrive/Desktop/emerxte course/projects/AddressBook-NewDesign/Addressbook$ gcc *.c
kota@murali:/mnt/c/Users/Mural/OneDrive/Desktop/emerxte course/projects/AddressBook-NewDesign/Addressbook$ ./a.out

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5
List of Contacts:
------------------------------------------------------------
Name                 Number               Email
------------------------------------------------------------
aditya               7829639797           aditya@gmail.com
Ajay                 1234567899           v@gmail.com
Amma                 7891252543           A@gmail.com
arun                 8289901703           arun@gmail.com
biplap sir           8789029730           bilap@gmail.com

--------------------------------------------------------------------
|emertxe info tech    8095557331           trainingemertxe@gmail.com |
--------------------------------------------------------------------

jay                  7550326052           aj@gmail.com
karthik              9535409589           karthik@gmail.com
mani                 9989356678           manikanta321@gmail.com
murali               7995287103           muralidhar@gmail.com
murali               9640204346           reddy@gmail.com
poorvasan sir        9360038223           poorvasan@gmail.com
praveen              9578572240           praveen17@gmail.com
roshan               9900694586           roshan@gmail.com
somu                 9381723305           gsomu@gmail.com
srinivasan           9629405162           srinivas@gmail.com
srinivasan           9629405162           srinivas@gmail.com
srinivasan           9629405162           srinivas@gmail.com
sudeep               6362841101           sudeep@gmail.com
srinivasan           9629405162           srinivas@gmail.com
sudeep               6362841101           sudeep@gmail.com
sudeep               6362841101           sudeep@gmail.com
varun                7892868298           varun@gmail.com
vishnu               9677835895           vk@gmail.com
vishwanth            8489061215           vishwanth@gmail.com
vishwanth            8489061215           vishwanth@gmail.com
------------------------------------------------------------
Total Contacts: 20

_________________________________________________________________________________________________________________________________________________


                                                             -----------------
•                                                            |Delete contact:|
                                                              -----------------

_________________________________________________________________________________________________________________________________________________                                                              
     Delete by name.
◦    Delete contact by phone number.
◦    Delete contact by email address.



Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 4
Delete the contact by:
1.Name
2.Mobile number
3.Email
4.Exit
Enter your choice: 1
Enter the contact name to delete: emertxe info tech
Contact found:
Name: emertxe info tech
Mobile number: 8095557331
Email: trainingemertxe@gmail.com
Are you sure you want to delete this contact? (y/n): y
Contact deleted successfully!
Delete the contact by:
1.Name
2.Mobile number
3.Email
4.Exit
Enter your choice: 2
Enter the contact mobile number to delete: 8095557331
Contact not found.
Delete the contact by:
1.Name
2.Mobile number
3.Email
4.Exit
Enter your choice: 4 

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5
List of Contacts:
------------------------------------------------------------
Name                 Number               Email
------------------------------------------------------------
aditya               7829639797           aditya@gmail.com
Ajay                 1234567899           v@gmail.com
Amma                 7891252543           A@gmail.com
arun                 8289901703           arun@gmail.com
biplap sir           8789029730           bilap@gmail.com
emertxe              8095557332           emertxe@gmail.com
------------------------------------------------------------
|                                                           |
------------------------------------------------------------

jay                  7550326052           aj@gmail.com
karthik              9535409589           karthik@gmail.com
mani                 9989356678           manikanta321@gmail.com
murali               9640204346           reddy@gmail.com
murali               7995287103           muralidhar@gmail.com
poorvasan sir        9360038223           poorvasan@gmail.com
praveen              9578572240           praveen17@gmail.com
roshan               9900694586           roshan@gmail.com
somu                 9381723305           gsomu@gmail.com
srinivasan           9629405162           srinivas@gmail.com
sudeep               6362841101           sudeep@gmail.com
varun                7892868298           varun@gmail.com
vishnu               9677835895           vk@gmail.com
vishwanth            8489061215           vishwanth@gmail.com
------------------------------------------------------------
Total Contacts: 20

Contact deleted successfully!

_________________________________________________________________________________________________________________________________________________

                                                                  -----------------  
                                                                  |  6.Artifacts  |
                                                                  -----------------
 
6.1	Skeleton Code:

   github:https://github.com/kotamuralidharreddy/Addressbook
•	
6.2	References:

•	https://en.wikipedia.org/wiki/Address_book
     www.emertxe.com/content/c-programming/code/addressbook_src.zip
     

     mentor guidence: Mr.poorvasan,
                      Mr.Biplap
               

















-------------------------------------------------------------------------------------------------------------------------------------------------