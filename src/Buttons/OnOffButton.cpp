#include "OnOffButton.h"

//-------------------------------------------------------------------------------------------
OnOffButton::OnOffButton(string name, int x, int y, bool& theValue):SimpleButton(name, x, y){
	// do nothing?
	on = &theValue;
} 


//-------------------------------------------------------------------------------------------
bool OnOffButton::checkClick(int x, int y){
	selected = false;
	if (visible) {
		relx = x-xpos;
		rely = y-ypos;
		if(relx > 0 && relx < w && rely > 0 && rely < h){
			selected = true;
		}else if(relx > 0 && relx < w && rely > h && rely < 2*h){
			*on = !*on;
			selected = true;
		}
	}
	return selected;
}


//-------------------------------------------------------------------------------------------
void OnOffButton::printValue(){
	cout << title << " = "<< *on <<endl;
}

//-------------------------------------------------------------------------------------------
void OnOffButton::draw(){
	if(visible){
		
		
		SimpleButton::draw();
		ofFill();
		ofPushMatrix();
		ofTranslate(xpos+2,ypos+h, 0);
		
		if (*on) {
			if(over){
				ofSetHexColor(BUTTONS_COLOR_HIGHLIGHT);
			}else{
				ofSetHexColor(BUTTONS_COLOR_MEDIUM);
				
			}
			ofRect(0, 0, w-5, h-2);
			ofSetHexColor(0xffffff);
			ofDrawBitmapString("ON", 4, h-6);
		}else {
			ofSetHexColor(BUTTONS_COLOR_LIGHT);
			ofRect(0, 0, w-5, h-2);
			ofSetHexColor(0x999999);
			ofDrawBitmapString("OFF", 4, h-6);
		}
		ofPopMatrix();
		//
	}
}



//-------------------------------------------------------------------------------------------
bool OnOffButton::checkOver(int x, int y){
	over = false;
	if(visible){
		
		relx = x-xpos;
		rely = y-ypos;
		over =(relx > 0 && relx < w && rely > 0 && rely < h*2);
	}
	
	return over;
}