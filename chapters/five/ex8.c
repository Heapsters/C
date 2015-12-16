#include <stdio.h>

#define DAYSINYEAR 365
#define DAYSINLEAP 366

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

/*
 * Implement error checking in 
 * `day_of_year` and `month_day`
*/
int main(int argc, const char * argv[])
{
    int year, month, day, yearday;
    int doy, pmonth, pday;
    
    year = 2015;
    month = 4;
    day = 29;
    
    doy = day_of_year(year, month, day);
    
    printf("%d-%d-%d: ", year, month, day);
    
    if (doy)
        printf("day %dth of the year\n", doy);
    else
        printf("invalid!\n");
    
    yearday = doy + 15;
    doy = month_day(year, yearday, &pmonth, &pday);
    
    printf("%d-%d-%d: ", year, pmonth, pday);

    if (doy)
        printf("day %dth of the year\n", doy);
    else
        printf("invalid!\n");
    
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return 0;
    
    int i, leap;
    
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    
    if (day > daytab[leap][month])
        return 0;
    
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 0 || yearday < 1)
        return 0;
    
    int i, leap;
    
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    
    if (yearday > (leap ? DAYSINLEAP : DAYSINYEAR))
        return 0;
    
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    
    *pmonth = i;
    *pday = yearday;
    
    return yearday;
}
