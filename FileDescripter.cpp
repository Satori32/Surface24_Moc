#include "FileDescripter.h"

bool Open(File& F, const char* Name, const char* Mode) {
	F.F = fopen(Name, Mode);
	return F.F != NULL ? true : false;
}
bool Close(File& F) {
	fclose(F.F);
	F.F = NULL;

	return true;
}
template<class T>
size_t Read(File& F, T* D, size_t L) {
	return fread((void*)D, sizeof(T), L, F.F);
}

template<class T>
size_t Write(File& F, T* D, size_t L) {
	return fwrite((void*)D, sizeof(T), L, F.F);
}

int Seek(File& F, intmax_t Offset, int Origin) {
	return fseek(F.F, Offset, Origin);
}

template<class T>
T* GetString(File& F, T* D, size_t L) {
	return fgets(D, L, F.F);
}

template<class T>
intmax_t Print(File& F, const T* const Fo, ...) {
	va_list VA = NULL;

	va_start(VA, Fo);
	intmax_t L = fprintf(F.F, Fo, VA);
	va_end(VA);

	return L;
}

template<class T>
intmax_t Scan(File& F, const T* const Fo, ...) {

	va_list VA = NULL;

	va_start(VA, Fo);
	intmax_t L = fscanf(F.F, Fo, VA);
	va_end(VA);

	return L;
}