#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(){
	void *handle;
	int (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int), (*divide)(int, int);
	char *error;
	
	handle = dlopen("./lib/libtest.so",RTLD_LAZY);
	if(!handle){
		fputs(dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	subtract = dlsym(handle, "subtract");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	divide = dlsym(handle, "divide");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	printf("add(1,2)=%d\n",(*add)(1,2));
	printf("subtract(2,1)=%d\n",(*subtract)(2,1));
	printf("multiply(2,3)=%d\n",(*multiply)(2,3));
	printf("divide(4,2)=%d\n",(*divide)(4,2));
	dlclose(handle);
	
}
