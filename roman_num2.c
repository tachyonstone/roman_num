#include <stdio.h>
#include <string.h>

#define BUFSIZE 20

int pattern_change(int *branch)
{
  char branch_ch[BUFSIZE];
  int lim;
  int flag;

  do{
	flag = 0;
	printf("\n1~3までの数字を入力し、表示パターンを選択してください。\n");
	printf("pattern > ");
	fgets(branch_ch, BUFSIZE, stdin);
	if(strlen(branch_ch)>=BUFSIZE-1){
	  while(getchar() != '\n');  //バッファに残った文字を取り除く
	}

	if(strcmp(branch_ch,"exit\n")==0 || strcmp(branch_ch,"\"exit\"\n")==0){
	  return -1;
	}
	if(strcmp(branch_ch,"change\n")==0 || strcmp(branch_ch,"\"change\"\n")==0){
	  *branch = -1;
	  flag = -1;
	}

	if(flag == 0){
	  *branch = atoi(branch_ch);

	  if(*branch>3 || *branch<1 || strlen(branch_ch)!=2){
		printf("不適切な文字が入力されました。\n\n");
		*branch = -1;
	  }

	  if(*branch==1){
		lim = 40000;  //表示パターン1の最大値用
	  }else if(*branch==2){
		lim = 50000;  //表示パターン2の最大値用
	  }else if(*branch==3){
		lim = 100000; //表示パターン3の最大値用
	  }
	}

  }while(*branch>3 || *branch<1);

  return lim;

}


int arabicnum_to_romannum1(int figure)
{
  int i;
  int n = 10000;
  char *r_num1[20] = {"I","V","X","L","C","D","M","F","T"};
  char *r_num2[20] = {"IV","IX","XL","XC","CD","CM","MF","MT"};

  for(i=8; i > 2; i=i-2){
	while(figure>=n){
	  printf("%s", r_num1[i]);
	  figure = figure-n;
	}
	if((n-n/10)<=figure && figure<n){
	  printf("%s", r_num2[i-1]);
	  figure = figure-(n-n/10);
	}
	if(figure>=n/2){
	  printf("%s", r_num1[i-1]);
	  figure = figure-n/2;
	}
	if((n/2-n/10)<=figure && figure<n/2){
	  printf("%s", r_num2[i-2]);
	  figure = figure-(n/2-n/10);
	}
	n /= 10;
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
  int n = 10000;
  char *r_num1[20] = {"I","V","X","L","C","D","M","F","T"};

  for(i=8; i>=1; i=i-2){
	while(figure>=n){
	  printf("%s", r_num1[i]);
	  figure = figure-n;
	}
	if(n/2<=figure && figure<n){
	  printf("%s", r_num1[i-1]);
	  figure = figure-n/2;
	}
	n /= 10;
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
  int n = 10000;
  char *r_num3[20] = {"I","X","C","M","T"};

  for(i=4; i>=0; i--){
	while(figure>=n){
	  printf("%s", r_num3[i]);
	  figure = figure - n;
	}
	n /= 10;
  }

  return 0;

}


int check_error(char *figure_buf, int lim)
{
  int figure;
  int i=0;
  int n;

  n = strlen(figure_buf);

  while(i<n-1){
	figure = figure_buf[i]-'0';
	if(figure < 0 || figure > 9){
	  printf("不適切な文字が入力されました。\n\n");
	  printf("1~%dまでのアラビア数字を入力してください。\n", lim-1);
	  printf("Arabic_numerals > ");
	  return 0;
	}
	i++;
  }

  figure = atoi(figure_buf);

  if(figure<=0 || figure >=lim){
	printf("不適切な文字が入力されました。\n\n");
	printf("1~%dまでのアラビア数字を入力してください。\n", lim-1);
	printf("Arabic_numerals > ");
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
  printf("= <使い方>                                               =\n");
  printf("= (1) 表示パターンの選択                                 =\n");
  printf("=  表示パターンを1~3の中から選んでください。             =\n");
  printf("=  例えば、\"958\"と入力したとすると、                     =\n");
  printf("=  表示パターン1 -> CMLVIII                              =\n");
  printf("=  表示パターン2 -> DCCCCLVIII                           =\n");
  printf("=  表示パターン3 -> CCCCCCCCCXXXXXIIIIIIII               =\n");
  printf("= (2) ローマ数字への変換                                 =\n");
  printf("=  半角のアラビア数字で整数を入力すると                  =\n");
  printf("=  ローマ数字に変換して表示されます。                    =\n");
  printf("= (3) コマンド操作                                       =\n");
  printf("=  \"change\"と入力すると表示パターンの切り替えができます。=\n");
  printf("=  \"exit\"と入力すると処理を終了します。                  =\n");
  printf("**********************************************************\n");

  lim = pattern_change(&branch);
  if(lim == -1){  //exit
	return 0;
  }

  while(1){  //label : flag==1のときここに戻る
	printf("\n1~%dまでのアラビア数字を入力してください。\n", lim-1);
	printf("Arabic_numerals > ");
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
		if(lim == -1){  //exit
		  return 0;
		}
		flag = 1;  //labelに戻る
		break;
	  }

	  figure = check_error(figure_buf, lim);

	}while(figure<=0 || figure >=lim);
	if(flag == 0){
	  if(branch==1){
		printf("Roman_numerals  > ");
		arabicnum_to_romannum1(figure);
		printf("\n");
	  }else if(branch==2){
		printf("Roman_numerals  > ");
		arabicnum_to_romannum2(figure);
		printf("\n");
	  }else if(branch==3){
		printf("Roman_numerals  > ");
		arabicnum_to_romannum3(figure);
		printf("\n");
	  }
	}else{  //labelに戻る
	  flag = 0;
	}
  }

}
