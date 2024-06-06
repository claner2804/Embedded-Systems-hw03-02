3.2 Ampel System (60%)
Die Stadt Innsbruck ist auf Sie zugegangen und hat Sie gebeten, eine neue Ampelsteuerung zu entwickeln. Der erste Schritt ist die Entwicklung eines Prototypen unter Verwendung der RGB-LED auf unserem Arduino-Board.
Konkret soll die Ampelsequenz folgendermaßen ausschauen:
	• Zu Beginn soll die Ampel für 7 Sekunden Rot leuchten.
	• Dann soll für 3 Sekunden auf Gelb umgeschaltet werden.
	• Die darauf folgende Grünphase soll 5 Sekunden dauern.
	• Bevor die Ampel wieder auf Gelb umschaltet, soll sie für 2 Sekunden Grün blinken. Dabei soll sie für jeweils 0.5 Sekunden abwechselnd leuchten und nicht leuchten.
	• Die folgende Gelbphase (3 Sekunden) schließt den Zyklus ab und die Ampel schaltet wieder auf Rot.
Fussgänger sollen durch einen Bewegungssensor erkannt werden (wir verwenden dafür den Bewegungssensor auf unserem Arduino-Board) und bei Erkennung eines Fussgängers soll die Ampel, wenn Sie sich gerade in einer Grün-Phase befindet, sofort zuerst auf Gelb und dann auf Rot umschalten (für die Gelb- und Rot-Phase gelten die oben genannten Zeiten). Ansonsten wird die Rot-Phase um 5 Sekunden verlängert.
Für Einsatzfahrzeuge soll es eine Fernbedienung geben (wir verwenden für unseren Prototypen stattdessen den Joystick-Button), die, wenn sich die Ampel gerade in einer Rot-Phase befindet, die Ampel zuerst auf Gelb und dann Grün umschaltet (es gelten für die jeweiligen Phasen wieder die oben angegebenen Zeiten). Ansonsten wird die Grün-Phase um 5 Sekunden verlängert.
Es soll auch eine Tag- und Nacht-Steuerung implementiert werden (mithilfe des Helligkeitssensors). Bei Tag soll die Ampel ganz normal funktionieren. Bei Nacht wird die Ampelregelung vorübergehend ausgeschalten und die Ampel soll durchgehend gelb blinken.
Kapseln Sie die Ampelsteuerung in einer eigenen Klasse Ampel (in den Dateien ampel.h und ampel.cpp) und implementieren Sie ein Demo-Programm in der Datei main.cpp. Entscheiden Sie dabei eigenständig, wie die öffentliche Schnittstelle der Klasse Ampel ausschaut und wie diese mit den Sensoren interagiert.
Laden Sie Ihr Programm auf JupyterHub in einen Unterordner namens Aufgabe_2 im Ordner dieses Übungszettel hoch.

![image](https://github.com/claner2804/Embedded-Systems-hw03-02/assets/131294860/dae903f4-cbff-4edc-862f-be91cb18f04f)
