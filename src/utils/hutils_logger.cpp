#include "hutils.h"

#include <iostream>
#include <iomanip>

using namespace std;

using namespace hUtils;

    namespace hUtils {
    Logger logger;

    void Logger::logAction(const string& message)
    {
        cout << message << '\n';
    }

    void Logger::logSuccess(const string& message)
    {
        cout.flush();
        cout << text.color(92) << message << '\n' << text.defaultText(); 
    }

    void Logger::logMoved(const string& message)
    {
        cout.flush();
        cout << text.color(93) << message<<'\n' << text.defaultText(); 
        filesMoved++;
    }

    void Logger::logRemoved(const string& message)
    {
        cout.flush();
        cout << text.color(93) << message << '\n' << text.defaultText(); 
        foldersRemoved++;
    }

    void Logger::logCreated(const string& message)
    {
        cout.flush();
        cout << text.color(92) << message << '\n' << text.defaultText(); 
        foldersCreated++;
    }

    void Logger::logError(const string& message)
    {
        cerr.flush();
        cerr << text.color(91) << message << '\n' << text.defaultText(); 
        errors++;
    }

    void Logger::logWarning(const string& message)
    {
        cerr.flush();
        cerr << text.color(95) << message << '\n' << text.defaultText(); 
        warnings++;
    }

    void Logger::displaySummary()
    {
        cout << "\nSummary:\n\n"
             << setw(17) << left << "Files Moved: "     << filesMoved     << '\n'
             << setw(17) << left << "Folders Removed: " << foldersRemoved << '\n'
             << setw(17) << left << "Folders Created: " << foldersCreated << '\n'
             << setw(17) << left << "Warnings: "        << warnings       << '\n'
             << setw(17) << left << "Errors: "          << errors         << "\n\n";
    }
}