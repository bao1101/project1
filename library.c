#include <stdio.h>
#include <string.h>
#include "library.h"

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf(" Cannot add more books, library is full.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &library[*count].id);
    printf("Enter book title: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", library[*count].author);

    library[*count].isBorrowed = 0;
    (*count)++;

    printf(" Book \"%s\" added successfully!\n", library[*count - 1].title);
}

void editBook(Book library[], int count) {
    int id, found = 0;
    printf("Enter the book ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("Enter new title: ");
            scanf(" %[^\n]", library[i].title);
            printf("Enter new author name: ");
            scanf(" %[^\n]", library[i].author);
            found = 1;
            printf(" Book details updated!\n");
            break;
        }
    }

    if (!found) {
        printf("Book ID %d not found!\n", id);
    }
}
 
void deleteBook(Book library[], int *count) {
    int id, found = 0;
    printf("Enter the book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1]; // Shift elements
            }
            (*count)--;
            found = 1;
            printf(" Book deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf(" Book ID %d not found!\n", id);
    }
}

void borrowBook(Book library[], User users[], int userCount, int bookCount, int userId, int bookId) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == bookId && library[i].isBorrowed == 0) {
            for (int j = 0; j < userCount; j++) {
                if (users[j].userId == userId) {
                    if (users[j].borrowedCount >= MAX_BORROWED) {
                        printf(" User has reached the borrowing limit!\n");
                        return;
                    }

                    users[j].borrowedBooks[users[j].borrowedCount] = bookId;
                    users[j].borrowedCount++;
                    library[i].isBorrowed = 1;
                    printf(" User %d borrowed book \"%s\"!\n", userId, library[i].title);
                    return;
                }
            }
        }
    }
    printf("Cannot borrow book!\n");
}

void returnBook(Book library[], User users[], int userCount, int bookCount, int userId, int bookId) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].userId == userId) {
            for (int j = 0; j < users[i].borrowedCount; j++) {
                if (users[i].borrowedBooks[j] == bookId) {
                    library[bookId].isBorrowed = 0;
                    users[i].borrowedBooks[j] = -1; // Remove book from borrowed list
                    users[i].borrowedCount--;
                    printf(" User %d returned book \"%s\"!\n", userId, library[bookId].title);
                    return;
                }
            }
        }
    }
    printf(" Book not found in borrowed list!\n");
}

void searchBook(Book library[], int count, const char *keyword) {
    printf("\n Searching for \"%s\":\n", keyword);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, keyword) || strstr(library[i].author, keyword)) {
            printf(" ID: %d | Title: %s | Author: %s | %s\n",
                   library[i].id, library[i].title, library[i].author,
                   library[i].isBorrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf(" No matching books found!\n");
    }
}

void displayAvailableBooks(Book library[], int count) {
    printf("\nAvailable Books:\n");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (library[i].isBorrowed == 0) {
            printf(" ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
        }
    }

    if (!found) {
        printf(" No available books!\n");
    }
}

void addUser(User users[], int *count) {
    if (*count >= MAX_USERS) {
        printf(" Cannot add more users, maximum limit reached.\n");
        return;
    }

    printf("Enter user ID: ");
    scanf("%d", &users[*count].userId);
    printf("Enter user name: ");
    scanf(" %[^\n]", users[*count].name);

    users[*count].borrowedCount = 0; // Initialize borrowed book count
    (*count)++;

    printf(" User \"%s\" added successfully!\n", users[*count - 1].name);
}

void editUser(User users[], int count) {
    int id, found = 0;
    printf("Enter the user ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (users[i].userId == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", users[i].name);
            found = 1;
            printf(" User details updated!\n");
            break;
        }
    }

    if (!found) {
        printf(" User ID %d not found!\n", id);
    }
}

void deleteUser(User users[], int *count) {
    int id, found = 0;
    printf("Enter the user ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (users[i].userId == id) {
            for (int j = i; j < *count - 1; j++) {
                users[j] = users[j + 1]; 
            }
            (*count)--;
            found = 1;
            printf(" User deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf(" User ID %d not found!\n", id);
    }
}

void displayUserLoans(User users[], int userCount, Book library[], int bookCount) {
    printf("\n User Information & Borrowed Books:\n");

    for (int i = 0; i < userCount; i++) {
        printf("\n👤 ID: %d | Name: %s\n", users[i].userId, users[i].name);
        printf(" Borrowed Books:\n");

        int found = 0;
        for (int j = 0; j < users[i].borrowedCount; j++) {
            int bookId = users[i].borrowedBooks[j];

            // Find book details
            for (int k = 0; k < bookCount; k++) {
                if (library[k].id == bookId) {
                    printf(" ID: %d | Title: %s | Author: %s\n",
                           library[k].id, library[k].title, library[k].author);
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("No books currently borrowed.\n");
        }
    }
}

