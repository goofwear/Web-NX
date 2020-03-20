#include <web/web.h>

static void launchWeb(const char *url)
{
    WebCommonConfig web;
    webPageCreate(&web, url);
    webConfigShow(&web, NULL);
}