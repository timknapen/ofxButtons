#include "ListItem.h"


//----------------------------------------------------------------
ListItem::ListItem(string theTitle){
	
	// cout<< "  ListItem: '" << theTitle << "'" << endl;
	counter = 100;
	title = theTitle;
	width = 4+ title.length()*CHAR_W; //textw
	ypos = 0;
	rely = 0;
	
	width = (width < 300) ? 300 : width;
	height = 18;
	
	selected = false;
	over = false;
}


//----------------------------------------------------------------
ListItem::~ListItem(){
	// destructor
}


//----------------------------------------------------------------
void ListItem::saveToXML( ofxXmlSettings& XML){
	// nothing yet
	XML.addTag("ListItem");
	int num = XML.getNumTags("ListItem") - 1;
	XML.setAttribute("ListItem", "name", title, num);
}



//----------------------------------------------------------------
void ListItem::printValue(){
	cout << "  " << title << endl;
}



//----------------------------------------------------------------
void ListItem::draw(){
	ofPushMatrix();
	ofTranslate(0, ypos, 0);
	ofFill();
	// bg color
	// ofSetColor(240, 255, 240);
	// ofRect(0,0, w, h);
	if(over){
		ofSetHexColor(0x333333);
	}else{
		ofSetHexColor(0x666666);
	}
	ofDrawBitmapString(title, 2, height-2);
	ofPopMatrix();
}

//----------------------------------------------------------------
void ListItem::setValue(float val){
	//
}

//----------------------------------------------------------------
void ListItem::drag(int x, int y){
	// alleen virtual voor sliders
	//cout<< "dragging: "<<title<< endl;
}
//


//----------------------------------------------------------------
void ListItem::update(){
	counter ++;
}


//----------------------------------------------------------------
bool ListItem::checkClick(int x, int y){
	return false;
}


//----------------------------------------------------------------
bool ListItem::checkOver(int x, int y){
	rely = y - ypos;
	over =(x > 0 && x < width && rely > 0 && rely < height);
	return over;
}


//----------------------------------------------------------------
void ListItem::unSelect(){
	selected =false;
}


//----------------------------------------------------------------
void ListItem::setName(string s){
	title = s;
}



//----------------------------------------------------------------
bool ListItem::hasName(string s){
	return !(strcmp(s.c_str(), title.c_str()));
}
