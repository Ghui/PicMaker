#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

int main(){
  int i, j, fd;
  fd = open("picture.ppm", O_CREAT | O_WRONLY | O_TRUNC,0644);
  write(fd, "P3 500 500 256\n", 15);
  srand(time(NULL));
  char *s = (char *)malloc(256);
  for(i = 0; i<500;i++){
    for(j=0;j<500;j++){
      if(i % 5 == 1){
	sprintf(s,"%d", 256);
	write(fd,s,strlen(s));
	write(fd," ",1);
	sprintf(s,"%d",64);
	write(fd,s,strlen(s));
	write(fd, " ",1);
	sprintf(s,"%d",64);
	write(fd,s,strlen(s));
	write(fd,"\n ",1);
      }
      else if(j%5 == 1){
	sprintf(s,"%d", 70);
	write(fd,s,strlen(s));
	write(fd," ",1);
	sprintf(s,"%d",80);
	write(fd,s,strlen(s));
	write(fd, " ",1);
	sprintf(s,"%d",250);
	write(fd,s,strlen(s));
	write(fd,"\n ",1);
      }
      else if(j % 5 == 0){
	sprintf(s,"%d", 40);
	write(fd,s,strlen(s));
	write(fd," ",1);
	sprintf(s,"%d",50);
	write(fd,s,strlen(s));
	write(fd, " ",1);
	sprintf(s,"%d",60);
	write(fd,s,strlen(s));
	write(fd,"\n ",1);
      }
      else if ( i % 5 == 0){
	sprintf(s,"%d", 60);
	write(fd,s,strlen(s));
	write(fd," ",1);
	sprintf(s,"%d",40);
	write(fd,s,strlen(s));
	write(fd, " ",1);
	sprintf(s,"%d",22);
	write(fd,s,strlen(s));
	write(fd,"\n ",1);
      }
      else{
	sprintf(s,"%d", i);
	write(fd,s,strlen(s));
	write(fd," ",1);
	sprintf(s,"%d",j);
	write(fd,s,strlen(s));
	write(fd, " ",1);
	sprintf(s,"%d",i);
	write(fd,s,strlen(s));
	write(fd,"\n ",1);
      }
    }
  }
  free( s);
  close(fd);
}
