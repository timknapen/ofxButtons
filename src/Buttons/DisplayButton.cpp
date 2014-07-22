#include "DisplayButton.h"


//-------------------------------------------------------------------------------------
DisplayButton::DisplayButton(string name, int x, int y, float& theValue):SimpleButton(name, x, y){
	// do nothing?
	// cout << "new Displaybutton " << name << endl;
	value = &theValue;
	
} 

//-------------------------------------------------------------------------------------
void DisplayButton::saveToXML( ofxXmlSettings& XML){
	// not needed, just for show
	XML.addTag("DisplayButton");
	int num = XML.getNumTags("DisplayButton") - 1;
	XML.setAttribute("DisplayButton", "name", title, num);
	XML.setAttribute("DisplayButton", "value", ofToString(*value, 2), num);
}


//-------------------------------------------------------------------------------------
void DisplayButton::draw(){
	if(visible){
		
		SimpleButton::draw();
		
		
		ofFill();
		ofPushMatrix();
		ofTranslate(xpos, ypos, 0);
		if(over){
			ofSetHexColor(0x666666);
		}else {
			ofSetHexColor(0x999999);
		}
		ofDrawBitmapString(ofToString(*value, 2), 4, 2*h-6);
		ofPopMatrix();
		//
	}
}

//-------------------------------------------------------------------------------------
void DisplayButton::printValue(){
	cout << title << " = "<< *value <<endl;
}

//-------------------------------------------------------------------------------------
bool DisplayButton::checkClick(int x, int y){
	selected = false;
	if(visible){
		
		relx = x-xpos;
		rely = y-ypos;
		selected =(relx > 0 && relx < w && rely > 0 && rely < 2*h);
	}
	return selected;

}

//-------------------------------------------------------------------------------------
bool DisplayButton::checkOver(int x, int y){
	over =false;
	if(visible){
		
	relx = x-xpos;
	rely = y-ypos;
	over =(relx > 0 && relx < w && rely > 0 && rely < h*2);
	}

	return over;

}