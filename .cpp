#include <iostream>
#include <unordered_map>
#include <thread>
#include <chrono>

class PLC {
private:
    std::unordered_map<std::string, bool> inputs;
    std::unordered_map<std::string, bool> outputs;

public:
    void setInput(std::string name, bool value) {
        inputs[name] = value;
    }

    bool getInput(std::string name) {
        return inputs[name];
    }

    void evaluate() {
        // Example rung: O0 = I0 AND I1
        outputs["O0"] = inputs["I0"] && inputs["I1"];

        // Example rung: O1 = I2 OR I3
        outputs["O1"] = inputs["I2"] || inputs["I3"];
    }

    void displayOutputs() {
        for (auto& out : outputs) {
            std::cout << out.first << ": " << (out.second ? "ON" : "OFF") << std::endl;
        }
    }
};

int main() {
    PLC plc;

    // Example inputs
    plc.setInput("I0", true);
    plc.setInput("I1", false);
    plc.setInput("I2", true);
    plc.setInput("I3", false);

    plc.evaluate();
    plc.displayOutputs();

    return 0;
}
