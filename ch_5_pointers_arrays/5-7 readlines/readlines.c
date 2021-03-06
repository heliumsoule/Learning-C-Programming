#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
char lines[MAXLINES];

int readlines(char *lineptr[], char *lines, int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(char *lineptr[], int left, int right);

int main() {
	int nlines;
	

	if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
		q_sort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int get_line(char *, int);
int min(int, int);
char *alloc(int);

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

int get_line(char s[], int lim) {
	int c, i;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1)
			s[i] = c;
	}
	if ((c == '\n') && i < lim - 1) {
		s[i] = c;
		++i;
	}
	s[min(i, lim - 1)] = '\0';
	return i;
}

int min(int a, int b) {
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}

int readlines(char *lineptr[], char *lines, int maxlines) {
	int len, nlines;
	char *p, *end, line[MAXLEN];
	
	end = lines + MAXLINES;
	p = lines;
	nlines = 0;

	while ((len = get_line(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || p + len > end)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	}
	return nlines;
} 

void writelines(char *lineptr[], int nlines) {
	// int i;
	// for (i = 0; i < nlines; i++) 
	// 	printf("%s\n", lineptr[i]);
	while (nlines-- > 0) 
		printf("%s\n", *lineptr++);
}

void q_sort(char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	q_sort(v, left, last - 1);
	q_sort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}






