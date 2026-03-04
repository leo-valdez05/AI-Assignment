# **AQI Monitoring using a Simple Reflex Agent**



### 1\. Introduction



Air pollution is one of the major environmental problems affecting human health. The Air Quality Index (AQI) is used to measure the level of pollution in the air and determine whether the air quality is safe or harmful.



In this assignment, a Simple Reflex Agent is designed to monitor the air quality of a region based on sensor readings of pollutants. The agent observes the current environmental conditions and decides the AQI category using predefined condition action rules.The agent then displays the AQI level and a health advisory.





### 2\. Example Environment – Shimla



For demonstrating the working of the AQI agent, the city Shimla (Himachal Pradesh) is taken as an example.



Shimla is known to have relatively cleaner air compared to many metropolitan cities. Recent air quality observations indicate that the AQI in Shimla generally ranges between 28 and 70, which falls under the Good to Moderate category.



The main pollutant affecting air quality in this region is PM2.5, although other pollutants such as PM10 and NO₂ also contribute.The AI agent receives pollution data from sensors placed in the city and determines the AQI category.



### 

### 3\. Agent Design



&nbsp;          

&nbsp;             Start the Agent    

&nbsp;          

&nbsp;                     |

&nbsp;                     v



&nbsp;              Read Sensor Data    

&nbsp;             (PM2.5, PM10, NO2)   

&nbsp;          

&nbsp;                     |

&nbsp;                     v



&nbsp;             Apply Reflex Rules  

&nbsp;            AQI = max(PM25,PM10, 

&nbsp;                   NO2) 

&nbsp;        

&nbsp;                     |

&nbsp;                     v 



&nbsp;            Determine AQI Range  

&nbsp;            (Good, Moderate,     

&nbsp;            Unhealthy, etc.)     

&nbsp;          

&nbsp;                     |

&nbsp;                     v

&nbsp;          

&nbsp;            Display AQI Level \&  

&nbsp;            Health Advisory      

&nbsp;          

&nbsp;                     |

&nbsp;                     v

&nbsp;         

&nbsp;                    End           





The flowchart represents the working of the Simple Reflex Agent, where the agent reads sensor inputs, applies predefined rules to determine the AQI value, classifies the air quality level, and provides a suitable health advisory.





### 4\. Components of the Agent



##### Sensors



The sensors measure pollutant levels in the environment.



The pollutants considered are:



PM2.5



PM10



NO₂



These sensor readings are stored in a data file, which is given as input to the agent.



##### Actuators



The agent performs the following actions:



Display pollutant values



Calculate the AQI



Display AQI category



Provide a health advisory





### 5\. AQI Classification

### 

The AQI levels are categorized as follows:



AQI Range	Category

0 – 50	         Good

51 – 100	Moderate

101 – 150	Unhealthy for Sensitive Groups

151 – 200	Unhealthy

201 – 300	Very Unhealthy

Above 300	Hazardous           





### 6\. Agent Rule



The agent determines the AQI using the following rule:



###### AQI = maximum value among PM2.5, PM10 and NO2



This means the pollutant with the highest impact determines the overall AQI.

### 

### 7\. Architecture of AQI Agent



The architecture of the AQI monitoring system can be represented as follows:



Environmental Sensors

(PM2.5, PM10, NO2)

&nbsp;       ↓

&nbsp;  Input Data File

&nbsp;       ↓

&nbsp;  AQI Reflex Agent

&nbsp;(Condition–Action Rules)

&nbsp;       ↓

&nbsp; AQI Calculation

&nbsp;       ↓

AQI Category Determination

&nbsp;       ↓

&nbsp;Health Advisory Output



### 8\. Sensor Input File



Example file: sensor\_data.txt



PM2.5 35

PM10 55

NO2 20

### 

### 9.code



### 10\. Sample Output

###### 

###### gcc sensor\_data.c

###### ./a.out

###### 



