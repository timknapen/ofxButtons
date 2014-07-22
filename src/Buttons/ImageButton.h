#ifndef _IMAGEBUTTON
#define _IMAGEBUTTON

#include "SimpleButton.h"
#include "ofxButtons.h"


class ImageButton : public SimpleButton{
public:
	
	ImageButton( int x, int y, string theFilename, bool& theValue);
	void draw();
	bool checkClick(int x, int y);
	bool checkOver(int x, int y);
	void saveToXML(ofxXmlSettings &XML);
	//
	bool * on;
	string filename;
	ofImage img;
	float steps;
	
};


#endif