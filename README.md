# pico-learning-lab
Introduction to Embedded Systems with Raspberry Pi Pico

## 2026-07-08

As of now, I am fairly new to both coding and Embedded Systems. Throughout this project, I hope to gain a basic understanding of Embedded Systems with Raspberry Pi Pico.

First, I decided to take a look at the pin-layout of my Pico which really confused me. Therefore, I made sure tom first cover GPIO, which according to my current view of this microcontroller, makes up almost the majority of all pins.

# What is GPIO?
- GPIO (Gener Purpose Input Output) - little programmable electrical connection points along the edges of the board. As the words "General Purpose" reffer, they are not fixed to one job, we, as programmers, are to decide whether a pin behaves like an input or output.

# What is SDK?
- SDK stands for Software Development Kit. Well, that's basically a set of tools that lets us comfortably use the functions listed below. Without SDK, we would have to control the RP2040 chip manually using the binary code, which would be hell of a job.

# Functions

Although there are many more functions to cover, those are the ones I can use right away to access my LED light.

- gpio_init() initializes a pin and prepares it for work
- gpio_set_dir() sets the direction of a given pin. Via this function, we decide whether a pin behaves as an input or output by writing GPIO_OUT or GPIO_IN as the second argument.
- gpio_put() puts a value onto a pin and thus sets the voltage

  High -> ~3.3V -> 1
  Low -> ~0V -> 0

## Building my first program - Password Lock


