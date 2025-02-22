# Hotel Management System

A console-based Hotel Management System built in C++ as part of the Winter Camp 2025 project. Developed by **Zero-One Developers**.

## Features
- **Inventory Management**: Track available stock in the hotel.
- **Billing System**: Generate invoices for customers.
- **Room Booking**: Manage room reservations.
- **Buffet Management**: Keep records of food orders and availability.

## Project Structure
```
Hotel-Management-System/
│-- src/
│   │-- main.cpp           # Entry point of the application
│   │-- inventory.cpp      # Handles stock management
│   │-- billing.cpp        # Handles invoice generation
│   │-- booking.cpp        # Manages room reservations
│   │-- buffet.cpp         # Manages food orders
│-- include/
│   │-- inventory.h
│   │-- billing.h
│   │-- booking.h
│   │-- buffet.h
│-- README.md              # Project documentation
│-- Makefile (optional)    # Compilation instructions
```

## How to Use
1. **Clone the repository**
   ```sh
   git clone https://github.com/yourusername/hotel-management-system.git
   cd hotel-management-system
   ```
2. **Compile the project** (if using g++)
   ```sh
   g++ -o hotel_management src/*.cpp
   ```
3. **Run the application**
   ```sh
   ./hotel_management
   ```
4. **Follow the on-screen instructions** to navigate the system.

## Requirements
- C++ Compiler (G++ recommended)
- A terminal/command prompt to run the application

## Contributors
- **Yassmine** - Inventory, Billing, Main Interface
- **Asmaa Khalaf** - Room Booking
- **Mery Nabeh** - Buffet Management

---
### Notes
This project is purely console-based and does not include a graphical interface. The focus is on implementing core functionalities in C++.
