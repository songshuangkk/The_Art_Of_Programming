#include <stdio.h>
#include <stdlib.h>


int length;

void get_data(char *buff, char user[3][100], int length)
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
                flag == 2:Get User New Password;
                flag == 3:Get Over!
            */
           while(buff[i]!='&' && buff[i] != '\0')
           {
               user[flag][j] = buff[i];
               j++;
               i++;
           }
           user[flag][j] = '\0';
           flag++;
           if (flag == 3)
           {
               break;
           }  
       }
    }
    printf("<h2>name=%s</h2>\n<h2>password= %s\n</h2><h2>new password= %s</h2>\n", user[0], user[1], user[2]);
}

void check_ident(char user[3][100])
{
    FILE *fp = NULL;

    fp = fopen("./auth", "r");

    if (fp == NULL)
    {
        printf("<h1>Error 503!\nServer Unavailable</h1>\n");
    }

    printf("<h1>Open Successfun!</h1>\n");

    fclose(fp);
    fp = NULL;
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
        user[2] --->  User New Pawword;
    */
    char user[3][100] = {0};
	
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

            check_ident(user);

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
