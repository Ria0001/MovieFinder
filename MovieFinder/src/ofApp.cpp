#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	logo.load("Logo.png");
	searchIcon.load("Search.png");
	searchText.load("Search Text.png");

	movieName.load("InriaSans-Regular.ttf", 20);
	movieYear.load("InriaSans-Regular.ttf", 14);

	blue.set(58, 80, 107);
	babyblue.set(91, 192, 190);
	lightblue.set(111, 255, 233);
	black.set(11, 19, 43);

	isSplashScreen = true;

	getApi(0);
	//3c18e906d6224567a2654c5ed4e26b85
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum() > 200) isSplashScreen = false;
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (isSplashScreen == true){
		ofBackgroundGradient(blue, babyblue, OF_GRADIENT_LINEAR);
		logo.draw(388,111,500, 495);
		return;
	}
	
	ofBackgroundGradient(babyblue, lightblue, OF_GRADIENT_LINEAR);
	
	ofSetColor(black);
	ofDrawRectangle(0, 0, 368, 720);

	ofSetColor(babyblue); // filter box
	ofDrawRectRounded(24, 32, 318, 43, 10);
	searchIcon.draw(308, 42, 24, 24);
	ofDrawRectRounded(24, 89, 318, 500, 10);

	//filters
	ofColor leftCol = lightblue;
	ofColor leftFont = (0);

	ofColor rightCol = blue;
	ofColor rightFont = (255);

	if (!currentFilters[0].isActive) {
		leftCol = blue;
		leftFont = (255);

		rightCol = lightblue;
		rightFont = (0);
	}
	ofSetColor(leftCol);
	ofDrawRectangle(33, 97, 151, 28);
	ofSetColor(leftFont);
	movieYear.drawString(currentFilters[0].filterName, 83, 118);

	ofSetColor(rightCol);
	ofDrawRectangle(184, 97, 151, 28);
	ofSetColor(rightFont);
	movieYear.drawString(currentFilters[1].filterName, 227, 118);


	ofSetColor(lightblue);
	ofDrawRectRounded(97, 645, 175, 43, 5);
	searchText.draw(125, 655, 116, 24);

	int xAxis = 415, yAxis = 32, xGap = 219, yGap = 340; //for movie group
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 4; j++) {
			ofSetColor(black);
			ofDrawRectangle(xAxis, yAxis, 180, 270);
			movieName.drawString("Movie Name", xAxis, yAxis + 295);
			movieYear.drawString("2020", xAxis, yAxis + 313);
			xAxis += xGap;
		}
		xAxis = 415;
		yAxis += yGap;
	}

}

void ofApp::getApi(int queryType) {
	string apiBaseUrl = "https://api.themoviedb.org/3/", apiSearchMode = "discover/", apiSearchType = "multi", apiKey = "?api_key=3c18e906d6224567a2654c5ed4e26b85";
	filter temp;

	switch (queryType) {
	case 0: //Get filters
		//temp.id = -1; // default
		temp.filterName = "Movies";
		temp.isActive = true;
		currentFilters.push_back(temp);

		temp.filterName = "TV shows";
		currentFilters.push_back(temp);

		for (int i = 0; i < 2; i++) {
			if (i == 0) apiBaseUrl = "https://api.themoviedb.org/3/genre/movie/list" + apiKey;
			else "https://api.themoviedb.org/3/genre/tv/list" + apiKey;

			apiContainers = ofJson::parse(ofLoadURL(apiBaseUrl).data);

			if (!apiContainers.empty()) {
				for (int j = 0; j < apiContainers["genres"].size(); j++) {
					temp.id = apiContainers["genres"][j]["id"].get<int>();
					temp.filterName = apiContainers["genres"][j]["name"].get<string>();
					currentFilters.push_back(temp);
				}
			}
			else { cout << "API error" << "\n"; }
		}
		break;
	default:
		break;
	}
	return;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
