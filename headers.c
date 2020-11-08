#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
void attach(char final[]);
void checkstatus(char final[]);
void dateandtime(char final[]);
void serverused(char final[]);
void contentlen(char final[]);
void contenttype(char final[]);
void connection(char final[]);
void lastmodified(char final[]);
char *month(int m);
char *week(int w);
void attach(char final[])
{
checkstatus(final);
dateandtime(final);
serverused(final);
lastmodified(final);
contentlen(final);
contenttype(final);
connection(final);
}
void checkstatus(char final[])
{
char status[100]="HTTP/1.1 200 OK \n";
strcat(final,status);
}
void dateandtime(char final[])
{
char dt[1024];
int a,b;
time_t now = time(&now);
struct tm *ptm = gmtime(&now);
a=ptm->tm_wday;
b=ptm->tm_mon;
char cm[30];
char cw[30];
strcpy(cm,month(b));
strcpy(cw,week(a));
sprintf(dt,"Date: %s,%d %s %d %d:%d:%d GMT \n",cw,ptm->tm_mday,cm,ptm->tm_year+1900,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
strcat(final,dt);
}
void serverused(char final[])
{
char s[50]= "Server: CSSOC \n";
strcat(final,s);
}
void contentlen(char final[])
{
char conlen[100];
sprintf(conlen,"Content-Length: %d\n",200);
strcat(final,conlen);
}
void contenttype(char final[])
{
char contyp[50] = "Content-Type: text/html \n";
strcat(final,contyp);
}
void connection(char final[])
{
char connect[30]="Connection: closed \n";
strcat(final,connect);
}
void lastmodified(char final[])
{
char lm[1024];
int x,y;
struct tm *foo;
struct stat attrib;
stat("index.html", &attrib);
foo = gmtime(&(attrib.st_mtime));
x=foo->tm_wday;
y=foo->tm_mon;
char M[30];
char W[30];
strcpy(M,month(y));
strcpy(W,week(x));
sprintf(lm,"Last-Modified: %s,%d %s %d %d:%d:%d GMT \n",W,foo->tm_mday,M,foo->tm_year+1900,foo->tm_hour,foo->tm_min,foo->tm_sec);
strcat(final,lm);
}
char * month(int m)
{
switch(m)
{
case 1:

return "Jan";

break ;

case 2:

return "Feb";

break ;

case 3:

return "Mar"  ;

break ;

case 4:

return "Apr" ;

break ;

case 5:

return "May";

break ;

case 6:

return "Jun"  ;

break ;

case 7:

return "Jul"  ;

break ;

case 8:

return "Aug" ;

break ;

case 9:

return "Sep";

break ;

case 10:

return "Oct";

break ;

case 11:

return "Nov";

break ;

case 12:

return "Dec";

break;

default : printf ( " EXIT " ) ;
}
}
char * week(int n)
{
switch(n)
{
        case 1: 
            return "Mon";
            break;
        case 2: 
            return "Tue";
            break;
        case 3: 
            return "Wed";
            break;
        case 4: 
            return "Thu";
            break;
        case 5: 
            return "Fri";
            break;
        case 6: 
            return "Sat";
            break;
        case 0: 
            return "Sun";
            break;
        default: 
            printf("Invalid input!");
    }
}









