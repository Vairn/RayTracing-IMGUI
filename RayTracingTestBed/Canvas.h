#pragma once
#include "Vector.h"
#include <string>
class Canvas
{
public:
		Canvas();
		Canvas(int width, int height);
	~Canvas();

	int Width() const;
	int Height() const;

	unsigned char* Pixels() const;

	void WritePixel(int x, int y, TUPLE c);
	void Clear(TUPLE c);
	TUPLE PixelAt(int x, int y) const;


	std::string ToPPM(std::string sOutFile="");
private:

	int width;
	int height;
	//unsigned char* pixels;
	TUPLE* pixels;
};