#include "main.h"



using namespace std;


void helloworld()
    {
        auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

        Gtk::Window window;
        window.set_default_size(200, 200);
        window.set_title("Hello World");

        Gtk::Button button("Hello World");

        window.add(button);

        button.show();

        return app->run(window);
    }