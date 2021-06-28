// ListDir.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <io.h>
#include <string.h>
#include <cstdlib>

#define MAXLEN 1024			//定义最大目录长度
unsigned long filenum = 0;	//记录文件数量
void ListDir(const char* pchData)
{
	_finddata_t   fdata;   
	long   done;    
	char tempdir[MAXLEN]={0};
	strcat(tempdir,pchData);
	strcat(tempdir , "\\*.*");
	
	done   =   _findfirst(tempdir, &fdata);   
	if (done != -1)
	{
		int ret = 0;
		while  (ret != -1)     
		{   //如果是文件，就直接输出文件名
			if (fdata.attrib != _A_SUBDIR)
			{
				if (strcmp(fdata.name,"...") != 0 &&
					strcmp(fdata.name,"..") != 0 &&
					strcmp(fdata.name,".") != 0)
				{
					char dir[MAXLEN]={0};
					strcat(dir,pchData);
					strcat(dir,"\\");
					strcat(dir,fdata.name);
					printf("%s\n",dir);
					filenum++;
				}
			}
			//如果是目录,调用_findnext函数继续遍历
			ret = _findnext(done,&fdata);  
			if (fdata.attrib == _A_SUBDIR && ret != -1)
			{
				if (strcmp(fdata.name,"...") != 0 &&
					strcmp(fdata.name,"..") != 0 &&
					strcmp(fdata.name,".") != 0)
				{
					char pdir[MAXLEN]= {0};
					strcat(pdir,pchData);
					strcat(pdir , "\\");
					strcat(pdir,fdata.name);
					ListDir(pdir);//需要递归遍历
				}
			}
		}
	}
}

int main(void)   
{   
	filenum = 0;
	ListDir("G:\\C以及其他教程\\后端\\c++\\《C++从入门到精通 (第2版)》.+源码光盘\\TM（视频讲解及实例源程序）\\lx（视频讲解）");
	printf("共计%d个文件\n",filenum);
	system("pause");
	return 0; 
}