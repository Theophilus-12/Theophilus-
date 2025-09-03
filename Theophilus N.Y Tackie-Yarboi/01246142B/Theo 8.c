#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100

// Structure to store book information
struct Book {
    int id;
    char title[50];
    char author[50];
};

// Global variables
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function declarations
void addBook();
void viewBooks();
void searchBook();
void removeBook();

// Helpers
static void trimNewline(char *s);
static int caseInsensitiveCompare(const char *a, const char *b);

int main() {
    int choice;

    do {
        printf("\n=== Library Management System ===\n");
        printf("1. Add a new book\n");
        printf("2. View all books\n");
        printf("3. Search for a book\n");
        printf("4. Remove a book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        getchar(); // consume newline

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: removeBook(); break;
            case 5: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new book
void addBook() {
    struct Book newBook;

    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    newBook.id = bookCount + 1;

    printf("Enter book title: ");
    if (fgets(newBook.title, sizeof(newBook.title), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    trimNewline(newBook.title);

    printf("Enter author name: ");
    if (fgets(newBook.author, sizeof(newBook.author), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    trimNewline(newBook.author);

    if (newBook.title[0] == '\0' || newBook.author[0] == '\0') {
        printf("Title and author cannot be empty!\n");
        return;
    }

    library[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully! ID = %d\n", newBook.id);
}

// Function to view all books
void viewBooks() {
    int i;

    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s\n", 
                library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book
void searchBook() {
    char searchTitle[50];
    int i;

    printf("Enter book title to search: ");
    if (fgets(searchTitle, sizeof(searchTitle), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    trimNewline(searchTitle);

    for (i = 0; i < bookCount; i++) {
        if (caseInsensitiveCompare(library[i].title, searchTitle) == 0) {
            printf("Book found! ID: %d | Title: %s | Author: %s\n",
                   library[i].id, library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found!\n");
}

// Function to remove a book
void removeBook() {
    int id, i, found;

    printf("Enter book ID to remove: ");
    if (scanf("%d", &id) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid ID input.\n");
        return;
    }
    getchar(); // consume newline

    found = -1;
    for (i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    for (i = found; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
        library[i].id = i + 1; // reassign IDs to stay contiguous
    }
    bookCount--;

    printf("Book removed successfully.\n");
}

// --- Helpers ---

static void trimNewline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

static int caseInsensitiveCompare(const char *a, const char *b) {
    unsigned char ca, cb;
    while (*a && *b) {
        ca = (unsigned char)tolower((unsigned char)*a);
        cb = (unsigned char)tolower((unsigned char)*b);
        if (ca != cb) return (int)ca - (int)cb;
        a++; b++;
    }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}

