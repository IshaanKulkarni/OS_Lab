#include "types.h"
#include "stat.h"
#include "user.h"
int main(){
	int pid=fork();
	if(pid>0){
		pid=wait();
		printf(1,"Child Process id is: %d\n",pid);
		int parent_id=getpid();
		printf(1,"The parent's process id is: %d\n",parent_id);
	}else if(pid==0){
		char*argv[2];
		argv[0]="2";
		argv[1]="5";
		exec("./addition",argv);
		printf(1,"Exited from child successfully\n");
		exit();
	}
	else{
		printf(1,"Fork error!\n");
	}

	exit();
}
