/*
 *  SliderItem.cpp
 *  buttons
 *
 *  Created by Tim Knapen on 30/01/10.
 *  Copyright 2010 Tim Knapen. All rights reserved.
 *
 */

#include "SliderItem.h"


//--------------------------------------------------------------
SliderItem::SliderItem(string theTitle, float theMin, float theMax, float& theValue):ListItem(theTitle){
    // cout << "making new sliderItem: "<< theTitle << endl;
    top = theMax;
    bottom = theMin;
    width = 30 + 4 + title.length()*CHAR_W; //textw
    width = (width < 300) ? 300 : width;
    value = &theValue;
    *value = MIN(theMax, MAX(theMin, *value));
} 

//-------------------------------------------------
void SliderItem::saveToXML( ofxXmlSettings& XML){
    // nothing yet
    XML.addTag("SliderItem");
    int num = XML.getNumTags("SliderItem") - 1;
    XML.setAttribute("SliderItem", "name", title, num);
    XML.setAttribute("SliderItem", "value", ofToString(*value, 2), num);
    XML.setAttribute("SliderItem", "min", ofToString(bottom, 2), num);
    XML.setAttribute("SliderItem", "max", ofToString(top, 2), num);
    
}

//----------------------------------------------------------------
void SliderItem::setValue(float val){
    *value= val;
}



//--------------------------------------------------------------
bool SliderItem::checkClick(int x, int y){
    rely = y - ypos;
    selected = false;
    if(x > 0 && x < (width -5) && rely > 0 && rely < height){
        selected = true;
    }
    if (selected) {
        float t = (float)x/(float)(width -5);
        t = (t >1) ? 1: t;
        t = (t <0) ? 0: t;
        *value = bottom + (top-bottom)*t;
    }
    return selected;
}
//



//--------------------------------------------------------------
void SliderItem::drag(int x, int y){
    rely = y -ypos;
    float t = (float)x/(float)(width -5);
    t = (t >1) ? 1: t;
    t = (t <0) ? 0: t;
    *value = bottom + (top-bottom)*t;
}


//--------------------------------------------------------------
void SliderItem::printValue(){
    cout << "  " << title << " = " <<*value<< endl;
}


//--------------------------------------------------------------
void SliderItem::draw(){
    float limVal = MAX(bottom , MIN( top, *value)); // limited val
    
    ofPushMatrix();
    ofTranslate(0, ypos,0);
    ofFill();
    ofSetHexColor(BUTTONS_COLOR_LIGHT);
    ofDrawRectangle(0, 2,(width -5), height-2);
    if(over){
        ofSetHexColor(BUTTONS_COLOR_GREEN_HIGHLIGHT);
        ofDrawRectangle(0, 2, (int)((width -5)*(limVal-bottom)/(top-bottom)), height-2);
    }else {
        ofSetHexColor(BUTTONS_COLOR_GREEN);
        ofDrawRectangle(0, 2,(int)((width -5)*(limVal-bottom)/(top-bottom)), height-2);
    }
    if(over){
        ofSetHexColor(0x333333);
    }else{
        ofSetHexColor(0x666666);
    }
    if(ABS(top-bottom) < 1){
        ofDrawBitmapString(title+" "+ofToString(*value, 3), 2, height-2);
    }if(ABS(top-bottom) > 100){
        ofDrawBitmapString(title+" "+ofToString(*value, 0), 2, height-2);
    }else{
        ofDrawBitmapString(title+" "+ofToString(*value, 2), 2, height-2);
    }
    ofPopMatrix();
    
    //
}

