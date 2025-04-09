# 🎮 UNO Game (C++ Console Edition)

A fully functional command-line implementation of the classic card game **UNO**, written in modern C++.

This project simulates a turn-based UNO game for 2 or more players, featuring full game rules, deck shuffling, card logic, and turn rotation — all with an emphasis on clean code structure and good memory management practices.

---

## 📌 Features

- ♠️ Full UNO rule implementation (skip, reverse, draw two, wild, wild draw four)
- 🧠 AI or player-vs-player modes (depending on implementation)
- 🎲 Randomized deck shuffle at each game start
- 🔄 Robust turn management and card validation logic
- 🚫 Rule enforcement (e.g., must say UNO before last card, penalties, etc.)
- 📦 Clean object-oriented design
- 🧹 Safe memory management using modern C++ features (smart pointers, RAII, deep x shallow copy)

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
