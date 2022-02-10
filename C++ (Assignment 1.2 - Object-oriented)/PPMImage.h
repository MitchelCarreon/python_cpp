#ifndef PPMIMAGE_H
#define PPMIMAGE_H

#include <string>
#include "BaseImage.h"

class PPMImage : public baseImage {
public:
	PPMImage() = delete;
	PPMImage(dimensions Dimensions, patternFactory* themes, std::string binaryFormat = "P3", int maxColorVal = 255);

	
	void read(std::string fileName) override;
	void draw(std::string fileName) override;
	
protected:
	pattern& choosePattern() override;
	void writeTo(std::string fileName) override;
	int maxColorVal;

};


#endif 
