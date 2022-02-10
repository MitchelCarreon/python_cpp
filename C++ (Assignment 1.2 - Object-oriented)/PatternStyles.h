#ifndef DRAWSTYLES_H
#define DRAWSTYLES_H

#include "Pattern.h"

class baseImage;

class Stripes : public pattern {
public:
	Stripes(baseImage* image);
	void create() override;
};

class Waves : public pattern {
public:
	Waves(baseImage* image);
	void create() override;
};

class Psychedelic : public pattern {
public:
	Psychedelic(baseImage* image);
	void create() override;
};
// Client may extend further by subclassing.


#endif