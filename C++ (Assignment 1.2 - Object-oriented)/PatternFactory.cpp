#include <algorithm>

#include "PatternFactory.h"
#include "PatternStyles.h"
#include "BaseImage.h"

void patternFactory::insertPatterns(std::vector<pattern*>& patternsFrom, std::vector<pattern*>* patternsTo) {
	std::copy(patternsFrom.begin(), patternsFrom.end(), std::back_inserter(*patternsTo));
}

void simplePatternsFactory::init(baseImage* image, std::vector<pattern*>* initPatterns) {
	
	std::vector<pattern*> patterns{ 
		new Stripes(image),
		new Waves(image),
	}; 

	insertPatterns(patterns, initPatterns);
}


void complexPatternsFactory::init(baseImage* image, std::vector<pattern*>* initPatterns) {

	std::vector<pattern*> patterns{
		new Psychedelic(image),
	};

	insertPatterns(patterns, initPatterns);
}





