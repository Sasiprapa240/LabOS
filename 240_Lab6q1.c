#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum;
int upper;
int msum;
void *runner(void *param);

int main(int argc, char *argv[]){
	
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, runner, argv[1]);
	int i;
	pthread_join(tid,NULL);
	if(upper>0){
		for(i=0; i<=upper; i++ ){
			msum +=i;
		}
	}		
	printf("msum = %d\n", msum);		
	printf("Difference of csum & msum = %d\n", csum-msum);
	return 0;
}
void *runner(void *param){
	upper = atoi(param);
	int i;
	csum = 0;

	if(upper > 0){
		for(i=0; i<=upper*2; i++){
			csum+=i;
		}
	}
	printf("csum = %d\n", csum);
	pthread_exit(0);
}
/* 2.5) มี 2 เคส คือ 1. ตัวแม่เสร็จก่อนตัวลูก
  		     2. ตัวลูกเสร็จก่อนตัวแม่
	ถ้า input คือ 5 และผลต่างของ csum กับ msum ไม่ใช่ -15 หรือ 40 นั่นคือ  กรณีที่ตัวลูกยังทำไม่เสร็จ แต่ตัวแม่เริ่มลบไปแล้ว คำตอบจึงไม่แน่นอน*/
