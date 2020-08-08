# Home Automation with NodeMCU
## Connections to be made prehand for Single MCP23017


| NodeMCU Physical Pin |  NodeMCU Pin Name | MCP23017 Physical Pin |	MCP23017 Pin Name	Description       |
|--------------|-----------|--------------|-------------------------|
|       17     |     D1    |      12    	| Serial Clock input      |
|       18     |     D2    |      13	    | SDA	I/O Serial Data     
|       21     |    3V3    |      18      | Reset	Use a 4.7kOhm resistor to disable hardware reset     |
|       21	   |    3V3	   |      09	    | VDD	Power               |
|       22     |    GND    |      10	    | VSS	Ground              |
|       22	   |    GND    |      15	    | A0	Hardware address pin|
|       22	   |    GND    |      16	    | A1	Hardware address pin|
|       22	   |    GND    |      17	    | A2	Hardware address pin|

![Test Image 4](https://miro.medium.com/max/875/1*oTyuiMVozV7-osMnRLDNeQ.png)

### Adressing more than 1 MCP23017 can be made with slight difference:
| Address	Adafruit address | A0 (PIN 15) | A1 (PIN 16) | A2 (PIN 17) |
|--------------------------|-------------|-------------|-------------|
|0x20	|0	|LOW | LOW | LOW|
|0x21	|1	|HIGH| LOW | LOW|
|0x22	|2	|LOW	|HIGH	|LOW|
|0x23	|3	|HIGH	|HIGH	|LOW
|0x24	|4	|LOW	|LOW	|HIGH|
|0x25	|5	|HIGH	|LOW	|HIGH|
|0x26	|6	|LOW	|HIGH	|HIGH|
|0x27	|7  |	HIGH|	HIGH|	HIGH|

### Conncetion for 2 MCP23017 is shown bellow
![Test Image 1](https://miro.medium.com/max/875/1*oTyuiMVozV7-osMnRLDNeQ.png)

### Note code for:
|   No of MCP's  | Intialising MCP|
|----------------|--------------|
| For 1 MCP23017 | mcp.begin(); |
| For 2 MCP23017 | mcp0.begin(0);<br>mcp1.begin(1);|
| For 3 MCP23017 | mcp0.begin(0);<br>mcp1.begin(1);<br>mcp2.begin(2);|

and so on

## Pins on MCP23017(conncet accornding to code)

| Adafruit PIN<br>(Pin-Number in Code) |	Physical Pin | Pin Name |
|----------------------------------|---------------|----------|
| 0	| 21 | GPA0|
| 1	| 22 | GPA1	|
| 2	| 23 |GPA2	|
| 3	| 24 |GPA3	|
| 4	| 25 |GPA4	|
| 5	| 26 |GPA5	|
| 6	| 27 |GPA6	|
| 7	| 28 |GPA7	|
| 8	| 1 |GPB0	|
| 9	| 2 |GPB1	|
| 10| 3	|GPB2	|
| 11| 4 |GPB3|
| 12| 5 |GPB4|
| 13|6|	GPB5|
| 14|7|	GPB6|
| 15|8|	GPB7|
