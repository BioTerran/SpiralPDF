#include <math.h>
#include <string.h>
#include "hpdf.h"

// Wrapper object that can be used to write characters to a page and generate a pdf
class HaruPDF {
private:
    //HaruPDF specific members
    HPDF_Doc  pdf;
    HPDF_Page page;
    HPDF_Font font;

    char filename[256];

    int size;

    float rad1;
public:
    // Constructor 
    HaruPDF();

    // Destructor
    ~HaruPDF();

    // Method used to write character on page with certain text angle and position.
    void placeCharacterOnPDF(char character, float textAngle, float x, float y);

    // Method used to save the PDF to a file
    void savePDF();
};

