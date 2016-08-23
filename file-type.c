#include "time.h"
#include "sys/stat.h"
#include "stdio.h"

void main(){
    struct stat status;
    FILE *fp;
    stat("/home/mec/akheel",&status);

    if (status.st_mode & S_IFDIR)
         printf("It is directory.\n");
    if (status.st_mode & S_IFCHR)
         printf("It is chracter file.");
    if (status.st_mode & S_IFREG)
         printf("It is regular file.");
    if (status.st_mode & S_IFBLK)
         printf("It is block file.");

}
