//
// Created by aegis on 12/6/24.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm-3.0/gtkmm.h>

class Window : public Gtk::Window {
    public:
        Window();
        ~Window();

    private:
      Gtk::Paned m_paned;
      Gtk::Box m_box;
      Gtk::MenuBar m_menu_bar;

      Gtk::MenuItem m_menu_item_file;
      Gtk::Menu m_file_menu;
    // This is the file menu functions
      Gtk::MenuItem m_menu_item_new_project;
      Gtk::MenuItem m_menu_item_load_project;
      Gtk::MenuItem m_menu_item_save_project;

      void on_new_project();
      void on_load_project();
      void on_save_project();

	// This is the driver manager functions
      Gtk::MenuItem m_menu_item_driver_manager;
      void on_driver_manager();

      Gtk::Label m_footer_label;
      void on_window_resize(Gtk::Allocation& allocation);

};

#endif //WINDOW_H
