#include <stdio.h>
#include <string.h>

// Maximum number of users
#define MAX_USERS 10

// Structure to represent a user
struct User {
    char username[50];
    char password[50];
};

// Array to store user data
struct User users[MAX_USERS];
int userCount = 0;

// Function to register a new user
void registerUser() {
    if (userCount < MAX_USERS) {
        struct User newUser;
        
        printf("Enter a username: ");
        scanf("%s", newUser.username);
        
        printf("Enter a password: ");
        scanf("%s", newUser.password);
        
        users[userCount] = newUser;
        userCount++;
        
        printf("Registration successful!\n");
    } else {
        printf("Maximum number of users reached. Registration failed.\n");
    }
}

// Function to log in a user
void loginUser() {
    char username[50];
    char password[50];
    
    printf("Enter your username: ");
    scanf("%s", username);
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful! Welcome, %s.\n", users[i].username);
            return;
        }
    }
    
    printf("Login failed. Invalid username or password.\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

