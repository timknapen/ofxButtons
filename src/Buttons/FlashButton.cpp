#include "FlashButton.h"


//-------------------------------------------------------------------------------------------
FlashButton::FlashButton(string name, int x, int y, bool& theValue):SimpleButton(name, x, y){
	// do nothing?
	on = &theValue;
	counter = 100;
	steps = 20;
} 

//-------------------------------------------------------------------------------------------
bool FlashButton::checkClick(int x, int y){
	selected = false;
	if(visible){
		relx = x-xpos;
		rely = y-ypos;
		if(relx > 0 && relx < w && rely > 0 && rely < h){
			selected = true;
		}else if(relx > 0 && relx < w && rely > h && rely < 2*h){
			*on = true;
			counter = 0;
			selected = true;
		}
	}
	return selected;
}


//-------------------------------------------------------------------------------------------
void FlashButton::saveToXML( ofxXmlSettings& XML){
	XML.addTag("FlashButton");
	int num = XML.getNumTags("FlashButton") - 1;
	XML.setAttribute("FlashButton", "name", title, num);
	XML.setAttribute("FlashButton", "on", (*on)?"true":"false", num);
}


//-------------------------------------------------------------------------------------------
void FlashButton::printValue(){
	cout << title << " = "<< *on <<endl;
}



//-------------------------------------------------------------------------------------------
void FlashButton::update(){
	if(*on){
		counter = 0;
		*on = false;
	}
	SimpleButton::update();
}



//-------------------------------------------------------------------------------------------
void FlashButton::draw(){
	if(visible){
		
		SimpleButton::draw();
		ofFill();
		ofPushMatrix();
		ofTranslate(xpos+2,ypos+h, 0);
		
		if(counter < steps) {
			ofSetColor(255, 255* counter / steps, 255 * counter / steps);
		}else if (*on) {
			if(over){
				ofSetHexColor(BUTTONS_COLOR_HIGHLIGHT);
			}else{
				ofSetHexColor(BUTTONS_COLOR_MEDIUM);
				
			}
		}else {
			ofSetHexColor(BUTTONS_COLOR_LIGHT);
		}
		ofRect(2, 4, w-9, h-8);
		
		ofPopMatrix();
		//
	}
	
}

//-------------------------------------------------------------------------------------------
bool FlashButton::checkOver(int x, int y){
	over =false;
	if(visible){
		relx = x-xpos;
		rely = y-ypos;
		over =(relx > 0 && relx < w && rely > 0 && rely < h*2);
	}
	return over;
	
}