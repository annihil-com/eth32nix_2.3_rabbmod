// ETH32 - an Enemy Territory cheat for linux
// Copyright (c) 2007 eth32 team
// www.nixcoders.org

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdarg.h>

class CDebug
{
public:
	CDebug();
	~CDebug();
	void Init();
	void SetLogFile(char *logFile);
	void Log(const char *logmsg, ...);
	void LogData(void *buf, size_t s_buf);
private:
	FILE *dbgFile;
	bool pathset;
	char path[256];
	bool dbgFileFirstOpen;

	pthread_mutex_t *mutex;
};
