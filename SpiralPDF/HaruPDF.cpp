#include <math.h>
#include "hpdf.h"
#include <string.h>
#include "HaruPDF.h"

// Constructor to initialize a HaruPDF object
HaruPDF::HaruPDF(){
    // Create the new PDF object
    pdf = HPDF_New (NULL, NULL);

    strcpy (filename, "spiralPDF.pdf");

    // Add new page to the pdf
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    // Set default font size
    size = 25;

    // Set a default font
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
}

// Destructor
HaruPDF::~HaruPDF(){
    // Clean up 
    HPDF_Free (pdf);
}

// Method to place certain character on page with certain text angle and x and y position.
void HaruPDF::placeCharacterOnPDF(char character, float textAngle, float x, float y){
    // Begin writing text on page
    HPDF_Page_BeginText (page);
    
    // Set up font and inputted font size
    HPDF_Page_SetFontAndSize (page, font, size);

    // Turn text angle into radians
    rad1 = textAngle / 180 * M_PI;

    // Set position on page where we want to place the character with a certain text angle
    HPDF_Page_SetTextMatrix(page,cos(rad1), sin(rad1), -sin(rad1), cos(rad1),x, y);

    // Put character in buffer to be written to pdf
    char buf[2];
    buf[0] = character;
    buf[1] = 0;
    HPDF_Page_ShowText (page, buf);

    // Stop writing text to the page
    HPDF_Page_EndText (page);


}

// Method to save pdf to file
void HaruPDF::savePDF(){
    // Save the pdf
    HPDF_SaveToFile (pdf, filename);  
}


