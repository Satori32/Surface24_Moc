#pragma once

#include <stdint.h>

#include "MemoryAllocator.h"
#include "FileDescripter.h"

struct RGB { //this need patting. tri is bad fortune for pc
	uint8_t B = 0;
	uint8_t G = 0;
	uint8_t R = 0;
};

struct Surface24
{
	Memory<RGB> C;
	size_t Width = 0;
	size_t Height = 0;
};

Surface24 ConstructSurface24(size_t Width, size_t Height);
bool Free(Surface24& In);
bool IsNULL(Surface24& In);
size_t Width(Surface24& In);
RGB* Index(Surface24& In, size_t X, size_t Y);
bool SetPixel(Surface24& In, size_t Width, size_t Height, RGB C);
bool SavePBM(Surface24& In, char* Name);
RGB MakeColor(uint8_t R, uint8_t G uint8_t B);





