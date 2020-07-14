#include "HaruPDF.h"
#include "Spiral.h"

using namespace std;

int main(int argc, char **argv){

    // 1st arg = x pos
    // 2nd arg = y pos
    // 3rd arg = radius size (minimum must be 55)
    // 4th arg = angle to start at
    // The angle to start at begins at 12 o'clock and goes clock wise
    //  90 degrees would start at 3 o'clock
    //  180 degrees would start at 6 o'clock
    //  270 degrees would start at 9 o'clock 
    Spiral spiral(210, 300, 55, 270);

    HaruPDF pdf;

    if(argc < 2){
        cout << "Enter a valid string to put in a spiral..." << endl;
        cout << "Exiting" << endl;
        exit(1);
    }

    int stringLen = strlen(argv[1]);
    char* string = argv[1];

    for(int i = 0; i < stringLen; i++){
        pdf.placeCharacterOnPDF(string[i], spiral.getTextAngle(), spiral.getTextX(), spiral.getTextY());
        spiral++;
    }

    pdf.savePDF();
}