#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"


int main(){

    stdio_init_all(); // setting up standart input and output
    const int led_pin = 25;

    gpio_init(led_pin); // initializing the pin 25
    gpio_set_dir(led_pin, GPIO_OUT); // setting it as an output


    while (1){
        char password[] = "arturkim747";
        char passkey[30];

        for (int i = 1; i <= 3; i++){
            printf("Attempt %d out of 3\n", i); 
            printf("Enter password: ");

            fflush(stdout);
            scanf("%s", passkey);

            if (strcmp(passkey, password) == 0){
                printf("Access Granted!\n");
                for (int i = 0; i < 5; i++){
                    gpio_put(led_pin, 1); // setting it hight
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
    return 0;
}



}
