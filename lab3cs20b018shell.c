#include "types.h"
#include "stat.h"
#include "user.h"
void prompt(){
	printf(1,"cs20b018$ ");
}
int getcmd(char *buf, int nbuf)
{
  prompt();
  memset(buf, 0, nbuf);
  gets(buf, nbuf);
  if(buf[0]=='#'){
	  return -2;
  }
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
}
void tostring(int val, char* c){
	for(int i=4;i>=0;i--){
		c[i]='0'+val%10;
		val=val/10;
	}
	c[5]='\0';
}
void print(char* buff){
	int n=strlen(buff);
	for(int i=0;i<n;i++){
		if(buff[i]!=' ')
			printf(1,"%c",buff[i]);
		else
			printf(1,"\n",buff[i]);
	}
}

void execu(int a, int b ,char ch){
	char as[6];
	char bs[6];

	char*argv[2];

	tostring(a,as);
	tostring(b,bs);

	argv[0]=as;
	argv[1]=bs;

	int pid=fork();
	if(pid>0){
		pid=wait();
	}else if(pid==0){
		if(ch=='+')
			exec("./addition",argv);
		else if(ch=='*')
			exec("./multiplication",argv);
		else if(ch=='-')
			exec("./subtraction",argv);

		exit();

	}
	else{
		printf(1,"Fork error!");
	}
}

void parse(char* buff){
	int n=strlen(buff);
	if(buff[0]=='e' && buff[1]=='c' && buff[2]=='h' && buff[3]=='o'){
			for(int i=5;i<n;i++){
			printf(1,"%c",buff[i]);
		}
	}
	else{
		int a=0;
		int b=0;
		char ch;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(buff[i]==' ') break;
			int val=buff[i]-'0';
			a=a*10+val;
			cnt++;
		}
		ch=buff[cnt+1];
		for(int i=cnt+3;i<n-1;i++){
			int val=buff[i]-'0';
			b=b*10+val;
		}
		//printf(1,"%d\n",a);
		//printf(1,"%d\n",b);
		//printf(1,"%c\n",ch);
		execu(a,b,ch);
	}
}
int main(int argc, char**argv){
	static char buff[100];
	int val=0;
	while(val!=-2){
		val=getcmd(buff,100);
		parse(buff);
	}
	printf(1,"%s",buff);
	return 0;
}
