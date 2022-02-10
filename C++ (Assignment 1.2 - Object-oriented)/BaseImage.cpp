#include <iostream>
#include <vector>

#include "BaseImage.h"
#include "PatternFactory.h"
#include "Pattern.h"

baseImage::baseImage(dimensions Dimensions, patternFactory* themes, std::string binaryFormat) 
	: pixels(Dimensions.height * Dimensions.width), Dimensions(Dimensions), themes(themes), binaryFormat(binaryFormat) {}

baseImage::~baseImage() {
	for (auto& pixel : pixels) { 
		delete pixel; 
		pixel = nullptr;
	}
	for (auto& pattern : patterns) { 
		delete pattern; 
		pattern = nullptr;
	}

	delete themes;
	themes = nullptr;
}

baseImage::pixel*& baseImage::operator[](int index) {
	return pixels[index];
}

const int baseImage::size() const { return pixels.size(); }

const baseImage::dimensions& baseImage::getDimensions() const  { return this->Dimensions; }
