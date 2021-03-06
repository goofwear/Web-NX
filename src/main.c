#include <nx_keyboard.h>
#include <web/web.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    consoleInit(NULL);

    printf("Asking for the user's URL.....");
    char *url = keyboard("Write your url here. Please include the \"https://\"", (size_t)0);
    launchWeb(url);

    while (appletMainLoop())
    {
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS)
            break;

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}