#include <stdio.h>


// For creating a new File
int createFile() {
	int fileDescriptor = creat("testy.txt", 0777);
	printf("%d file descriptor while creating file : \n",fileDescriptor);
}

int openFile() {
	int fileDescriptor = open("testy.txt", 2);
	//0 - Read only
	//1 - Write only
	//2 - Read Write mode

	printf("File Descriptor %d \n", fileDescriptor);
	return fileDescriptor;
}


// Writing to Stream
void writeToStream(int fileDescriptor) {
	int noOfBytesWritten = write(fileDescriptor, "Hello", 5);
	printf("No of bytes Written %d \n", noOfBytesWritten );

}

//Sleep the program
void sleepThePgm() {
	int n = 2;
	printf("sleep for %d seconds \n", n);
	sleep(n);
}


// Reading from a stream
void readFromStream(int fileDescriptor) {
	char ArrayOfChar[100];
	int returnValForRead = read(fileDescriptor, ArrayOfChar, 5);
	printf("Return Value for read %d \n", returnValForRead);
	printf("Value read was : %s \n", ArrayOfChar );
}

// Forking
void forking() {
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

}


//Kill a process
void killProcess() {
	int processId = 4742;
	int returnValForKill = kill(processId, 1);
	printf("returnValForKill : %d\n", returnValForKill);
}



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

	// int fileDescriptor1 = createFile();
	int fileDescriptor2 = openFile();

	// printf("fileDescriptor1 %d \n", fileDescriptor1 );
	printf("fileDescriptor2 %d \n", fileDescriptor2 );

	writeToStream(fileDescriptor2);
	// sleepThePgm();

	readFromStream(fileDescriptor2);


	forking();

	// close(fileDescriptor1);
	close(fileDescriptor2);


	return 0;
}
