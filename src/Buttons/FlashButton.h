#ifndef _FLASHBUTTON
#define _FLASHBUTTON

#include "SimpleButton.h"
#include "ofxButtons.h"


class FlashButton : public SimpleButton{
public:
	
	FlashButton(string name, int x, int y, bool& theValue);
	void update();
	void draw();
	bool checkClick(int x, int y);
	bool checkOver(int x, int y);
	void printValue();
	void saveToXML(ofxXmlSettings &XML);
	//
	bool * on;
	float steps;
};


#endif