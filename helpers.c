#include <time.h>
#include <strings.h>
#include <stdio.h>


char* append_date(char* data) {

    /*Generating datetime string */
    char time_string[100];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(time_string, sizeof(time_string)-1, "%d%m%Y%H:%M", t);

    /*Modifying the string*/
    char result[100];
    strncpy(result, data, 100);
    strncat(result, time_string, 10);
    return result;
}
