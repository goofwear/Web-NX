#include <switch.h>
#include <string.h>

void launchWeb(char *url)
{
    WebCommonConfig web;
    webPageCreate(&web, url.c_str());
    webConfigShow(&web, NULL);
}