# Student Grade Management System (C)

This project is a structured and modular student management simulation developed in C. The program allows users to maintain student personal records, manage exam scores for three core subjects (Math, Physics, and Chemistry), and calculate grade averages.

## ✭ Features
* **Student Management:** Functionalities to add, update, and delete student records.
* **Course-Based Grade Entry:** Support for three exams per subject (Mathematics, Physics, and Chemistry). 
* **Average Calculation:** A modular function to calculate the arithmetic mean of exam scores for any given course. 
* **Data Listing:** A formatted display of all registered students along with their specific grades.

## ✭ Technical Overview
The project demonstrates core C programming concepts and modular design:
- **Structs (Data Structures):** Uses nested structures (`Ogrenci`, `Notlar`, and `Ders`) for efficient data modeling. 
- **Modular Architecture:** Logic is separated into `main.c`, `ogrenci.c`, and `ders.c` to ensure maintainability and readability. 
- **Header Files:** Proper use of `.h` files for function prototyping and global definitions. 

## ✭ How to Run
Clone the repository and compile the source files using a C compiler (like GCC):

```bash
gcc main.c ogrenci.c ders.c -o student_system
./student_system
