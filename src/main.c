#include <nx_keyboard.h>
#include <web/web.h>

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Asking for the user's URL.....");

    char *url = keyboard("Write your url here. Please include the \"https://\"", sizeof(url));
    
    launchWeb(url);

    return 0;
}