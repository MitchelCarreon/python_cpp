#include <fstream>
#include <string>
#include <iostream>

#include <thread>
#include <chrono>

#include "PPMImage.h"

PPMImage::PPMImage(dimensions Dimensions, patternFactory* themes, std::string binaryFormat, int maxColorVal) 
	: baseImage(Dimensions, themes, binaryFormat), maxColorVal(maxColorVal){}

void PPMImage::writeTo(std::string fileName) {
	std::fstream file;	
	file.open(fileName, std::ios::out);

	if (file.is_open()) {
		std::cout << "Writing to file...\n";

		file << this->binaryFormat << "\n"
			<< this->Dimensions.width << " " << this->Dimensions.height << "\n"
			<< this->maxColorVal << "\n";

		for (auto itr{ this->pixels.begin() }; itr != this->pixels.end(); ++itr) {
			itr != (this->pixels.end() - 1) ? file << *(*(itr)) << "\n" : file << *(*itr);
		}
	}
	system("cls");
	std::cout << "PPM Created\n";
}

void PPMImage::read(std::string fileName)  {
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (file.is_open()) {

		std::string text;
		while (std::getline(file, text)) {
			std::cout << text << "\n";
		}
	}
	file.close();
}

void PPMImage::draw(std::string fileName) {
	themes->init(this, &patterns);
	choosePattern().create();
	this->writeTo(fileName);
}

pattern& PPMImage::choosePattern() {
	
	int choice{ 0 };
	try {
		std::cout << "Choose # from the list of built-in patterns:\n";
		for (auto& pattern : patterns) std::cout << *pattern << std::endl;
		std::cout << "\nInput: ";
		std::cin >> choice;
		system("cls");
		if (choice <= -1) throw(choice);
	} 
	catch (int invalidChoice) {
		std::cout << "CHOICES START AT 0. By default, pattern 0 is chosen for you.\n";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");
		return *patterns[0];	
	}

	return *patterns[choice];
}