#include "Canvas.h"
#include <iostream>
#include <sstream>
#include <fstream>

Canvas::Canvas()
{

}

Canvas::Canvas(int _width, int _height)
{
	width = _width;
	height = _height;
	pixels = new TUPLE[width * height];
}

Canvas::~Canvas()
{
	width = 320;
	height = 240;
	pixels = new TUPLE[width * height];
}

int Canvas::Width() const
{
	return	width;
}

int Canvas::Height() const
{
	return height;
}

void Canvas::WritePixel(int x, int y, TUPLE c)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return;
	}

	if (c.r < 0.0f) c.r = 0.0f;
	if (c.g < 0.0f) c.g = 0.0f;
	if (c.b < 0.0f) c.b = 0.0f;
	if (c.r > 1.0f) c.r = 1.0f;
	if (c.g > 1.0f) c.g = 1.0f;
	if (c.b > 1.0f) c.b = 1.0f;

	pixels[y * width + x] = c;
}

void Canvas::Clear(TUPLE c)
{
	for (int y=0; y<width;y++)
	{
		for (int x = 0; x < height; x++)
		{
			pixels[y * width + x] =c;
		}
	}
	//memset(pixels, 0, width * height);
}

TUPLE Canvas::PixelAt(int x, int y) const
{
	return pixels[y * width + x];
}

std::string Canvas::ToPPM(std::string sOutFile)
{
	// Write image to a PPM.
	std::string ppm = "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n";
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			TUPLE c = PixelAt(x, y);
			int r = (int)ceil(c.r * 255.0f);
			int g = (int)ceil(c.g * 255.0f);
			int b = (int)ceil(c.b * 255.0f);
			// limit to 70 characters per line
			
			ppm += std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b) + ((x==width-1) ?"\n" : " ");
		}
	}

	if (sOutFile.length() > 0)
	{
		std::ofstream file(sOutFile.c_str());
		if (file.is_open())
		{
			file << ppm;
			file.close();
		}
	}

	return ppm;
}
