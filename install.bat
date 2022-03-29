@move build\lib\*.a lib
@move build\lib\*.dll .
@move SFML\include\SFML include
@rd /s /q build
@rd /s /q SFML