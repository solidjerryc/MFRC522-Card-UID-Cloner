//原始万能卡：03 FC FF C1
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

MFRC522::MIFARE_Key key;

byte uid[]={0xff,0xff,0xff,0xff};

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600); // Initialize serial communications with the PC
    while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card

    // Prepare the key (used both as key A and as key B)
    // using FFFFFFFFFFFFh which is the default at chip delivery from the factory
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

Serial.println("Please insert a card which you want to copy it's UID");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid[i]=mfrc522.uid.uidByte[i];
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  
  Serial.println("Remove the old card and insert a new card in 5 seconds.");
  delay(2000);
  Serial.println("5......");
  delay(1000);
  Serial.println("4......");
  delay(1000);
  Serial.println("3......");
  delay(1000);
  Serial.println("2......");
  delay(1000);
  Serial.println("1......");
  delay(1000);
  Serial.println("0......");
  //byte newUid[] =  mfrc522.uid.uidByte;

  
  while ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    Serial.println("No card, fail to write data. Please try again.\n");
    Serial.println("Please insert a card which you want to copy it's UID");
    return;
  }
  Serial.println("Writeing data. Do not remove card now.");
  if ( mfrc522.MIFARE_SetUid(uid, (byte)4, true) ) {
    Serial.println("Wrote new UID to card.");
  }

  mfrc522.PICC_HaltA();
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    return;
  }
  
  // Dump the new memory contents
  Serial.println(F("New UID and contents:"));
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
}


// Setting the UID can be as simple as this:
//void loop() {
//  byte newUid[] = NEW_UID;
//  if ( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) ) {
//    Serial.println("Wrote new UID to card.");
//  }
//  delay(1000);
//}
