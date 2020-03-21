#include <switch.h>

#include <string>

void launchWeb(std::string url)
{
    WebCommonConfig web;
    webPageCreate(&web, url.c_str());
    webConfigShow(&web, NULL);
}