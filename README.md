# 42_fractol

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)

## Introduction

Fractol is a project that allows you to discover fractals, mathematical sets that exhibit a repeating pattern displayed at every scale. It will enable you to explore complex mathematical concepts, such as continuous and discrete, as well as to take a first look at the concept of optimization in computer graphics. You will also discover your first graphic library: miniLibX. This project introduces you to the basics of graphics programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint.

## How to use
- Clone the repository
- Run `make` or `make bonus` to compile the project
- Run `./fractol mandelbrot` or `./fractol julia number number` or `./fractol burningship`

## Example
![Example](./img.png)

## Supported fractals

- [x] Mandelbrot
- [x] Julia
- [x] Burning ship

## Controls

### General

- [x] `ESC` : Quit the program
- [ ] `R` : Reset the view
- [ ] `C` : Change the color
- [ ] `+` : Increase the number of iterations
- [ ] `-` : Decrease the number of iterations
- [x] `Mouse Wheel` : Zoom in/out
- [ ] `Left Click` : Zoom in
- [ ] `Right Click` : Zoom out

### Mandelbrot

- [ ] `W` : Increase the contrast
- [ ] `S` : Decrease the contrast
- [ ] `A` : Increase the color variation
- [ ] `D` : Decrease the color variation
- [ ] `Q` : Increase the color offset
- [ ] `E` : Decrease the color offset

### Julia

- [ ] `W` : Increase the contrast
- [ ] `S` : Decrease the
