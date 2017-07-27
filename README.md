# Fabric Engin

Tiny, tiny ""engine""

## Instanciation Tree

                         Engine
                       /       \
                      /         \
                     /           \       
                    /             \ 
                   / Keeps Pointer \
                  /       to:       \
                GameObject    GameObject  <---------------------  Get instaciated by game.cpp.
                |        |        |
                |        |        |     Instaciate and keep pointer to:
                |        |        |
            Behavior   Behavior   Behavior