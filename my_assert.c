#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int my_assert(int expression){
    if (expression == 0){
        printf("%s: %s:%d: ", __FUNCTION__,__FILE__, __LINE__);
        return 0;
    }
    else 
        return 1;
}

void foo(int num){
    if (my_assert(((num >= 0) && (num <= 100))) == 0){
        printf("%s: Assertion '((num >= 0) && (num <= 100))' failed.\n", __FUNCTION__);
        abort();
    }

    printf("foo : num = %d\n", num);
}
int main(int argc, char *argv[]){
    int num;

    if (argc < 2){
        fprintf(stderr, "Usage : my_assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
}
