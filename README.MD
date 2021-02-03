## What is this repo?  

It's nothing. 

## Absolutely NOT some technical task  

Additional “nice to have” features (evaluate by yourself how many features possible to implement)  
• ~~ Circle contact list pictures at the left side, you may use any available image assets ~~  
• ~~ Call function: by tap you call ContactListProvider::call(id) and indicate somehow active call ~~  
• ~~ Grid view switcher for our contact viewer (here contact pictures “must have”) ~~  
• Smart chunk-retrieving for long lists (e.g ContactListProvider has getChunk(index, size))  
• ~~ Favorites: possibility to add to favorites (use star/plus button) and show only favorites ~~  
• ~~ Local filter: text field by using which we may filter out contacts (great if “on the fly”) ~~  
• Alphabetical jump: service provides getAvailableLetters chars and sorted contact list  
• Expert level: combine alphabetical jump with previously described chunk retrieving  

## Requirements
* Compiler with C++17 Support  
* Qt 5.15  
* CMake 3.14 or higher

## Building

I'm using CMake so if you have `PATH` correctly setup for Qt and C++ the building is standard

```
git clone https://github.com/Malibushko/totally_non_suspicios_repo.git
cd totally_non_suspicios_repo
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . 
```

## Notes

To change number of generated contacts you should use `generatedContactsNum` variable in  `main.qml` (line 13)

## License

MIT
