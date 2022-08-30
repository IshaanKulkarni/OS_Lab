#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char*argv[]){
	int x=0;
	int y=0;
	x=atoi(argv[0]);
	y=atoi(argv[1]);
	printf(1,"\nThe difference is %d\n",x-y);
	exit();
}
