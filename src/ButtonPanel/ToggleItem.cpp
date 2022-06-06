/*
 *  ToggleItem.cpp
 *  buttons
 *
 *  Created by Tim Knapen on 30/01/10.
 *  Copyright 2010 Tim Knapen. All rights reserved.
 *
 */

#include "ToggleItem.h"

//--------------------------------------------------------------
ToggleItem::ToggleItem(string theTitle, bool& theValue):ListItem(theTitle){
	// do nothing?
	width = 30 + 4 + title.length()*CHAR_W; //textw
	width = (width < 300) ? 300 : width;
	on = &theValue;
} 

//-------------------------------------------------
void ToggleItem::saveToXML( ofxXmlSettings& XML){
	// nothing yet
	XML.addTag("ToggleItem");
	int num = XML.getNumTags("ToggleItem") - 1;
	XML.setAttribute("ToggleItem", "name", title, num);
	XML.setAttribute("ToggleItem", "value", (*on)?"1":"0", num);
	
}

//----------------------------------------------------------------
void ToggleItem::setValue(float val){
	*on= (bool)val;
}

//--------------------------------------------------------------
void ToggleItem::printValue(){
	cout << "  " << title << " = " <<*on<< endl;
}

//--------------------------------------------------------------
bool ToggleItem::checkClick(int x, int y){
	rely = y - ypos;
	selected = false;
	if(x > 0 && x < width && rely > 0 && rely < height){
		selected = true;
		*on = !*on;
	}
	return selected;
}

//--------------------------------------------------------------
void ToggleItem::draw(){
	ofPushMatrix();
	ofTranslate(0, ypos,0);
	
	int toggleh = height-4;
	ofPushMatrix();
	ofTranslate(5,2);
	// frame last
	ofFill();
	ofSetHexColor(BUTTONS_COLOR_LIGHT);
	ofDrawRectangle(0, 0, 2*toggleh, toggleh);
	
	ofFill();
	if(*on){ // ON!
		if(over){
			ofSetHexColor(BUTTONS_COLOR_GREEN_HIGHLIGHT);
		}else{
			ofSetHexColor(BUTTONS_COLOR_GREEN);
		}
		ofDrawRectangle(0, 0, toggleh, toggleh);
	}else { // OFF
		if(over){
			ofSetHexColor(BUTTONS_COLOR_ACTIVE_RED);
		}else{
			ofSetHexColor(BUTTONS_COLOR_MEDIUM);
		}
		ofDrawRectangle(toggleh, 0, toggleh, toggleh);
	}
	ofPopMatrix();

    if(over){
        ofSetHexColor(BUTTONS_COLOR_TEXT_DARK);
    }else{
        ofSetHexColor(BUTTONS_COLOR_TEXT_LIGHT);
    }
    ofDrawBitmapString(title , 50, height-4);
	ofPopMatrix();
	
	//
}

