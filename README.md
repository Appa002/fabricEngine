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
        GameObject    GameObject  <---------------------  Gets instaciated by game.cpp.
        |        |        |
        |        |        |     Instaciate and keep pointer to:
        |        |        |
    Behavior   Behavior   Behavior
    
## Engine

This class houses the event loop, render functions and loading of gameObjects.

It's implemented acording to the Singleton design pattern.
