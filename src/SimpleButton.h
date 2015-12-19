#ifndef _SIMPLE_BUTTON
#define _SIMPLE_BUTTON

#if OF_VERSION_MAJOR <= 0 && OF_VERSION_MINOR <= 8
#define		ofDrawRectangle(a,b,c,d)	ofRectangle(a,b,c,d)
#define		ofDrawEllipse(a,b,c,d)		ofEllipse(a,b,c,d)
#define		ofDrawLine(a,b,c,d)			ofLine(a,b,c,d)
#endif

#include "ofMain.h"
#include "ofxXmlSettings.h"
#define CHAR_W		8	

class SimpleButton {
public:
	
	SimpleButton(string name, int xpos, int ypos);
	~SimpleButton();
	// virtuals
	virtual void update();
	virtual void draw();
	virtual bool checkClick(int x, int y);
	virtual bool checkOver(int x, int y);
	virtual void unSelect();
	virtual void drag(int x, int y);
	virtual void printValue();
	virtual void saveToXML(ofxXmlSettings &XML);
	virtual void setFromXML(ofxXmlSettings &XML);
	//
	void setPos(int x, int y);
	void setTitle(string s);
	void showHide();
	void show();
	void hide();
	
	//
	bool hasName(string s);
	
	string title;
	int xpos;
	int ypos;
	int w;
	int h;
	int buttonheight;
	int relx; //where I received the click (for draging)
	int rely;
	bool selected; // has been clicked
	bool over; // has been rolled over
	bool visible;
	//
	float * value;
	//
	int counter; // for animation etc..
};

#endif


