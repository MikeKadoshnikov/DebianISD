#include <gtkmm.h>
#include <iostream>
#include "window.h"

Window::Window() :
    m_box(Gtk::ORIENTATION_VERTICAL),  // Initialize box in vertical orientation
    m_menu_item_file("_File", true),   // "_File" means 'F' is a shortcut
    m_menu_item_new_project("_New Project", true),
    m_menu_item_load_project("_Load Project", true),
    m_menu_item_save_project("_Save Project", true),
	m_menu_item_driver_manager("_Driver Manager", true),
	m_footer_label("Info")
{

    // Set the title of the window
    set_title("Debain-ISD");
    set_size_request(800, 600);
    set_default_size(800, 600);


    // Add the menu items to the file menu
    m_file_menu.append(m_menu_item_new_project);
    m_file_menu.append(m_menu_item_load_project);
    m_file_menu.append(m_menu_item_save_project);


    // Set the file menu to the File MenuItem
    m_menu_item_file.set_submenu(m_file_menu);

    // Add the File menu item to the menu bar
    m_menu_bar.append(m_menu_item_file);
    m_menu_bar.append(m_menu_item_driver_manager);

    // Connect signal handlers to menu items
    m_menu_item_new_project.signal_activate().connect(sigc::mem_fun(*this, &Window::on_new_project));
    m_menu_item_load_project.signal_activate().connect(sigc::mem_fun(*this, &Window::on_load_project));
    m_menu_item_save_project.signal_activate().connect(sigc::mem_fun(*this, &Window::on_save_project));

    m_menu_item_driver_manager.signal_activate().connect(sigc::mem_fun(*this, &Window::on_driver_manager));

    // Add the menu bar to the box
    m_box.pack_start(m_menu_bar, Gtk::PACK_SHRINK);  // Shrink ensures menu bar takes minimal space

    m_paned.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_paned.add1(m_box);

    m_paned.add2(m_footer_label);

    add(m_paned);

    signal_size_allocate().connect(sigc::mem_fun(*this, &Window::on_window_resize));

    // Show all children of the window
    show_all_children();
}

Window::~Window() {
    std::cout << "Window destroyed" << std::endl;
}

// Signal handlers
void Window::on_new_project() {
    std::cout << "New Project clicked" << std::endl;
}

void Window::on_load_project() {
    std::cout << "Load Project clicked" << std::endl;
}

void Window::on_save_project() {
    std::cout << "Save Project clicked" << std::endl;
}

void Window::on_driver_manager() {
    std::cout << "Driver Manager should open up here" << std::endl;
}

void Window::on_window_resize(Gtk::Allocation& allocation) {
  int window_height = allocation.get_height();
  int pane_position = static_cast<int>(window_height * 0.8);
  m_paned.set_position(pane_position);
}