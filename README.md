"# MFRC522-Card-UID-Cloner" 

#### This is a trail example for copying an M1 card's UID to another one.

##### In some case, Access Control System reads your RFID card's UID to open the door. Probably you don't want to open the door downstairs for your close friend every time when they come to visit you. So you can copy a same card for him for convenience.

##### This example is based on this MFRC522 library example; see https://github.com/miguelbalboa/rfid.

##### First, make sure you have successfully installed Arduino IDE and drivers of Arduino UNO.

##### Make sure you have installed the MFRC522 library mentioned before.

##### Connecting MFRC522 module with Arduino.

---

```
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno           Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 * 

```

--- 
##### Upload this ino file to your arduino, and open the serial monitor.

##### Put a card which you want to copy the UID. After Arduino returned a successful signal, you need to follow the instruction that insert a new card which you want to write the UID.

* ### The card's UID must be changeable. Make sure you bought this kind of cards.

##### Wait for sevaral seconds and your new card can be used immidiatly.

##### Give it to your friend and he can easily come to vist you.
