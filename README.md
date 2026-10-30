🚆 Passenger Seat Booking System in C

A simple Passenger Seat Booking System developed in C language using file handling. This project allows users to add, view, update, and delete passenger records while storing data permanently in a binary file.

📌 Features
Add new passenger records
View all passenger records
Update passenger travel details
Delete passenger records
Persistent data storage using file handling (passengers.dat)
Menu-driven console application
🛠 Technologies Used
C Programming
File Handling
Structures
Arrays
Standard Input/Output Library
📂 Project Structure
Passenger-Seat-Booking-System/
│
├── main.c
├── passengers.dat
└── README.md

📋 Passenger Information Stored

Each passenger record contains:

Seat Number
Passenger Name
Source
Destination
Travel Date
C
struct Passenger {
int seatNo;
char name[50];
char source[50];
char destination[50];
char date[20];
};
 
🚀 How to Run
Using GCC
Clone the repository
Shell
git clone https://github.com/your-username/Passenger-Seat-Booking-System.git
 
Navigate to the project folder
Shell
cd Passenger-Seat-Booking-System
Compile the program
Shell
gcc main.c -o booking
Run the executable
Shell
./booking
For Windows
Shell
gcc main.c -o booking.exe
booking.exe
📖 Menu Options
Passenger Seat Booking System

1. Add Passenger
2. View Passengers
3. Update Passenger
4. Delete Passenger
5. Exit

💾 Data Persistence

The project uses a binary file named:

passengers.dat


All passenger records are automatically saved and loaded whenever the program starts or exits.

🔄 CRUD Operations
Create

Add a new passenger record.

Read

Display all passenger records.

Update

Modify source, destination, and travel date using the seat number.

Delete

Remove a passenger record using the seat number.

🎯 Learning Objectives

This project demonstrates:

Structures in C
Arrays of Structures
File Handling (fopen, fread, fwrite, fclose)
CRUD Operations
Menu-Driven Programs
Data Persistence
📸 Sample Output
Passenger Seat Booking System

1. Add Passenger
2. View Passengers
3. Update Passenger
4. Delete Passenger
5. Exit

Enter Choice: 1

Enter Seat No: 101
Enter Name: Mukesh
Enter Source: Bengaluru
Enter Destination: Chennai
Enter Date: 15/11/2026

Passenger added successfully!

👨‍💻 Author

Mukesh

Student | C Programming Learner

📄 License

This project is open-source and available under the MIT License.
