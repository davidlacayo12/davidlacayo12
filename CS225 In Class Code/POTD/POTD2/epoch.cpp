#include "epoch.h"
/* Your code here! */
//86400 seconds in a day, 3600 in an hour 
int hours(time_t t) {
    return (t/3600);
}

int days(time_t t) {
    return ((t/ 86400));
}

int years(time_t t){
    return ((t / 86400) / 365);
}