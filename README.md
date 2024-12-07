To compile the project use following command in the /src dir:
```
g++ main.cpp window.cpp -o app $(pkg-config --cflags --libs gtkmm-3.0)
```
