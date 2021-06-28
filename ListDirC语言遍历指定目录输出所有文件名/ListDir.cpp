// ListDir.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <io.h>
#include <string.h>
#include <cstdlib>

#define MAXLEN 1024			//�������Ŀ¼����
unsigned long filenum = 0;	//��¼�ļ�����
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
		{   //������ļ�����ֱ������ļ���
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
			//�����Ŀ¼,����_findnext������������
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
					ListDir(pdir);//��Ҫ�ݹ����
				}
			}
		}
	}
}

int main(void)   
{   
	filenum = 0;
	ListDir("G:\\C�Լ������̳�\\���\\c++\\��C++�����ŵ���ͨ (��2��)��.+Դ�����\\TM����Ƶ���⼰ʵ��Դ����\\lx����Ƶ���⣩");
	printf("����%d���ļ�\n",filenum);
	system("pause");
	return 0; 
}