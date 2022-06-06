/*
 *  ColorPickerItem.cpp
 *  buttons
 *
 *  Created by Tim Knapen on 30/02/18.
 *  Copyright 2010 Tim Knapen. All rights reserved.
 *
 */

#include "ColorPickerItem.h"


//--------------------------------------------------------------
ColorPickerItem::ColorPickerItem(string theTitle, ofPoint& _color, float saturation):ListItem(theTitle){
	// cout << "making new sliderItem: "<< theTitle << endl;
	width = 30 + 4 + title.length()*CHAR_W; //textw
	width = (width < 300) ? 300 : width;
	int imgw = width - 16;
	int imgh = height;
	color = &_color;
	img.allocate(imgw, imgh, OF_IMAGE_COLOR);
	// set the colors
	ofPixels pix = img.getPixels();
	int id;
	float xpct, ypct;
	for(int x = 0; x < imgw; x++){
		for(int y = 0; y < imgh; y++){
			id = x + y * imgw;
			ofColor newColor;
			xpct = (float)x/(float)(imgw-10);
			ypct = (float)y/(float)(imgh-1);
			
			if( x < imgw - 10){
				newColor.setHsb( 255 * xpct,		// H
								saturation * 255 * ((ypct < 0.5) ?  2 * ypct : 1 ), // 1 - 2 *(ypct - 0.5))),		 // S
								255 * ((ypct < 0.5) ? 1 :  1 - 2 *(ypct - 0.5))	// B
								);
			}else if(x == imgw - 10){
				newColor.set(255, 255, 255);
			}else{
				float l = ceil(255.0 * (1.0 - ypct) );
				newColor.set(l, l, l );
			}
			pix[3 * id] = newColor.r;
			pix[3 * id + 1] = newColor.g;
			pix[3 * id + 2] = newColor.b;
		}
	}
	img.setFromPixels(pix);
}

//-------------------------------------------------
void ColorPickerItem::saveToXML( ofxXmlSettings& XML){
	// nothing yet
	XML.addTag("ColorPickerItem");
	int num = XML.getNumTags("ColorPickerItem") - 1;
	XML.setAttribute("ColorPickerItem", "name", title, num);
	XML.setAttribute("ColorPickerItem", "r", ofToString(color->x, 0), num);
	XML.setAttribute("ColorPickerItem", "g", ofToString(color->y, 0), num);
	XML.setAttribute("ColorPickerItem", "b", ofToString(color->z, 0), num);
	
}

//----------------------------------------------------------------
void ColorPickerItem::setValue(ofPoint _color){
	*color = _color;
}

//----------------------------------------------------------------
void ColorPickerItem::setValue(float _val){
	//*val = _color; do nothing
}



//--------------------------------------------------------------
bool ColorPickerItem::checkClick(int x, int y){
  ofPoint imgPos( x - 10, y - ypos ); // the image is drawn at 10, 0
	int imgw = img.getWidth();
	int imgh = img.getHeight();
	selected = false;
	if(imgPos.x >= 0 && imgPos.x < imgw && imgPos.y >= 0 && imgPos.y < imgh){
		selected = true;
	}
	if (selected) {
		ofPixels pix = img.getPixels();
		int id = (int)imgPos.x + (int)imgPos.y * imgw;
		color->set(pix[3*id], pix[3*id+1], pix[3*id+2]);
	}
	return selected;
}
//



//--------------------------------------------------------------
void ColorPickerItem::drag(int x, int y){
  ofPoint imgPos( x - 10, y - ypos); // the image is drawn at 10, 0
	int imgw = img.getWidth();
	int imgh = img.getHeight();
	if(imgPos.x < 0){
		imgPos.x = 0;
	}
	if(imgPos.x >= imgw){
		imgPos.x = imgw-1;
	}
	if(imgPos.y < 0){
		imgPos.y = 0;
	}
	if(imgPos.y >= imgh){
		imgPos.y = imgh-1;
	}
	
	if(imgPos.x >= 0 && imgPos.x < imgw && imgPos.y >= 0 && imgPos.y < imgh){
		ofPixels pix = img.getPixels();
		int id = (int)imgPos.x + (int)imgPos.y * imgw;
		color->set(pix[3*id], pix[3*id+1], pix[3*id+2]);
	}
	
	//*value = bottom + (top-bottom)*t;
}


//--------------------------------------------------------------
void ColorPickerItem::printValue(){
	cout << "  " << title << " = " << (int)(color->x) << ", " << (int)(color->y ) << ", " << (int)(color->z) << endl;
}


//--------------------------------------------------------------
void ColorPickerItem::draw(){

	
	ofPushMatrix();
	ofTranslate(0, ypos);
	// draw the sample color
	ofFill();
	ofSetColor(color->x, color->y, color->z);
	ofDrawRectangle(0, 0, 8, height);
	// draw the image at 10, ypos
	ofSetColor(255);
	img.draw(10, 0);
	if(over){
		ofSetHexColor(0xffffff);
	}else{
		ofSetHexColor(0x000000);
	}
	ofDrawBitmapString(title+": "+ofToString(color->x, 0)+
					   ", " + ofToString(color->y, 0) +
					   ", " + ofToString(color->z, 0), 12, height-4);
	ofPopMatrix();
	
}

