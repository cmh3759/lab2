#include <stdio.h>
#include <search.h>
#include <string.h>
#include <stdlib.h>

/* 학생 구조체 : 이름, 중간고사 점수, 기말고사 점수, 합계 점수 */
struct student {
    char *name;
    int midterm_score;
    int final_score;
    int total_score;
};

struct student *root = NULL;

/* 탐색중인 노드의 위치를 비교 */
int compare(const void *cp1, const void *cp2)
{
    return strcmp(((struct student *)cp1)->name,
        ((struct student *)cp2)->name);
}

/* twalk 가 노드를 처음 만나게 되면 출력됨 */
void print_student_node(const void *nodeptr, VISIT order, int level)
{
    if (order == preorder || order == leaf)
        printf("\n name = %s,\n midterm exam score = %d,\n final exam score = %d,\n total score = %d\n",
            (*(struct student **)nodeptr) -> name,
            (*(struct student **)nodeptr) -> midterm_score,
            (*(struct student **)nodeptr) -> final_score,
            (*(struct student **)nodeptr) -> total_score);
}

int main()
{
    int i, j;
    int num_students;
    
    struct student **ret;

    printf("How many students in this class? Input: ");
    scanf("%d", &num_students);

    /* 입력받은 크기 만큼의 이름을 저장할 테이블 */
    char nametable[num_students * 20];
    char *nameptr = nametable;
    
    /* 입력받은 크기 만큼의 노드가 담길 테이블 */
    struct student nodetable[num_students];
    struct student *nodeptr = nodetable;

//    struct student *nodap;

    /* 학생 구조체를 사용하여 사용자가 입력한 수 만큼 메모리 할당 */
    nodeptr = (struct student*)malloc(num_students * sizeof(struct student));

    for(i=1; i<num_students+1; i++)
    {
        printf("\n We are talking about student : number is %d \n", i);
        printf(" What is his name? / student number %d / Input : ", i);
        scanf("%s", nameptr);
        printf("Mid-term exam score? / student number %d / Input : ", i);
        scanf("%d", &nodeptr->midterm_score);
        printf("Fianl exam score? / student number %d / Input : ", i);
        scanf("%d", &nodeptr->final_score);

        nodeptr->total_score = nodeptr->midterm_score + nodeptr->final_score;
        
        nodeptr->name = nameptr;

        /* 트리에 넣기 */    
        ret = (struct student**)tsearch((void *)nodeptr,
            (void **)&root, compare);
        printf("\"%s\" : ", (*ret)->name);
        if (*ret == nodeptr)
        {
            printf("Added in this Tree\n");
        }
        else
        {
            printf("is already exists!\n");
        }

        nameptr += strlen(nameptr) +1;
        nodeptr++;
    }

    twalk((void *)root, print_student_node);

    free(nodeptr - num_students);    

    printf("\n");

    return 0;
}
