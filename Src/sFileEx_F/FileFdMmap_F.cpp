/*
 * file_fd_mmap_ex_f.cpp
 *
 *  Created on: Jul 3, 2012
 *      Author: lucid
 */

#include "CommLib_F.h"
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include "FileFdMmap_F.h"

//will finish it later
//how to allocate the memory dynamic and effective is very important


CFileFdMmap_F::CFileFdMmap_F()
	:CFileFd_F()
{
	m_pData = 0;
}

CFileFdMmap_F::~CFileFdMmap_F()
{
	Close();
}

ssize_t CFileFdMmap_F::Write(U32 dwPos,const void* pData,U32 dwLen)
{
	if (dwPos + dwLen > GetLength())
		return 0;
	memcpy(m_pData+dwPos,pData,dwLen);
	fsync(m_fd);
	return dwLen;
}

ssize_t CFileFdMmap_F::Read(U32 dwPos,void* pData,U32 dwLen)
{
	if (dwPos + dwLen > GetLength())
		return 0;
	memcpy(pData,m_pData+dwPos,dwLen);
	return dwLen;
}

int CFileFdMmap_F::Close()
{
	CloseMap();
	return CFileFd_F::Close();
}

void* CFileFdMmap_F::GetDataAddr()
{
	return m_pData;
}

int CFileFdMmap_F::OpenMap(U32 dwLen)
{
	CloseMap();
	SetLength(dwLen);
	m_pData = (U8*)mmap(0,dwLen,PROT_READ|PROT_WRITE,MAP_SHARED,m_fd,0);
	return (m_pData != 0) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}

int CFileFdMmap_F::CloseMap()
{
	if(!m_pData)
		return RETURN_ERROR_F;
	int iRet = munmap(m_pData,GetLength());
	if (0 == iRet) {
		m_pData = 0;
	}
	return (0 == iRet) ? RETURN_SUCCESS_F : RETURN_ERROR_F;
}







