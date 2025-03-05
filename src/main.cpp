#include <stdio.h>  //printf()
#include <stdlib.h> //exit()
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <time.h>
#include "OLED_Driver.h"
#include "OLED_GUI.h"
#include "DEV_Config.h"
#include "KEY_APP.h"

#define TIME_STRING_LEN 25U
#define LOGIN_HINT_STR_LEN 20U
#define IP_STRING_LEN 15U

typedef enum
{
    TIME_ONLY = 0x00,
    FULL_INFO,
} piInfoFormat_t;

const char *get_ip_address()
{
    struct ifaddrs *interfaces = NULL;
    struct ifaddrs *ifa = NULL;
    static char ip_str[IP_STRING_LEN] = {0};
    memset(ip_str, 0, sizeof(ip_str));
    if (getifaddrs(&interfaces) == -1)
    {
        perror("getifaddrs");
        return ip_str;
    }

    for (ifa = interfaces; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET)
        {
            void *tmpAddrPtr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, tmpAddrPtr, ip_str, INET_ADDRSTRLEN);
        }
    }
    freeifaddrs(interfaces);
    return ip_str;
}

void writeLine(const char *str, const int size, sFONT *Font, int xPoint, int yPoint)
{
    int xWide = Font->Width - 1;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '\0')
            break;
        GUI_DisChar((xPoint++) * xWide, yPoint, str[i], Font, FONT_BACKGROUND, WHITE);
    }
}

void printPiInfo(piInfoFormat_t f)
{
    static const char ipTagStr[5] = {'I', 'P', ':', ' ', '\0'};
    char time_str[TIME_STRING_LEN];
    char loginInfoStr[LOGIN_HINT_STR_LEN] = {'\0'};
    sprintf(loginInfoStr, "UserName: %s Pass: 1", "pi");
    time_t now;
    struct tm *timenow;
    time(&now);
    timenow = localtime(&now);
    memset(time_str, 0, sizeof(time_str));

    if (f == TIME_ONLY)
    {
        strftime(time_str, sizeof(time_str), "%H:%M:%S", timenow);
        writeLine(time_str, sizeof(time_str), &Font32, 0, 32);
    }
    else if (f == FULL_INFO)
    {
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timenow);
        writeLine(time_str, sizeof(time_str), &Font12, 0, 0);
        get_ip_address();
        writeLine(ipTagStr, sizeof(ipTagStr), &Font12, 0, 11);
        writeLine(get_ip_address(), IP_STRING_LEN, &Font12, 4, 11);
        writeLine(loginInfoStr, sizeof(loginInfoStr), &Font12, 0, 22);
    }
    else
    {
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timenow);
        writeLine(time_str, sizeof(time_str), &Font12, 0, 0);
        get_ip_address();
        writeLine(ipTagStr, sizeof(ipTagStr), &Font12, 0, 11);
        writeLine(get_ip_address(), IP_STRING_LEN, &Font12, 4, 11);
        writeLine(loginInfoStr, sizeof(loginInfoStr), &Font12, 0, 22);
    }
}

int main(void)
{
    time_t now;
    struct tm *timenow;
    if (DEV_ModuleInit())
        exit(0);
    printf("**********Init OLED**********\r\n");
    OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;
    OLED_Init(OLED_ScanDir);

    printf("OLED Show \r\n");
    GUI_Show();
    OLED_Clear(0x00);

    while (1)
    {
        OLED_Clear(0x00);
        time(&now);
        timenow = localtime(&now);

        if (timenow->tm_hour >= 23 || timenow->tm_hour <= 7)
        {
            printPiInfo(TIME_ONLY);
        }
        else
        {
            printPiInfo(FULL_INFO);
        }
        OLED_Display();
        DEV_Delay_ms(999);
    }
    DEV_ModuleExit();
    return 0;
}
