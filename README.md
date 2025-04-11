# 🎮 UNO Game (C++ Console Edition)

A fully functional command-line implementation of the classic card game **UNO**, written in modern C++.

This project simulates a turn-based UNO game for 2 or more players, featuring full game rules, deck shuffling, card logic, and turn rotation — all with an emphasis on clean code structure and good memory management practices.

![image](https://github.com/user-attachments/assets/0f54c2d3-d9ad-44dd-ad73-1eeaaaca432f)

---

## 📌 Features

- ♠️ Full UNO rule implementation (skip, reverse, draw two, wild, wild draw four)
- 🧠 Smart AI and player interactions
- 🎲 Randomized deck shuffle at each game start
- 🔄 Robust turn management and card validation logic
- 🚫 Rule enforcement (e.g., must say UNO before last card, penalties, etc.)
- 📦 Clean and decoupled object-oriented design
- 🧹 Safe memory management using modern C++ features (smart pointers, RAII, deep x shallow copy)

![image](https://github.com/user-attachments/assets/a8c91499-fab0-4125-88ac-bd7a7b255254)

---

## 🚀 Getting Started

### Prerequisites

- C++17 or later
- CMake (optional, if using a build system)
- An IDE like `Visual Studio` or `Rider`, or a C++ compiler like `g++` or `clang++`

### Compilation

- Using IDE:
  - Open the solution(.sln) file
  - Run the project (F5) inside with the IDE Compiler

Using terminal:
```bash
g++ -std=c++17 -Wall -Wextra -o unoGame main.cpp
./unoGame
