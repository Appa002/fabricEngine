# Fabric Engine a tiny, tiny engine

### Disclaimer

I made this for learning porpuses and the code needs major refactoring.


### Setup:

SDL is required put the devel library into engine/SDL you might need to change your CMakeLists.txt if the naming conversation changes. Currently, the conversation is SDL/include, SDL/lib/x86 and SDL/lib/x64.
Lua is also required put the Lua library into engine/Lua you can see further details in the CMakeLists.txt

### Explanation:

GameObjects are compiled DLL's in the __game folder.
The Lua files contain information about the object.
Using EXPORT in a game object CPP file one can export a symbol.
In the Lua files, the values for those symbols are defined.
Symboles "transform" and "mesh" are predefined and the values get suplied by the engine.
