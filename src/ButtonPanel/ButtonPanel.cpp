/*
 *  ButtonPanel.cpp
 *  buttons
 *
 *  Created by timknapen on 30/01/10.
 *  Copyright 2010 Indianen. All rights reserved.
 *
 */

#include "ButtonPanel.h"


//-------------------------------------------------
void ButtonPanel::saveToXML( ofxXmlSettings& XML){
	// nothing yet
	XML.addTag("ButtonPanel");
	int num = XML.getNumTags("ButtonPanel") - 1;
	XML.setAttribute("ButtonPanel", "name", title, num);
	
	XML.pushTag("ButtonPanel", num);
	for (int i = 0; i < items.size(); i++) {
		items[i]->saveToXML(XML);
	}
	XML.popTag();
}


//-------------------------------------------------
void ButtonPanel::setFromXML(ofxXmlSettings &XML){
	// we should be inside the <ButtonPanel> tag
	int num;
	num = XML.getNumTags("SliderItem");
	// cout << "\t- SliderItems (" << num <<")"<<endl;
	for(int i = 0; i < num; i++){
		string name = XML.getAttribute("SliderItem", "name", "", i);
		float val = XML.getAttribute("SliderItem", "value", 1.0f, i);
		setByName( name,  val);
		// cout <<"\t"<< i<<"\t\tSliderItem\t\tname: '"<< name <<"',\t\t value: "<<val<<endl;
	}
	
	num = XML.getNumTags("ToggleItem");
	// cout << "\t- ToggleItems (" << num <<")"<<endl;
	for(int i = 0; i < num; i++){
		string name = XML.getAttribute("ToggleItem", "name", "", i);
		bool val = (bool)XML.getAttribute("ToggleItem", "value", false, i);
		setByName( name,  val);
		// cout <<"\t"<< i<<"\t\tToggleItem\t\tname: '"<< name <<"',\t\t value: "<<val<<endl;
	}
	
	num = XML.getNumTags("SelectionItem");
	// cout << "\t- SelectionItems (" << num <<")"<<endl;
	for(int i = 0; i < num; i++){
		string name = XML.getAttribute("SelectionItem", "name", "", i);
		int val = XML.getAttribute("SelectionItem", "value", false, i);
		setByName( name,  val);
		// cout <<"\t"<< i<<"\t\tSelectionItem\t\tname: '"<< name <<"',\t\t value: "<<val<<endl;
	}
	
	num = XML.getNumTags("ColorPickerItem");
	// cout << "\t- ColorPickerItems (" << num <<")"<<endl;
	for(int i = 0; i < num; i++){
		string name = XML.getAttribute("ColorPickerItem", "name", "", i);
		float r = XML.getAttribute("ColorPickerItem", "r", 1.0f, i);
		float g = XML.getAttribute("ColorPickerItem", "g", 1.0f, i);
		float b = XML.getAttribute("ColorPickerItem", "b", 1.0f, i);

		setByName( name,  ofPoint(r, g, b));
		// cout <<"\t"<< i<<"\t\tSelectionItem\t\tname: '"<< name <<"',\t\t value: "<<val<<endl;
	}
}


//--------------------------------------------------------------
void ButtonPanel::setByName(string name, float val){
	for (int i =0; i <items.size(); i++) {
		if(items[i]->hasName(name)) {
			items[i]->setValue(val);
			return;
		}
	}
	cout << "\t\t could not find item: "<<name<<endl;
    
}

//--------------------------------------------------------------
void ButtonPanel::setByName(string name, ofPoint pt){
	for (int i =0; i <items.size(); i++) {
		if(items[i]->hasName(name)) {
			ColorPickerItem * pItem = dynamic_cast < ColorPickerItem * > (items[i]);
			if(pItem != NULL){
				pItem->setValue(pt);

			}
			return;
		}
	}
	cout << "\t\t could not find item: "<<name<<endl;
	
}


//--------------------------------------------------------------
ButtonPanel::ButtonPanel(string theTitle, int x, int y):SimpleButton(theTitle, x, y){
	sel = -1;
	itemheight = 22;
}


//--------------------------------------------------------------
void ButtonPanel::printValue(){
	cout <<endl<< "__"<< title << "_______"<< endl;
	for(int i = 0; i <items.size(); i ++){
		items[i]->printValue();
	}
	cout << "----------------------------"<<endl;
}


//--------------------------------------------------------------
ButtonPanel::~ButtonPanel(){
	clearItems();
}

