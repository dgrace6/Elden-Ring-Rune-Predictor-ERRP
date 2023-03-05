# Elden-Ring-Rune-Predictor-ERRP
A Elden Ring Rune Predictor (or ERRP) using C++ and the wxwidget library to create an simple window that calculates runes needed for leveling up. When running the exe, you input your current level then desired number of level ups (inputing 1 gives you 1 stat point).

If you just want the Application, download the .exe file and run it! 

To build your own solution, download the Github repository and follow the steps below! 

Set the wxwidgets folder as an environment variable and install win32 and x64 wxwidgets. I followed this awesome tutorial on YouTube from 

OttoBotCode

You should only need to follow the second video in the playlist from the 0:00 to 4:56:

https://www.youtube.com/watch?v=BjQhp0eHmJw&list=PLFk1_lkqT8MbVOcwEppCPfjGOGhLvcf9G&index=1

Open the 'Elden Ring Rune Predictor ERRP.sln' with Visual Studio and make sure you are set to x86 at the top instead of x64 or win32.

With environmental variable is set, the project should recognize all the functions in the source.cpp. Run the 'Local Windows Debugger' just to make sure there is no issues. If no issues pop up, change the 'Debug' option at the top to 'Release', then click the 'Build' option at the top and select 'Build Solution'. That will create a new folder, 'Release', next to the .sln. In there is the Application. Enjoy!

Thanks for checking out my code!

