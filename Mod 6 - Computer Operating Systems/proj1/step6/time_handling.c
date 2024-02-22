#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>

/*
 * uses:
 * size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
 */

int main(){
	struct stat fileinfo;

	/* 
	 * demonstrate how to get the time associated with a file 
	 * ... lazily, for now, without error checking
	 */
	int i = stat("test.txt", &fileinfo);
	struct tm *tmp;
	char time_string[80];

	/* fileinfo should now contain info about the file names listdir2.c */
	//
	time_t modified_time = fileinfo.st_mtime;
	
	printf("format a time field using strftime \n");
	// localtime() converts the calendar time timep to a broken-down  time  
	// representation, expressed  relative  to  the  user's  specified  timezone.
	tmp = localtime(&fileinfo.st_mtime);
	
	//strftime can be used to extract various field of this broken-down time
	//representation using format specifiers as seen below:
	
	strftime(time_string, sizeof(time_string), "a produces %a and A produces %A", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "b produces %b and B produces %B", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "c produces %c and C produces %C", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "d produces %d and D produces %D", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "e produces %e and E is used only as a modifier", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "no f, but F produces %F", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "g produces %g and G produces %G", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "h produces %h and H produces %H", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "no i but I produces %I", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "j produces %j and there's no J", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "k produces %k and there's no K", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "l produces %l and there's no L", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "m produces %m and M produces %M", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "n produces %n and there's no N", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "no o and O is used as a modifier", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "p produces %p and P produces %P", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "no q or Q ", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "r produces %r and R produces %F", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "s produces %s and S produces %S", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "t produces %t (a tab character) and T produces %T", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "u produces %u and U produces %U", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "no v but V produces %V", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "w produces %w and W produces %W", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "x produces %x and X produces %X", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "y produces %y and Y produces %Y", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	strftime(time_string, sizeof(time_string), "z produces %z and Z produces %Z", tmp);
	printf("%s \n", time_string);
	bzero(time_string, 80);

	//strftime(mtime, sizeof mtime, "%d %b %Y %T", tmp);

}
