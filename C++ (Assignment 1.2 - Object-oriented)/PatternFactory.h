#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H


#include <vector>

class pattern;
class baseImage;

class patternFactory {
public:
	virtual void init(baseImage* image, std::vector<pattern*>* initPatterns) = 0;
protected:
	void insertPatterns(std::vector<pattern*>& patternsFrom, std::vector<pattern*>* patternsTo);
};

typedef class simplePatternsFactory : public patternFactory {
public:
	void init(baseImage* image, std::vector<pattern*>* initPatterns) override;
} simpleTheme;

typedef class complexPatternsFactory : public patternFactory {
public:
	void init(baseImage* image, std::vector<pattern*>* initPatterns) override;
} complexTheme;

// Client may extend further by subclassing.

#endif