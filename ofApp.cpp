#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int radius = 70;
	int circle_width = radius * 0.25;
	int deg_span = 15;

	for (int x = 72; x < ofGetWidth(); x += 144) {

		for (int y = 72; y < ofGetHeight(); y += 144) {

			ofPushMatrix();
			ofTranslate(x, y);

			for (int deg = 0; deg < 360; deg += deg_span) {

				ofColor color;
				ofPoint color_point(x + radius * cos((deg + deg_span * 0.5) * DEG_TO_RAD), y + radius * sin((deg + deg_span * 0.5) * DEG_TO_RAD));
				float noise_value = ofNoise(color_point.x * 0.01 + color_point.y * 0.01, ofGetFrameNum() * 0.01) * 255;
				color.setHsb(noise_value, 200, 255);
				ofSetColor(color);

				vector<ofPoint> vertices;
				for (int d = deg; d <= deg + deg_span; d++) {

					vertices.push_back(ofPoint(radius * cos(d * DEG_TO_RAD), radius * sin(d * DEG_TO_RAD)));
				}

				for (int d = deg + deg_span; d >= deg; d--) {

					vertices.push_back(ofPoint((radius - circle_width)  * cos(d * DEG_TO_RAD), (radius - circle_width) * sin(d * DEG_TO_RAD)));
				}

				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}