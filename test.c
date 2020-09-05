#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define MAX_LINE 1024
char buf1[MAX_LINE];
int hu = 12;
int pnum =0;
int hnum = 0;
int rnum = 0;
int tnum = 0;
int wnum = 0;

int number1(char buf1[])
{
	int i=0;
	int num_int;
	char *dest_str; // Ä¿±ê×Ö·û´®
	char number[10];
	printf("%d",hu);
	hu = hu + 2;  //Ìø¹ý:

	while(buf1[hu] != ':')
	{
		if(buf1[hu] == '*')
		{
			break;
		}
		number[i] = buf1[hu];
		i++;
		hu++;
	}

	hu = hu + 1;
	
	//printf("---%c---",buf1[hu]);
	dest_str = (char *)malloc(sizeof(char) * (sizeof(number) + 1));
    	/* Îª×Ö·û´®·ÖÅä¶Ñ¿Õ¼ä */
     
    	strncpy(dest_str, number, sizeof(number));
		
		num_int = atoi(dest_str);
     
    	return num_int;
}


int pipei(char buf1[MAX_LINE])
{
	
	int p = 0;
	int h = 0;
	int r = 0;
	int t = 0;
	int w = 0;

	while(buf1[hu] != '*')
	{
		switch(buf1[hu])
		{
			case 'H':
				hnum += number1(buf1);
				printf("this is h\n");
				
				h++;
				break;
			case 'P':
				pnum += number1(buf1);
				printf("this is p\n");
				p++;
				break;
			case 'R':
				rnum += number1(buf1);
				printf("this is r\n");

				r++;
				break;
			case 'T':
				tnum += number1(buf1);
				printf("this is t\n");
				//printf("%c---",buf1[hu]);
				t++;
				break;
			case 'W':
				wnum += number1(buf1);
				printf("this is w\n");
				//printf("%d",number1(buf1));
				w++;
				break;
			case 'D':
				printf("=.=");
				if(buf1[hu+11] != ':')
					hu += 13;
				else
					hu += 12;
			default:
				break;
		}
	}
	printf("average pnum=%d----hunm=%d----rnum=%d----tnum=%d----wnum=%d----\n",pnum/p,hnum/h,rnum/r,tnum/t,wnum/w);
	return 0;
}



int main()
{
	 char buf[MAX_LINE];  
	 FILE *fp;           
	 int len;             
	 int num;
	 char *s = "**";
	 if((fp = fopen("test.txt","r")) == NULL)
	{
		perror("fail to read");
		exit (1) ;
	}
	while(fgets(buf,MAX_LINE,fp) != NULL)
	{
		len = strlen(buf);
		buf[len-1] = '\0'; 
		strcat(buf1,buf);
	}
	
	
	
	strcat(buf1,s);
	len = strlen(buf1);
	buf1[len] = '\0';
	printf("%s %d \n",buf1,len - 1);
	pipei(buf1);

	return 0;
}