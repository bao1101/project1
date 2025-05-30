#include <stdio.h>
#include "library.h"

int main() {
    Book library[MAX_BOOKS];
    User users[MAX_USERS];
    int bookCount = 0, userCount = 0;
    int choice, userId, bookId;
    char keyword[100];

    while (1) {
        printf("\n Library Management System \n");
        printf("1. Add book\n2. Edit book\n3. Delete book\n4. Search book\n5. Display available books\n");
        printf("6. Add user\n7. Edit user\n8. Delete user\n9. Borrow book\n10. Return book\n11. Display users and their borrowed books\n12. Exit\n");
        printf("Choose an option: ");
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
                printf("Enter keyword to search (title or author): ");
                scanf(" %[^\n]", keyword);
                searchBook(library, bookCount, keyword);
                break;
            case 5:
                displayAvailableBooks(library, bookCount);
                break;
            case 6:
                addUser(users, &userCount);
                break;
            case 7:
                editUser(users, userCount);
                break;
            case 8:
                deleteUser(users, &userCount);
                break;
            case 9:
                printf("Enter user ID: ");
                scanf("%d", &userId);
                printf("Enter book ID to borrow: ");
                scanf("%d", &bookId);
                borrowBook(library, users, userCount, bookCount, userId, bookId);
                break;
            case 10:
                printf("Enter user ID: ");
                scanf("%d", &userId);
                printf("Enter book ID to return: ");
                scanf("%d", &bookId);
                returnBook(library, users, userCount, bookCount, userId, bookId);
                break;
            case 11:
                displayUserLoans(users, userCount, library, bookCount);
                break;
            case 12:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please enter a valid option.\n");
        }
    }
}
