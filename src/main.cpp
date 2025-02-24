#include "hutils.h"

#include <iostream>

//  You can use "using namespace" to shorten code.
using namespace hUtils::Text;  /* Best use for "using" is putting them
                                 inside of source files. */

int main(){
    hUtils::setConsoleWindowSize(); hUtils::Text::clearAll();
    
    toCentered("The hell. This window is paused and resized.");
    toCentered("This is a list.", true, 34);
    toCentered("Item two.", true, 35);
    toRight("Yo, Im right.");
    toLeft("Hey, Im left.");
    toLeft("I have an indent.", 1);
    toLeft("And I have a deeper indent", 2);

    hUtils::pause(); hUtils::Text::clearAll();

    std::cout << color(92) + "This is bright green (92)\n" + defaultText();
    std::cout << color(32) + "This is not bright but green (32)\n" + defaultText();
    std::cout << color(32, true) + "This is not bright but green and in bold (32, true)" + defaultText();
    
    hUtils::pause();

    return 0;
}