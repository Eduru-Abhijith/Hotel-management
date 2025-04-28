
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50

// Structure to represent a room
typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int isBooked;
} Room;

// Function to display all rooms
void displayRooms(Room rooms[], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].isBooked == 0) {
            printf("Room %d: Available\n", rooms[i].roomNumber);
        } else {
            printf("Room %d: Booked by %s\n", rooms[i].roomNumber, rooms[i].guestName);
        }
    }
}

// Function to book a room
void bookRoom(Room rooms[], int numRooms, int roomNumber, char* guestName) {
    if (roomNumber >= 1 && roomNumber <= numRooms) {
        if (rooms[roomNumber - 1].isBooked == 0) {
            rooms[roomNumber - 1].isBooked = 1;
            strcpy(rooms[roomNumber - 1].guestName, guestName);
            printf("Room %d booked successfully.\n", roomNumber);
        } else {
            printf("Room %d is already booked.\n", roomNumber);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

// Function to cancel a booking
void cancelBooking(Room rooms[], int numRooms, int roomNumber) {
    if (roomNumber >= 1 && roomNumber <= numRooms) {
        if (rooms[roomNumber - 1].isBooked == 1) {
            rooms[roomNumber - 1].isBooked = 0;
            strcpy(rooms[roomNumber - 1].guestName, "");
            printf("Booking cancelled for room %d.\n", roomNumber);
        } else {
            printf("Room %d is not booked.\n", roomNumber);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

int main() {
    int numRooms;
    printf("Enter the number of rooms: ");
    scanf("%d", &numRooms);

    Room rooms[numRooms];
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = 0;
        strcpy(rooms[i].guestName, "");
    }

    while (1) {
        printf("\nHotel Room Booking System\n");
        printf("1. Display Rooms\n");
        printf("2. Book Room\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2: {
                int roomNumber;
                char guestName[MAX_NAME_LENGTH];
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter guest name: ");
                scanf("%s", guestName);
                bookRoom(rooms, numRooms, roomNumber, guestName);
                break;
            }
            case 3: {
                int roomNumber;
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                cancelBooking(rooms, numRooms, roomNumber);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}
