#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;
int main()
{

    Mat input;
    string k = "";
    int y = 1;

    while (1) {
        if (y == 7)
            return 0;
        k = to_string(y);
        input = imread("C:\\Users\\velu2\\OneDrive\\Pictures\\Saved Pictures\\IMG-20240928-WA000" + k + ".jpg");
        if (input.empty()) {
            continue;
        }
        Mat inrange;
        inRange(input,Scalar(42,82,87), Scalar(255,255,255), inrange);
        imshow("usingInrange", inrange);
        waitKey(0);
        vector<vector<Point>> contours;
        findContours(inrange, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
        string Area = "AREA:";
        for (int i = 0; i < contours.size(); i++) {
            if ((contourArea(contours[i]) > 18000.0) && (contourArea(contours[i]) < 50000.0)) {
                Area += to_string(contourArea(contours[i])) + "px";
                putText(input, Area, Point(30, 200), FONT_HERSHEY_COMPLEX, 1.5, Scalar(250, 225, 100), 4);
                drawContours(input, contours, i, Scalar(255, 0, 0), 2);
                imshow("Area Of Cashew nut", input);
                waitKey(0);
            }

        }


        destroyAllWindows();
        y++;
    }
    return 0;
}
