# FireWatch
FireWatch is a simple app for people who work in forest and monitor the fire. They need to collect nature info to make shure that forest not under danger situation.
Utility use SQLite, Qt/Cpp and API. Employeer who have acsess in your system can enter in DB what the wheather now, temperature and wind speed. If someone need to compare wheather from forecast, app can make graphical representation of collect data.

# Installation and configuration
1. Your need QT6 and SQLite. Download this, and return this guide.
2. Follow the command.
    ```markdown
    git clone git@github.com:1wwg2/FireWatch.git
4. Run sql script in dir ScriptForDb, in file you will see how to do it. After that you need to find API, which can shows the weather you need. I recommend https://openweathermap.org/api#pro.
5. Regardless of your OS, just choose correct path to DB and URL API.
   # src/LoginToApp/logintoapp.h
  ```cpp

namespace SettingPathDb
{
    const QString dbPath = "Path_To_Your_File_Db/employ.db";
    const QString UrlApi("Url_To_Your_API");
}
```
4. Don`t forget complile and run program:) In QT creator you have hotkey ctrl + r. 
   
 
## 🎬 Demo 

![Example](demo.gif)  
   
