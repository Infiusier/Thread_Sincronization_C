#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char g_vector[30];

pthread_t g_TA;
pthread_t g_TB;
pthread_t g_TC;

int g_flag1 = 1;
int g_flag2 = 0;
int g_flag3 = 0;

int g_vector_index = 0;

void *thread_A(void *arg);
void *thread_B(void *arg);
void *thread_C(void *arg);
void print_vector();

void *thread_A(void *arg) {
while(1){
    while(g_flag1 == 0);
   
    g_vector[g_vector_index++] = 'A';
   
    g_flag2 = 1;
    g_flag1 = 0;
}
}

void *thread_B(void *arg) {
while(1){
    while(g_flag2 == 0);
   
    g_vector[g_vector_index++] = 'B';
    g_flag3 = 1;
    g_flag2 = 0;
}
}

void *thread_C(void *arg) {
while(1){
    if(g_vector_index == 30){
    print_vector();
    g_flag1 = 0;
    g_flag2 = 0;
    g_flag3 = 0;
    return;
    }
   
    while(g_flag3 == 0);
   
    g_vector[g_vector_index++] = 'C';
   
    g_flag1 = 1;
    g_flag3 = 0;
}
}

void print_vector(){
for(int i = 0 ; i< 30 ; i++){
printf("%c ", g_vector[i]);
}
}

int main(void) {

pthread_create(&g_TA,NULL,thread_A,NULL);
pthread_create(&g_TA,NULL,thread_B,NULL);
pthread_create(&g_TA,NULL,thread_C,NULL);
pthread_join(g_TA, NULL);
pthread_join(g_TB, NULL);
pthread_join(g_TC, NULL);
return 0;
}
