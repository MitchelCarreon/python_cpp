#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

void setImageDimensions(pair<int,int> dimensions, pair<pair<int, int>, vector<tuple<int, int, int>>>& image) {
	image.first.first = dimensions.first;
	image.first.second = dimensions.second;
}

void choosePattern(pair<pair<int, int>, vector<tuple<int, int, int>>>& image, vector<void (*) (pair<pair<int, int>, vector<tuple<int, int, int>>>& image) >& patterns) {

	int choice{ 0 };
	cout << "Choose # from the list of built-in patterns:\n"
	     << "Stripes\nWaves\n"
	     << "\nInput: ";
	cin >> choice;
	switch (choice) {
	case 0:
		patterns[0](image);
		break;
	case 1:
		patterns[1](image);
		break;
	default:
		cout << "CHOICES START AT 0. By default, pattern 0 is chosen for you.\n";
		patterns[0](image);
		break;
	}

}
void createStripes(pair<pair<int, int>, vector<tuple<int, int, int>>>& image) {
	
	string patternName{ __func__ };
	patternName = patternName.substr(6);
	std::cout << "Creating " << patternName << "...\n";
	int size{ image.first.first * image.first.second };
	int linePixels = ( size / 10);
	std::tuple<int, int, int> rgb{ 0, 0, 0 };

	for (int i{ 0 }; i < size;) {
		 if (i < linePixels) {								
			 image.second.push_back(make_tuple(get<0>(rgb), get<1>(rgb), get<2>(rgb)));
			 ++i;
		}
		else {
			linePixels += size / 10;
			get<1>(rgb) == 0 ? get<1>(rgb) = 255 : get<1>(rgb) = 0;				
			get<2>(rgb) = get<0>(rgb);											
		}
	}
	
}
void createWaves(pair<pair<int, int>, vector<tuple<int, int, int>>>& image) {
	int red{ 0 }, green{ 255 }, blue{ 0 };
	int size{ image.first.first * image.first.second };
	for (int i{ 0 }; i < size; ++i) {

		if (red > 255) red = 50;
		else red++;

		if (green <= 0) green = 25;
		else green--;

		if (blue > 255) blue = 100;
		else blue++;
		image.second.push_back(make_tuple(red, green, 0));
	}
}

void initializePatterns(vector<void (*) (pair<pair<int, int>, vector<tuple<int, int, int>>>&) >& patterns) {
	patterns.push_back(createStripes);
	patterns.push_back(createWaves);
}

void writeTo(string fileName, const pair<pair<int, int>, vector<tuple<int, int, int>>>& image) {
	std::fstream file;
	file.open(fileName, std::ios::out);

	string binaryFormat{ "P3" };
	int maxColorVal{ 255 };

	if (file.is_open()) {
		std::cout << "Writing to file...\n";

		file << binaryFormat << "\n"
			<< image.first.first << " " << image.first.second << "\n"
			<< maxColorVal << "\n";

		for (auto pixel : image.second) {
			file << get<0>(pixel) << " " << get<1>(pixel) << " " << get<2>(pixel) << "\n";
		}
	}
	system("cls");
	std::cout << "PPM Created\n";
}
void read(string fileName) {
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

int main() {

	pair<pair<int, int>, vector<tuple<int, int, int>>> image; 
	vector<void (*) (pair<pair<int, int>, vector<tuple<int, int, int>>>&) > patterns;

	setImageDimensions(make_pair(300, 200), image);
	initializePatterns(patterns);

	string fileName{ "Sample.ppm" };
	choosePattern(image, patterns);
	writeTo(fileName, image);

	read(fileName);										

	return 0;
}




// uncomment to see textual content in console. WARNING: Might take some time.