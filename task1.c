#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS];
int userCount = 0;

int main() {
    int choice;
    do {
        printf("Welcome to the User Management System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User database is at full capacity. Cannot register more users at this time.\n");
        return;
    }

    User newUser;
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    printf("Enter a password: ");
    scanf("%s", newUser.password);

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful!\n");
}

void loginUser() {
    char username[50];
    char password[50];
    int loggedIn = 0;

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful! Welcome, %s.\n", username);
            loggedIn = 1;
            break;
        }
    }

    if (!loggedIn) {
        printf("Login failed. Please check your credentials and try again.\n");
    }
}
