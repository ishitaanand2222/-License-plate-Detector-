#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>//used to work with hard cascade files
#include<iostream>

using namespace std;
using namespace cv;

///////////////////////// Project 3: License plate Detector /////////////////////////////

//From chapter 8 and 1

int main()
{
	VideoCapture cap(0);
	Mat img;


	CascadeClassifier plateCascade;// we will load our CascadeClassifier
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	//this statement is to check if the image is loaded or not
	if (plateCascade.empty()) { cout << "XML file not loaded\n"; }

	vector<Rect>plates;
	while (true)
	{
		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 10);
		for (int i = 0; i < plates.size(); i++)
		{
			Mat imgCrop = img(plates[i]);
			//imshow(to_string(i), imgCrop);
			imwrite("Resources/Plates/" + to_string(i)+".png",imgCrop);// to save the image
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
		}

		imshow("Image", img);
		waitKey(1);
	}




	return 0;
}