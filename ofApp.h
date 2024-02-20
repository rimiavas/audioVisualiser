#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// Petal count
		int petalCount;

		// Petal size  
		int petalSize;

		// Seed count
		int seedCount;

		// Seed size
		int seedSize;

		// GUI
		ofxPanel gui;
		ofParameter<float> volume;
		ofParameter<float> decay;


		// Audio 
		ofSoundPlayer sound;
		float *fft;
		float *soundSpectrum;
		int bands;
};
