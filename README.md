<h1 align="center">so_long</h1>

<p align="center">
  A small 2D game in C built with MiniLibX, centered on map validation, path checking, and event-driven rendering.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 badge" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language badge" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" alt="Status badge" />
</p>

<p align="center">
  <strong>MiniLibX, DFS path validation, tile-based rendering, X11 events, memory cleanup</strong>
</p>

---

## 📌 Overview

`so_long` is a project developed as part of the 42 curriculum.

The repository implements a small tile-based game where the player must collect every collectible on the map before reaching the exit. The codebase combines file parsing, rule validation, graphical rendering with MiniLibX, keyboard handling, and explicit resource cleanup.

This project focuses on:
- validating `.ber` map files before launching the game
- checking map reachability with a depth-first search
- rendering a tile-based world with XPM sprites
- handling player input and clean program shutdown

---

## ✨ Features

- ✅ Loads maps from `.ber` files passed on the command line
- ✅ Validates map shape, walls, characters, player count, exit count, and collectible count
- ✅ Checks that the exit and all collectibles are reachable before the window opens
- ✅ Displays XPM sprites through MiniLibX and updates the map as the player moves
- ✅ Supports `ZQSD`, arrow keys, `ESC`, and window-close events
- ⚠️ No enemy system or sprite animation is implemented in this repository

---

## 🧠 Concepts Covered

This project demonstrates the following concepts:

- file parsing and dynamic allocation for map loading
- 2D grid representation with `char **`
- flood-fill / DFS validation for path checking
- event hooks with MiniLibX and X11 keycodes
- sprite rendering in a tile-based window
- explicit cleanup of images, display, window, and allocated buffers

---

## 🛠️ Build

Clone the repository and compile the project:

```bash
git clone https://github.com/Middle-555/so_long.git
cd so_long
make
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

 The Makefile links the local `minilibx-linux` directory against X11 (`-lX11 -lXext`), so a Linux graphical environment is required to run the game.

---

## 🚀 Usage

Run the program with:

```bash
./so_long <map_file.ber>
```

### Examples

```bash
./so_long map/01.ber
./so_long map/map_valid.ber
./so_long path/to/your_map.ber
```

Map rules enforced by the program:

- the file must use the `.ber` extension
- the map must be rectangular
- the map must be surrounded by walls
- the map must contain exactly one `P` and exactly one `E`
- the map must contain at least one `C`
- only `1`, `0`, `P`, `E`, and `C` are accepted

Controls available in-game:

- `Z`, `Q`, `S`, `D`
- arrow keys
- `ESC` to quit immediately

---

## 📂 Project Structure

```text
.
├── Makefile
├── include/
│   └── so_long.h
├── src/
│   ├── main.c
│   ├── so_long.c
│   ├── move.c
│   ├── map_parsing.c
│   └── ...
├── map/
├── sprites/
├── libraries/
├── minilibx-linux/
└── README.md
```

### Structure Details

- `include/` : shared constants, structs, keycodes, and function prototypes
- `src/` : gameplay logic, parsing, validation, rendering, input handling, and cleanup
- `map/` : sample maps used to try valid and invalid scenarios
- `sprites/` : XPM assets loaded for the player, walls, ground, exit, and collectibles
- `libraries/` : local `libft`, `ft_printf`, and `get_next_line` sources bundled into `libraries.a`
- `minilibx-linux/` : local MiniLibX source used for window creation, rendering, and events

---

## ⚙️ Project Constraints

This repository stays within a small C project scope:

- written in C
- uses MiniLibX for graphics
- relies on local utility libraries included in the repository
- reads the game map from a `.ber` file
- performs explicit cleanup for allocated maps, images, display, and window resources

---

## 🧪 Testing

The repository can be tested with the following approach:

- successful compilation with `make`
- valid map execution
- invalid extension handling
- map validation failures for walls, characters, player/exit count, and collectibles
- DFS reachability failures for blocked exits or unreachable collectibles

### Manual test examples

```bash
./so_long map/01.ber
./so_long map/map_valid.ber
./so_long map/test.be
```

### Memory checks

```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/01.ber
```

Running the executable requires an X11-capable graphical session because the project uses `minilibx-linux`.

---

## 📖 What This Project Highlights

Readers exploring this repository can focus on:

- how a 2D map can be validated before rendering anything
- how DFS can be used to reject unwinnable levels
- how a simple event loop is wired with MiniLibX
- how resource cleanup is handled in a small graphical C program

---

## 🚧 Possible Improvements

Although the project is functional, several improvements are visible from the current implementation:

- merge the four movement functions into one generic movement routine
- avoid re-reading the same map file multiple times during parsing
- display the move counter directly inside the game window
- add animation states or more visual feedback for the player and collectibles

---

## 👤 Author

kpourcel 
42 student

<p>
  <a href="https://github.com/Middle-555">GitHub</a>
</p>
