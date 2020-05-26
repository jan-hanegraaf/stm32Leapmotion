# __**stm32_leapmotion**__
het semesteropdracht van het vak C-programmeren was een project te maken rond de stm32. het project is een leapmotion game waarbij je door middel van handbewegingen een pixel op de 0.96inch display kunt laten bewegen.
er wordt gebruik gemaakt van een extra virtuele COM poort waarvoor een @de usb kabel aan de STM32 is aangebracht. Hiervan zijn de D+ en D- lijn (usb kant) verbonden met D2 en d109 STM kant).

Het uitlezen van de coordinaten van de LeapMotion word gedaan door een hulp programma geschreven in java (processing). Het programma leest de X en Z coordinaat in om zo een vlak veld te gebruiken, deze waardes worden gemapt naar een gangbare waaarde voor het scherm.
Hierna worden deze in een string doorgestuurd naar de STM32 over de COM poort. De string heeft een vaste omvang van 8 chars.

Aan de STM kant van het project wordt de zojuist ontvangen waarde uit de buffer gelezen en in een globale variabele gezet. Deze word verdeeld onder de X en Y waardes die nodig zijn voor een pixel op het scherm te tonen. Bij elke ontvangen waarde word de locatie geupdate. dit zorgt voor een vrij vloeiende beweging.
De speelse toepassing die we gekozen hebben is dat je met de getekende pixel van de handlocatie een random gegenereerde pixel dient te "vangen".
Als uitbereiding hierbij hebben we een menu voorzien waarin je kunt kiezen om door te spelen of te stoppen. hierbij word de keuze puur gebaseerd op basis van de kant waar de hand positie zich bevind.

in de map leapV1 staat de java code, en in core->source->main.c staat de C-code.

<i>link naar de video demonstratie: https://drive.google.com/file/d/1MUtedUv3HyfUfhUrnAdrfcm2BhYjN70K/view?fbclid=IwAR3HknYq5nVwUCKMyuF2t7tBH4M_8D7pp2hsU5D-TTVX5SzxzedZzi_F0q0</i>

<img align="center" src="https://images.squarespace-cdn.com/content/v1/57bfa41debbd1a395f0edf68/1584722444826-3QGPNDPS8N2QV6SUOU2C/ke17ZwdGBToddI8pDm48kJcQqSupaQ8ME-CpCzJvW1AUqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKcLRyezCat90lXN39-p-cXdsCLvA__x_4SbjXXBQQdd4UjGKnGFLtBRbLkH_cFMBof/controller-2.png " width="400" height="400">
