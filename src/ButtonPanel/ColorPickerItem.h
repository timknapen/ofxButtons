/*
 *  ColorPicker.h
 *  buttons
 *
 *  Created by Tim Knapen on 30/01/10.
 *  Copyright 2010 Tim Knapen. All rights reserved.
 *
 */

#ifndef _COLORPICKERITEM
#define _COLORPICKERITEM

#include "ListItem.h"
#include "ofxButtons.h"

class ColorPickerItem : public ListItem{
private:
	
public:
	ColorPickerItem( string theTitle, ofPoint& color, float saturation = 1);
	void draw();
	void drag(int x, int y);
	bool checkClick(int x, int y);
	void printValue();
	void saveToXML( ofxXmlSettings& XML);
	void setValue(float _val);
	void setValue(ofPoint _color);
	
  ofPoint * color;
private:
	ofImage img;
};

#endif
