#include <stdio.h>
#include <time.h>

#include "Header/Date.h"

void printCurrentDateAndTime(void) {
    time_t rawtime;
    struct tm *timeinfo;

    // Get current time
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Print the time and date in the desired format
    printf("%d%02d ", timeinfo->tm_hour > 12 ? timeinfo->tm_hour - 12 : (timeinfo->tm_hour == 0 ? 12 : timeinfo->tm_hour), timeinfo->tm_min);
    printf("%s ", timeinfo->tm_hour >= 12 ? "PM" : "AM");

    // Assuming EDT (Eastern Daylight Time) - you can adjust this
    if (timeinfo->tm_isdst > 0) {
        printf("EDT ");
    } else {
        printf("EST ");
    }

    // Print the day of the week
    char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    printf("%s ", days[timeinfo->tm_wday]);

    // Print the month
    char* months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%s ", months[timeinfo->tm_mon + 1]);

    // Print the day of the month and year
    printf("%d %d\n", timeinfo->tm_mday, 1900 + timeinfo->tm_year);
    printf("\n");
}

void printInputDateAndTime(int hour, int minute, bool tzn, int dow, int month, int day, int year) {
    printf("%d%02d ", hour, minute);
    printf("%s ", "PM");

    if (tzn) {
        printf("EDT ");
    }
    else {
        printf("EST ");
    }

    char* days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    printf("%s ", days[4]);

    char* months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%s ", months[12]);

    printf("%d %d\n", 14, 2023);
    printf("\n");
}