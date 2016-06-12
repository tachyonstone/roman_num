#include <stdio.h>

#define BUFSIZE 20

int arabicnum_to_romannum(int figure){
  int i;
  char *r_num1[20] = {"I","V","X","L","C","D","M"};
  char *r_num2[20] = {"IV","IX","XL","XC","CD","CM"};

  while(figure>=1000){
	printf("%s", r_num1[6]);
	figure = figure-1000;
  }
  if(900<=figure && figure<1000){
	printf("%s", r_num2[5]);
	figure = figure-900;
  }
  if(500<=figure && figure<900){
	printf("%s", r_num1[5]);
	figure = figure-500;
  }
  if(400<=figure && figure<500){
	printf("%s", r_num2[4]);
	figure = figure-400;
  }

  while(figure>=100){
	printf("%s", r_num1[4]);
	figure = figure-100;
  }

  if(90<=figure && figure<100){
	printf("%s", r_num2[3]);
	figure = figure-90;
  }
  if(50<=figure && figure<90){
	printf("%s", r_num1[3]);
	figure = figure-50;
  }
  if(40<=figure && figure<50){
	printf("%s", r_num2[2]);
	figure = figure-40;
  }

  while(figure>=10){
	printf("%s", r_num1[2]);
	figure = figure-10;
  }
  if(5<=figure && figure<9){
	printf("%s", r_num1[1]);
	figure = figure-5;
  }
  if(figure == 9){
	printf("%s\n", r_num2[1]);
	return 0;
  }else if(figure == 4){
	printf("%s\n", r_num2[0]);
	return 0;
  }else{
	while(figure>=1){
	  printf("%s", r_num1[0]);
	  figure--;
	}
  }

  printf("\n");

  return 0;

}


int main(void)
{
  int figure;
  char figure_buf[BUFSIZE];
  printf("please put a figure!\n");
  do{
	fgets(figure_buf, BUFSIZE, stdin);
	figure = atoi(figure_buf);
	if(figure<=0 || figure >=4000)
	  printf("Please  a figure within 1~3999!\n");
  }while(figure<=0 || figure >=4000);

  arabicnum_to_romannum(figure);


  return 0;

}
