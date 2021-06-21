# Arduino-CO2-Sensor-Project

Measuring CO2 in classrooms or other closed spaces allows us to check if the ventilation system is bringing in fresh air to replace the air with CO2 we are breathing out. 

If somebody has COVID-19 in a room, they are breathing out virus particles and CO2. As CO2 accumulates virus particles also accumulate. We can measure the CO2 levels to understand how much virus particles accumulate. If there is a good ventilation system that replaced inside air with fresh outside air, the CO2 levels will get reduced close to outside CO2 levels of around 400ppm and the virus particles will also get reduced. The CO2 level serves as a proxy for the concentration of airborne virus.

If there are a lot of people in a room, and one has COVID, then everyone is breathing out CO2 but only one person in shedding airborne virus. In this situation the CO2 level is not a direct proxy for the amount of virus in the air, but it's a proxy for the risk of infecting someone. The more people in the room, the higher the risk that one (or more) of them can get infected. So if the CO2 levels are high and someone has COVID in that room, there is a good chance that someone could get it as well. 


Airborne viruses is not the only reason why we might be worried about the CO2 concentration. If too much CO2 accumulates in the air, studies have shown that people tend to not work as well academically if there's too much CO2 in the air and that it is harder for your lungs to take in oxygen and breathe out CO2. 

## Background and further reading

There are a number of resources that explain how CO2 sensors can be used for risk evaluation here are some more resources that you can read if you are interested. 
* [UK Recomandation on ventillation and CO2 monitoring](https://assets.publishing.service.gov.uk/government/uploads/system/uploads/attachment_data/file/928720/S0789_EMG_Role_of_Ventilation_in_Controlling_SARS-CoV-2_Transmission.pdf)
* [Journal article on CO2 as a proxy for infection risk](https://pubs.acs.org/doi/10.1021/acs.estlett.1c00183)

## Parts

These are the parts we used, similar components can be used for most of them like the CO2 sensor we just put the ones we used.

* CO2 sensor (MHZ19B)
* Humidity/Temperature sensor (DHT11)
* Arduino nano
* BreadBoard
* Wires
* Female & Male Connectors
* Dupont Connector Housing
* Switch
* LED Display (WayinTop 20x4 2004 LCD Display Module with IIC/I2C/TWI Serial Interface Adapter) 
* Box

## Plans

### Cirquit board
![Cirquit Board](images/IMG_2898.heic)
This is the schematic drawing of the circuit used to make the CO2 sensor.

### Images
![Cirquit Board](images/IMG_2905.heic)
This is an Image of our result for the circuit as the final product.

![LED](images/IMG_2906.heic)
This is an Image of how we set up the LED board and where the wires go.

## Program

This is the [arduino program](Arduino_CO2_program.ino) that we used to make the CO2 sensor function accordingly.

