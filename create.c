#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int length;

void get_data(char *buff, char user[2][100], int length)
{
    int i;
    int j=0;
    int flag = 0;

    for(i = 0; i < length; i++)
    {
       if (buff[i] == '=')
       {
           i++;
           j = 0;

           /*
                flag == 0:Get User Name;
                flag == 1:Get User Password;
            */
           while(buff[i]!='&' && buff[i] != '\0')
           {
               user[flag][j] = buff[i];
               j++;
               i++;
           }
           user[flag][j] = '\0';
           flag++;
           if (flag == 2)
           {
               break;
           }  
       }
    }
    printf("<center><h2>Login Successfull</h2></center>\n");
}

void create_ident(char user[2][100])
{
    FILE *fp = NULL;
    FILE *f1 = NULL;
    int len = 0;
    char c = '\n';
    char ret;

    fp = fopen("./create.txt", "w");

    if (fp == NULL)
    {
        printf("<h1>Error 503!\nServer Unavailable</h1>\n");
    }

    //write the login user data to the name.txt
    len = strlen(user[0]);
    fwrite(user[0], len, 1, fp);
    fwrite(&c, 1, 1, fp);
    len = strlen(user[1]);
    fwrite(user[1], len, 1, fp);

    printf("<center><h1>Open Successfull!</h1></center>\n");
    
    fclose(fp);

    printf("<h1>user = %s Password = %s</h1>\n", user[0], user[1]);
    system("create.py");
    f1 = fopen("./check.txt", "r");
    fread(&ret, 1, 1, f1);

    if(ret == '1')
    {
      //Jump to the SVN web
      printf("<h1>OK</h1>\n");
    }
    if (ret == '0')
    {
      printf("<h1>Error</h1>\n");
    }
    
    fclose(f1);
    fp = NULL;
    f1 = NULL;
}

int
main(int argc, const char *argv[])
{
    char *len = NULL;
    char *method = NULL;
    char *data;
    char buff[100] = {};

    /*
        user[0] --->  User Name;
        user[1] --->  User Password;
    */
    char user[2][100] = {0};
	
  printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<body>\n");

	//Check The Method
	method = getenv("REQUEST_METHOD");
	if(method!=NULL)
    {
    	//The 'POST' method
		if(!strcmp(method, "POST"))
		{
            int i, j=0;
            int length;
		    len = getenv("CONTENT_LENGTH");
            if (len == NULL)
            {
                printf("<h1>Len(NULL)Error!</h1>\n");
                return;
            }
            length = atoi(len)+1;
            fgets(buff, length, stdin);
            buff[length] = '\0';
            get_data(buff, user, length);

            create_ident(user);

		}

		//The 'GET' method
	    if(!strcmp(method, "GET"))
	    {
	        printf("<h1>GET</h1>");
	        return;
	    }
    } 

	printf("</body>\n");
	printf("</html>\n");
	return 0;
}

