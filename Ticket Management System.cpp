#include <stdio.h>
#include <string.h>

struct Passenger {
    int seatNo;
    char name[50];
    char source[50];
    char destination[50];
    char date[20]; 
};

struct Passenger passengers[100];
int count = 0;

void loadPassengers() {
    FILE *fp = fopen("passengers.dat", "rb");
    if (fp != NULL) {
        count = fread(passengers, sizeof(struct Passenger), 100, fp);
        fclose(fp);
    }
}

void savePassengers() {
    FILE *fp = fopen("passengers.dat", "wb");
    if (fp != NULL) {
        fwrite(passengers, sizeof(struct Passenger), count, fp);
        fclose(fp);
    }
}

void createPassenger(int seatNo, char name[], char source[], char destination[], char date[])
 {
    passengers[count].seatNo = seatNo;
    strcpy(passengers[count].name, name);
    strcpy(passengers[count].source, source);
    strcpy(passengers[count].destination, destination);
    strcpy(passengers[count].date, date);
    count++;
    savePassengers();
    printf("Passenger added successfully!\n");
}

void readPassengers() {
    if (count == 0) {
        printf("No passenger records found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Seat No: %d | Name: %s | Source: %s | Destination: %s | Date: %s\n",
               passengers[i].seatNo, passengers[i].name, passengers[i].source,
               passengers[i].destination, passengers[i].date);
        printf("____________________________________________________________________________________\n");
    }
}

void updatePassenger(int seatNo, char newSource[], char newDestination[], char newDate[]) {
    for (int i = 0; i < count; i++) {
        if (passengers[i].seatNo == seatNo) {
        	strcpy(passengers[i].source, newSource);
            strcpy(passengers[i].destination, newDestination);
            strcpy(passengers[i].date, newDate);
            savePassengers();
            printf("Passenger details updated successfully!\n");
            return;
        }
    }
    printf("Passenger not found!\n");
}

void deletePassenger(int seatNo) {
    for (int i = 0; i < count; i++) {
        if (passengers[i].seatNo == seatNo) {
            for (int j = i; j < count - 1; j++) {
                passengers[j] = passengers[j + 1];
            }
            count--;
            savePassengers();
            printf("Passenger record deleted!\n");
            return;
        }
    }
    printf("Passenger not found!\n");
}

int main() {
    int choice, seatNo;
    char name[50], source[50], destination[50], date[20];

    loadPassengers(); 

    while (1) {
        printf("\nPassenger Seat Booking System\n");
        printf("1. Add Passenger\n");
        printf("2. View Passengers\n");
        printf("3. Update Passenger\n");
        printf("4. Delete Passenger\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Seat No: ");
                scanf("%d", &seatNo);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Source: ");
                scanf(" %[^\n]", source);
                printf("Enter Destination: ");
                scanf(" %[^\n]", destination);
                printf("Enter Date (DD/MM/YYYY): ");
                scanf(" %[^\n]", date);
                createPassenger(seatNo, name, source, destination, date);
                break;
            case 2:
                readPassengers();
                break;
            case 3:
                printf("Enter Seat No to update: ");
                scanf("%d", &seatNo);
                printf("Enter new Source: ");
                scanf(" %[^\n]", source);
                printf("Enter new Destination: ");
                scanf(" %[^\n]", destination);
                printf("Enter new Date (DD/MM/YYYY): ");
                scanf(" %[^\n]", date);
                updatePassenger(seatNo, source, destination, date);
                break;
            case 4:
                printf("Enter Seat No to delete: ");
                scanf("%d", &seatNo);
                deletePassenger(seatNo);
                break;
            case 5:
                printf("Exiting system... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

