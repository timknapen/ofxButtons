#ifndef _ONOFFBUTTON
#define _ONOFFBUTTON

#include "SimpleButton.h"
#include "ofxButtons.h"


class OnOffButton : public SimpleButton{
public:
	
	OnOffButton(string name, int x, int y, bool& theValue);
	void draw();
	bool checkClick(int x, int y);
	bool checkOver(int x, int y);
	void printValue();

	//
	bool * on;
	
};


#endif