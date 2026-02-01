
---

# ♟️ Chess Game (C++ / SFML)

A simple and interactive **Chess Game** made in **C++** using **SFML**.
It supports **local multiplayer**, **AI mode**, and **save/load** using files like **CSV / JSON**.

---

## ✨ Features

* ✅ **Classic Chess Rules**
* 🎮 **Local Multiplayer (Player vs Player)**
* 🤖 **Play Against AI (Player vs Computer)**
* 💾 **Save Game**
* 📂 **Load Game**
* 🗂️ Save format support:
  * CSV
  * JSON

---

## 🛠️ Built With

* **C++**
* **SFML (Simple and Fast Multimedia Library)**
* **Visual Studio**

---

## 🎯 Game Modes

### 1) Player vs Player (Local)

Two players can play on the same computer using the same chessboard.

### 2) Player vs AI

Play against the computer AI.
The AI will make moves automatically.

---

## 💾 Save & Load System

This project supports saving and loading the match so you can continue later.

Saved data includes:

* Current board position
* Player turn
* Captured pieces *(optional if implemented)*
* Game state (check/checkmate/stalemate if included)

Example file formats:

* `savegame.csv`
* `savegame.json`

---

## ▶️ How to Run

### Requirements

* Visual Studio (recommended)
* SFML installed and linked properly
* C++ compiler (MSVC)

### Steps

1. Clone the repository:

   ```bash
   git clone https://github.com/TalhaAhmad-Codes/Chess-Game
   ```

2. Open the project in **Visual Studio**

3. Make sure SFML is configured:

   * Include directories
   * Library directories
   * DLL files in output folder

4. Build and run the project 🎉

---

## 🎮 Controls (Basic)

*(will be updated soon)...*

---

## 📂 Folder Structure

```
Chess/
│
├── assets/
│   ├── fonts/
│   │   └── arial.ttf
│   ├── textures/
│   │   └── chess_pieces.png
│   ├── sounds/
│   │   └── move.wav
│   └── data/
│       ├── saves/
│       │   └── game1.json
│       └── config.json
│
├── include/
│   ├── core/
│   │   ├── Game.hpp
│   │   └── Application.hpp
│   │
│   ├── board/
│   │   ├── Board.hpp
│   │   ├── Tile.hpp
│   │   └── Position.hpp
│   │
│   ├── pieces/
│   │   ├── Piece.hpp
│   │   ├── King.hpp
│   │   ├── Queen.hpp
│   │   └── Pawn.hpp
│   │
│   ├── ai/
│   │   └── ChessAI.hpp
│   │
│   └── utils/
│       ├── FileIO.hpp
│       └── Constants.hpp
│
├── src/
│   ├── core/
│   │   ├── Game.cpp
│   │   └── Application.cpp
│   │
│   ├── board/
│   │   ├── Board.cpp
│   │   └── Tile.cpp
│   │
│   ├── pieces/
│   │   ├── Piece.cpp
│   │   └── Pawn.cpp
│   │
│   ├── ai/
│   │   └── ChessAI.cpp
│   │
│   └── utils/
│       └── FileIO.cpp
│
├── main.cpp
└── README.md
```

---

## 📜 License

This project is open-source and free to use for learning and practice.

---
