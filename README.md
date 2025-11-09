# Wolfcaster

Wolfcaster is an initial prototype for a Wolfenstein 3D-style game engine using raycasting techniques. This project implements a basic 3D rendering system with solid-colored walls, a simple grid-based map, player movement, and collision detection. It does not include monsters (sprites), textures, or advanced features at this stage. The engine is built in C with SDL2 for graphics and input handling, targeting Linux environments with VSCode for development.

This repository represents the initialization phase of the project, focusing on core raycasting mechanics inspired by historical game engines like Wolfenstein 3D.

## Description

The raycasting engine renders a 2D grid map (24x24) as a pseudo-3D first-person view:
- Walls are colored based on map tile types (e.g., red for type 1, green for type 2).
- Side walls are shaded darker for depth perception.
- Ceiling is light gray; floor is dark gray.
- Field of View (FOV) is appro- Player starts at position (22.0, 12.0) facing west.
ximately 66 degrees.
- Rendering uses Digital Differential Analyzer (DDA) for ray marching, with perpendicular distance correction to avoid fisheye distortion.
- No textures or sprites are implemented yet; walls are solid colors.

The codebase is modular, with separation for map data, raycasting logic, input handling, and main loop. It achieves ~60 FPS on modern hardware.

## Requirements

- **Operating System**: Linux distribution (tested on Ubuntu/Debian).
- **Compiler**: GCC (version 9+ recommended).
- **Libraries**: SDL2 (install via `sudo apt install libsdl2-dev` on Debian-based systems).
- **Development Tools**: VSCode for editing and debugging (optional `.vscode/` configurations included).
- **Hardware**: Standard desktop/laptop; no GPU acceleration required beyond SDL2's renderer.

No additional dependencies are needed; the project is self-contained except for SDL2.

## Build Instructions

1. Clone the repository:

```bash
git clone https://github.com/Gerald1973/wolfcaster.git
cd wolfcaster
```

2. Ensure SDL2 is installed:

```bash
sudo apt update && sudo apt install libsdl2-dev
```


3. Build the project using the provided Makefile:

```bash
make
```

- This compiles all `.c` files from `src/` into object files in `build/obj/`.
- The executable is generated at `build/wolfcaster`.

If compilation fails, check for GCC and SDL2 installation errors.

## Running the Game

Run the executable:

```bash
./build/wolfcaster
```


- Window: 640x480 pixels, titled "Wolfcaster - Basic Raycaster".
- Frame Rate: Capped at ~60 FPS via `SDL_Delay(16)`.
- Exit: Press ESC or close the window.

## Controls

- **W**: Move forward.
- **S**: Move backward.
- **A**: Rotate left.
- **D**: Rotate right.
- **ESC**: Quit the game.

Movement speed: 0.1 units per frame. Rotation speed: 0.05 radians per frame. Collisions prevent passing through walls.

## Project Structure


## References

- Raycasting implementation based on: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html).
- Inspired by the original Wolfenstein 3D engine, as detailed in *Game Engine Black Book: Wolfenstein 3D* by Fabien Sanglard (v2.2), focusing on pragmatic raycasting for performance (pages 9, 11-12, 110-111, 159-164).
- SDL2 documentation: [SDL Wiki](https://wiki.libsdl.org/).

## License

This project is licensed under the MIT License. See the LICENSE file for details (add one if not present).

## Contributing

This is an initialization prototype. Contributions are welcome via pull requests. For issues, open a GitHub issue.

Last updated: November 09, 2025.