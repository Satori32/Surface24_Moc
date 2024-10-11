#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

struct File {
	FILE* F = NULL;
};


bool Open(File& F, const char* Name, const char* Mode);
bool Close(File& F);
template<class T> size_t Read(File& F, T* D, size_t L);
template<class T> size_t Write(File& F, T* D, size_t L);
int Seek(File& F, intmax_t Offset, int Origin);
template<class T> T* GetString(File& F, T* D, size_t L);
template<class T> intmax_t Print(File& F, const T* const Fo, ...);
template<class T> intmax_t Scan(File& F, const T* const Fo, ...)