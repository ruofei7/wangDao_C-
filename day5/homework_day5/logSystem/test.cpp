#include<stdio.h>  
#include<string>
#include<iostream>
using namespace std;
//void warn(const char *msg,string filename=__FILE__,string funcName=__FUNCTION__,int line=__LINE__);
void warn(char * message,const char *filename=__FILE__,const char *funcname=__FUNCTION__,const int line=__LINE__)
{
    char buff[200]={0};
    sprintf(buff,"%s %s %5d %s",filename,funcname,line,message);
    printf("%s\n",buff);
}
int main()  
{  
  /*char file[16];  
  char func[16];  
  int line;   
  sprintf(file,__FILE__); //文件名  
  sprintf(func,__FUNCTION__);//函数名  
  printf("file=%s\n",file);  
  printf("func=%s\n",func);  
  printf("%05d\n",__LINE__);//行号    */
  //warn("this is a message",__FILE__,__FUNCTION__,__LINE__);
  warn("this is a message");
  return 0;  
}
/* void warn(const char *msg,string filename=__FILE__,string funcName=__FUNCTION__,int line=__LINE__)
{
    cout<<msg<<' '<<filename<<' '<<funcName<<' '<<line<<endl;
}*/