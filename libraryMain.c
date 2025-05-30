#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main() {
    Book library[MAX_BOOKS];
    User users[MAX_USERS];
    int bookCount = 0, userCount = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Edit Book\n");
        printf("3. Delete Book\n");
        printf("4. Display Books\n");
        printf("5. Add User\n");
        printf("6. Edit User\n");
        printf("7. Delete User\n");
        printf("8. Display Users\n");
        printf("9. Borrow Book\n");
        printf("10. Return Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                editBook(library, bookCount);
                break;
            case 3:
                deleteBook(library, &bookCount);
                break;
            case 4:
                displayBooks(library, bookCount);
                break;
            case 5:
                addUser(users, &userCount);
                break;
            case 6:
                editUser(users, userCount);
                break;
            case 7:
                deleteUser(users, &userCount);
                break;
            case 8:
                displayUsers(users, userCount);
                break;
            case 9: {
                int userId, bookId;
                printf("Enter user ID: ");
                scanf("%d", &userId);
                printf("Enter book ID: ");
                scanf("%d", &bookId);
                borrowBook(library, users, userCount, bookCount, userId, bookId);
                break;
            }
            case 10: {
                int userId, bookId;
                printf("Enter user ID: ");
                scanf("%d", &userId);
                printf("Enter book ID: ");
                scanf("%d", &bookId);
                returnBook(library, users, userCount, bookCount, userId, bookId);
                break;
            }
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}