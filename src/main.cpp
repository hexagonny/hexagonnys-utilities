#include "hutils.h"
#include "menu_templates.h"

#include <iostream>

//  You can use "using namespace" to shorten code.
using namespace hUtils::Text;  /* Best use for "using" is putting them
                                 inside of source files. */

int main(){
    hUtils::setConsoleWindowSize(); hUtils::Text::clearAll();
    
    toCentered("The hell. This window is paused and resized.");
    toCentered("This is a list.", 34, 1);
    toCentered("Item two.", 35, 2);
    toRight("Yo, Im right.");
    toLeft("Hey, Im left.");
    toLeft("I have an indent.", 1);
    toLeft("And I have a deeper indent", 2);

    hUtils::pause(); hUtils::Text::clearAll();

    std::cout << color(92) + "This is bright green (92)\n" + defaultText();
    std::cout << color(32) + "This is not bright but green (32)\n" + defaultText();
    
    hUtils::pause();

    int option;
    bool stay = true;

    while(stay){
        hUtils::Text::clearAll();
        std::cout << "Pick a menu (1/2/3): "; std::cin >> option;

        switch(option){
            case 1: infoMenu(); break;
            case 2: itemPaginatedMenu(); break;
            case 3: itemListMenu(); break;
            case 4: stay = false; break;
            default: std::cout << "Incorrect value.";
        };

        hUtils::pause();
    }

    hUtils::pause();

    return 0;
}