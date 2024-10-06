# InstaFollowers with esp32 and oled display
**InstaFollowers** is an ESP8266/ESP32 module designed for easily get Instagram Followers / Following count number.
Tnx to xamrex for the library

![IMG20241006134915](https://github.com/user-attachments/assets/ecb190bf-0361-4bf0-9ae0-88ab2a587f10)



## Limitation
FREE account allows only for 500 requests/month.

## Installation

1. [Arduino Library Manager (Recommended)](https://www.arduino.cc/en/Guide/Libraries)  
2. [Download or clone this repository into your arduino libraries directory](https://help.github.com/articles/cloning-a-repository/)  



## Basic Usage
1.  To make this libraty working, you need to create an account on https://rapidapi.com/, 

then search for **instagram scraper api** https://rapidapi.com/social-api1-instagram/api/instagram-scraper-api2
and press **Subscribe for Basic**

![alt text](https://github.com/xamrex/arduino-InstagramFollowers/blob/main/pics/subscribe.png)

Coppy **x-rapidapi-host**, and **x-rapidapi-key**

![alt text](https://github.com/xamrex/arduino-InstagramFollowers/blob/main/pics/apikey.png)

2. Connect to Wi-Fi  
3. Include InstaFollowers module  
      ```cpp
   #include <InstaFollowers.h>
   ```
4. Create a InstaFollowers object with rapidapi-host and rapidapi-key
      ```cpp
   InstaFollowers instaStats("instagram-scraper-api2.p.rapidapi.com", "RAPID_API_KEY");
   ```
   
5. Now you can get Followers number given username:
      ```cpp
   int FollowersCount= instaStats.GetUserFollowersCount("arduino.cc");
   Serial.print("Follower count:"+String(FollowersCount));
   ```
   
## Picture
![alt text](https://github.com/xamrex/arduino-InstagramFollowers/blob/main/pics/pic.png)
