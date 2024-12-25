#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::remove
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() {}
};

// Subject Interface
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// Concrete Subject: Weather Station
class WeatherData : public Subject {
private:
    vector<Observer*> observers; // List of observers
    float temperature;
    float humidity;
    float pressure;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::remove(observers.begin(), observers.end(), observer); // Shift elements
        observers.erase(it, observers.end()); // Physically remove them
    }

    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setWeatherData(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers();
    }
};

// Concrete Observer: Display Device
class CurrentConditionsDisplay : public Observer {
public:
    void update(float temperature, float humidity, float pressure) override {
        cout << "Current Conditions: " << temperature << "°C, " << humidity << "% humidity, "
             << pressure << " hPa" << endl;
    }
};

class StatisticsDisplay : public Observer {
private:
    float maxTemp = -1e9, minTemp = 1e9, sumTemp = 0;
    int numReadings = 0;

public:
    void update(float temperature, float humidity, float pressure) override {
        if (temperature > maxTemp) maxTemp = temperature;
        if (temperature < minTemp) minTemp = temperature;
        sumTemp += temperature;
        numReadings++;
        cout << "Statistics: Max Temp = " << maxTemp << "°C, Min Temp = " << minTemp
             << "°C, Avg Temp = " << sumTemp / numReadings << "°C" << endl;
    }
};

// Main function
int main() {
    // Create WeatherData (Subject)
    WeatherData weatherStation;

    // Create Observers
    CurrentConditionsDisplay currentDisplay;
    StatisticsDisplay statsDisplay;

    // Register Observers
    weatherStation.addObserver(&currentDisplay);
    weatherStation.addObserver(&statsDisplay);

    // Simulate new weather data
    weatherStation.setWeatherData(25.0, 65.0, 1013.0);
    weatherStation.setWeatherData(27.0, 70.0, 1012.0);
    weatherStation.setWeatherData(23.0, 60.0, 1011.0);

    return 0;
}
