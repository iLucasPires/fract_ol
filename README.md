<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/fract-olm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# fract-ol
Frac-ol is a 42 school project whose goal is to create a fractal explorer.
The program will display different fractals and allow the user to zoom and change the color of the fractal.

## How to use

- Clone the repository with `git clone https://github.com/iLucasPires/fract-ol.git`
- You need to use [MiniLibX](https://github.com/42Paris/minilibx-linux)
- Run `make` to compile the executable
- Run `./fractol [fractal]` to execute the program

## Install MiniLibX

- Clone the repository with `https://github.com/42Paris/minilibx-linux.git`
- Run `make` to compile the library need to install libbsd-dev libXext-dev
- Copy the library `libmlx.a` from the root of the home directory
- Copy the header file `mlx.h` from the root of the home directory

```bash
$> sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

```bash
$> cp libmlx.a /usr/local/lib/
```

```bash
$> cp mlx.h /usr/local/include/
```

## Mandatory part

- [x] The executable file must be named fractol.
- [x] The project must be written in accordance with the Norm.
- [x] The executable must be able to display at least the Mandelbrot and Julia sets.
- [x] The executable must be able to zoom in and out of the fractal using the mouse wheel.

## Bonus part

- [x] The executable must be able to change the color palette.
- [x] The executable must be able to move the fractal with the arrow keys.
- [x] The executable must be able to lock the fractal on a point with the mouse.
- [x] The exacutable must be able to display at least one other fractal of your choice.

## Controls

The following controls are available:

<table>
  <tr><td><strong>Controls</strong></td><td><strong>Action</strong></td></tr>
  <tr><td><kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Move</td></tr>
  <tr><td><kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Quit fract-ol</td></tr>
  <tr><td><kbd>&nbsp;C&nbsp;</kbd></td><td>Change color (only in Bonus)</td></tr>
</table>

## Example

Display the [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set) set

```bash
$> ./fractol mandelbrot
```

![Example](./img.png)

Display the [Julia](https://en.wikipedia.org/wiki/Julia_set) set

```bash
$> ./fractol julia number number
```

![Example](./img2.png)

Display the [Burning Ship](https://en.wikipedia.org/wiki/Burning_Ship_fractal) set

```bash
$> ./fractol burningship
```

![Example](./img3.png)
