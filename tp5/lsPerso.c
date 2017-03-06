#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char** argv){

	DIR* curDir = opendir(".");
	
	struct dirent* nextEntry = readdir(curDir);
	
	struct stat buf;
	
	while(nextEntry != NULL){
		stat(nextEntry->d_name, &buf);

		printf("%s", (buf.st_mode & S_IRUSR) ? "r":"-");
		printf("%s", (buf.st_mode & S_IWUSR) ? "w":"-");
		printf("%s", (buf.st_mode & S_IXUSR) ? "x":"-");
		printf("%s", (buf.st_mode & S_IRGRP) ? "r":"-");
		printf("%s", (buf.st_mode & S_IWGRP) ? "w":"-");
		printf("%s", (buf.st_mode & S_IXGRP) ? "x":"-");
		printf("%s", (buf.st_mode & S_IROTH) ? "r":"-");
		printf("%s", (buf.st_mode & S_IWOTH) ? "w":"-");
		printf("%s\t", (buf.st_mode & S_IXOTH) ? "x":"-");

		printf("%i\t", buf.st_nlink);
		
	
		struct passwd* user = getpwuid(buf.st_uid);
		printf("%s\t", user->pw_name);

		struct group* group = getgrgid(buf.st_gid);
		printf("%s\t", group->gr_name);
		printf("%i\t", buf.st_size);	

		char dateStr[20];
		struct tm* datetm = localtime(&(buf.st_mtime));
		strftime(dateStr, 20, "%B    %d\t%H:%M", datetm);

		printf("%s\t", dateStr);
		printf("%s\n", nextEntry->d_name);
		
		nextEntry = readdir(curDir);
	}
	closedir(curDir);
		
	return 0;
}
