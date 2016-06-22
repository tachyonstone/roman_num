#include <stdio.h>
#include <string.h>

#define BUFSIZE 20

int pattern_change(int *branch)
{
  int figure;
  char figure_buf[BUFSIZE];
  char branch_ch[BUFSIZE];
  int flag=0;
  int lim;
  int branch1;

  do{
	printf("\n1~3までの数字を入力し、表示パターンを選択してください。\n");
	printf("pattern > ");
	fgets(branch_ch, BUFSIZE, stdin);
	if(strlen(branch_ch)>=BUFSIZE-1){
	  while(getchar() != '\n');
	}
	if(strcmp(branch_ch,"exit\n")==0 || strcmp(branch_ch,"\"exit\"\n")==0){
	  return -1;
	}
	if(strcmp(branch_ch,"change\n")==0 || strcmp(branch_ch,"\"change\"\n")==0){
	  lim = pattern_change(&branch1);
	}

	*branch = atoi(branch_ch);
	if(*branch>3 || *branch<1 || strlen(branch_ch)!=2){
	  printf("不適切な文字が入力されました。\n\n");
	}

	if(*branch==1){
	  lim = 40000;
	}else if(*branch==2){
	  lim = 50000;
	}else{
	  lim = 100000;
	}

  }while(*branch>3 || *branch<1);

  return lim;

}


int arabicnum_to_romannum1(int figure)
{
  int i;
  char *r_num1[20] = {"I","V","X","L","C","D","M","F","T"};
  char *r_num2[20] = {"IV","IX","XL","XC","CD","CM","MF","MT"};

  while(figure>=10000){
	printf("%s", r_num1[8]);
	figure = figure-10000;
  }
  if(9000<=figure && figure<10000){
	printf("%s", r_num2[7]);
	figure = figure-9000;
  }
  if(figure>=5000){
	printf("%s", r_num1[7]);
	figure = figure-5000;
  }
  if(4000<=figure && figure<5000){
	printf("%s", r_num2[6]);
	figure = figure-4000;
  }

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

  return 0;

}


int arabicnum_to_romannum2(int figure)
{
  int i;
  char *r_num1[20] = {"I","V","X","L","C","D","M","F","T"};

  while(figure>=10000){
	printf("%s", r_num1[8]);
	figure = figure-10000;
  }
  if(5000<=figure && figure<10000){
	printf("%s", r_num1[7]);
	figure = figure-5000;
  }

  while(figure>=1000){
	printf("%s", r_num1[6]);
	figure = figure-1000;
  }
  if(500<=figure && figure<1000){
	printf("%s", r_num1[5]);
	figure = figure-500;
  }

  while(figure>=100){
	printf("%s", r_num1[4]);
	figure = figure-100;
  }
  if(50<=figure && figure<100){
	printf("%s", r_num1[3]);
	figure = figure-50;
  }

  while(figure>=10){
	printf("%s", r_num1[2]);
	figure = figure-10;
  }
  if(5<=figure && figure<10){
	printf("%s", r_num1[1]);
	figure = figure-5;
  }

  while(figure>=1){
	printf("%s", r_num1[0]);
	figure--;
  }

  return 0;

}


int arabicnum_to_romannum3(int figure)
{
  int i;
  char *r_num1[20] = {"I","V","X","L","C","D","M","F","T"};

  while(figure>=1000){
	printf("%s", r_num1[6]);
	figure = figure - 1000;
  }
  while(figure>=100){
	printf("%s", r_num1[4]);
	figure = figure -100;
  }
  while(figure>=10){
	printf("%s", r_num1[2]);
	figure = figure -10;
  }
  while(figure>=1){
	printf("%s", r_num1[0]);
	figure = figure -1;
  }

  return 0;

}

int input_error(char *figure_buf, int lim)
{
  int figure;
  int i=0,n;
  char branch_ch[BUFSIZE];
  int branch;
  int flag=0;

  n = strlen(figure_buf);

  while(i<n-1){
	figure = figure_buf[i]-'0';
	if(figure < 0 || figure > 9){
	  printf("不適切な文字が入力されました。\n\n1~%dまでのアラビア数字を入力してください。\n", lim-1);
	  printf("arrabic_number > ");
	  return 0;
	}
	i++;
  }

  figure = atoi(figure_buf);

  if(figure<=0 || figure >=lim){
	printf("不適切な文字が入力されました。\n\n1~%dまでのアラビア数字を入力してください。\n", lim-1);
	printf("arrabic_number > ");
  }

  return figure;

}


int main(void)
{
  int figure;
  char figure_buf[BUFSIZE];
  int branch;
  int flag=0;
  int lim;

  printf("**********************************************************\n");
  printf("=   <使い方>                                             =\n");
  printf("=(1) 表示パターンの選択                                  =\n");
  printf("=  表示パターンを1~3の中から選んでください。             =\n");
  printf("=  例えば、\"958\"と入力したとすると、                     =\n");
  printf("=  表示パターン1 -> CMLVIII                              =\n");
  printf("=  表示パターン2 -> DCCCCLVIII                           =\n");
  printf("=  表示パターン3 -> CCCCCCCCCXXXXXIIIIIIII               =\n");
  printf("=(2) ローマ数字への変換                                  =\n");
  printf("=  最大で99999までの半角のアラビア数字で整数を入力すると =\n");
  printf("=  ローマ数字に変換して表示されます。                    =\n");
  printf("=(3) コマンド操作                                        =\n");
  printf("=  \"change\"と入力すると表示パターンの切り替えができます。=\n");
  printf("=  \"exit\"と入力すると処理を終了します。                  =\n");
  printf("**********************************************************\n");

  lim = pattern_change(&branch);
  if(lim == -1){
	return 0;
  }

  while(1){
	printf("\n1~%dまでのアラビア数字を入力してください。\n", lim-1);
	printf("arrabic_number > ");
	do{
	  fgets(figure_buf, BUFSIZE, stdin);
	  if(strlen(figure_buf)>=BUFSIZE-1){
		while(getchar() != '\n');
	  }
	  if(strcmp(figure_buf,"exit\n")==0 || strcmp(figure_buf,"\"exit\"\n")==0){
		return 0;
	  }
	  if(strcmp(figure_buf,"change\n")==0 || strcmp(figure_buf,"\"change\"\n")==0){
		lim = pattern_change(&branch);
		if(lim == -1){
		  return 0;
		}
		flag = 1;
		break;
	  }

	  figure = input_error(figure_buf, lim);
	  if(figure == -1){
		return 0;
	  }

	}while(figure<=0 || figure >=lim);

	if(flag == 0){
	  if(branch==1){
		printf("roman_number   > ");
		arabicnum_to_romannum1(figure);
		printf("\n");
	  }else if(branch==2){
		printf("roman_number   > ");
		arabicnum_to_romannum2(figure);
		printf("\n");
	  }else if(branch==3){
		printf("roman_number   > ");
		arabicnum_to_romannum3(figure);
		printf("\n");
	  }
	}else{
	  flag = 0;
	}

  }

  return 0;

}
