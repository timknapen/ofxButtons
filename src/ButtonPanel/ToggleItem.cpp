/*
 *  ToggleItem.cpp
 *  buttons
 *
 *  Created by timknapen on 30/01/10.
 *  Copyright 2010 Indianen. All rights reserved.
 *
 */

#include "ToggleItem.h"

//--------------------------------------------------------------
ToggleItem::ToggleItem(string theTitle, bool& theValue):ListItem(theTitle){
	// do nothing?
	w = 34 + 4+ title.length()*CHAR_W; //textw
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
	if(x > 0 && x < w && rely > 0 && rely < h){
		selected = true;
		*on = !*on;
	}
	return selected;
}

//--------------------------------------------------------------
void ToggleItem::draw(){
	ofPushMatrix();
	ofTranslate(32, 0, 0);
	ListItem::draw();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(0, ypos,0);
	ofFill();
	if (*on) {
		if(over){
			ofSetHexColor(marked);
		}else{
			ofSetHexColor(0x999999);
			
		}
		ofRect(0, 2, 30, h-4);
		ofSetHexColor(0xffffff);
		ofDrawBitmapString("ON", 4, h-4);
	}else {
		ofSetHexColor(0xcccccc);
		ofRect(0, 2, 30, h-4);
		ofSetHexColor(0x999999);
		ofDrawBitmapString("OFF", 4, h-4);
	}
	ofPopMatrix();
	
	//
}

