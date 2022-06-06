/*
 *  ToggleItem.h
 *  buttons
 *
 *  Created by Tim Knapen on 30/01/10.
 *  Copyright 2010 Tim Knapen. All rights reserved.
 *
 */

#ifndef _ONOFFITEM
#define _ONOFFITEM

#include "ListItem.h"
#include "ofxButtons.h"

class ToggleItem : public ListItem{
private:
	
public:
	ToggleItem( string theTitle, bool& value);
	void draw();
	bool checkClick(int x, int y);
	void printValue();
	void saveToXML( ofxXmlSettings& XML);
	void setValue(float val);
	//
	bool * on;
};

#endif
