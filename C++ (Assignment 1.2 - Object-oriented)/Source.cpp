#include <iostream>

#include "ImageManipulator.h"

using namespace std;

int main() {
	baseImage* myImage = new PPMImage({ 300, 200 }, new simpleTheme());
	myImage->draw("Sample.ppm");
	delete myImage;

	return 0;
}