#ifndef PATTERN_H
#define PATTERN_H

#include <iostream>
#include <string>

class baseImage;

class pattern { 
public:
	pattern() = delete;
	pattern(baseImage* image);
	~pattern();
	friend std::ostream& operator<<(std::ostream& obj, const pattern& pattern) {
		std::string name{ typeid(pattern).name() }, type{ "class " };
		obj << name.replace(name.find("class"),type.length(), "");
		return obj;
	}
	
	virtual void create() {
		std::cout << "Creating " << *this << "...\n";
	};
	

protected:
	baseImage* image = nullptr;
	
};

#endif