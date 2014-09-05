/*
 * file_ex_f.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: lucid
 */

#include "CommLib_F.h"
#include <stdio.h>
#include <unistd.h>
#include "File_F.h"

CFile_F::CFile_F()
{
	m_pFile = 0;
}
CFile_F::~CFile_F()
{
	Close();
}

int CFile_F::IsFileExist(const char* chName)
{
	return (0 == access(chName,F_OK)) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

int CFile_F::IsOpened()
{
	return (0 != m_pFile) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

int CFile_F::Create(const char* chName,U32 dwFlag)		//return error if exist
{
	if ( IsFileExist(chName) )
		return RETURN_ERROR_F;

	if(!(FILE_ACCESS_FLAG_WRITE & dwFlag))	//create but has not write flag,return
		return RETURN_ERROR_F;

	char chFlag[4];
	chFlag[0] = 'w';	//create must be have write flag
	chFlag[1] = 'b';	//must use binary format
	if (FILE_ACCESS_FLAG_READ & dwFlag)
	{
		chFlag[2] = '+';
		chFlag[3] = 0;		//chFlag = "wb+"
	}
	else
	{
		chFlag[2] = 0;		//chFlag = "wb"
	}


	Close();
	m_pFile = fopen(chName,chFlag);
	return (0!=m_pFile) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

int CFile_F::CreateNewAlways(const char* chName,U32 dwFlag)	//create or open truncate to 0
{
	Close();
	if (FILE_ACCESS_FLAG_READ & dwFlag)
	{
		m_pFile = fopen(chName,"wb+");
	}
	else
	{
		m_pFile = fopen(chName,"wb");
	}
	return (0!=m_pFile) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

int CFile_F::OpenExist(const char* chName,U32 dwFlag)	//return error if not exist
{
	if ( !IsFileExist(chName) )
	{
		return RETURN_ERROR_F;
	}

	Close();
	if (FILE_ACCESS_FLAG_WRITE & dwFlag)
	{
		m_pFile = fopen(chName,"r+");	//write also read
	}
	else
	{
		m_pFile = fopen(chName,"r");	//read only
	}
	return (0!=m_pFile) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

int CFile_F::CreateOrOpenExist(const char* chName,U32 dwFlag)	//create no truncate
{
	if ( !IsFileExist(chName) )
		return CreateNewAlways(chName,dwFlag);
	else
		return OpenExist(chName,dwFlag);
}

int CFile_F::OpenDirectly(const char* chName,const char* chModes)
{
	Close();
	m_pFile = fopen(chName,chModes);
	return (0!=m_pFile) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

ssize_t CFile_F:: Write(U32 dwPos,const void* pData,U32 dwLen)
{
	fseek(m_pFile,dwPos,SEEK_SET);
	return fwrite(pData,1,dwLen,m_pFile);
}

ssize_t CFile_F::Read(U32 dwPos,void* pData,U32 dwLen)
{
	fseek(m_pFile,dwPos,SEEK_SET);
	return fread(pData,1,dwLen,m_pFile);
}

int CFile_F::Flush()
{
	return fflush(m_pFile);
}

int CFile_F::Close()
{
	int iRet = 0;
	if ( m_pFile )
	{
		iRet = fclose(m_pFile);
		m_pFile = 0;
	}
	return iRet;
}

U32 CFile_F::GetLength()
{
    U32 dwCurPos,dwLen;
    dwCurPos = ftell(m_pFile);
    fseek(m_pFile,0,SEEK_END);
    dwLen = ftell(m_pFile);
    fseek(m_pFile,dwCurPos,SEEK_SET);
    return dwLen;
}

U32 CFile_F::GetCurrentPos()
{
	return ftell(m_pFile);
}

int CFile_F::SetLength(U32 uLen)
{
	int fd = fileno(m_pFile);
	return ftruncate(fd,uLen);
}













