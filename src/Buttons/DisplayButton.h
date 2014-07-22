#ifndef _DISPLAYBUTTON
#define _DISPLAYBUTTON

#include "SimpleButton.h"


class DisplayButton: public SimpleButton {
public:
	DisplayButton(string name, int x, int y, float& theValue);
	void draw();
	//void drag(int x, int y);
	bool checkClick(int x, int y);
	bool checkOver(int x, int y);
	void printValue();
	void saveToXML(ofxXmlSettings &XML);
	
};

#endif