#include <stdio.h>

int main() {

	int processId = getpid();
	int parentPID = getppid();

	int realUserID = getuid();
	int groupID = getgid();

	int EUserID = geteuid();
	int EgroupID = getegid();

	printf("Process ID %d \n", processId);
	printf("Parent Process ID %d \n", parentPID );

	printf("Real user ID %d \n", realUserID );
	printf("Real Group ID %d \n", groupID );


	printf("Effective  user ID %d \n", EUserID );
	printf("Effective Group ID %d \n", EgroupID );

	// For creating a new File
	// int fileDescriptor = creat("testy.txt", 0777);
	// printf("%d \n",fileDescriptor);


	int fileDescriptor = open("testy.txt", 2);
	//0 - Read only
	//1 - Write only
	//2 - Read Write mode

	printf("File Descriptor %d \n", fileDescriptor);



	// Writing to Stream
	// int noOfBytesWritten = write(fileDescriptor, "Hello", 20);
	// printf("No of bytes Written %d \n", noOfBytesWritten );


	//Sleep the program
	int n = 2;
	printf("sleep for %d seconds \n", n);
	sleep(n);





	// Reading from a stream
	char ArrayOfChar[100];
	int returnValForRead = read(fileDescriptor, ArrayOfChar, 15);
	printf("Return Value for read %d \n", returnValForRead);
	printf("Value read was : %s \n", ArrayOfChar );

	close(fileDescriptor);

	// Forking
	int childIDOrZero = fork();

	if(childIDOrZero == 0) {
		//Logic for the Child process
		printf("This was by the child process \n");
	}

	else {
		//Logic for the parent process
		printf("This was by the parent process \n");
		printf("The child process ID is %d \n", childIDOrZero);
	}

	return 0;
}