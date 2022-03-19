# ESP 8266 12F IoT Button custom PCB

- [ESP 8266 12F IoT Button custom PCB](#esp-8266-12f-iot-button-custom-pcb)
	- [Funktion](#funktion)
	- [PCB](#pcb)
	- [Flashen](#flashen)
		- [Bootmodus aktivieren](#bootmodus-aktivieren)
	- [Teile](#teile)

## Funktion
Der ESP wird durch den großen Reset Knopf aus dem Deep Sleep aufgeweckt und sendet seine Request an einen Webserver, danach geht er wieder in den Deep Sleep (Stromverbrauch ±0,0258mA). Über RTC Memory kann man sich "Flags" trotz Deep Sleep speichern, so kann der Controller z.B. auch wissen, das wievielte mal er aufgeweckt wurde und dementsprechend anders handeln. Ein entsprechendes Beispiel ist unter [Code/IoTButton_Code_RTCMemory.ino](https://github.com/MarvinHofmann/ESP-8266-IotButton/blob/main/Code/IoTButton_Code_RTCMemory.ino)zu finden.

## PCB

<p align="center">
<img src="pcbDesing.png" width="400">
</p>

Das PCB läuft auf Akkubetrieb. Dieser kann durch Anstecken eines Micro USB-Kabels geladen werden. Die Bauteilgröße der SMD Teile ist 0805. 
	Die Abmaße sind 52,7mm x 35,5mm

Mit dem *TP 4056* wird der Akku geladen. Dieser lädt bis 4,2V, die Geschwindigkeit kann durch den Widerstand R3 festgelegt werden (R3 = 1k2 => Lädt mit 1000mAh).
Die Status LEDs (LED1 und LED2) zeigen an, ob der Akku noch lädt (leuchtet rot) oder ob der Akku voll ist (leuchtet Grün).
Siehe dazu auch die Tabellen auf Seite 3 im [Datenblatt](https://dlnmh9ip6v2uc.cloudfront.net/datasheets/Prototyping/TP4056.pdf).

Der ESP8266 ist ein 3,3V Mikrocontroller deshalb regelt ein *AMS 1117* für Konstante 3,3V trotz einer Batteriespannung von bis zu 4,2V

## Flashen
Da der blanke ESP 12F verbaut ist, kann nicht über die USB Schnittstelle geflasht werden. Um z.B. über die Arduino IDE zu Flashen einfach CP2102 USB to TTL Modul an die Leisten links neben dem Chip anstecken, externen 3,3V Stromversorgung anschließen. Danach den Boot Modus aktivieren und als ESP8266 12E in der Arduino IDE bespielen.

### Bootmodus aktivieren
Flash und Reset gleichzeitig drücken und Flash vor Reset wieder loslassen. Danach ist der Chip bespielbar. Sobald der Chip beschrieben wurde einfach erneut Reset Drücken, um den Boot Modus zu verlassen.

## Teile
- 1x ESP 12F
- 1x TP 4056
- 1x Micro-USB Buchse
- 1x AMS 1117 -3.3V
- 1x Button 12x12
- 2x Button 6x6
- 4x Widerstand 1k
- 1x Widerstand 1,33k
- 5x Widerstand 10k
- 1x Widerstand 18k
- 1x Widerstand 5,6k 
- 2x LED rot
- 2x LED grün

<p align="center">
<img src="pcbAssembl.jpeg" width="400">
</p>
