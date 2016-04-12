#include <iostream>
#include "Belote.h"
#include "tinyxml.h"
#include "tinystr.h"
#include <iostream>
#include <string>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    char* outputXmlFile;
    int mode ;

    if (argc>=3) {
        // convert from *char to int to use switch
        if( 0==strcmp(argv[1],"1"))
            mode = 1;
        else if ( 0==strcmp(argv[1],"2"))
            mode = 2;
        else
            mode = 3;
//         // in plain old C++03 you would do:
//         char* end;
//         int mode = strtol( argv[1] , &end , 10 );
        switch ( mode )
        {
            case 1:
            case 2:
            case 3:
                cout << "Game mode : " << mode << endl;
                break;
            default:
                cerr << "Unknown game mode." << endl;
                return 0;
        }

        // Pause the execution this way
        cout << "Press enter to continue..." << endl;
        cin.get();
        outputXmlFile = argv[2];
        cout << "Output XML file: " << outputXmlFile << endl;
    } else {
        cerr << "Not enough arguments. Aborting..." << endl;
        return 0;
    }

    TiXmlDocument doc;
    // Don't mind the XML declaration, it is only to conform to the XML standards.
    TiXmlDeclaration decl ( "1.0", "", "" );
    doc.InsertEndChild( decl );
    Belote belote;
    doc.InsertEndChild( belote.start(mode));
    doc.SaveFile(outputXmlFile);
    
    return 0;
}
