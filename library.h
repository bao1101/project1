#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define MAX_USERS 50
#define MAX_BORROWED 10


typedef struct {
    int id;
    char title[100];
    char author[100];
    int isBorrowed; 
} Book;


typedef struct {
    int userId;
    char name[50];
    int borrowedBooks[MAX_BORROWED]; 
    int borrowedCount;
} User;


void addBook(Book library[], int *count);
void editBook(Book library[], int count);
void deleteBook(Book library[], int *count);
void displayBooks(Book library[], int count);

void addUser(User users[], int *count);
void editUser(User users[], int count);
void deleteUser(User users[], int *count);
void displayUsers(User users[], int count);

void borrowBook(Book library[], User users[], int userCount, int bookCount, int userId, int bookId);
void returnBook(Book library[], User users[], int userCount, int bookCount, int userId, int bookId);

#endif // LIBRARY_H