//--------------------------------------------------------------
bool ButtonPanel::checkClick(int x, int y){
	selected = false;
	if(visible){
		
		relx = x-xpos-2; // Items are indented 2px in draw!
		rely = y-ypos;
		selected = false;
		if(relx > 0 && relx < width && rely > 0 && rely < buttonheight){
			selected = true;
		}
		
		// items
		sel = -1;
		for(int i = 0; i<items.size(); i++){
			if(items[i]->checkClick(relx , rely )){
				sel = i;
			}
		}
	}
	
	
	return selected;
}


//--------------------------------------------------------------
void ButtonPanel::update(){
	for (int i = 0; i< items.size(); i++) {
		items[i]->update();
	}
	
	SimpleButton::update();
}


//--------------------------------------------------------------
void ButtonPanel::draw(){
	if(visible){
		/// SimpleButton style drawing
		ofPushMatrix();
		ofTranslate((int)xpos, (int)ypos, 0);
		
		// SHADOW
		// ofFill();
		// ofSetColor(0, 0, 0,20);
		// ofDrawRectangle(5, 5, w, buttonheight);
        
        // BACKGROUND
        ofFill();
		//ofSetHexColor(0xffffff);
		ofSetColor(255, 255, 255, 220);
		if(over){
			ofSetColor(255, 255, 255, 250);
		}
		ofDrawRectangle(0, 0, width, buttonheight);
        
		// BORDER
        if(over){
			ofSetHexColor(0x666666);
		}else{
			ofSetHexColor(0x999999);
		}
		ofNoFill(); // bg border
        ofDrawRectangle(0, 0, width, buttonheight);
		
        // TITLE
        ofDrawBitmapString(title, 2, height/2 +6);
		
		//
		ofFill();
		if(over){
			ofSetHexColor(0x666666);
		}else{
			ofSetHexColor(0x999999);
		}
        
		// teken de inhoud!
		drawItems();
		
		ofPopMatrix();
		//
	}
}


//--------------------------------------------------------------
void ButtonPanel::drawItems(){
	// DRAW CHOICES
	ofPushMatrix();
	ofTranslate(2, 0, 0);
	for(int i =0; i<items.size(); i++){
		items[i]->draw();
	}
	ofPopMatrix();
}


//--------------------------------------------------------------
void ButtonPanel::clearItems(){
	// is dit nodig?
	sel = -1;
	for(int i =0; i <items.size(); i++){
		delete items[i];
	}
	items.clear();
}


//--------------------------------------------------------------
void ButtonPanel::addListItem( ListItem * item){
	item->ypos = itemheight + items.size()*itemheight;
	items.push_back(item);
	buttonheight = height/2 + itemheight * (items.size()+1);
	int tempw = item->width;
	width = (tempw > width) ? tempw : width;
	// cout << "adding a list item" << endl;
}


//--------------------------------------------------------------
void ButtonPanel::addListItem(string title){
	ListItem * l = new ListItem(title);
	addListItem(l);
}


//--------------------------------------------------------------
void ButtonPanel::addToggleItem(string title, bool& value){
	ListItem * l = new ToggleItem(title, value);
	addListItem(l);
}


//--------------------------------------------------------------
SliderItem * ButtonPanel::addSliderItem(string title, float bottom, float top, float& value){
	SliderItem * l = new SliderItem(title,bottom,top,value);
	addListItem(l);
	return l;
}


//--------------------------------------------------------------
void ButtonPanel::addColorItem(string title, ofPoint& c, float saturation){
	ColorPickerItem * cpi = new ColorPickerItem(title, c, saturation);
	addListItem(cpi);
}

//--------------------------------------------------------------
void ButtonPanel::addFlashItem(string title,bool& value){
	ListItem * l = new FlashItem(title,value);
	addListItem(l);
}


//--------------------------------------------------------------
void ButtonPanel::addSelectionItem(string name,  const int stateValue, int& state){
	ListItem * l = new SelectionItem(name, state, stateValue);
	addListItem(l);
}



//--------------------------------------------------------------
void ButtonPanel::drag(int x, int y){
	if (visible) {
		if(sel >= 0){
			items[sel] ->drag(x-xpos-2,y-ypos);
		}else {
			
			SimpleButton::drag(x,y);
		}
	}
	
}


//--------------------------------------------------------------
bool ButtonPanel::checkOver(int x, int y){
	over = false;
	if(visible){
		
		relx = x-xpos;
		rely = y-ypos;
		over =(relx > 0 && relx < width && rely > 0 && rely < buttonheight);
		if(over){
			for (int i =0 ; i <items.size(); i++) {
				items[i]->checkOver(relx, rely);
			}
		}
	}
	
	return over;
}
