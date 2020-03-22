#include <nx_keyboard.h>

bool appletinit = false;

char *keyboard(char *message, size_t size)
{
    if(!appletinit)
    {
        userAppInit();
        appletinit = true;
    }

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

void userAppInit(void)
{
	void *addr = NULL;
	if (svcSetHeapSize(&addr, 0x4000000) == (Result)-1) fatalSimple(0);
}