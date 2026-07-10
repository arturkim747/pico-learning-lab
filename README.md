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

It is time to apply everything I have learned so far.

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h" // including a header file for Pico


int main(){

    stdio_init_all(); // setting up standart input and output
    sleep_ms(3000); // waiting for the USB serial connection, else certain messages are lost
    const int led_pin = 25;

    gpio_init(led_pin); // initializing the pin 25
    gpio_set_dir(led_pin, GPIO_OUT); // setting it as an output

    printf("***PASSWORD-LOCKER READY***\n");

    while (1){
        char password[] = "arturkim747";
        char passkey[30];

        for (int i = 1; i <= 3; i++){
            printf("Attempt %d out of 3\n", i); 
            printf("Enter password: ");

            scanf("%s", passkey);

            if (strcmp(passkey, password) == 0){
                printf("Access Granted!\n");
                for (int i = 0; i < 5; i++){
                    gpio_put(led_pin, 1); // setting it high
                    sleep_ms(1000);
                    gpio_put(led_pin, 0); // setting it low
                    sleep_ms(1000);
                }
                return 1;
            }
            else continue;
    }
        printf("You are out of attempts!\n");
        printf("Please wait for 10 seconds to try again\n");
        for (int i = 10; i > 0; i--){
                printf("%d seconds left\n", i);
                sleep_ms(1000); 
    }

}

}


# Problems encountered & solutions.

-  At the time of writing the code, I did not know that we must write the function gpio_init_all() to enable the use of input/output functions, and yet the most important role of this function - enabling USB Serial. Consequently, I could not even access my Pico serial USB port. A good way to prevent this is to add it right at the very beginning of a function.

- Another problem I countered is that I could not see any input/output in the terminal window. However, later I learned that, for this purpose, we must use the Serial Monitor. Serial Monitor is simply a program that lets us exchange text with a microcontroller.

- As we are reading the source code, we may see that I let my Pico sleep for 2 seconds before executing the main code block. Because as I was running the code, I faced that first 2 input messages were missing. I did that on purpose not to lose first input messages which is a big issue of microcontrollers. Microcontollers read a code in fractions of a seconds, while for my Computer it may take a bit longer to set up the USB connection. As a result, the first message appearing as ""***PASSWORD-LOCKER READY***\n" literally gets lost.




