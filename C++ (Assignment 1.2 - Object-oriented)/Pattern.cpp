#include "Pattern.h"

pattern::pattern(baseImage* image) : image(image) {}
pattern::~pattern() { this->image = nullptr; }

