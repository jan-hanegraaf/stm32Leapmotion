# __**stm32_leapmotion**__
het semesteropdracht van het vak C-programmeren was een project te maken rond de stm32. het project is een leapmotion game waarbij je door middel van handbewegingen een pixel op de 0.96imch display kunt laten bewegen.
er wordt gebruik gemaakt van een extra virtuele COM poort waarvoor een @de usb kabel aan de STM32 is aangebracht. Hiervan zijn de D+ en D- lijn (usb kant) verbonden met D2 en d109STM kant).

Het uitlezen van de coordinaten van de LeapMotion word gedaan door een hulp programma geschreven in java (processing). Het programma leest de X en Z coordinaat in om zo een vlak veld te gebruiken, deze waardes worden gemapt naar een gangbare waaarde voor het scherm.
Hierna worden deze in een string doorgestuurd naar de STM32 over de COM poort. De string heeft een vaste omvang van 8 chars.

Aan de STM kant van het project wordt de zojuist ontvangen waarde uit de buffer gelezen en in een globale variabele gezet. Deze word verdeeld onder de X en Y waardes die nodig zijn voor een pixel op het scherm te tonen. Bij elke ontvangen waarde word de locatie geupdate. dit zorgt voor een vrij vloeiende beweging.
De speelse toepassing die we gekozen hebben is dat je met de getekende pixel van de handlocatie een random gegenereerde pixel dient te "vangen".
Als uitbereiding hierbij hebben we een menu voorzien waarin je kunt kiezen om door te spelen of te stoppen. hierbij word de keuze puur gebaseerd op basis van de kant waar de hand positie zich bevind.


