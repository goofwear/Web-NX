#include <switch.h>

void launchWeb(const char *url)
{
    WebCommonConfig web;
    webPageCreate(&web, url);
    webConfigShow(&web, NULL);
}