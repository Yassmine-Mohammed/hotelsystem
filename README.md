# Hotel Management System

A **console-based** Hotel Management System built in **C++** as part of the **Winter Camp 2025** project. This project is developed by **Zero-One Developers**, focusing on core hotel operations like inventory, billing, room booking, and buffet management.

## 🚀 Features
- **Inventory Management** 📦 – Tracks available stock and ensures proper management of hotel resources.
- **Billing System** 💰 – Generates invoices for customers based on their usage and purchases.
- **Room Booking** 🏨 – Manages guest reservations, check-ins, and check-outs efficiently.
- **Buffet Management** 🍽️ – Keeps records of food orders and buffet availability.

## 📁 Project Structure
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
│-- Makefile               # Compilation instructions (if available)
```

## 🔧 How to Use
1️⃣ **Clone the repository**
   ```sh
   git clone https://github.com/yourusername/hotel-management-system.git
   cd hotel-management-system
   ```
2️⃣ **Compile the project** (using g++)
   ```sh
   g++ -o hotel_management src/*.cpp
   ```  
   *OR, if a `Makefile` is provided, just run:*
   ```sh
   make
   ```  

3️⃣ **Run the application**
   ```sh
   ./hotel_management
   ```  
4️⃣ **Follow the on-screen instructions** to navigate through the system.

## 🛠️ Input Validation
The system includes input validation to ensure correct data entry and prevent invalid operations. This includes:
- Checking if the **departure date** is after the **arrival date**.
- Allowing users to **review and edit** entered dates before finalizing.
- Preventing incorrect or missing input fields.

## 📌 Requirements
- **C++ Compiler** (e.g., G++)
- **Terminal/Command Prompt** for execution

## 👥 Contributors
- **Yassmine** – Inventory, Billing, Main Interface
- **Asmaa Khalaf** – Room Booking
- **Mery Nabeh** – Buffet Management

---

## 🔮 Future Plans
We plan to enhance the system by adding:
- **Leap Year Handling** 📅 – Ensure accurate date validation for leap years.
- **Multiple Payment Methods** 💳 – Support for credit cards, PayPal, and other payment options.
- **Graphical User Interface (GUI)** 🖥️ – Transition from a console-based system to a user-friendly graphical interface.

---
### ℹ️ Notes
- This project is purely **console-based** and does **not** include a graphical interface.
- The primary focus is on implementing structured and efficient **C++ code** for hotel management operations.
