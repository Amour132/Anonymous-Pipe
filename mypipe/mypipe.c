#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int pipefd[2];
  if(pipe(pipefd) == -1)
  {
    printf("pipe error\n");
    exit(1);
  }
  pid_t id;
  id = fork();
  if(id<0)
  {
    printf("fork error\n");
    exit(1);
  }
  else if(id == 0)//child
  {
    char buff[10] = {0};
    scanf("%s",buff);
    close(pipefd[0]);
    {
      write(pipefd[1],buff,strlen(buff));
    }
      close(pipefd[1]);
      exit(0);
  }
  else//parent
  {
    close(pipefd[1]);
    char buff[10] = {0};
    read(pipefd[0],buff,10);
    printf("buff: %s\n",buff); 
  }
  return 0;
}
