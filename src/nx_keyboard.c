#include <nx_keyboard.h>

char *keyboard(char *message, size_t size)
{
    SwkbdConfig skp;
    Result keyrc = swkbdCreate(&skp, 0);

    char *output = NULL;
    output = (char *)calloc(sizeof(char), size + 1);

    if(R_SUCCEEDED(keyrc) && output != NULL)
    {
        swkbdConfigMakePresetDefault(&skp);
        swkbdConfigSetGuideText(&skp, message);
        keyrc = swkbdShow(&skp, output, size);
        swkbdClose(&skp);
    }
    else
    {
        free(output);
        output = NULL;   
    }

    return (output);
}