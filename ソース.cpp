#include <stdint.h>

#include "MemoryAllocator.h"
#include "FileDescripter.h"

struct RGB{//this need patting. tri is bad fortune for pc
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

Surface24 ConstructSurface24(size_t Width, size_t Height) {
	Surface24 S;
	S.C = ConstructMemroy<RGB>(Width * Height);
	if (IsNULL(S.C) == false) {
		S.Width = Width;
		S.Height = Height;
	}

	return S;
}

bool Free(Surface24& In) {
	Free(In.C);
	In.Height = 0;
	In.Width = 0;
}

bool IsNULL(Surface24& In) {
	return IsNULL(In.C);
}
size_t Width(Surface24& In) {
	return In.Width;
}

size_t Height(Surface24& In) {
	return In.Height;
}

RGB* Index(Surface24& In, size_t Width, size_t Height) {
	return Index(In.C, Width * Height);
}

bool SetPixel(Surface24& In, size_t Width, size_t Height, RGB C) {
	
	if (In.Width >= Width) return false;
	if (In.Height >= Height) return false;	
	
	(*Index(In.C, Width * Height)) = C;
	return true;
}

bool SavePBM(Surface24& In, char* Name) {
	File F;
	bool B = Open(F, Name, "w");
	if (B == false) { return false; }

	Print(F, "P6");
	Print(F, "# no comment");
	Print(F, "%d %d",Width(In), Height(In));
	
	for (size_t i = 0; i < Height(In); i++) {
		for (size_t j = 0; j < Width(In); j++) {
			RGB* C = Index(In, j, i);
			Print(F, "%d %d %d ",C->R,C->G,C->B);
		}
	}
	Close(F);

	return true;
}

RGB MakeColor(uint8_t R, uint8_t G uint8_t B) {
	RGB C = { B,G,R };

	return C;
}

int main() {
	Surface24 S;

	S = ConstructSurface24(15, 17);
	SetPixel(S, 8, 8, MakeColor(255, 0, 0));
	SavePBM(S, "tekitou.PBM");
	Free(S);
}