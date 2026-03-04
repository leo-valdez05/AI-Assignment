#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char pollutant[20];
    int value;
    int pm25 = 0, pm10 = 0, no2 = 0;
    int aqi;

    fp = fopen("sensor_data.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening sensor data file\n");
        return 1;
    }

    while(fscanf(fp,"%s %d", pollutant, &value) != EOF)
    {
        if(strcmp(pollutant,"PM25") == 0)
            pm25 = value;

        else if(strcmp(pollutant,"PM10") == 0)
            pm10 = value;

        else if(strcmp(pollutant,"NO2") == 0)
            no2 = value;
    }

    fclose(fp);

    printf("Location: Shimla\n\n");

    printf("PM2.5 = %d\n", pm25);
    printf("PM10 = %d\n", pm10);
    printf("NO2 = %d\n\n", no2);

    aqi = pm25;

    if(pm10 > aqi)
        aqi = pm10;

    if(no2 > aqi)
        aqi = no2;

    printf("Final AQI = %d\n", aqi);

    if(aqi <= 50)
        printf("Air Quality: Good\nAdvice: Air quality is satisfactory.\n");

    else if(aqi <= 100)
        printf("Air Quality: Moderate\nAdvice: Acceptable air quality.\n");

    else if(aqi <= 150)
        printf("Air Quality: Unhealthy for Sensitive Groups\nAdvice: Limit outdoor activity.\n");

    else if(aqi <= 200)
        printf("Air Quality: Unhealthy\nAdvice: Avoid prolonged outdoor exertion.\n");

    else if(aqi <= 300)
        printf("Air Quality: Very Unhealthy\nAdvice: Stay indoors if possible.\n");

    else
        printf("Air Quality: Hazardous\nAdvice: Health alert.\n");

    return 0;
}