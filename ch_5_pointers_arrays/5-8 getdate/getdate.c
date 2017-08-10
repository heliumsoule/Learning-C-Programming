#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
	printf("Day of Year is %d\n", day_of_year(2017, 3, 20));
	return 1;
}


int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) 
			|| year % 400 == 0;

	assert(year > 0);
	assert(month > 0 && month <= 12);
	assert(day > 0 && day <= daytab[leap][month]);

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	assert(year > 0);
	assert(yearday > 0 && yearday <= 365);

	leap = (year % 4 == 0 && year % 100 != 0)
		    || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}