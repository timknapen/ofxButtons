#include "ImageButton.h"

//-------------------------------------------------------------------------------------------
ImageButton::ImageButton(int x, int y,string theFilename, bool& theValue):SimpleButton("", x, y){
	// do nothing?
	on = &theValue;
	counter = 100;
	filename = theFilename;
	img.loadImage(filename);
	w = img.getWidth()+4;
	h = img.getHeight()+4;
	buttonheight = h;
	steps =  10;
} 


//-------------------------------------------------------------------------------------------
bool ImageButton::checkClick(int x, int y){
	relx = x-xpos;
	rely = y-ypos;
	if(relx > 2 && relx < w-2 && rely > 2 && rely < h-2){
		*on = true;
		counter = 0;
		selected = true;
	}else if(relx > 0 && relx < w && rely > 0 && rely < h){
		selected = true;
	}
	
	return selected;
}



//-------------------------------------------------
void ImageButton::saveToXML( ofxXmlSettings& XML){
	XML.addTag("ImageButton");
	int num = XML.getNumTags("ImageButton") - 1;
	XML.setAttribute("ImageButton", "name", title, num);
	XML.setAttribute("ImageButton", "filename", filename, num);
	XML.setAttribute("ImageButton", "on", (*on)?"true":"false", num);
}



//-------------------------------------------------------------------------------------------
void ImageButton::draw(){
	if(visible){
		
		ofFill();
		ofPushMatrix();
		ofTranslate(xpos,ypos, 0);
		if(over){
			ofSetHexColor(BUTTONS_COLOR_HIGHLIGHT);
			ofRect(0, 0, w, h);
		}	
		if(counter < steps) {
			int bright = 255 * ((float)counter/steps);
			ofSetColor(255, bright,bright);
		}else {
			ofSetHexColor(0xffffff);
		}
		
		img.draw(2, 2);
		
		ofPopMatrix();
		//
	}
	
}

//
bool ImageButton::checkOver(int x, int y){
	relx = x-xpos;
	rely = y-ypos;
	over =(relx > 0 && relx < w && rely > 0 && rely < h);
	return over;
}