# fract-ol

Fract-ol is a small C program that renders interactive fractals (Mandelbrot, Julia, Burning Ship, etc.) using the MiniLibX graphics library. It is commonly implemented as an educational project to practice low-level graphics, complex numbers, event handling and optimisation in C.

A compact, responsive fractal viewer with keyboard and mouse controls for zooming, panning and tweaking iteration/color parameters.

---

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Build](#build)
- [Usage](#usage)
- [Controls](#controls)
- [Available fractals](#available-fractals)
- [Implementation notes](#implementation-notes)
- [Troubleshooting](#troubleshooting)
- [Acknowledgements](#acknowledgements)

---

## Features

- Real-time rendering of classic fractals:
  - Mandelbrot set
  - Julia sets (with interactive parameter control)
  - Burning Ship
- Zoom & pan with mouse and keyboard
- Adjustable max iterations and color schemes
- Lightweight, written in C, uses MiniLibX

---

## Prerequisites

- A UNIX-like environment (Linux or macOS)
- C compiler (clang or gcc)
- Make
- MiniLibX (installation depends on your platform)
  - macOS: Install the macOS MiniLibX (often provided by 42/your environment)
  - Linux: Install the X11 MiniLibX and link with X11 libraries (libx11, libxext, libm, etc.)

Common additional libraries/headers (Linux):
- libx11-dev
- libxext-dev
- libbsd-dev (optional; some MLX forks require -lbsd)

---

## Build

The repository provides a Makefile with common targets:

```bash
# build the program
make

# remove object files
make clean

# remove objects and executable
make fclean

# recompile from scratch
make re
```

The default target usually produces a `fractol` executable. If your environment requires special linker flags for MiniLibX, check the Makefile and adjust as needed (e.g., add `-lX11 -lXext -lm -lbsd` on Linux).

---

## Usage

Basic usage:

```bash
# show help / usage (if implemented)
./fractol

# example: open Mandelbrot
./fractol Mandelbrot

# example: open Julia with optional complex parameter (real imag)
./fractol Julia -0.7 0.27015

# example: Burning Ship
./fractol BurningShip
```

Notes:
- Fractal names are case-insensitive.
- Julia set needs to have to floats as parameter, the real and the imaginary part..

---

## Controls

Interactive controls:

Mouse:
- Scroll wheel up / down — Zoom in / out (centered at cursor)
- Left or right click — In Julia set: change parameters ; Others: change color shift

Keyboard:
- Arrow keys — Pan view (left/right/up/down)
- + / - (or numpad) — Increase / decrease max iterations
- 1 - 9 — Change color scheme
- J — Switch to Julia set
- B — Switch to Burning ship
- M — Switch to Mandelbrot set
- ESC / Q — Quit

---

## Available fractals

- Mandelbrot
- Julia (with seed parameter)
- Burning Ship

---

## Implementation notes

- Rendering uses the MiniLibX for window creation and pixel drawing.
- The main loop handles events (keyboard, mouse) to update parameters and re-render only when needed.
- Performance tips:
  - Limit redraws to when parameters change.
  - Use an iterative escape-time algorithm and tune max iterations.
  - Consider multithreading (pthreads) to split the image into stripes for faster redraws.

---

## Troubleshooting

- "Undefined reference" errors when linking MiniLibX on Linux:
  - Make sure you add: -L/path/to/minilibx -lmlx -lX11 -lXext -lm -lbsd (adjust as necessary)
  - Install X11 development packages: `sudo apt-get install libx11-dev libxext-dev libbsd-dev`
- On macOS, MLX sometimes requires linking with OpenGL frameworks; check your MLX fork docs.
- If the window opens black / no response:
  - Confirm you have correct event hooks and that the main loop is running.
  - Try smaller window size or lower iteration counts.

---

## Acknowledgements

- MiniLibX — lightweight graphics library used for teaching graphics in C
- 42 school

---

Maintainer: mojosama (GitHub: https://github.com/mojosama)
