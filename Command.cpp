#include <iostream>
#include <string>
#include <vector>

// Receiver: The object that performs the actual action
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }
    void turnOff() {
        std::cout << "Light is OFF" << std::endl;
    }
};

class Fan {
public:
    void start() {
        std::cout << "Fan is spinning" << std::endl;
    }
    void stop() {
        std::cout << "Fan is stopped" << std::endl;
    }
};

// Command Interface
class Command {
public:
    virtual void execute() = 0; // Executes the command
    virtual ~Command() {}
};

// Concrete Commands
class LightOnCommand : public Command {
private:
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override {
        light->turnOn();
    }
};

class LightOffCommand : public Command {
private:
    Light* light;
public:
    LightOffCommand(Light* l) : light(l) {}
    void execute() override {
        light->turnOff();
    }
};

class FanStartCommand : public Command {
private:
    Fan* fan;
public:
    FanStartCommand(Fan* f) : fan(f) {}
    void execute() override {
        fan->start();
    }
};

class FanStopCommand : public Command {
private:
    Fan* fan;
public:
    FanStopCommand(Fan* f) : fan(f) {}
    void execute() override {
        fan->stop();
    }
};

// Invoker: The Remote Control
class RemoteControl {
private:
    std::vector<Command*> commands;
public:
    void setCommand(Command* command) {
        commands.push_back(command);
    }
    void pressButton() {
        if (!commands.empty()) {
            commands.back()->execute();
            commands.pop_back();
        }
    }
};

// Main function
int main() {
    // Create receivers
    Light light;
    Fan fan;

    // Create commands
    Command* lightOn = new LightOnCommand(&light);
    Command* lightOff = new LightOffCommand(&light);
    Command* fanStart = new FanStartCommand(&fan);
    Command* fanStop = new FanStopCommand(&fan);

    // Create invoker
    RemoteControl remote;

    // Simulate button presses
    remote.setCommand(lightOn);
    remote.setCommand(fanStart);
    remote.setCommand(fanStop);
    remote.setCommand(lightOff);


    for (int i = 0; i < 4; ++i) {
    std::cout << "Press button to execute a command: ";
    remote.pressButton();
}


    // Clean up memory
    delete lightOn;
    delete lightOff;
    delete fanStart;
    delete fanStop;

    return 0;
}
