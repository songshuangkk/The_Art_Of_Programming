#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct node{
	char name;
	int length[7];
}Node;

char start;
char end;
char path[20] = {0};
int start_flag = 0;
int end_flag = 0;
int use[7] = {0};
int path_num = 0;

Node grap[7] = {{'A',{0,2,6,8,1000,1000,1000}},{'B',{2,0,3,1000,1000,1000,1000}},
{'C',{6,3,0,9,11,1000,1000}},{'D',{8,1000,9,0,13,17,1000}},{'E',{1000,1000,11,13,0,6,1000}},
{'F',{1000,1000,1000,17,13,0,1000}},{'G',{1000,1000,1000,1000,1000,1000,0}}};

void search(char start, char end)
{
	int i,j;
	int n = 1;
	int flag = 0;
	for(i=0; i<7; i++)
	{
		if(grap[i].name == start)
			start_flag = i;
		if(grap[i].name == end)
			end_flag = i;
	}

	use[start_flag] = 1;

	path[0] = grap[start_flag].name;
	path_num++;

	while(n<7)
	{
		int tempmin = MAX;
		for(i=0; i<7; i++)
		{
			if(use[i]==0&&grap[start_flag].length[i]<tempmin&&i!=start_flag)
			{
				tempmin = grap[start_flag].length[i];
				flag = i;
			}
		}
		use[flag] = 1;
		n++;
		/*Update the length*/
		for(j=0; j<7;j++)
		{
			if(grap[flag].length[j]+tempmin<grap[start_flag].length[j]&&use[j]==0&&grap[flag].length[j]!=MAX)
			{
				grap[start_flag].length[j] = grap[flag].length[j]+tempmin;
			}
		}
		if(flag == end_flag)
			break;
	}
	
	
}

int
main(int argc, const char **argv)
{
	int i, j;
	for(i=0; i<7; i++)
	{
		printf("%c: ", grap[i].name);
		for(j=0; j<7; j++)
		{
			printf("%d ", grap[i].length[j]);
		}
		printf("\n");
	}

	while(1)
	{
		printf("Please input the start:");
		scanf("%c", &start);
		getchar();
		printf("Please input the end:");
		scanf("%c", &end);
		getchar();

		search(start, end);
	}
	return 0;
}
