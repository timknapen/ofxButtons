#ifndef _SLIDEBUTTON
#define _SLIDEBUTTON

#include "SimpleButton.h"
#include "ofxButtons.h"

class SlideButton: public SimpleButton {
public:
	SlideButton(string name, int x, int y, float& theValue);
	SlideButton(string name, int x, int y, float fbottom, float ftop, float& theValue);
	
	void draw();
	void drag(int x, int y);
	bool checkClick(int x, int y);
	bool checkOver(int x, int y);
	void printValue();
	void saveToXML(ofxXmlSettings &XML);

	float bottom; // min value of slider
	float top; // top value of slider
};

#endif