#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"
#include "console.cpp"

using namespace std;


int world(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a web engine view widget
    QWebEngineView *webView = new QWebEngineView;

    // Load a local HTML file
    webView->setUrl(QUrl::fromLocalFile("file.html"));

    // Check if the web engine view widget was properly initialized
    if (webView->page() == nullptr) {
        qCritical() << "Failed to initialize QWebEngineView";
        return 1;
    }

    // Show the web engine view widget
    webView->show();

    // Run the event loop
    return app.exec();
}
int command()
{
        string command;

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "exit") {
            break;
        }
        else if (command == "help")
        {
            printf("Commands:\n");
            printf("exit\n");
            printf("help\n");
            printf("ls\n");
            printf("cd\n");
            printf("pwd\n");
            printf("mkdir\n");
            printf("rmdir\n");
            printf("rm\n");
            printf("mv\n");
            printf("cp\n");
        }
        else if (command == "ls")
{
    // get the current directory
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << "Current directory: " << cwd << endl;

    // open the directory
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(cwd)) != NULL)
    {
        // print all the files and directories within directory
        while ((ent = readdir(dir)) != NULL)
        {
            cout << ent->d_name << endl;
        }
        closedir(dir);
    }
    else
    {
        // could not open directory
        perror("");
        return 1;
    }
}
else if (command == "gtk")
{
    // show the GTK window from console.cpp
    world(0, NULL);
}
        else if (command == "cd")
        {
            // get the current directory
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            // get the new directory
            string newDir;
            cout << "Enter the new directory: ";
            getline(cin, newDir);
            // change the directory
            chdir(newDir.c_str());
            // clear the input stream
            cin.clear();
            cin.sync();
        }
        else if (command == "pwd")
        {
            // get the current directory
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            cout << "Current directory: " << cwd << endl;
        }
        else if (command == "mkdir")
        {
            // get the new directory name
            string newDir;
            cout << "Enter the new directory name: ";
            getline(cin, newDir);
            // create the new directory
            mkdir(newDir.c_str(), 0777);
            // clear the input stream
            cin.clear();
            cin.sync();
        }
        else if (command == "rmdir")
        {
            // get the directory name
            string newDir;
            cout << "Enter the directory name: ";
            getline(cin, newDir);
            // remove the directory
            rmdir(newDir.c_str());
            // clear the input stream
            cin.clear();
            cin.sync();
        }
        else if (command == "rm")
        {
            // get the file name
            string newFile;
            cout << "Enter the file name: ";
            getline(cin, newFile);
            // remove the file
            remove(newFile.c_str());
            // clear the input stream
            cin.clear();
            cin.sync();
        }
        else if (command == "mv")
        {
            // get the file name
            string oldFile;
            cout << "Enter the old file name: ";
            getline(cin, oldFile);
            // get the new file name
            string newFile;
            cout << "Enter the new file name: ";
            getline(cin, newFile);
            // rename the file
            rename(oldFile.c_str(), newFile.c_str());
            // clear the input stream
            cin.clear();
            cin.sync();
        }
        else if (command == "cp")
        {
            // get the file name
            string oldFile;
            cout << "Enter the old file name: ";
            getline(cin, oldFile);
            // get the new file name
            string newFile;
            cout << "Enter the new file name: ";
            getline(cin, newFile);
            // open the old file
            ifstream src(oldFile.c_str(), ios::binary);
            // open the new file
            ofstream dest(newFile.c_str(), ios::binary);
            // copy the file
            dest << src.rdbuf();
            // clear the input stream
            cin.clear();
            cin.sync();
        }
        

        else{
            cout << "Command not recognized: " << command << endl;

            }

            // clear the input stream
        cin.clear();
        cin.sync();

        // Add your own commands here
    }
}

int main() {

    world(0, NULL);
    return 0;
}
