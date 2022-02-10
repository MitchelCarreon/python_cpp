#ifndef BASEIMAGE_H
#define BASEIMAGE_H

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

#include "PatternFactory.h"
#include "Pattern.h"

class baseImage {
public:
	struct pixel {
		pixel() = delete;
		pixel(int red, int green, int blue) 
			: red(red), green(green), blue(blue){}
		pixel(std::tuple<int, int, int> rgb) {
			std::tie(this->red, this->green, this->blue) = rgb;
		}

		int red;
		int green;
		int blue;

		friend std::ostream& operator<<(std::ostream& out, const pixel& pixel) {
			out << pixel.red << " " << pixel.green << " " << pixel.blue;
			return out;
		}
	};
	struct dimensions {
		int width;
		int height;
	};
	
	baseImage() = delete;
	baseImage(dimensions Dimesions, patternFactory* themes, std::string binaryFormat);
	~baseImage();
	
	virtual void read(std::string fileName) = 0;
	virtual void draw(std::string fileName) = 0;
	

	pixel*& operator[](int index);
	const dimensions& getDimensions() const;
	const int size() const;

	
	
protected:
	virtual pattern& choosePattern() = 0;
	virtual void writeTo(std::string fileName) = 0; 
	
	std::vector<pixel*> pixels;
	std::vector<pattern*> patterns;

	dimensions Dimensions;
	patternFactory* themes{nullptr};
	std::string binaryFormat;
	
};

#endif