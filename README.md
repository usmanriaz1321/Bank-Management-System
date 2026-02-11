# Bank Management System (C++)

## Overview

The Bank Management System is a console-based application developed in C++ that simulates basic banking operations. This project allows users to create accounts, perform transactions, manage personal information, and view transaction history. It is designed as an academic project to demonstrate core programming concepts and real-world system functionality.

## Features

### User Features

* User Signup with:

  * Name
  * CNIC (13-digit validation)
  * 8-digit Account Number
  * 6-digit Password
  * Initial Deposit
* Secure Login using Account Number and Password
* Check Account Balance
* Deposit Money
* Withdraw Money
* Transfer Money to another account
* View Transaction History
* Edit Account Details:

  * Change Name
  * Change CNIC
  * Change Password
* Delete Account permanently

### Admin Features

* Admin Login (Password Protected)
* View all user accounts
* Search account by CNIC
* Search account by Account Number

## Data Storage

* User data is stored in a file (`data.txt`)
* File handling is used to:

  * Save account information
  * Load existing user data when the program starts

## Input Validations

* CNIC must be exactly 13 digits
* Account number must be 8 digits
* Password must be 6 digits
* Deposit and withdrawal amounts must be valid
* Password confirmation required for sensitive operations

## Transaction Management

* Maintains transaction history for each user
* Records deposits, withdrawals, and transfers
* Displays complete transaction history on request

## Technologies Used

* C++
* Object-Oriented Programming Concepts
* File Handling (ifstream, ofstream)
* Structures
* Arrays
* Input Validation
* Dynamic Memory Allocation

## Learning Objectives

This project helped in understanding:

* Real-world problem solving using programming
* File handling and data persistence
* User authentication systems
* Menu-driven program design
* Data validation and security basics


## Future Improvements

* Graphical User Interface (GUI)
* Database integration (MySQL)
* Improved security and encryption
* Online banking features

## Author

Muhammad Usman
BSCS Student (2nd Semester)
Aspiring Cybersecurity & Web Developer

