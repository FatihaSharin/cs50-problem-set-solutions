#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // getting name of the user---
    string name = get_string("What is your name? :  ");
    
    // printing the required word with the name of the user---
    printf("Hello, %s!\n", name);
    
}
