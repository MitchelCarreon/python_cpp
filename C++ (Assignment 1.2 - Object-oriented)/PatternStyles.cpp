#include "PatternStyles.h"
#include "BaseImage.h"

#include <iostream>
#include <tuple>

#include <cstdlib>


Stripes::Stripes(baseImage* image) : pattern(image) {}
void Stripes::create() {
	pattern::create();

	int linePixels = (image->size() /10) ;
	std::tuple<int, int, int> rgb{ 0, 0, 0 };
	for (int i{ 0 }; i < image->size();) {
		if (i < linePixels) (*image)[i++] = new baseImage::pixel(rgb);
		else {
			linePixels += (image->size() / 10);
			std::get<1>(rgb) == 0 ? std::get<1>(rgb) = 255 : std::get<1>(rgb) = 0;
			std::get<2>(rgb) = std::get<0>(rgb);
		}
	}
}

Waves::Waves(baseImage* image) : pattern(image){}
void Waves::create() {
	pattern::create();

	int red{ 0 }, green{ 255 }, blue{ 0 };
	for (int i{ 0 }; i < image->size(); ++i) {

		if (red > 255) red = 50;
		else red++;

		if (green <= 0) green = 25;
		else green--;

		if (blue > 255) blue = 100;
		else blue++;
		(*image)[i] = new baseImage::pixel((int)red, (int)green, 0);
	}
}

Psychedelic::Psychedelic(baseImage* image) : pattern(image){}
void Psychedelic::create() {
	pattern::create();

	for (int i{ 0 }; i < image->size(); ++i) {
		(*image)[i] = new baseImage::pixel(rand() % 256, rand() % 256 + 50, rand() % 256 + 100);
	}
}



