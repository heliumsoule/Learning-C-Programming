#include <stdio.h>
#include <stdlib.h>

static char *daytab[] = {
	(char []){0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	(char []){0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
	int* month = malloc(sizeof (int*));
	int* day = malloc(sizeof (int*));

	month_day(2016, 80, month, day);
	printf("It's %d/%d\n", *month, *day);
	printf("It's %d day of the year\n", day_of_year(2016, 3, 20));
	return 1;
}

int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	while (month >= 1) {
		day += *(daytab[leap] + month--);
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	i = 1;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	while (yearday > *(daytab[leap] + i))
		yearday -= *(daytab[leap] + i++);

	*pmonth = i;
	*pday = yearday;
}