#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
int main ( int argc, char *argv[]){
	struct stat FileAttrib;
	struct tm dt;
	printf("argc=%d and argv[0]=%s and argv[1]=%s\n",argc,argv[0],argv[1]);
	if(argc <= 1){
		printf("Argument missing!\n");
		exit(10);
 	}
 	if (stat(argv[(argc - 1)], &FileAttrib) < 0)
	printf("File Error Message = %s\n", strerror(errno));
	else
	printf( "Permissions: %o\n", FileAttrib.st_mode );
	printf("\nFile st_uid %d \n",FileAttrib.st_uid);
	printf("\nFile st_blksize %ld \n",FileAttrib.st_blksize);
	printf("\nFile st_gid %d \n",FileAttrib.st_gid);
	printf("\nFile st_blocks %ld \n",FileAttrib.st_blocks);
	printf("\nFile st_size %ld \n",FileAttrib.st_size);
	printf("\nFile st_nlink %u \n",(unsigned int)FileAttrib.st_nlink);
	printf("\nFile Permissions User\n");
	printf((FileAttrib.st_mode & S_IRUSR)? "r":"-");
	printf((FileAttrib.st_mode & S_IWUSR)? "w":"-");
	printf((FileAttrib.st_mode & S_IXUSR)? "x":"-");
	printf("\n");
	printf("\nFile Permissions Group\n");
	printf((FileAttrib.st_mode & S_IRGRP)? "r":"-");
	printf((FileAttrib.st_mode & S_IWGRP)? "w":"-");
	printf((FileAttrib.st_mode & S_IXGRP)? "x":"-");
	printf("\n");
	printf("\nFile Permissions Other\n");
	printf((FileAttrib.st_mode & S_IROTH)? "r":"-");
	printf((FileAttrib.st_mode & S_IWOTH)? "w":"-");
	printf((FileAttrib.st_mode & S_IXOTH)? "x":"-");
	printf("Fileaccess time %ld",FileAttrib.st_ctime);
	// File modification time
	dt = *(gmtime(&FileAttrib.st_mtime));
	printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon,dt.tm_year + 1900,	dt.tm_hour, dt.tm_min,dt.tm_sec);
	dt = *(gmtime(&FileAttrib.st_atime));
	printf("\nAccess time: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon,dt.tm_year + 1900,	dt.tm_hour, dt.tm_min,dt.tm_sec);
	switch (FileAttrib.st_mode & S_IFMT) {
		case S_IFBLK: 
			printf(" block device\n"); break;
		case S_IFCHR: 
			printf(" character device\n"); break;
		case S_IFDIR: 
			printf(" directory\n"); break;
		case S_IFIFO: 
			printf(" FIFO/pipe\n"); break;
		case S_IFLNK: 
			printf(" symlink\n"); break;
		case S_IFREG: 
			printf(" regular file\n"); break;
		case S_IFSOCK: 
			printf(" socket\n"); break;
		default: 
			printf(" unknown?\n"); break;
	}
	printf("\n");
	return 0;
}
