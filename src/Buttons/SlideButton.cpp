#include "SlideButton.h"


//-------------------------------------------------------------------------------------
SlideButton::SlideButton(string name, int x, int y, float& theValue):SimpleButton(name, x, y){
	// do nothing?
	value = &theValue;
	bottom = 0;
	top = 100;
} 


//-------------------------------------------------------------------------------------
SlideButton::SlideButton(string name, int x, int y,float fbottom, float ftop, float& theValue):SimpleButton(name, x, y){
	// do nothing?
	value = &theValue;
	bottom = fbottom;
	top = ftop;
} 


//-------------------------------------------------------------------------------------
void SlideButton::saveToXML( ofxXmlSettings& XML){
	XML.addTag("SlideButton");
	int num = XML.getNumTags("SlideButton") - 1;
	XML.setAttribute("SlideButton", "name", title, num);
	XML.setAttribute("SlideButton", "value", *value, num);
}


//-------------------------------------------------------------------------------------
void SlideButton::printValue(){
	cout << title << " = "<< *value <<endl;
}


//-------------------------------------------------------------------------------------
void SlideButton::draw(){
	if(visible){
		SimpleButton::draw();
		
		ofFill();
		ofPushMatrix();
		ofTranslate(xpos, ypos, 0);
		ofSetHexColor(0xeeeeee);
		ofRect(2, h+2,w-5, h-4);
		if(over){
			ofSetHexColor(BUTTONS_COLOR_HIGHLIGHT);
			ofRect(2, h+2,(int)((w-5)*(*value-bottom)/(top-bottom)), h-4);
			ofSetHexColor(0x666666);
		}else {		
			ofSetHexColor(0xcccccc);
			ofRect(2, h+2,(int)((w-5)*(*value-bottom)/(top-bottom)), h-4);
			ofSetHexColor(0x999999);
		}
		ofDrawBitmapString(ofToString(*value, 2), 4, 2*h-6);
		ofPopMatrix();
		//
	}
}



//-------------------------------------------------------------------------------------
void SlideButton::drag(int x, int y){
	if(visible){
		if (rely > h) {
			float t = (float)(x-xpos)/(float)(w-5);
			t = (t >1) ? 1: t;
			t = (t <0) ? 0: t;
			*value = bottom + (top-bottom)*t;
		}else{
			SimpleButton::drag(x,y);
		}
	}
}



//-------------------------------------------------------------------------------------
bool SlideButton::checkClick(int x, int y){
	selected = false;
	if(visible){
		relx = x-xpos;
		rely = y-ypos;
		selected =(relx > 0 && relx < w && rely > 0 && rely < 2*h);
		if (rely > h && selected) {
			float t = (float)(x-xpos)/(float)(w-4);
			t = (t >1) ? 1: t;
			t = (t <0) ? 0: t;
			*value = bottom + (top-bottom)*t;
		}
	}
	return selected;
}



//-------------------------------------------------------------------------------------
bool SlideButton::checkOver(int x, int y){
	over = false;
	if(visible){
		relx = x-xpos;
		rely = y-ypos;
		over =(relx > 0 && relx < w && rely > 0 && rely < h*2);
	}
	return over;
}